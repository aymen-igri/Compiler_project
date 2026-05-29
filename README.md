# Welcome to the Atlas Compiler Project!

This project is a complete compiler for the **Atlas Language**, translating source code into intermediate **MAP** (Machine À Pile) code and executing it via a custom C-based virtual machine simulator.

---

## 1. Prerequisites

Ensure you have the following tools installed on your Linux system:
- `gcc` (C Compiler)
- `flex` (Lexical Analyzer Generator)
- `bison` (Parser Generator)
- `make` (Build Automation)

---

## 2. Getting Started

The easiest way to interact with the project is using the provided `Makefile`.

### Build the Compiler
To generate the `atlas` compiler executable, run:
```bash
make
```

### Clean Temporary Files
To remove all generated files and start fresh:
```bash
make clean
```

---

## 3. Compiling and Running Atlas Code

You can test any `.atlas` file using these simple commands. Replace `filename.atlas` with your actual file path.

### Option A: Standard Run (Recommended)
This compiles your Atlas code and runs it immediately. This is the most common command you will use:
```bash
make run FILE=TestProgram/factoriel.atlas
```

### Option B: Debug / Test Mode
This shows you the **Intermediate MAP Code** (machine instructions) first, and then runs the program. Great for seeing how the compiler works:
```bash
make test FILE=TestProgram/somme.atlas
```

### Option C: Only show MAP Code
If you only want to see the generated instructions without executing them:
```bash
make map FILE=TestProgram/test1.atlas
```

### Option D: Manual Compilation
If you want to compile now but run later:
```bash
make compile FILE=TestProgram/somme.atlas
# Then later run:
./result
```

---

## 4. Atlas Language Syntax Features

The Atlas compiler supports:
- **Variables & Constants**: Declare `ent` (integers) and `bool` (booleans).
- **Arithmetic**: Full support for `+`, `-`, `*`, `/`, `%`, `puiss`, and `valabs()`.
- **Logic**: Boolean operations using `et`, `ou`, and `non`.
- **Control Flow**:
    - `si ... alors ... [sinon] ... fsi` (Conditions)
    - `tantque ... faire ... ftq` (While loops)
    - `pour ... depuis ... jusqua ... [parpas ...] faire ... fpour` (For loops)
- **Flexible Syntax**: Parentheses for conditions and the trailing dot after `fin` are **optional**.

---

## 5. Directory Structure

- `atlas.l`: Flex lexical analyzer.
- `atlas.y`: Bison parser and code generator.
- `simulator.c`: The virtual machine that runs the compiled code.
- `Makefile`: Automation scripts for building and testing.
- `TestProgram/`: A collection of sample Atlas programs (somme, factoriel, etc.).

---

**Enjoy coding with Atlas!** 
