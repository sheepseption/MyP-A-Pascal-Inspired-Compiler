#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

LOADF(1.100000)
LOADF(2.100000)
LOADF(3.100000)
MULTF
ADDF

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

