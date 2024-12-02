#include "PCode.h"

int main() { // Starts program target code

// Declare variable x of type int with offset 0 at depth 0
LOADI(0) // initial integer value for x

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADI(0)
STOREP // storing x (right) value at x adress (left value)


 // Entering standalone block at depth 1
SAVEBP
// Declare variable x of type int with offset 1 at depth 1
LOADI(0) // initial integer value for x

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected x (right) value in stack
LOADI(1)
STOREP // storing x (right) value at x adress (left value)

RESTOREBP
//Exiting stand alone block at depth 1
// removing variable x in TDS at depth 1

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

// Ends program target code

return stack[sp-1].int_value;
}

