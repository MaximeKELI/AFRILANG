const EXAMPLES = {
  hello: `say "Hello from AFRILANG!"

repeat 3 times
    say "Hello"
end
`,
  natural: `say "Natural English syntax"

if 42 is greater than 40 then
    say "Condition is true"
else
    say "False branch"
end
`,
  cookbook: `# Mini-programme commenté
create score = 85
create grades = list of "A", "B", "C"

if score is greater than or equal to 80 then
    say "Bravo : {score}"
    say grades at 0
else
    say "Continue"
end

for each g in grades do
    say g
end
`,
  oop: `class Greeter
    function hello()
        say "Hello from a class!"
    end
end

create g = new Greeter
g.hello()
`,
  advanced: `enum Status
    case Ok
    case Error with message text
end

create s = Status.Ok
create e = Status.Error with "failed"

match s
    case Ok then
        say "ok"
    end
    default
        say "other"
    end
end

match e
    case Error then
        say e.message
    end
end

create nickname text? = nothing
if nickname is defined then
    say nickname
else
    say "no nickname"
end
`,
  matchAdvanced: `function classify(n number) returns text
    return match n
        case 0 then "zéro"
        end
        case 1 to 10 then "petit"
        end
        case 11 or 12 or 13 then "ado"
        end
        case _ then "grand"
        end
    end
end

say classify(0)
say classify(7)
say classify(12)
say classify(99)
`,
  generics: `function identity<T>(x T) returns T
    return x
end

function first<T>(items list of T) returns T
    return items at 0
end

say identity(42)
say identity("hello")

create nums = list of 10, 20, 30
say first(nums)

create words = list of "a", "b", "c"
say first(words)
`,
  constraints: `function twiceNum<T>(x T) returns T where T is number
    return x + x
end

say twiceNum(21)
`,
  generators: `generator function compteur(n int) returns list int
    create i int = 0
    while i is less than n do
        yield i
        set i = i + 1
    end
end

for each v in compteur(5) do
    say v
end
`,
  ranges: `for each x in 1..5 do
    say x
end

create xs = 1..3
say length of xs
say xs at 0
`,
  optionals: `create empty number? = nothing
say empty or else 0

function half(x number) returns number or error
    if x is less than 0 then
        return error "négatif"
    end
    return x / 2
end

say half(8) or else 0
say half(-1) or else -99
`,
  macros: `macro shout(msg)
    say msg
end

macro assertEq(a, b)
    assert a is equal to b
end

shout!("macros ok")
assertEq!(2 + 2, 4)
`,
  interp: `create name = "AFRILANG"
create version = 1
say "Hello {name}!"
say "Version {version}.0"
`,
  wasm: `say "Phase E WASM OK"

create i int = 0
while i is less than 3 do
    say "hello wasm"
    set i = i + 1
end
`
};

const editor = document.getElementById('editor');
const output = document.getElementById('output');
const status = document.getElementById('status');
const examples = document.getElementById('examples');

function loadExample(name) {
  editor.value = EXAMPLES[name] || EXAMPLES.hello;
  output.textContent = '(click Run)';
  status.textContent = '';
}

examples.addEventListener('change', () => loadExample(examples.value));
loadExample('hello');

document.getElementById('run').addEventListener('click', () => runCode('/api/run', 'Compiling...'));
document.getElementById('runInstant').addEventListener('click', async () => {
  status.textContent = 'Compiling (client)...';
  output.textContent = '';
  output.classList.remove('error');
  try {
    const result = await window.AfrilangCompilerClient.runInstant(editor.value);
    output.textContent = result.output || '(no output)';
    status.textContent = result.clientSide ? 'OK (WASM client)' : 'OK (server JS)';
  } catch (e) {
    status.textContent = 'Error';
    output.textContent = String(e.message || e);
    output.classList.add('error');
  }
});
document.getElementById('runWasm').addEventListener('click', () => runCode('/api/run/wasm', 'Compiling WASM (server)...'));

document.getElementById('runWasmBrowser').addEventListener('click', async () => {
  status.textContent = 'Building WASM for browser...';
  output.textContent = '';
  output.classList.remove('error');
  try {
    const res = await fetch('/api/build/wasm', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ source: editor.value })
    });
    const data = await res.json();
    if (!data.ok || !data.id) {
      output.textContent = data.output || 'Build failed';
      status.textContent = 'Error';
      output.classList.add('error');
      return;
    }
    status.textContent = 'Running in browser...';
    await window.runWasmInBrowser(data.id, output, status);
    status.textContent = 'OK (browser WASM)';
  } catch (e) {
    status.textContent = 'Error';
    output.textContent = String(e);
    output.classList.add('error');
  }
});

async function runCode(endpoint, busyLabel) {
  status.textContent = busyLabel;
  output.textContent = '';
  try {
    const res = await fetch(endpoint, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ source: editor.value })
    });
    const data = await res.json();
    output.textContent = data.output || '(no output)';
    status.textContent = data.ok ? 'OK' : 'Error (code ' + data.exitCode + ')';
    output.classList.toggle('error', !data.ok);
  } catch (e) {
    status.textContent = 'Network error';
    output.textContent = String(e);
    output.classList.add('error');
  }
}

document.getElementById('fmt').addEventListener('click', async () => {
  status.textContent = 'Formatting...';
  try {
    const res = await fetch('/api/fmt', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ source: editor.value })
    });
    const data = await res.json();
    if (data.ok && data.source) {
      editor.value = data.source;
      status.textContent = 'Formatted';
      output.classList.remove('error');
    } else {
      output.textContent = data.output || 'Format failed';
      status.textContent = 'Format error';
      output.classList.add('error');
    }
  } catch (e) {
    status.textContent = 'Network error';
    output.textContent = String(e);
  }
});

editor.addEventListener('keydown', (e) => {
  if ((e.ctrlKey || e.metaKey) && e.key === 'Enter') {
    e.preventDefault();
    document.getElementById('run').click();
  }
});
