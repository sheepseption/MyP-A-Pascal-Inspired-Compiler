#include "PCode.h"

void call_toOne(){
// Start compiling function toOne at depth 0 with args (in reverse order)
// x with offset -2, type int and depth 1
// and return type int

// loading toOne adress (left value) in stack
LOADBP // load current BP address
SHIFT(-1) // apply offset -1
// loading expected toOne (right) value in stack
LOADI(1)
STOREP // storing toOne (right) value at toOne adress (left value)

// removing variable toOne in TDS at depth 1
// removing variable x in TDS at depth 1
}// Stop compiling function

int main() { // Starts program target code

// loading 1 arguments for function toOne 
LOADI(2)
// Loading default return value
LOADI(0)
SAVEBP
CALL(call_toOne)
RESTOREBP
ENDCALL(1) // unloading 1 args of function toOne
// Ends program target code

return stack[sp-1].int_value;
}

