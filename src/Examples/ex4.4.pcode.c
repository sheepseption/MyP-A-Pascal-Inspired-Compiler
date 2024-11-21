#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

// Declare variable x of type int with offset 0 at depth 0
LOADI(0) // initial integer value for x
// Declare variable y of type int with offset 1 at depth 0
LOADI(0) // initial integer value for y
// Declare variable z of type int with offset 2 at depth 0
LOADI(0) // initial integer value for z

// Debut conditionelle 0

// Read variable x value
  // loading x address (left value) at depth 0 and offset 0 in stack
LOADBP
SHIFT(0) // local var with offset 0 
  // reading x (right) value at its adress (left value)
LOADP
LOADI(0)
LTI
IFN(False_0)
// la condition 0 est vraie

// Debut conditionelle 1

// Read variable y value
  // loading y address (left value) at depth 0 and offset 1 in stack
LOADBP
SHIFT(1) // local var with offset 1 
  // reading y (right) value at its adress (left value)
LOADP
LOADI(0)
GTI
IFN(False_1)
// la condition 1 est vraie

// Write a value into variable z
  // loading z adress (left value) in stack
LOADBP
SHIFT(2) // offset 2 
  // loading expected z (right) value in stack
LOADI(0)
  // storing z (right) value at z adress
STOREP

GOTO(End_1)
False_1:
// la condition 1 est fausse

// Write a value into variable z
  // loading z adress (left value) in stack
LOADBP
SHIFT(2) // offset 2 
  // loading expected z (right) value in stack
LOADI(1)
  // storing z (right) value at z adress
STOREP

End_1:
// Fin conditionelle 1
GOTO(End_0)
False_0:
// la condition 0 est fausse

// Debut conditionelle 2

// Read variable y value
  // loading y address (left value) at depth 0 and offset 1 in stack
LOADBP
SHIFT(1) // local var with offset 1 
  // reading y (right) value at its adress (left value)
LOADP
LOADI(0)
LTI
IFN(False_2)
// la condition 2 est vraie

// Write a value into variable z
  // loading z adress (left value) in stack
LOADBP
SHIFT(2) // offset 2 
  // loading expected z (right) value in stack
LOADI(2)
  // storing z (right) value at z adress
STOREP

GOTO(End_2)
False_2:
// la condition 2 est fausse

// Write a value into variable z
  // loading z adress (left value) in stack
LOADBP
SHIFT(2) // offset 2 
  // loading expected z (right) value in stack
LOADI(4)
  // storing z (right) value at z adress
STOREP

End_2:
// Fin conditionelle 2
End_0:
// Fin conditionelle 0

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

