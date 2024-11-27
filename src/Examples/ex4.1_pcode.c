#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

LOADI(0)
LOADI(0)
LOADBP
SHIFT(0)
LOADI(1);
STOREP
LOADBP;
SHIFT(0)
LOADP;
LOADI(1);
GTI
IFN(False_0)
LOADBP
SHIFT(1)
LOADI(3);
STOREP
GOTO(End_0)
False_0:
LOADBP
SHIFT(1)
LOADI(4);
STOREP
END_0:
