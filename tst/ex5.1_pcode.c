#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

LOADI(0)
// Accessing variable x at depth 0 (current depth: 0)
LOADBP
SHIFT(0)
LOADI(0);
STOREP
LOADI(0)
SAVEBP
// Accessing variable y at depth 0 (current depth: 1)
LOADBP
LOADP
SHIFT(1)
LOADI(1);
STOREP
// Accessing variable x at depth 0 (current depth: 1)
LOADBP
LOADP
SHIFT(0)
LOADBP;
SHIFT(1)
LOADP;
STOREP
RESTOREBP
LOADBP;
SHIFT(0)
LOADP;

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

