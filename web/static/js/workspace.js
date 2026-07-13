/**
 * AFRILANG local workspace — IndexedDB virtual FS (folders + .afr files).
 * Exposed as window.AfrWorkspace.
 */
(function () {
  const DB_NAME = 'afrilang_workspace';
  const DB_VER = 1;
  const STORE = 'meta';
  const KEY = 'workspace_v1';
  const DEFAULT_FILE = 'Mes projets/hello.afr';
  const DEFAULT_SOURCE =
    'say "Bonjour depuis mon projet!"\n\n' +
    'create name text = "AFRILANG"\n' +
    'say "Hello, {name}!"\n';

  function openDb() {
    return new Promise((resolve, reject) => {
      const req = indexedDB.open(DB_NAME, DB_VER);
      req.onupgradeneeded = () => {
        const db = req.result;
        if (!db.objectStoreNames.contains(STORE)) db.createObjectStore(STORE);
      };
      req.onsuccess = () => resolve(req.result);
      req.onerror = () => reject(req.error);
    });
  }

  async function idbGet() {
    const db = await openDb();
    return new Promise((resolve, reject) => {
      const tx = db.transaction(STORE, 'readonly');
      const r = tx.objectStore(STORE).get(KEY);
      r.onsuccess = () => resolve(r.result || null);
      r.onerror = () => reject(r.error);
    });
  }

  async function idbSet(value) {
    const db = await openDb();
    return new Promise((resolve, reject) => {
      const tx = db.transaction(STORE, 'readwrite');
      tx.objectStore(STORE).put(value, KEY);
      tx.oncomplete = () => resolve();
      tx.onerror = () => reject(tx.error);
    });
  }

  function normalizePath(raw) {
    let p = String(raw || '')
      .replace(/\\/g, '/')
      .replace(/^\/+/, '')
      .trim();
    const parts = p.split('/').filter((x) => x && x !== '.');
    if (parts.some((x) => x === '..' || x.startsWith('.'))) {
      throw new Error('Chemin invalide');
    }
    return parts.join('/');
  }

  function ensureAfr(path) {
    const p = normalizePath(path);
    if (!p.toLowerCase().endsWith('.afr')) return `${p}.afr`;
    return p;
  }

  function parentDir(path) {
    const i = path.lastIndexOf('/');
    return i <= 0 ? '' : path.slice(0, i);
  }

  function seedState() {
    return {
      files: { [DEFAULT_FILE]: DEFAULT_SOURCE },
      folders: ['Mes projets'],
      activePath: DEFAULT_FILE,
    };
  }

  const state = {
    files: {},
    folders: [],
    activePath: null,
    dirty: false,
    saveTimer: null,
    listeners: [],
  };

  function emit() {
    state.listeners.forEach((fn) => {
      try {
        fn(snapshot());
      } catch (_) {
        /* ignore */
      }
    });
  }

  function snapshot() {
    return {
      files: { ...state.files },
      folders: [...state.folders],
      activePath: state.activePath,
    };
  }

  function allFolderPaths() {
    const set = new Set(state.folders);
    Object.keys(state.files).forEach((f) => {
      let dir = parentDir(f);
      while (dir) {
        set.add(dir);
        dir = parentDir(dir);
      }
    });
    return [...set].sort();
  }

  function scheduleSave() {
    state.dirty = true;
    clearTimeout(state.saveTimer);
    state.saveTimer = setTimeout(() => {
      persist().catch(() => {});
    }, 400);
  }

  async function persist() {
    await idbSet({
      files: state.files,
      folders: allFolderPaths(),
      activePath: state.activePath,
    });
    state.dirty = false;
  }

  async function load() {
    let data = null;
    try {
      data = await idbGet();
    } catch (_) {
      data = null;
    }
    if (!data || !data.files || !Object.keys(data.files).length) {
      data = seedState();
    }
    state.files = { ...data.files };
    state.folders = Array.isArray(data.folders) ? [...data.folders] : [];
    state.activePath =
      data.activePath && state.files[data.activePath]
        ? data.activePath
        : Object.keys(state.files).sort()[0];
    emit();
    return snapshot();
  }

  function getActiveSource() {
    if (!state.activePath) return '';
    return state.files[state.activePath] || '';
  }

  function setActiveSource(code) {
    if (!state.activePath) return;
    state.files[state.activePath] = code;
    scheduleSave();
  }

  function openFile(path) {
    const p = normalizePath(path);
    if (!(p in state.files)) throw new Error('Fichier introuvable');
    state.activePath = p;
    scheduleSave();
    emit();
    return state.files[p];
  }

  function createFolder(path) {
    const p = normalizePath(path);
    if (!p) throw new Error('Nom de dossier requis');
    if (!state.folders.includes(p)) state.folders.push(p);
    scheduleSave();
    emit();
  }

  function createFile(path, content) {
    const p = ensureAfr(path);
    if (p in state.files) throw new Error('Le fichier existe déjà');
    const dir = parentDir(p);
    if (dir && !state.folders.includes(dir)) state.folders.push(dir);
    state.files[p] =
      content != null
        ? content
        : `say "Nouveau fichier: ${p}"\n`;
    state.activePath = p;
    scheduleSave();
    emit();
    return p;
  }

  function deletePath(path) {
    const p = normalizePath(path);
    if (p in state.files) {
      delete state.files[p];
      if (state.activePath === p) {
        const keys = Object.keys(state.files).sort();
        state.activePath = keys[0] || null;
      }
    } else {
      // folder: remove folder + nested files
      state.folders = state.folders.filter((f) => f !== p && !f.startsWith(p + '/'));
      Object.keys(state.files).forEach((f) => {
        if (f === p || f.startsWith(p + '/')) delete state.files[f];
      });
      if (state.activePath && (state.activePath === p || state.activePath.startsWith(p + '/'))) {
        const keys = Object.keys(state.files).sort();
        state.activePath = keys[0] || null;
      }
    }
    if (!Object.keys(state.files).length) {
      const seeded = seedState();
      state.files = seeded.files;
      state.folders = seeded.folders;
      state.activePath = seeded.activePath;
    }
    scheduleSave();
    emit();
  }

  function renamePath(from, to) {
    const src = normalizePath(from);
    const dest = src.endsWith('.afr') || src in state.files ? ensureAfr(to) : normalizePath(to);
    if (src in state.files) {
      if (dest in state.files) throw new Error('Cible déjà utilisée');
      state.files[dest] = state.files[src];
      delete state.files[src];
      if (state.activePath === src) state.activePath = dest;
    } else {
      // rename folder prefix
      const nextFiles = {};
      Object.keys(state.files).forEach((f) => {
        if (f === src || f.startsWith(src + '/')) {
          nextFiles[dest + f.slice(src.length)] = state.files[f];
        } else {
          nextFiles[f] = state.files[f];
        }
      });
      state.files = nextFiles;
      state.folders = state.folders.map((f) => {
        if (f === src || f.startsWith(src + '/')) return dest + f.slice(src.length);
        return f;
      });
      if (state.activePath && (state.activePath === src || state.activePath.startsWith(src + '/'))) {
        state.activePath = dest + state.activePath.slice(src.length);
      }
    }
    scheduleSave();
    emit();
  }

  function copyExampleIntoProject(slug, source, preferredName) {
    const base = preferredName || `${slug || 'example'}.afr`;
    let path = ensureAfr(`Mes projets/${base}`);
    let n = 2;
    while (path in state.files) {
      path = ensureAfr(`Mes projets/${(slug || 'example')}_${n}.afr`);
      n += 1;
    }
    state.files[path] = source || 'say "Hello"\n';
    if (!state.folders.includes('Mes projets')) state.folders.push('Mes projets');
    state.activePath = path;
    scheduleSave();
    emit();
    return path;
  }

  function buildRunPayload() {
    // Flush active editor content before run (caller should sync first).
    const files = { ...state.files };
    const entry = state.activePath;
    if (!entry || !(entry in files)) {
      throw new Error('Aucun fichier actif');
    }
    return { entry, files };
  }

  function onChange(fn) {
    state.listeners.push(fn);
    return () => {
      state.listeners = state.listeners.filter((x) => x !== fn);
    };
  }

  /** Build a simple nested tree for UI rendering. */
  function treeNodes() {
    const folders = allFolderPaths();
    const files = Object.keys(state.files).sort();
    const root = { name: '', children: {}, files: [] };

    function ensureNode(parts) {
      let node = root;
      parts.forEach((part) => {
        if (!node.children[part]) {
          node.children[part] = { name: part, children: {}, files: [] };
        }
        node = node.children[part];
      });
      return node;
    }

    folders.forEach((f) => ensureNode(f.split('/')));
    files.forEach((f) => {
      const parts = f.split('/');
      const name = parts.pop();
      const node = ensureNode(parts);
      node.files.push({ name, path: f });
    });
    return root;
  }

  window.AfrWorkspace = {
    load,
    persist,
    snapshot,
    getActiveSource,
    setActiveSource,
    openFile,
    createFolder,
    createFile,
    deletePath,
    renamePath,
    copyExampleIntoProject,
    buildRunPayload,
    onChange,
    treeNodes,
    get activePath() {
      return state.activePath;
    },
    DEFAULT_FILE,
  };
})();
