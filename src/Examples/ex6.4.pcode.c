#include "PCode.h"

void call_fact(){
// Start compiling function fact at depth 0 with args (in reverse order)
// x with offset -2, type int and depth 1
// and return type int

// Debut conditionelle 0

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(-2) // apply offset -2
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

LOADI(1)
LTI
IFN(False_0)
// la condition 0 est vraie

// loading fact adress (left value) in stack
LOADBP // load current BP address
SHIFT(-1) // apply offset -1
// loading expected fact (right) value in stack
LOADI(1)
STOREP // storing fact (right) value at fact adress (left value)

GOTO(End_0)
False_0:
// la condition 0 est fausse

// loading fact adress (left value) in stack
LOADBP // load current BP address
SHIFT(-1) // apply offset -1
// loading expected fact (right) value in stack

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(-2) // apply offset -2
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

// loading 1 arguments for function fact 

// loading x adress (left value) in stack
LOADBP // load current BP address
SHIFT(-2) // apply offset -2
// loading expected x (right) value in stack
LOADP // loading x (right) value on stack

LOADI(1)
SUBI
// Loading default return value
LOADI(0)
SAVEBP
CALL(call_fact)
RESTOREBP
ENDCALL(1) // unloading 1 args of function fact
MULTI
STOREP // storing fact (right) value at fact adress (left value)

End_0:
// Fin conditionelle 0
// removing variable fact in TDS at depth 1
// removing variable x in TDS at depth 1
}// Stop compiling function

int main() { // Starts program target code

// loading 1 arguments for function fact 
LOADI(3)
// Loading default return value
LOADI(0)
SAVEBP
CALL(call_fact)
RESTOREBP
ENDCALL(1) // unloading 1 args of function fact
// Ends program target code

return stack[sp-1].int_value;
}

