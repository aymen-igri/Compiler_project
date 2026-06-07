# Project Report: Semantic Analysis and Code Generation — Atlas Language

---

## 1. Overview

This project focuses on **compiling a source language called Atlas** into a target language called **MAP** (Machine À Pile / Stack Machine). It covers the entire compilation chain: lexical analysis, syntax analysis with attributed grammar, semantic analysis, object code generation, and simulation of the target machine.

---

## 2. Source Language: Atlas

### 2.1 General Structure of an Atlas Program

An Atlas program consists of two parts:

- **Declarative part**: Declaration of constants (`const`) and/or variables (`var`), in that order.
- **Operative part**: Program instructions, contained in a single block (`debut ... fin.`).

Comments are introduced by `//` (end-of-line comment).

**Structure Example:**
```
programme <name> ;
const
    ent <id> = <value> ;
    bool <id> = <value> ;
var
    ent <id1>, <id2>, ... ;
debut
    <instructions>
fin.
```

### 2.2 Data Types

There are only **two simple types**:
- `ent`: Integers
- `bool`: Booleans (1 = true, 0 = false)

No arrays, structures, pointers, or functions.

### 2.3 Operators

| Category | Operators |
|---|---|
| Arithmetic | `+`, `-` (unary and binary), `*`, `/`, `%`, `puiss`, `valabs` |
| Logical | `et`, `ou`, `non` |
| Comparison | `>`, `>=`, `=`, `<=`, `<>` (different) — non-associative |
| Assignment | `:=` |

**Arithmetic priorities (ascending order):** `+`, `-` (binary) → `*`, `/`, `%` → `-` (unary)

> The second operand of `/` and `%` must be non-zero. `puiss(0, 0)` is illegal.

### 2.4 Instructions

- **Assignment**: `ID := exp;`
- **Empty instruction**: `passer;` (not translated)
- **Input/Output**:
  - `lire ID;` / `lireRC ID;`
  - `ecrire ID;` / `ecrireRC ID;`
  - `imprimer 'text';` / `imprimerRC 'text';`
  - *(RC = line break after the operation)*
- **Conditional test**:
  ```
  si (condition)
      alors instruction_1
      [sinon instruction_2]
  fsi
  ```
- **For loop**:
  ```
  pour ID depuis vi jusqua vf [parpas pas] faire
      instruction
  fpour
  ```
  (`vi`, `vf`: numeric expressions; `pas`: integer constant, default +1)
- **While loop**:
  ```
  tantque (condition) faire
      instruction
  ftq
  ```

Each instruction ends with a semicolon `;`.

---

## 3. Semantic Rules

### 3.1 Symbol Table (ST)

The symbol table stores for each object (constant or variable):

| Field | Description |
|---|---|
| Name | Object identifier |
| Category | `const` or `var` |
| Type | `ent` or `bool` |
| Address | Integer incremented at each declaration |
| Value | Initial value (default 0 for variables) |

**Example (`maximum` program):**

| Name | Category | Type | Address | Value |
|---|---|---|---|---|
| a | Var | Ent | 0 | 0 |
| b | Var | Ent | 1 | 0 |
| max | Var | Ent | 2 | 0 |

### 3.2 Symbol Table Utility Functions

- `lookup(ST, ID)` → returns the index of the object in the ST, or `-1` if it doesn't exist.
  - If ≠ -1: **semantic error** (multiple declaration).
  - If = -1: register via `put(ST, ID)`.
- `getAdr(ST, ID)` → returns the address of an object.
- `getVal(ST, adr)` → returns the value of a constant.
- `getGenre(ST, ID)` → returns the category of an identifier.

### 3.3 Important Rules

- The initial value of a variable is **0** by default.
- It is **forbidden** to initialize a variable during its declaration.
- A constant **must** be initialized by a constant expression.
- In an assignment, the left operand of `:=` must be an **lvalue** (variable identifier).
- The right expression must be of the same type as the lvalue.
- The argument of `lire` / `lireRC` must also be an lvalue.
- You cannot convert a boolean to an integer.

