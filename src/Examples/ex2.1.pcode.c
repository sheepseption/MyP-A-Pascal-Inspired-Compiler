#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

LOADI(1)
LOADF(3.500000)
LOADI(2)
I2F2 // converting second arg to float
MULTF
I2F1 // converting first arg to float
ADDF

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

