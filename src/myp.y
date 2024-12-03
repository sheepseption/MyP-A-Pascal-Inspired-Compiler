%{

#include "Table_des_symboles.h"

#include <stdio.h>
#include <stdlib.h>
  
extern int yylex();
extern int yyparse();

void yyerror (char* s) {
  printf ("Erreur: %s\n",s);
  exit(0);
  }
		
 int depth = -1; // block depth
 int offset=0;
 int label=0;
 int loop=0;
 int label_and = 0;
 int label_or = 0; 
 int arguments = 0;
  char * start_main=  
"int main() {\n\
/* Starting (main) program target PCode */\n";
    
  char * end_main_int=  
"\n\
/* Stoping (main) program target PCode */\n\
return stack[sp-1].int_value;\n\
}\n";  
  char * end_main_float=  
"\n\
/* Stoping (main) program target PCode */\n\
return stack[sp-1].float_value;\n\
}\n";  

int new_offset() {
  static int x = 1;
  return x++;
}

 
%}

%union { 
  struct ATTRIBUTE * symbol_value;
  char * string_value;
  int int_value;
  float float_value;
  int type_value;
  int label_value;
  int offset_value;
}

%token <int_value> NUM 
%token <float_value> DEC

%token PRG FUN VAR BIN BOUT AFF CLN DOT

%token INT FLOAT VOID

%token <string_value> ID 
%token PO PF PV VIR
%token <label_value> IF ELSE WHILE

%token <label_value> AND OR NOT DIFF EQUAL SUP INF
%token PLUS MOINS STAR DIV
%token ARR

%nonassoc IFX
%left OR                       // higher priority on ||
%left AND                      // higher priority on &&
%left DIFF EQUAL SUP INF       // higher priority on comparison
%left PLUS MOINS               // higher priority on + - 
%left STAR DIV                 // higher priority on * /
%left DOT ARR                  // higher priority on . and -> 
%nonassoc UNA                  // highest priority on unary operator
%nonassoc ELSE


%{
char * type2string (int c) {
  switch (c)
    {
    case INT:
      return("int");
    case FLOAT:
      return("float");
    case VOID:
      return("void");
    default:
      return("type error");
    }  
};

  
  %}


%start prog  

// liste de tous les non terminaux dont vous voulez manipuler l'attribut
%type <type_value> type exp  typename ret inst inst_list prog_body 
%type <string_value> fun_head fun_name arg arg_list fid 
%type <int_value> aff_symb if while app
 /* Attention, la rêgle de calcul par défaut $$=$1 
    peut créer des demandes/erreurs de type d'attribut */

%%

 // I. Programme (top level)

prog : prog_head prog_body;

prog_head : PRG ID PV
;

prog_body : opt_funs
            {printf("%s\n",start_main);}
            opt_vars
	    BIN inst_list BOUT DOT
	    { if($5 == FLOAT)
        printf("%s\n",end_main_float);
        else 
        printf("%s\n",end_main_int);}
        
            
;


// II. Declarations de variables

opt_vars : var decl_list    {}
|                           {if(depth == -1)
                              depth++;}
;

var: VAR {if(depth != -1) {
  printf("SAVEBP\n"); depth++; offset=1;}
  else depth++;}// ici on entre dans des declarations de variables
;

decl_list : decl_list decl   {} 
| decl                       {}
;

decl: ID CLN type PV             {
                                  attribute i = makeSymbol($3, offset++, depth);
                                  set_symbol_value((sid)$1,i);
                                  if ($3 == INT) {printf("LOADI(%d)\n", 0);}
                                  else if ($3 == FLOAT) {printf("LOADF(%f)\n", 0.0);}
                                  //$$ = (int) i->offset;
                                  }
;

type
: typename                     {$$=$1;}
;

typename
: INT                          {$$=INT;}
| FLOAT                        {$$=FLOAT;}
| VOID                         {$$=VOID;}
;
// III. Déclarations de functions

opt_funs : opt_funs function
| {printf("/* (Optionnal) functions' target PCode */\n\n");}
;

function : fun_head fun_body {printf("}\n");}
;

fun_head : fun fun_name opt_arg CLN type {
                                        attribute i = makeSymbol($5, -1, 0); 
                                        set_symbol_value((sid)$2,i); 
                                        printf("void call_%s(){\n", (sid)$2 );
                                        }
;

fun:FUN 

fun_name : ID {offset = -1;
              $$ = (sid)$1;}
;

opt_arg : PO arg_list PF
| ;


