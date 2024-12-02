#include "PCode.h"

int main() { // Starts program target code

// Declare variable x of type int with offset 0 at depth 0
LOADI(0) // initial integer value for x
// Declare variable y of type int with offset 1 at depth 0
LOADI(0) // initial integer value for y

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADI(1)
STOREP // storing x (right) value at x adress (left value)


// Debut conditionelle 0

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

LOADI(1)
GTI
IFN(False_0)
// la condition 0 est vraie

// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected y (right) value in stack
LOADI(3)
STOREP // storing y (right) value at y adress (left value)

GOTO(End_0)
False_0:
// la condition 0 est fausse

// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected y (right) value in stack
LOADI(4)
STOREP // storing y (right) value at y adress (left value)

End_0:
// Fin conditionelle 0
// Ends program target code

return stack[sp-1].int_value;
}

