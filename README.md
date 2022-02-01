# AlgoCompiler
AlgoCompiler est compilateur du langage algorithmique en français qui contient un analyseur lexical, syntaxique et sementique.\
\
Afin d'obtenir meilleure resultats nous avons utiliser [FLEX](https://www.cs.princeton.edu/~appel/modern/c/software/flex/flex.html) generateur d'analyseur lexical et aussi [BISON](https://www.gnu.org/software/bison/) pour generer l'analyseur syntaxique et ce qui cencerne l'analyseur semantique est programmer a la main
\
\
Réalisé par
* Sofyan MZIZI
* Youssef MEZIANI
* Mohamed BOUMAAZA
* Chaimae ELHAIBA
* Majda KHALIFA


## Installation

Utiliser le Makefile fichier afin de compiler le projet.

```bash
user@laptop:~AlgoCompiler$ make
```

## Usage
Pour tester notre compilateur exécuter la commande ci-dessous, il existe deja un fichier "test.algo" 
```bash
./algoCompiler <pathFile>.algo
```

## Tests
test 1: sans erreurs
```bash
user@laptop:~$ ./algoCompiler test1.algo
Ouverture reussie.

lexic: true
parser: true
user@laptop:~$ 
```

test 2: erreur syntaxique
```bash
user@laptop:~$ ./algoCompiler test2.algo
Ouverture reussie.

line 13, column 11: syntax error
user@laptop:~$
```

test 3: erreur lexical
```bash
user@laptop:~$ ./algoCompiler test3.algo
Ouverture reussie.

line 21, column 5: lexical error <%>
line 21, column 6: syntax error
user@laptop:~$
```