arg_list : arg vir arg_list {get_symbol_value($1)->offset=--offset;}
	   // récursion droite pour numéroter les paramètres du dernier au premier
     
| arg {get_symbol_value($1)->offset=--offset;}
;
arg : ID CLN type  {$$=$1;
                    attribute i = makeSymbol($3, 0, depth);
                    set_symbol_value($1, i);
                   }            
;

vir : VIR                      
;

fun_body : opt_vars BIN inst_list BOUT PV    {}
;

// IV. Instructions


inst_list: inst_list inst PV   {$$ = $2;} 
| inst PV                      {$$ = $1;}
;

     // chaque instruction se termine par ";" contrairement au langage C

inst:
opt_vars block_begin inst_list block_end   {}
| aff                         {}
| ret                         {$$ = $1;}
| cond                        {}
| loop                        {}
;

// Entrée et sortie explicite d'un bloc

block_begin : BIN       {/*printf("SAVBP\n"); depth++;*/}
;
// entrée dans un sous-bloc

block_end : BOUT        {printf("RESTOREBP\n"); 
                          unstack(offset-1);
                          depth--;}
;
// sortie d'un sous-bloc


// IV.1 Affectations

aff : ID aff_symb exp               {if(get_symbol_value($<string_value>1)->type == FLOAT)
                                      {
                                        if($3 == INT)
                                          printf("I2F2\n");
                                        printf("STOREP\n");
                                      }
                                    else if (get_symbol_value($<string_value>1)->type == $3)
                                      {printf("STOREP\n");}
                                     else {printf("Erreur: Type error in affectation\n");
                                     return 0;}
                                    }
                                
                        
;

aff_symb: AFF {attribute x  = get_symbol_value($<string_value>0);
              
              if (x->depth == depth)
                printf("LOADBP\nSHIFT(%d)\n", x->offset);
              else 
                printf("LOADBP\nLOADP\nSHIFT(%d)\n", x->offset);
              }
                                    


// IV.2. Conditionelles
//           N.B. ces rêgles génèrent un conflit déclage reduction
//           qui est résolu comme on le souhaite par un décalage (shift)
//           avec ELSE en entrée (voir y.output)

cond :
if bool_cond inst  elsop       {printf("END_%d:\n", $<int_value>1);}
;

elsop : else inst              {}
|                  %prec IFX   {} // juste un "truc" pour éviter le message de conflit shift / reduce
;

bool_cond : PO exp PF         {printf("IFN(False_%d)\n", $<int_value>0);}
;

if : IF                       {$$ = label++;}
;

else : ELSE                   {printf("GOTO(End_%d)\nFalse_%d:\n", $<int_value>-2, $<int_value>-2);}
;

// IV.3. Iterations

loop : while while_cond inst  {printf("GOTO(StartLoop_%d)\nEndLoop_%d:\n", $1,$1 );}
;

while_cond : PO exp PF        {printf("IFN(EndLoop_%d)\n", $<int_value>0);}

while : WHILE                 {$$=loop++; printf("StartLoop_%d:\n", $$);}
;

// IV.4. Valeur

ret : exp                     {$$ = $1;}
;



// V. Expressions

exp
// V.1 Exp. arithmetiques
: MOINS exp %prec UNA         {}
         // -x + y lue comme (- x) + y  et pas - (x + y)
| exp PLUS exp                {if($1 == INT && $3 == INT) {
                                printf("ADDI\n");
                                $$ = INT;
                              }
                              else if($1 == FLOAT && $3 == FLOAT) {
                                printf("ADDF\n");
                                $$ = FLOAT;
                              }
                              else if($1 == FLOAT && $3 == INT) {
                                printf("I2F2\n");
                                printf("ADDF\n");
                                $$ = FLOAT;
                              }
                              else if($1 == INT && $3 == FLOAT) {
                                printf("I2F1\n");
                                printf("ADDF\n");
                                $$ = FLOAT;
                              }
                              
                              }

| exp MOINS exp               {if($1 == INT && $3 == INT) {
                                printf("SUBI\n");
                                $$ = INT;
                              }
                              else if($1 == FLOAT && $3 == FLOAT) {
                                printf("SUBF\n");
                                $$ = FLOAT;
                              }
                              else if($1 == FLOAT && $3 == INT) {
                                printf("I2F2\n");
                                printf("SUBF\n");
                                $$ = FLOAT;
                              }
                              else if($1 == INT && $3 == FLOAT) {
                                printf("I2F1\n");
                                printf("SUBF\n");
                                $$ = FLOAT;
                              };
                              
                              }

