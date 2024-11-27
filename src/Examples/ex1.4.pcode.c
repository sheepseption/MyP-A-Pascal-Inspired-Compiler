#include "PCode.h"

int main() { // Starts program target code

LOADI(1)
LOADI(2)
ADDI
LOADI(3)
MULTI
// Ends program target code

return stack[sp-1].int_value;
}

