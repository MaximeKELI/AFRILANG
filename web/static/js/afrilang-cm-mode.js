(function (mod) {
  if (typeof CodeMirror === 'undefined') return;

  CodeMirror.defineMode('afrilang', function () {
    var keywords = new RegExp(
      '\\b(?:say|ask|create|set|if|then|else|end|while|do|repeat|times|for|each|in|with|' +
      'function|returns|return|class|extends|new|module|import|use|export|private|public|' +
      'enum|union|match|case|default|async|await|try|catch|throw|const|operator|abstract|' +
      'final|static|protected|property|destroy|super|interface|trait|record|nothing|defined|' +
      'dire|demander|creer|si|sinon|fin|tant|que|repeter|fois|pour|dans|avec|fonction|retourne|' +
      'classe|etend|nouveau|module|importer|utiliser|exporter|prive|publique|enumeration|' +
      'correspondance|cas|defaut|essayer|attraper|lancer|operateur|abstrait|statique)\\b',
      'i'
    );
    var types = /\b(?:number|text|bool|int|void|list|map|error|Result)\b/i;
    var builtins = /\b(?:is greater than|is less than|is equal to|at|to|of|or error)\b/i;

    return {
      token: function (stream) {
        if (stream.match(/^"([^"\\]|\\.)*"/)) return 'string';
        if (stream.match(/^'([^'\\]|\\.)*'/)) return 'string';
        if (stream.match(/^\/\/.*/)) return 'comment';
        if (stream.match(/^#.*/)) return 'comment';
        if (stream.match(/^\d+(\.\d+)?/)) return 'number';
        if (stream.match(keywords)) return 'keyword';
        if (stream.match(types)) return 'type';
        if (stream.match(builtins)) return 'builtin';
        if (stream.match(/^[a-zA-Z_]\w*/)) return 'variable';
        stream.next();
        return null;
      },
    };
  });

  CodeMirror.defineMIME('text/x-afrilang', 'afrilang');
})(typeof module !== 'undefined' && module.exports ? module : {});
