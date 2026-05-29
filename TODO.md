# Rapport de Projet : Analyse Sémantique et Génération de Code — Langage Atlas

---

## 1. Vue d'ensemble

Ce projet porte sur la **compilation d'un langage source appelé Atlas** vers un langage cible appelé **MAP** (Machine À Pile). Il couvre l'ensemble de la chaîne de compilation : analyse lexicale, analyse syntaxique avec grammaire attribuée, analyse sémantique, génération de code objet, et simulation de la machine cible.

---

## 2. Langage Source : Atlas

### 2.1 Structure générale d'un programme Atlas

Un programme Atlas se compose de deux parties :

- **Partie déclarative** : déclaration des constantes (`const`) et/ou des variables (`var`), dans cet ordre.
- **Partie opératoire** : les instructions du programme, contenues dans un bloc unique (`debut ... fin.`).

Les commentaires sont introduits par `//` (commentaire de fin de ligne).

**Exemple de structure :**
```
programme <nom> ;
const
    ent <id> = <valeur> ;
    bool <id> = <valeur> ;
var
    ent <id1>, <id2>, ... ;
debut
    <instructions>
fin.
```

### 2.2 Types de données

Il n'existe que **deux types simples** :
- `ent` : entiers
- `bool` : booléens (1 = vrai, 0 = faux)

Pas de tableaux, ni structures, ni pointeurs, ni fonctions.

### 2.3 Opérateurs

| Catégorie | Opérateurs |
|---|---|
| Arithmétiques | `+`, `-` (unaire et binaire), `*`, `/`, `%`, `puiss`, `valabs` |
| Logiques | `et`, `ou`, `non` |
| Comparaison | `>`, `>=`, `=`, `<=`, `<>` (différent) — non-associatifs |
| Affectation | `:=` |

**Priorités arithmétiques (ordre croissant) :** `+`, `-` (binaire) → `*`, `/`, `%` → `-` (unaire)

> Le second opérande de `/` et `%` doit être non nul. `puiss(0, 0)` est illégal.

### 2.4 Instructions

