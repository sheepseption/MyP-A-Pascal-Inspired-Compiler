#include "PCode.h"

void call_addOne(){
// Start compiling function addOne at depth 0 with args (in reverse order)
// y with offset -2, type int and depth 1
// and return type int

// loading addOne adress (left value) in stack
LOADBP // load current BP address
SHIFT(-1) // apply offset -1
// loading expected addOne (right) value in stack

// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(-2) // apply offset -2
// loading expected y (right) value in stack
LOADP // loading y (right) value on stack

LOADI(1)
ADDI
STOREP // storing addOne (right) value at addOne adress (left value)

// removing variable addOne in TDS at depth 1
// removing variable y in TDS at depth 1
}// Stop compiling function

int main() { // Starts program target code

// loading 1 arguments for function addOne 
LOADI(2)
// Loading default return value
LOADI(0)
SAVEBP
CALL(call_addOne)
RESTOREBP
ENDCALL(1) // unloading 1 args of function addOne
// Ends program target code

return stack[sp-1].int_value;
}