| exp STAR exp                {if($1 == INT && $3 == INT) {
                                printf("MULTI\n");
                                $$ = INT;
                              }
                              else if($1 == FLOAT && $3 == FLOAT) {
                                printf("MULTF\n");
                                $$ = FLOAT;
                              }
                              else if($1 == FLOAT && $3 == INT) {
                                printf("I2F2\n");
                                printf("MULTF\n");
                                $$ = FLOAT;
                              }
                              else if($1 == INT && $3 == FLOAT) {
                                printf("I2F1\n");
                                printf("MULTF\n");
                                $$ = FLOAT;
                              }
                              //$$ = $1 * $3;
                              }
| exp DIV exp                 {if($1 == INT && $3 == INT) {
                                printf("DIVI\n");
                                $$ = INT;
                              }
                              else if($1 == FLOAT && $3 == FLOAT) {
                                printf("DIVF\n");
                                $$ = FLOAT;
                              }
                              else if($1 == FLOAT && $3 == INT) {
                                printf("I2F2\n");
                                printf("DIVF\n");
                                $$ = FLOAT;
                              }
                              else if($1 == INT && $3 == FLOAT) {
                                printf("I2F1\n");
                                printf("DIVF\n");
                                $$ = FLOAT;
                              }
                              //$$ = $1 / $3;
                              }
| PO exp PF                   {$$ = $2;}
| ID                          {attribute x = get_symbol_value((sid)$1);
                               printf("LOADBP\nSHIFT(%d)\nLOADP\n", x->offset); 
                               $$ = x->type;
                              }
| app                         {}
| NUM                         {
                              $$ = INT;
                              printf("LOADI(%d)\n", $1);
                              }
| DEC                         {
                              
                              $$ = FLOAT;
                              printf("LOADF(%f)\n", (float)$1);}
                             


// V.2. Booléens

| NOT exp %prec UNA           {printf("NOT\n");}
| exp INF exp                 {if($1 == INT && $3 == INT){printf("LTI\n");}
                               else {printf("LTF\n");}
                              }
| exp SUP exp                 {if($1 == INT && $3 == INT){printf("GTI\n");}
                               else {printf("GTF\n");}
                              }
| exp EQUAL exp               {if($1 == INT && $3 == INT){printf("EQI\n");}
                               else {printf("EQF\n");}
                              }
| exp DIFF exp                {if($1 == INT && $3 == INT){printf("NEQI\n");}
                               else {printf("NEQF\n");}
                              }
| exp AND exp                 {int local_label = label_and++;
                                 printf("IFN(LF_AND_FALSE_%d)\n", local_label);
                                 printf("AND\n");
                                 printf("LF_AND_FALSE_%d:\n", local_label);
                             }

| exp OR exp                  {
                                 int local_label = label_or++;
                                 
                                 printf("IFT(LV_OR_TRUE_%d)\n", local_label);
                                 
                                 printf("OR\n");
                                  

                                 printf("LV_OR_TRUE_%d:\n", local_label);
                             }


;

// V.3 Applications de fonctions


app : fid PO args PF          {if(get_symbol_value($1)->type == INT)
                                    {printf("LOADI(0)\nSAVEBP\nCALL(call_%s)\nRESTOREBP\nENDCALL(%d)\n", $<string_value>1, arguments);}
                               else if (get_symbol_value($1)->type == FLOAT)
                                    {printf("LOADI(0.0)\nSAVEBP\nCALL(call_%s)\nRESTOREBP\nENDCALL(%d)\n", $<string_value>1, arguments);}
                               else
                                    {printf("LOADI(0)\nSAVEBP\nCALL(call_%s)\nRESTOREBP\nENDCALL(%d)\n", $<string_value>1, arguments);}

                               arguments=0;
                               $$=get_symbol_value($1)->type;}
;

fid : ID                      {$$=$1;}

args :  arglist               {}
|                             {}
;

arglist : arglist VIR exp     {++arguments;} // récursion gauche pour empiler les arguements de la fonction de gauche à droite
| exp                         {++arguments;}
;

%% 
int main () {

  /* Ici on peut ouvrir le fichier source, avec les messages 
     d'erreur usuel si besoin, et rediriger l'entrée standard 
     sur ce fichier pour lancer dessus la compilation.
  */
  
  
printf("#include \"PCode.h\"\n\n");
    	 
return yyparse ();

} 

