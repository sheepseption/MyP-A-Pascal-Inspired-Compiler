#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

LOADI(0)
LOADI(0)
LOADI(0)
LOADBP;
SHIFT(0)
LOADP;
LOADI(0);
LTI
IFN(False_0)
LOADBP;
SHIFT(1)
LOADP;
LOADI(0);
GTI
IFN(False_1)
LOADBP
SHIFT(2)
LOADI(0);
STOREP
GOTO(End_1)
False_1:
LOADBP
SHIFT(2)
LOADI(1);
STOREP
END_1:
GOTO(End_0)
False_0:
LOADBP;
SHIFT(1)
LOADP;
LOADI(0);
LTI
IFN(False_2)
LOADBP
SHIFT(2)
LOADI(2);
STOREP
GOTO(End_2)
False_2:
LOADBP
SHIFT(2)
LOADI(4);
STOREP
END_2:
END_0:

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

