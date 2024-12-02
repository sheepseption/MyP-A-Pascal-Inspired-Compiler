#include "PCode.h"

/* (Optionnal) functions' target PCode */

void call_toOne(){
LOADBP
SHIFT(-1)
LOADI(1)
STOREP
}
int main() {
/* Starting (main) program target PCode */

LOADI(2)
LOADI(0)
SAVEBP
CALL(call_toOne)
RESTOREBP
ENDCALL(1)

/* Stoping (main) program target PCode */
return stack[sp-1].int_value;
}

