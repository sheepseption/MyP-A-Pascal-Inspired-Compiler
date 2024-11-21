#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

// Declare variable x of type int with offset 0 at depth 0
LOADI(0) // initial integer value for x
// Declare variable y of type int with offset 1 at depth 0
LOADI(0) // initial integer value for y

// Write a value into variable x
  // loading x adress (left value) in stack
LOADBP
SHIFT(0) // offset 0 
  // loading expected x (right) value in stack
LOADI(1)
  // storing x (right) value at x adress
STOREP


// Debut conditionelle 0

// Read variable x value
  // loading x address (left value) at depth 0 and offset 0 in stack
LOADBP
SHIFT(0) // local var with offset 0 
  // reading x (right) value at its adress (left value)
LOADP

// Read variable y value
  // loading y address (left value) at depth 0 and offset 1 in stack
LOADBP
SHIFT(1) // local var with offset 1 
  // reading y (right) value at its adress (left value)
LOADP
LOADI(3)
ORI
ANDI
IFN(False_0)
// la condition 0 est vraie

// Write a value into variable y
  // loading y adress (left value) in stack
LOADBP
SHIFT(1) // offset 1 
  // loading expected y (right) value in stack
LOADI(1)
  // storing y (right) value at y adress
STOREP

GOTO(End_0)
False_0:
// la condition 0 est fausse

// Write a value into variable y
  // loading y adress (left value) in stack
LOADBP
SHIFT(1) // offset 1 
  // loading expected y (right) value in stack
LOADI(1)
  // storing y (right) value at y adress
STOREP

End_0:
// Fin conditionelle 0

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

