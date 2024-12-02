#include "PCode.h"

int main() { // Starts program target code

LOADF(1.100000)
LOADF(2.100000)
LOADF(3.100000)
MULTF
ADDF
// Ends program target code

return stack[sp-1].int_value;
}

