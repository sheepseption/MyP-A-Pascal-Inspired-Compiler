#include "PCode.h"

void call_add(){
// Start compiling function add at depth 0 with args (in reverse order)
// y with offset -2, type int and depth 1
// x with offset -3, type int and depth 1
// and return type int

// loading add adress (left value) in stack
LOADBP // load current BP address
SHIFT(-1) // apply offset -1
// loading expected add (right) value in stack

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(-3) // apply offset -3
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack


// loading y adress (left value) in stack
LOADBP // load current BP address
SHIFT(-2) // apply offset -2
// loading expected y (right) value in stack
LOADP // loading y (right) value on stack

ADDI
STOREP // storing add (right) value at add adress (left value)

// removing variable add in TDS at depth 1
// removing variable y in TDS at depth 1
// removing variable x in TDS at depth 1
}// Stop compiling function

int main() { // Starts program target code

// loading 2 arguments for function add 
LOADI(1)
LOADI(2)
// Loading default return value
LOADI(0)
SAVEBP
CALL(call_add)
RESTOREBP
ENDCALL(2) // unloading 2 args of function add
// Ends program target code

return stack[sp-1].int_value;
}

