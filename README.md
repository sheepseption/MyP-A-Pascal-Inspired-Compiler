######### Projet de compilation #########
Le projet consiste en la réalisation d'un compilateur pour un language "MyP" inspiré du Pascal.


######## Utilisation #########
Pour produire un exécutable : 
    make

Pour produire un fichier compilé : 
    ./run ex*.*

Pour afficher le fichier compilé sur le terminal : 
    ./myp < tst/ex*.*


######### Fonctionalité du projet #########
I) Gestion des expressions arithmétiques simples avec constantes :
Dans cette phase, les expressions arithmétiques simples impliquant des constantes sont gérées. Les constantes sont analysées en fonction de leur type (int ou float),  Les conversions sont réalisées pour assurer la cohérence des expressions mixtes (addition d'un entier avec un flottant). Les instructions nécessaires pour les conversions, telles que I2F1 et I2F2, sont générées automatiquement.

II) Gestion des types : 
La gestion des types introduit la conversion automatique entre int et float lors des évaluations d'expressions mixtes. La règle de conversion est conforme au principe de promotion des types (int vers float) pour éviter les pertes de précision. Les instructions comme I2F1 (conversion d'entier en flottant sous sommet de pile) et I2F2 (conversion en sommet de pile) sont insérées dans le code généré lorsque nécessaire.

III) Gestion des variables globales : 
Les variables globales sont déclarées et sont initialisées par défaut à 0 au début. Cette phase gère également l'allocation de ces variables dans la mémoire avec des offsets appropriés, en utilisant une table des symboles pour suivre les informations comme (nom, type, offset). Lors des affectations, une vérification est effectuée pour s'assurer que le type de la valeur assignée correspond au type de la variable. 

IV) Gestion des branchements :  Effectuée avec une évaluation paresseuse.
Dans cette partie, les règles concernant les booléens ont été manipulées: pour chaque opérateurs
on affiche la fonction Pcode correspondante (NOT -> afficher NOT, exp SUP exp -> afficher GTI si les exps sont des entiers sinon GTF ...). Afin de réaliser une évaluation paresseuse, on met à jour les deux règles suivantes:
- AND: au lieu d'afficher que AND, on a déclaré une variable globale label_and incrémentée à chaque fois qu'on rencontre le AND (cela permet de traiter le cas où les conditions sont imbriquées), puis on affiche: 
    IFN(LF_AND_FALSE_(label_and)) 
    AND
    LF_AND_FALSE_(label_and):

ainsi si le premier exp est faux on saute le deuxième et si on a (x AND y) OR (y AND z) on saura vers quel LF_AND_FALSE sauter des deux.

- OR: Par la même logique on définie la variable globale label_or, et on affiche:
    IFT(LV_OR_TRUE_(label_or))
    OR
    LV_OR_TRUE_(label_or):

Pour if-else:
    La valeur du int label déclaré global est remontée et incrémentée via le non-terminal if.
    
Pour while:
    La valeur du int loop déclaré global est remontée et incrémentée via le non-terminal while.

Dans ces deux cas, l'affichage tient en compte l'ordre de parcours des non-terminaux.

V) Gestion des sous-blocs : 
Dans une première étape on manipule, la partie "Déclaration des variables" car c'est "var" qui annonce le début d'un block.
- On a défini une variable globale "depth" incrémentée dans la règle du non-terminal var et initialisée à -1 afin de différencier le block initial des les sous block, ainsi on n'affiche SAVEBP que si depth!=-1 ie qu'on rencontre VAR pour la première fois.

- Dans la règle de var, on met l'offset à 1 car quand on entre dans un sous block, on réserve oldBP à l'offset 0.

Dans une deuxième étape, on rencontre block_end, on décrémente le depth, et on appelle unstack avec le paramètre offset-1 qui est le nombre des variables déclarées dans le sous block. cette fonction unstack(qui applique une fonction remove_symbol définie dans le même fichier sur tout symbole ajouté dans le sous block) est définie dans "table_des_symboles" et elle dépile de cette dernière toute variable déclarée au sous block.


VI) Gestion des fonctions :
Dans cette partie, on use de la récursion à droite pour le stockage des arguments. 
Quand on rencontre un fun_head, on stocke la fonction dans la table des symboles avec comme type son type de retour. Ce dernier est utile pour la récursivité ou pour l'appel de la fonction dans opération arithmétique
Pour l'appel des fonctions, on définie la variable globale "arguments" qui sera incrémenté à chaque traitement d'un argument, et qui sera réinitialisée à 0 quand on finit l'appel. Elle permet de garder le nombre des arguments afin de stocker la valeur de retour dans l'emplacement du premier argument.
Cependant, cette solution n'est pas valable si on a un argument comme appel à une autre fonction: Sisyphus(inf,mountain,Rock(10, round)).
La vérification de la cohérence des types d'arguments de la fonction n'a pas été implémentée.
