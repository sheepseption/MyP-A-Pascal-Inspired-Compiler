#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

LOADI(1);
LOADI(2);
LOADI(3);
MULTI;
ADDI;

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

