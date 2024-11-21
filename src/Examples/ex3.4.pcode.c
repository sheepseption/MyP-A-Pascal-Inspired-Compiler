#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

// Declare variable x of type int with offset 0 at depth 0
LOADI(0) // initial integer value for x
// Declare variable y of type float with offset 1 at depth 0
LOADF(0.0) // initial float value for y

// Write a value into variable x
  // loading x adress (left value) in stack
LOADBP
SHIFT(0) // offset 0 
  // loading expected x (right) value in stack
LOADI(3)
  // storing x (right) value at x adress
STOREP


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
Erreur: Type error in affectation

