#include "PCode.h"

int main() { // Starts program target code

LOADI(1)
LOADF(3.500000)
I2F1 // converting first arg to float
ADDF
LOADI(2)
LOADI(7)
ADDI
I2F2 // converting second arg to float
MULTF
LOADI(6)
I2F2 // converting second arg to float
ADDF
// Ends program target code

return stack[sp-1].int_value;
}

