# MyP: A Pascal-Inspired Compiler

A teaching compiler for **MyP**, a Pascal-inspired language.  
It generates P-Code and implements type handling, global variables, lazy boolean evaluation, nested blocks, and basic functions.

---

##  Usage

Build everything:
```bash
make
```

Compile a source file to P-Code (output alongside the source):
```bash
./run ex*.*
```

Display a compiled file in the terminal:
```bash
./myp < tst/ex*.*
```

> Adjust the `ex*.*` / `tst/ex*.*` patterns to your actual filenames.

---

## Features

### I) Simple arithmetic expressions with constants
- Parses integer and floating-point constants.
- Performs implicit numeric promotions in mixed expressions (e.g., `int + float`).
- Emits conversion instructions when needed:
  - `I2F1` (convert integer under the stack top)
  - `I2F2` (convert integer at the stack top)

### II) Type handling
- Automatic promotion **int → float** in mixed expressions to preserve precision.
- Inserts `I2F1` / `I2F2` in generated code as required.

### III) Global variables
- Globals are declared and implicitly initialized to **0**.
- Managed via a **symbol table** storing *(name, type, offset)*.
- Type checks on assignment to ensure the value’s type matches the variable’s type.
- Memory allocation with proper offsets.

### IV) Branching with **lazy evaluation**
- Boolean operators generate the corresponding P-Code (`NOT`, `GTI`/`GTF`, etc. depending on operand types).
- **Short-circuit AND**:
  - Uses a global counter `label_and` to create unique labels and handle nesting.
  - Emits:
    ```
    IFN(LF_AND_FALSE_(label_and))
    AND
    LF_AND_FALSE_(label_and):
    ```
  - If the first operand is false, the second is skipped.
- **Short-circuit OR**:
  - Uses a global counter `label_or`, emits:
    ```
    IFT(LV_OR_TRUE_(label_or))
    OR
    LV_OR_TRUE_(label_or):
    ```
- **if / else**:
  - Uses a global `label` incremented by the `if` nonterminal to build unique labels.
- **while**:
  - Uses a global `loop` incremented by the `while` nonterminal.
- Emission order respects the traversal of nonterminals.

### V) Nested blocks (sub-blocks)
- The keyword `var` marks the start of a block.
- Global `depth` starts at **-1** to distinguish the initial block from sub-blocks.
  - `SAVEBP` is emitted **only** when `depth != -1` (i.e., on first `var` in a sub-block).
- On entering a sub-block:
  - Offsets start at **1** because `oldBP` is reserved at offset **0**.
- On `block_end`:
  - Decrement `depth`, then **unstack** all symbols declared in the sub-block:
    - `unstack(n)` calls `remove_symbol` `n` times to pop sub-block variables from the symbol table.

### VI) Functions
- Right-recursive parsing to push arguments in the correct order.
- On encountering `fun_head`, the function is inserted into the symbol table with its **return type**:
  - Needed for recursion and for type-correct usage in expressions.
- Calls:
  - Global counter `arguments` increments for each processed argument and resets to `0` after the call.
  - The **return value** is stored in the location of the **first argument**.
- **Known limitation**:
  - Nested function calls as arguments (e.g., `Sisyphus(inf, mountain, Rock(10, round))`) are **not** fully supported by this mechanism.
  - Type checking of function arguments is **not implemented** yet.

---

## Implementation Notes

- **Symbol table** tracks identifiers with `(name, type, offset)`; used for globals, locals, and functions.
- **Lazy boolean evaluation** relies on unique labels (`label_and`, `label_or`) to preserve correctness with nested expressions.
- **Stack discipline**:
  - Uses `SAVEBP` only for sub-blocks (`depth != -1`).
  - Sub-blocks reserve `oldBP` at offset 0; locals start from offset 1.

---

##  Repository Layout (suggested)

```
/
├─ src/                # Compiler sources
├─ tst/                # Test sources / sample programs
├─ run                 # Driver/wrapper to compile a file to P-Code
├─ myp                 # P-Code interpreter/runner
├─ Makefile
└─ README.md
```

---

##  TODO

- Argument type checking for function calls (not implemented).
- Robust support for nested function calls as arguments.
- More complete P-Code runtime checks and error reporting.

---
