#include "PCode.h"

int main() { // Starts program target code

// Declare variable x of type int with offset 0 at depth 0
LOADI(0) // initial integer value for x
// Declare variable y of type float with offset 1 at depth 0
LOADF(0.0) // initial float value for y

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADI(3)
STOREP // storing x (right) value at x adress (left value)


// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected y (right) value in stack

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

I2F2 // Converting int to float
STOREP // storing y (right) value at y adress (left value)

LOADI(1)
LOADI(2)

// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected y (right) value in stack
LOADP // loading y (right) value on stack

I2F1 // converting first arg to float
MULTF
I2F1 // converting first arg to float
ADDF
// Ends program target code

return stack[sp-1].int_value;
}