- **Affectation** : `ID := exp;`
- **Instruction vide** : `passer;` (non traduite)
- **Entrée/Sortie** :
  - `lire ID;` / `lireRC ID;`
  - `ecrire ID;` / `ecrireRC ID;`
  - `imprimer 'text';` / `imprimerRC 'text';`
  - *(RC = sauter une ligne après l'opération)*
- **Test conditionnel** :
  ```
  si (condition)
      alors instruction_1
      [sinon instruction_2]
  fsi
  ```
- **Boucle pour** :
  ```
  pour ID depuis vi jusqua vf [parpas pas] faire
      instruction
  fpour
  ```
  (`vi`, `vf` : expressions numériques ; `pas` : constante entière, par défaut +1)
- **Boucle tant que** :
  ```
  tantque (condition) faire
      instruction
  ftq
  ```

Chaque instruction se termine par un point-virgule `;`.

---

## 3. Règles Sémantiques

### 3.1 Table des symboles (TS)

La table des symboles stocke pour chaque objet (constante ou variable) :

| Champ | Description |
|---|---|
| Nom | Identifiant de l'objet |
| Genre | `const` ou `var` |
| Type | `ent` ou `bool` |
| Adresse | Entier incrémenté à chaque déclaration |
| Valeur | Valeur initiale (0 par défaut pour les variables) |

**Exemple (programme `maximum`) :**

| Nom | Genre | Type | Adresse | Valeur |
|---|---|---|---|---|
| a | Var | Ent | 0 | 0 |
| b | Var | Ent | 1 | 0 |
| max | Var | Ent | 2 | 0 |

### 3.2 Fonctions utilitaires de la TS

- `lookup(TS, ID)` → retourne l'indice de l'objet dans la TS, ou `-1` s'il n'existe pas.
  - Si ≠ -1 : **erreur sémantique** (déclaration multiple).
  - Si = -1 : enregistrer via `put(TS, ID)`.
- `getAdr(TS, ID)` → retourne l'adresse d'un objet.
- `getVal(TS, adr)` → retourne la valeur d'une constante.
- `getGenre(TS, ID)` → retourne le genre d'un identifiant.

### 3.3 Règles importantes

- La valeur initiale d'une variable est **0** par défaut.
- Il est **interdit** d'initialiser une variable lors de sa déclaration.
- Une constante **doit** être initialisée par une expression constante.
- Dans une affectation, l'opérande gauche de `:=` doit être une **lvalue** (identifiant de variable).
- L'expression droite doit être du même type que la lvalue.
- L'argument de `lire` / `lireRC` doit aussi être une lvalue.
- On ne peut pas convertir un booléen en entier.

---

## 4. Langage Cible : MAP (Machine À Pile)

Le code cible est généré vers le langage **MAP**, basé sur une machine à pile d'entiers.

- La pile est nommée `pile[]`, avec le sommet désigné par l'indice `ip`.

### 4.1 Instructions MAP et leur effet en C

| Instruction MAP | Effet en C |
|---|---|
| `ouverture-bloc` | `ip = 0;` |
| `fermeture-bloc` | *(fin du programme)* |
| `reserver-kst N` | Réserve N emplacements pour les constantes, initialisés via `getVal(TS, i)` |
| `reserver-var N` | Réserve N emplacements pour les variables, initialisés à 0 |
| `empiler-val K` | `ip++; pile[ip] = K;` — empile la valeur constante K |
| `empiler-adr A` | `ip++; pile[ip] = A;` — empile l'adresse d'une variable |
| `valeur-pile` | `pile[ip] = pile[pile[ip]];` — charge la valeur de la variable dont l'adresse est au sommet |
| `affect` | `pile[pile[ip-1]] = pile[ip]; ip--;` — affecte le sommet à la variable |
| `lire` / `lireRC` | `pile[pile[ip]] = valeur_clavier;` |
| `ecrire` / `ecrireRC` | `printf("%d\n", pile[ip]); ip--;` |
| `imprimer text` / `imprimerRC text` | `printf("%s\n", text);` |
| `plus` | `pile[ip-1] = pile[ip-1] + pile[ip]; ip--;` |
| `moins` | `pile[ip-1] = pile[ip-1] - pile[ip]; ip--;` |
| `mult` | `pile[ip-1] = pile[ip-1] * pile[ip]; ip--;` |
| `div` | `pile[ip-1] = pile[ip-1] / pile[ip]; ip--;` |
| `mod` | `pile[ip-1] = pile[ip-1] % pile[ip]; ip--;` |
| `puiss` | `pile[ip-1] = pow(pile[ip-1], pile[ip]); ip--;` |
| `valabs` | `pile[ip] = pile[ip] >= 0 ? pile[ip] : -pile[ip];` |
| `neg` | `pile[ip] = -pile[ip];` |
| `egal`/`pps`/`pgs`/`pp-egal`/`pg-egal`/`dif` | Comparaisons : `pile[ip-1] = pile[ip-1] op pile[ip]; ip--;` |
| `ou` / `et` | Logique : `pile[ip-1] = pile[ip-1] op pile[ip]; ip--;` |
| `non` | `pile[ip] = ~pile[ip];` |
| `bsf etiq` | `CO = (pile[ip] == 0) ? etiq : CO+1; ip++;` — branchement si faux |
| `bsv etiq` | `CO = (pile[ip] == 1) ? etiq : CO+1; ip++;` — branchement si vrai |
| `bra etiq` | `CO = etiq;` — branchement inconditionnel |

---

## 5. Exemples de Compilation

### Exemple 1 : Programme `somme` (prog1.atlas → prog1.map)

**Source Atlas :**
```
programme somme;
var
    ent a, b, c;
debut
    lire a;
    lire b;
    c := a + b;
    imprimer 'somme:';
    ecrire c;
fin.
```

**Code MAP généré (prog1.map) :**
```
1   ouverture-bloc
2   reserver-var 3
3   empiler-adr 0
4   lire
5   empiler-adr 1
6   lire
7   empiler-adr 2
8   empiler-adr 0
9   valeur-pile
10  empiler-adr 1
11  valeur-pile
12  plus
13  affect
14  imprimer 'somme:'
15  empiler-adr 2
16  valeur-pile
17  ecrire
18  fermeture-bloc
```

---

### Exemple 2 : Programme `test` avec constante et si/sinon (prog2.atlas → prog2.map)

**Source Atlas :**
```
programme test;
const
    ent max = 100;
var
    ent a, b, c;
debut
    lire a;
    b := a * 2;
    si b >= max
        alors c := max;
        sinon c := b;
    fsi
    ecrire c;
fin.
```

**Code MAP généré (prog2.map) :**
```
1   ouverture-bloc
2   reserver-kst 1
3   reserver-var 3
4   empiler-adr 1
5   lire
6   empiler-adr 2
7   empiler-adr 1
8   valeur-pile
9   empiler-val 2
10  mult
11  affect
12  empiler-adr 2
13  valeur-pile
14  empiler-adr 0
15  valeur-pile
16  pp-egal
17  bsf 22          ← si faux, aller en 22 (branche sinon)
18  empiler-adr 3
19  empiler-adr 0
20  valeur-pile
21  affect
    bra 26          ← saut fin du si
22  empiler-adr 3
23  empiler-val 2
24  valeur-pile
25  affect
26  empiler-adr 3
27  valeur-pile
28  ecrire
29  fermeture-bloc
```

---

### Exemple 3 : Programme `factoriel` avec boucle (prog3.atlas → prog3.map)

**Source Atlas :**
```
programme factoriel;
var
    ent n, f, i;
debut
    lire n;
    si (n < 0)
        alors imprimer 'impossible';
        sinon
            f := 1;
            pour i depuis 2 jusqua n faire
                f := f * i;
            fpour
            ecrire f;
    fsi
fin.
```

**Code MAP généré (prog3.map) :**
```
1   ouverture-bloc
2   reserver-var 3
3   empiler-adr 0
4   lire
5   empiler-adr 0
6   valeur-pile
7   empiler-val 0
8   pps
9   bsf 12
10  imprimer 'impossible'
11  bra 41
12  empiler-adr 1
13  empiler-val 1
14  affect
15  empiler-adr 2
16  empiler-val 2
17  affect
18  empiler-adr 2
19  valeur-pile
20  empiler-adr 0
21  valeur-pile
22  pp-egal
23  bsf 38          ← fin de boucle
24  empiler-adr 1
25  empiler-adr 1
26  valeur-pile
27  empiler-adr 2
28  valeur-pile
29  mult
30  affect
31  empiler-adr 2
32  empiler-adr 2
33  valeur-pile
34  empiler-val 1
35  plus
36  affect
37  bra 18          ← retour début boucle
38  empiler-adr 1
39  valeur-pile
40  ecrire
41  fermeture-bloc
```

---

## 6. Travail à Réaliser

Le projet demande de réaliser **4 composants** :

### 6.1 Simulateur de la Machine à Pile (en C)
- Implémenter en C un simulateur capable d'exécuter le code MAP produit par le compilateur.
- Il doit interpréter toutes les instructions MAP listées ci-dessus.

### 6.2 Compilateur avec Bison (Grammaire Attribuée)
- Écrire une **grammaire attribuée** pour le langage Atlas à l'aide de **Bison**.
- Enrichir la grammaire par les **actions sémantiques** (vérifications de types, gestion de la TS).
- Générer le code objet dans un fichier `.map`.

### 6.3 Analyseur Lexical avec Flex
- Écrire un **analyseur lexical** pour le langage Atlas à l'aide de **Flex**.
- Reconnaître les tokens : mots-clés, identifiants, entiers, opérateurs, etc.

### 6.4 Programme Principal
- Écrire un **programme principal** qui :
  1. Affiche le code objet MAP d'un programme source Atlas.
  2. Exécute ce code MAP via le simulateur.

---

## 7. Résumé de l'Architecture du Projet

```
prog.atlas
    │
    ▼
[Flex : Analyseur Lexical]
    │ tokens
    ▼
[Bison : Analyseur Syntaxique + Sémantique]
    │ actions sémantiques + Table des Symboles
    ▼
[Génération de Code] ──→ prog.map
    │
    ▼
[Simulateur MAP en C]
    │
    ▼
Résultat d'exécution
```

---

*Rapport généré à partir des documents du cours — Analyse Sémantique et Génération de Code, Langage Atlas / MAP.*