---

## 4. Target Language: MAP (Machine À Pile / Stack Machine)

The target code is generated in the **MAP** language, based on an integer stack machine.

- The stack is named `pile[]`, with the top designated by the index `ip`.

### 4.1 MAP Instructions and their effect in C

| MAP Instruction | Effect in C |
|---|---|
| `ouverture-bloc` | `ip = 0;` |
| `fermeture-bloc` | *(end of program)* |
| `reserver-kst N` | Reserve N slots for constants, initialized via `getVal(ST, i)` |
| `reserver-var N` | Reserve N slots for variables, initialized to 0 |
| `empiler-val K` | `ip++; pile[ip] = K;` — push constant value K |
| `empiler-adr A` | `ip++; pile[ip] = A;` — push variable address |
| `valeur-pile` | `pile[ip] = pile[pile[ip]];` — load the value of the variable whose address is at the top |
| `affect` | `pile[pile[ip-1]] = pile[ip]; ip--;` — assign the top to the variable |
| `lire` / `lireRC` | `pile[pile[ip]] = keyboard_value;` |
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
| `egal`/`pps`/`pgs`/`pp-egal`/`pg-egal`/`dif` | Comparisons: `pile[ip-1] = pile[ip-1] op pile[ip]; ip--;` |
| `ou` / `et` | Logic: `pile[ip-1] = pile[ip-1] op pile[ip]; ip--;` |
| `non` | `pile[ip] = ~pile[ip];` |
| `bsf etiq` | `CO = (pile[ip] == 0) ? etiq : CO+1; ip++;` — branch if false |
| `bsv etiq` | `CO = (pile[ip] == 1) ? etiq : CO+1; ip++;` — branch if true |
| `bra etiq` | `CO = etiq;` — unconditional branch |

---

## 5. Compilation Examples

### Example 1: `somme` program (prog1.atlas → prog1.map)

**Atlas Source:**
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

**Generated MAP Code (prog1.map):**
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

### Example 2: `test` program with constant and if/else (prog2.atlas → prog2.map)

**Atlas Source:**
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

**Generated MAP Code (prog2.map):**
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
17  bsf 22          ← if false, go to 22 (else branch)
18  empiler-adr 3
19  empiler-adr 0
20  valeur-pile
21  affect
    bra 26          ← jump to end of if
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

### Example 3: `factoriel` program with loop (prog3.atlas → prog3.map)

**Atlas Source:**
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

**Generated MAP Code (prog3.map):**
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
23  bsf 38          ← end of loop
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
37  bra 18          ← back to loop start
38  empiler-adr 1
39  valeur-pile
40  ecrire
41  fermeture-bloc
```

---

## 6. Work to Realize

The project requires the creation of **4 components**:

### 6.1 Stack Machine Simulator (in C)
- Implement a simulator in C capable of executing the MAP code produced by the compiler.
- It must interpret all the MAP instructions listed above.

### 6.2 Compiler with Bison (Attributed Grammar)
- Write an **attributed grammar** for the Atlas language using **Bison**.
- Enrich the grammar with **semantic actions** (type checks, ST management).
- Generate object code in a `.map` file.

### 6.3 Lexical Analyzer with Flex
- Write a **lexical analyzer** for the Atlas language using **Flex**.
- Recognize tokens: keywords, identifiers, integers, operators, etc.

### 6.4 Main Program
- Write a **main program** that:
  1. Displays the MAP object code of an Atlas source program.
  2. Executes this MAP code via the simulator.

---

## 7. Project Architecture Summary

```
prog.atlas
    │
    ▼
[Flex: Lexical Analyzer]
    │ tokens
    ▼
[Bison: Syntax + Semantic Analyzer]
    │ semantic actions + Symbol Table
    ▼
[Code Generation] ──→ prog.map
    │
    ▼
[MAP Simulator in C]
    │
    ▼
Execution Result
```

---

*Report generated from course documents — Semantic Analysis and Code Generation, Atlas / MAP Language.*
