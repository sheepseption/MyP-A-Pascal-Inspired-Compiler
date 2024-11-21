#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

// Declare variable x of type int with offset 0 at depth 0
LOADI(0) // initial integer value for x

// Write a value into variable x
  // loading x adress (left value) in stack
LOADBP
SHIFT(0) // offset 0 
  // loading expected x (right) value in stack
LOADI(3)
  // storing x (right) value at x adress
STOREP

LOADI(1)
LOADI(2)

// Read variable x value
  // loading x address (left value) at depth 0 and offset 0 in stack
LOADBP
SHIFT(0) // local var with offset 0 
  // reading x (right) value at its adress (left value)
LOADP
MULTI
ADDI

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

