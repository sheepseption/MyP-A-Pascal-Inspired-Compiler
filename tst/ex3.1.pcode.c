#include "PCode.h"

int main() { // Starts program target code

// Declare variable x of type int with offset 0 at depth 0
LOADI(0) // initial integer value for x

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADI(3)
STOREP // storing x (right) value at x adress (left value)

LOADI(1)
LOADI(2)

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

MULTI
ADDI
// Ends program target code

return stack[sp-1].int_value;
}

