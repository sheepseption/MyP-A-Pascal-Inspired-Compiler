#include "PCode.h"

int main()
{
    // Déclaration des variables
    SAVEBP       // Sauvegarde l'ancien BP
        LOADI(0) // Initialisation de z
        LOADI(0) // Initialisation de y
        LOADI(0) // Initialisation de x

        // Initialisation de x := 3
        LOADBP       // Charge BP dans la pile
            SHIFT(2) // Offset pour x
        LOADI(3)     // Valeur à assigner
        STOREP       // x := 3

            // Début de la condition if (x < 3 && y = 0)
            // Vérification de x < 3
            LOADBP               // Charge BP dans la pile
                SHIFT(2)         // Offset pour x
        LOADP                    // Charger la valeur de x
            LOADI(3)             // Charger la valeur 3
        LTI                      // Vérifie si x < 3
            IFN(False_Condition) // Si x >= 3, aller à False_Condition

        // Bloc then : z := 1
        LOADBP                  // Charge BP dans la pile
            SHIFT(0)            // Offset pour z
        LOADI(1)                // Valeur à assigner
        STOREP                  // z := 1
            GOTO(End_Condition) // Aller à la fin de la condition

        // Bloc else : z := 2
        False_Condition : LOADBP       // Charge BP dans la pile
                              SHIFT(0) // Offset pour z
                          LOADI(2)     // Valeur à assigner
                          STOREP       // z := 2

                              End_Condition : RESTOREBP // Restaure BP à sa valeur précédente
                                              return 0;
}
