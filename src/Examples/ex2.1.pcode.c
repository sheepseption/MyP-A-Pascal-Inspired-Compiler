#include "PCode.h"

int main() { // Starts program target code

LOADI(1)
LOADF(3.500000)
LOADI(2)
I2F2 // converting second arg to float
MULTF
I2F1 // converting first arg to float
ADDF
// Ends program target code

return stack[sp-1].int_value;
}

