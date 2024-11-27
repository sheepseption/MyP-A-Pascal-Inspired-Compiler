#include "PCode.h"

int main() { // Starts program target code

// Declare variable x of type int with offset 0 at depth 0
LOADI(0) // initial integer value for x
// Declare variable y of type int with offset 1 at depth 0
LOADI(0) // initial integer value for y
// Declare variable z of type int with offset 2 at depth 0
LOADI(0) // initial integer value for z

// Debut conditionelle 0

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

LOADI(0)
LTI
IFN(False_0)
// la condition 0 est vraie

// Debut conditionelle 1

// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected y (right) value in stack
LOADP // loading y (right) value on stack

LOADI(0)
GTI
IFN(False_1)
// la condition 1 est vraie

// loading z adress (left value) in stack
LOADBP // load current BP address
SHIFT(2) // apply offset 2
// loading expected z (right) value in stack
LOADI(0)
STOREP // storing z (right) value at z adress (left value)

GOTO(End_1)
False_1:
// la condition 1 est fausse

// loading z adress (left value) in stack
LOADBP // load current BP address
SHIFT(2) // apply offset 2
// loading expected z (right) value in stack
LOADI(1)
STOREP // storing z (right) value at z adress (left value)

End_1:
// Fin conditionelle 1
GOTO(End_0)
False_0:
// la condition 0 est fausse

// Debut conditionelle 2

// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected y (right) value in stack
LOADP // loading y (right) value on stack

LOADI(0)
LTI
IFN(False_2)
// la condition 2 est vraie

// loading z adress (left value) in stack
LOADBP // load current BP address
SHIFT(2) // apply offset 2
// loading expected z (right) value in stack
LOADI(2)
STOREP // storing z (right) value at z adress (left value)

GOTO(End_2)
False_2:
// la condition 2 est fausse

// loading z adress (left value) in stack
LOADBP // load current BP address
SHIFT(2) // apply offset 2
// loading expected z (right) value in stack
LOADI(4)
STOREP // storing z (right) value at z adress (left value)

End_2:
// Fin conditionelle 2
End_0:
// Fin conditionelle 0
// Ends program target code

return stack[sp-1].int_value;
}

