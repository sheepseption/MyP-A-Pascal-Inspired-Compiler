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


// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected y (right) value in stack
LOADI(0)
STOREP // storing y (right) value at y adress (left value)

StartLoop_0: // chargement condition boucle while 0

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

LOADI(10)
LTI
IFN(EndLoop_0)
// Debut boucle while 0

// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected y (right) value in stack

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(0) // apply offset 0
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack


// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(1) // apply offset 1
// loading expected y (right) value in stack
LOADP // loading y (right) value on stack

ADDI
STOREP // storing y (right) value at y adress (left value)

GOTO(StartLoop_0)
//Fin boucle while 0
EndLoop_0:
 // Ends program target code

return stack[sp-1].int_value;
}

