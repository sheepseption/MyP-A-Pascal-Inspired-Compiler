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


// Write a value into variable y
  // loading y adress (left value) in stack
LOADBP
SHIFT(1) // offset 1 
  // loading expected y (right) value in stack
LOADI(0)
  // storing y (right) value at y adress
STOREP

StartLoop_0: // chargement condition boucle while 0

// Read variable x value
  // loading x address (left value) at depth 0 and offset 0 in stack
LOADBP
SHIFT(0) // local var with offset 0 
  // reading x (right) value at its adress (left value)
LOADP
LOADI(10)
LTI
IFN(EndLoop_0)
// Debut boucle while 0

// Write a value into variable y
  // loading y adress (left value) in stack
LOADBP
SHIFT(1) // offset 1 
  // loading expected y (right) value in stack

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
ADDI
  // storing y (right) value at y adress
STOREP

GOTO(StartLoop_0)
//Fin boucle while 0
EndLoop_0:
 
/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

