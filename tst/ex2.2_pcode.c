#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

LOADI(1);
LOADF(3.500000);
I2F1;
ADDF;
LOADI(2);
LOADI(7);
ADDI;
I2F2;
MULTF;
LOADI(6);
I2F2;
ADDF;

/* Stoping (main) program target PCode */
return stack[sp-1].float_value;
}

