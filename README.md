# Welcome to the Atlas Compiler Project!

This project is a complete compiler for the **Atlas Language**, translating source code into intermediate **MAP** (Machine À Pile / Stack Machine) code and executing it via an integrated virtual machine simulator.

---

## 1. Prerequisites

Ensure you have the following tools installed on your Linux system:
- `gcc` (C Compiler)
- `flex` (Lexical Analyzer Generator)
- `bison` (Parser Generator)
- `make` (Build Automation)

---

## 2. Directory Structure

The project follows a clean, modular architecture:

```text
Compiler_project/
├── bin/                    # Compiled executable (atlas)
│   └── atlas
├── examples/               # Sample Atlas source programs
│   ├── factoriel.atlas     # Factorial calculation example
│   ├── somme.atlas         # Simple addition example
│   └── test2.atlas         # Comprehensive test of all features
├── includes/               # Shared header files
│   └── atlas.h             # Compiler/Simulator shared definitions
├── src/                    # Compiler source code
│   ├── atlas.l             # Flex: Lexical analyzer
│   ├── atlas.y             # Bison: Syntax & Semantic analyzer
│   ├── main.c              # Integrated CLI & Execution engine
│   └── simulator.c         # Machine À Pile (MAP) VM logic
├── Makefile                # Build orchestration script
├── README.md               # This documentation
└── SPEC.md                 # Language & VM specifications
```

- **src/**: Contains the core implementation of the compiler and virtual machine.
- **includes/**: Shared data structures (like the symbol table and instruction set).
- **bin/**: Where the final `atlas` tool is generated after running `make`.
- **examples/**: Pre-written programs to demonstrate the language capabilities.

---

## 3. Getting Started

The project uses an integrated **"All-in-One"** binary. When you compile an Atlas file, it generates the `.map` instructions AND immediately executes them.

### Build the Project
To compile the `bin/atlas` tool, run:
```bash
make
```

### Clean Workspace
To remove all generated binaries, temporary build files, and `.map` files:
```bash
make clean
```

---

## 4. Compiling and Running Atlas Code

### Integrated Compilation & Execution
This is the standard way to run an Atlas program. It will compile to MAP, save the `.map` file, and then execute it:
```bash
./bin/atlas examples/factoriel.atlas
```
*Alternatively, you can use the Makefile shortcut:*
```bash
make run FILE=examples/factoriel.atlas
```

### View Intermediate MAP Code
If you want to see the generated machine instructions without executing the program:
```bash
make map FILE=examples/factoriel.atlas
```

### Input Prompt
When a program requires input (e.g., `lire n;`), it will display a blue prompt:
`[INPUT] > `
Simply type your integer and press **Enter**.

---

## 5. Atlas Language Features

- **Variables & Constants**: Support for `ent` (integers) and `bool` (booleans).
- **Arithmetic**: Full support for `+`, `-`, `*`, `/`, `%`, `puiss`, and `valabs()`.
- **Logic**: Boolean operations using `et`, `ou`, and `non`.
- **Control Flow**:
    - `si ... alors ... [sinon] ... fsi` (Supports nested conditionals).
    - `tantque ... faire ... ftq` (While loops).
    - `pour ... depuis ... jusqua ... [parpas ...] faire ... fpour` (For loops with optional steps).
- **Semantic Safety**: Includes type checking, constant protection, and duplicate declaration detection.

---

## 6. Technical Specifications

For developers interested in the internal logic, semantic rules, and the target VM instruction set, please refer to the [SPEC.md](SPEC.md) file. It contains:
- **Language Grammar**: Detailed rules for Atlas syntax.
- **Semantic Rules**: Type checking, constant management, and symbol table logic.
- **MAP Instruction Set**: A complete reference for all Stack Machine instructions and their C implementation details.

---

**Enjoy coding with Atlas!**
