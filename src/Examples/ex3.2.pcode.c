#include "PCode.h"

int main() { // Starts program target code

// Declare variable x of type float with offset 0 at depth 0
LOADF(0.0) // initial float value for x

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADI(3)
I2F2 // Converting int to float
STOREP // storing x (right) value at x adress (left value)

LOADI(1)

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

LOADI(2)
I2F2 // converting second arg to float
MULTF
I2F1 // converting first arg to float
ADDF
// Ends program target code

return stack[sp-1].int_value;
}

