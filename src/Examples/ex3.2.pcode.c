#include "PCode.h"

/* (Optionnal) functions' target PCode */

int main() {
/* Starting (main) program target PCode */

// Declare variable x of type float with offset 0 at depth 0
LOADF(0.0) // initial float value for x

// Write a value into variable x
  // loading x adress (left value) in stack
LOADBP
SHIFT(0) // offset 0 
  // loading expected x (right) value in stack
LOADI(3)
Erreur: Type error in affectation

