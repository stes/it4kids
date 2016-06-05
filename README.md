# IT4Kids Code Editor und Kurshandbuch

[![master](https://travis-ci.org/stes/it4kids.svg?branch=master)](https://travis-ci.org/stes/it4kids)

Du hast gerade das Repo von **IT4Kids** gefunden!

## Die Idee hinter IT4Kids

Informatik hat in unserer Gesellschaft einen hohen Stellenwert. Sie umgibt uns ständig im Alltag - und bestimmt diesen in vielen Bereichen mit. Dennoch wird an vielen Schulen Informatik erst zu einem sehr späten Zeitpunkt als Fach angeboten. Ziel des Projekts IT4Kids ist es, an möglichst vielen Schulen Arbeitsgruppen einzurichten, in denen die Grundlagen der Informatik und des Programmierens auf ansprechende Weise schon jungen Schülerinnen und Schülern vermittelt werden.

Wir bringen dazu Studierende, interessierte Lehrkräfte und Eltern mit Schulen zusammen, um dort Arbeitsgruppen einzurichten. Die Organisation, das Erstellen von Materialien und die Weiterentwicklung der im Kurs behandelten Themen werden von uns übernommen. Für die Kursbetreuung zahlen wir eine Aufwandsentschädigung.

## Der IT4Kids Code Editor

Aktuell verwenden wir [Scratch](https://scratch.mit.edu) und [Snap](code.it-for-kids.org) in unseren Kursen. Der IT4Kids Code Editor setzt optisch auf diesen beiden Programmen auf, bietet aber einige Zusatzfunktionen, die im Kursbetrieb nützlich sind:

- Virtuelle Klassenräume mit Lehrer- und Schüleraccounts
- Konvertieren der Projekte in direkt ausführbare Python Skripte
- Schnelles Ausführen von Projekten durch [Pyglet](https://bitbucket.org/pyglet/pyglet/wiki/Home) Backend (nutzt OpenGL)
- Nahtloser Übergang von der der grafischen Programmierung zur direkten Python-Programmierung - alles in einem Editor!

### Abhängigkeiten

Bevor das Programm erstellt werden kann, müssen folgende Abhängigkeiten erfüllt sein:

- python>=3.3
- pyglet
- Qt>=5.4

Für den Buildprozess muss zusätzlich **qmake** installiert sein.

### Erstellen

Das Programm kann per

```
qmake
make
```

erstellt und per 

```
cd bin
./it4kids-editor
```

ausgeführt werden.

### Aktueller Stand

Aktuell befindet sich der Editor in aktiver Entwicklung. Eine erste Alpha Version wird voraussichtlich im Januar 2016 erscheinen.

|    Build Status der einzelnen Zweige                                                                                ||
|-------|--------------------------------------------------------------------------------------------------------------|
|master | [![master](https://travis-ci.org/stes/it4kids.svg?branch=master)](https://travis-ci.org/stes/it4kids)        |
|pyglet | [![dev-pyglet](https://travis-ci.org/stes/it4kids.svg?branch=dev-pyglet)](https://travis-ci.org/stes/it4kids)|
|GUI    | [![GUI](https://travis-ci.org/stes/it4kids.svg?branch=GUI)](https://travis-ci.org/stes/it4kids)       |
|devKM  | [![devKM](https://travis-ci.org/stes/it4kids.svg?branch=devKM)](https://travis-ci.org/stes/it4kids)       |

## Das IT4Kids Lehrkonzept

Unser Lehrkonzept ist unser der Creative Commons Lizenz verfügbar und findet sich hier im Repository im Ordner
```
docs
```

Das Material wird [auf unserer Homepage](www.it-for-kids.org/projects) gesammelt. Auf dieser Grundlage wird in regelmäßigen Abständen der Inhalt im Repo aktualisiert. Wir arbeiten an einer Synchronisation zwischen dem Inhalt auf unserer Homepage, unserem Repository und dem [deutschsprachigen Scratch-Wiki](http://scratch-dach.info/wiki/Kategorie:IT4Kids_Projektsammlung).

## Kontakt

*IT4Kids* wurde von Studenten der RWTH Aachen gegründet. Weitere Infos unter www.it-for-kids.org.
Bei Fragen oder Interesse, unsere Arbeit zu unterstützen, melde dich bei info@it-for-kids.org

Wir suchen stetig nach neuen Interessent/innen, für die Bereiche Softwareentwicklung, Entwicklung des Lehrkonzepts und für die Kursbetreuung. Falls du Interesse hast, melde dich gerne über unser [Kontaktformular](http://www.it-for-kids.org/contact).
