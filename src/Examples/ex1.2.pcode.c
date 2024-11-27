#include "PCode.h"

int main() { // Starts program target code

LOADI(1)
LOADI(2)
LOADI(3)
MULTI
ADDI
// Ends program target code

return stack[sp-1].int_value;
}

