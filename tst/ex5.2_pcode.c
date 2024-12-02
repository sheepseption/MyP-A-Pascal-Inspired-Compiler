#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

LOADI(0)
LOADI(0)
LOADBP
SHIFT(0)
LOADI(0);
STOREP
LOADI(0)
SAVEBP
LOADBP
SHIFT(2)
LOADI(1);
STOREP
LOADBP
SHIFT(1)
LOADBP;
SHIFT(2)
LOADP;
STOREP
RESTOREBP
LOADBP;
SHIFT(1)
LOADP;

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

