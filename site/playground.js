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

document.getElementById('run').addEventListener('click', async () => {
  status.textContent = 'Compiling...';
  output.textContent = '';
  try {
    const res = await fetch('/api/run', {
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
});

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
