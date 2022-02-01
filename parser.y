%{ /*-------- prog.y --------*/
    #include <stdio.h>
    #include <stdlib.h>
    #include "file.h"

    int yylex(void); // defini dans progL.c, utilise par yyparse()
    void yyerror(const char * msg); // defini plus loin, utilise par yyparse()

    int lineNbr; // notre compteur de lignes
    int columnNbr; // notre compteur de colones
    extern FILE * yyin; // defini dans progL.cpp, utilise par main()
%}

%token ALGO_TOKEN CONST_TOKEN VAR_TOKEN
%token DEBUT_TOKEN FIN_TOKEN
%token SI_TOKEN ALORS_TOKEN SINON_TOKEN FINSI_TOKEN
%token REPETER_TOKEN JUSQUA_TOKEN
%token TANTQUE_TOKEN FINTANTQUE_TOKEN
%token POUR_TOKEN DeA_TOKEN FINPOUR_TOKEN
%token LIRE_TOKEN ECRIRE_TOKEN
%token OR_TOKEN AND_TOKEN
%token PLUS_TOKEN MOINS_TOKEN MULT_TOKEN DIV_TOKEN VIR_TOKEN AFF_TOKEN INF_TOKEN INFEG_TOKEN SUP_TOKEN SUPEG_TOKEN DIFF_TOKEN EGALE_TOKEN PO_TOKEN PF_TOKEN
%token ID_TOKEN INT_TOKEN FLOAT_TOKEN STRING_TOKEN
%token INT_TYPE_TOKEN FLOAT_TYPE_TOKEN STRING_TYPE_TOKEN
%token ERREUR_TOKEN

%start program

%%

program :
    ALGO_TOKEN ID_TOKEN block
;

block:
    constBlock varBlock mainBlock
;


constBlock:
    %empty
    | CONST_TOKEN ID_TOKEN EGALE_TOKEN constValue constList
;
constValue:
    INT_TOKEN
    | FLOAT_TOKEN
    | STRING_TOKEN
;
constList:
    %empty
    | VIR_TOKEN ID_TOKEN EGALE_TOKEN constValue constList
;


varBlock:
    %empty
    | VAR_TOKEN varType ID_TOKEN varList
;
varType:
    INT_TYPE_TOKEN
    | FLOAT_TYPE_TOKEN
    | STRING_TYPE_TOKEN
;
varList:
    %empty
    | VIR_TOKEN varType ID_TOKEN varList
;


mainBlock:
    DEBUT_TOKEN instList FIN_TOKEN
;

inst:
    affect
    | si
    | pour
    | tantque
    | repeter
    | ecrire
    | lire
;
instList:
    %empty
    | inst instList
;


affect:
    ID_TOKEN AFF_TOKEN expr
;
si:
    SI_TOKEN cond ALORS_TOKEN instList sinon FINSI_TOKEN
;
sinon:
    %empty
    | SINON_TOKEN instList
;
pour:
    POUR_TOKEN ID_TOKEN INT_TOKEN DeA_TOKEN INT_TOKEN ALORS_TOKEN instList FINPOUR_TOKEN
;
tantque:
    TANTQUE_TOKEN cond ALORS_TOKEN instList FINTANTQUE_TOKEN
;
repeter:
    REPETER_TOKEN instList JUSQUA_TOKEN cond
;
ecrire:
    ECRIRE_TOKEN PO_TOKEN expr ecrireList PF_TOKEN
;
ecrireList:
    %empty
    | VIR_TOKEN expr ecrireList
;
lire:
    LIRE_TOKEN PO_TOKEN ID_TOKEN lireList PF_TOKEN
;
lireList:
    %empty
    | VIR_TOKEN ID_TOKEN lireList
;

cond:
    expr cmpCond expr
;
cmpCond:
    EGALE_TOKEN
    | DIFF_TOKEN
    | SUP_TOKEN
    | SUPEG_TOKEN
    | INF_TOKEN
    | INFEG_TOKEN
    | OR_TOKEN
    | AND_TOKEN
;
expr:
    term exprList
;
exprList:
    %empty
    | PLUS_TOKEN term exprList
    | MOINS_TOKEN term exprList 
;
term:
    fact termList
;
termList:
    %empty
    | MULT_TOKEN fact termList
    | DIV_TOKEN fact termList
;
fact:
    ID_TOKEN
    | INT_TOKEN
    | FLOAT_TOKEN
    | PO_TOKEN expr PF_TOKEN
;

%%

void yyerror(const char * msg)
{
    printf("line %d, column %d: %s\n", lineNbr, columnNbr, msg);
}


int main(int argc,char ** argv)
{
    if(argc == 2)
    {
        yyin = openFile(argv[1]);

        lineNbr=1;
        columnNbr=1;

        if(!yyparse())
            printf("lexic: true\nparser: true\n");
        return(0);
    }
    else
    {
        fprintf(stderr, "ERROR: argument command.\n");
        exit(-1);
    }
}
