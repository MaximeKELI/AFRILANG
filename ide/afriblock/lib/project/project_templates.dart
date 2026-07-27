/// Built-in AFRILANG project scaffolds for AFRIBLOCK New Project.
class ProjectTemplate {
  const ProjectTemplate({
    required this.id,
    required this.label,
    required this.description,
    required this.mainSource,
    this.tomlExtra = '',
  });

  final String id;
  final String label;
  final String description;
  final String mainSource;
  final String tomlExtra;
}

const kProjectTemplates = <ProjectTemplate>[
  ProjectTemplate(
    id: 'app',
    label: 'Application (Hello)',
    description: 'Petit programme console avec say',
    mainSource: '''
// {{name}} — entrée principale
say "Hello from {{name}}"
''',
  ),
  ProjectTemplate(
    id: 'lib',
    label: 'Library',
    description: 'Module réutilisable avec une fonction exportée',
    mainSource: '''
// {{name}} — bibliothèque
function greet(name: text) returns text
    return "Hello, " + name
end

say greet("AFRILANG")
''',
  ),
  ProjectTemplate(
    id: 'cli',
    label: 'CLI tool',
    description: 'Outil en ligne de commande avec arguments',
    mainSource: '''
// {{name}} — CLI
create args as list
say "Usage: pass args via runtime — demo:"
say "ready"
''',
  ),
  ProjectTemplate(
    id: 'test',
    label: 'With tests',
    description: 'main + tests/smoke.afr',
    mainSource: '''
function add(a: number, b: number) returns number
    return a + b
end

say add(2, 3)
''',
    tomlExtra: '\n[[test]]\npath = "tests/smoke.afr"\n',
  ),
  ProjectTemplate(
    id: 'gui',
    label: 'GUI window',
    description: 'Fenêtre minimale (std/ui)',
    mainSource: '''
import "std/ui"
use ui

open window titled "{{name}}"
say "Window opened — close to exit"
while window is open do
end
''',
  ),
];

ProjectTemplate projectTemplateById(String id) =>
    kProjectTemplates.firstWhere((t) => t.id == id, orElse: () => kProjectTemplates.first);

String expandProjectTemplate(String body, String name) =>
    body.replaceAll('{{name}}', name);
