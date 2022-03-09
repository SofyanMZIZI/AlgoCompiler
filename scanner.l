%{

#include "parser.h"
extern int lineNbr;
extern int columnNbr;
void yyerror(const char * msg);

%}

%option noyywrap
integer [0-9]+
real [0-9]+\.[0-9]*|\.[0-9]+
ident [a-zA-Z_][0-9a-zA-Z_]*
string \"(\\.|[^"\\])*\"

%%

"Algorithme"            { columnNbr+=yyleng; return ALGO_TOKEN; }
"Constante"             { columnNbr+=yyleng; return CONST_TOKEN; }
"Variable"              { columnNbr+=yyleng; return VAR_TOKEN; }

"Debut"                 { columnNbr+=yyleng; return DEBUT_TOKEN; }
"Fin"                   { columnNbr+=yyleng; return FIN_TOKEN; }

"Si"                    { columnNbr+=yyleng; return SI_TOKEN; }
"Alors"                 { columnNbr+=yyleng; return ALORS_TOKEN; }
"Sinon"                 { columnNbr+=yyleng; return SINON_TOKEN; }
"FinSi"                 { columnNbr+=yyleng; return FINSI_TOKEN; }

"Repeter"               { columnNbr+=yyleng; return REPETER_TOKEN; }
"Jusqu'a"               { columnNbr+=yyleng; return JUSQUA_TOKEN; }

"TantQue"               { columnNbr+=yyleng; return TANTQUE_TOKEN; }
"FinTantQue"            { columnNbr+=yyleng; return FINTANTQUE_TOKEN; }

"Pour"                  { columnNbr+=yyleng; return POUR_TOKEN; }
"->"                    { columnNbr+=yyleng; return DeA_TOKEN; }
"FinPour"               { columnNbr+=yyleng; return FINPOUR_TOKEN; }

"Lire"                  { columnNbr+=yyleng; return LIRE_TOKEN; }
"Ecrire"                { columnNbr+=yyleng; return ECRIRE_TOKEN; }

"OU"                    { columnNbr+=yyleng; return OR_TOKEN; }
"ET"                    { columnNbr+=yyleng; return AND_TOKEN; }

"entier"                { columnNbr+=yyleng; return INT_TYPE_TOKEN; }
"reel"                  { columnNbr+=yyleng; return FLOAT_TYPE_TOKEN; }
"charactere"            { columnNbr+=yyleng; return STRING_TYPE_TOKEN; }

"+"                     { columnNbr+=yyleng; return PLUS_TOKEN; }
"-"                     { columnNbr+=yyleng; return MOINS_TOKEN; }
"*"                     { columnNbr+=yyleng; return MULT_TOKEN; }
"/"                     { columnNbr+=yyleng; return DIV_TOKEN; }
","                     { columnNbr+=yyleng; return VIR_TOKEN; }
"<-"                    { columnNbr+=yyleng; return AFF_TOKEN; }
"<"                     { columnNbr+=yyleng; return INF_TOKEN; }
"<="                    { columnNbr+=yyleng; return INFEG_TOKEN; }
">"                     { columnNbr+=yyleng; return SUP_TOKEN; }
">="                    { columnNbr+=yyleng; return SUPEG_TOKEN; }
"<>"                    { columnNbr+=yyleng; return DIFF_TOKEN; }
"="                     { columnNbr+=yyleng; return EGALE_TOKEN; }
"("                     { columnNbr+=yyleng; return PO_TOKEN; }
")"                     { columnNbr+=yyleng; return PF_TOKEN; }

{ident}                 { columnNbr+=yyleng; return ID_TOKEN; }
{integer}               { columnNbr+=yyleng; return INT_TOKEN; }
{real}                  { columnNbr+=yyleng; return FLOAT_TOKEN; }
{string}                { columnNbr+=yyleng; return STRING_TOKEN; }


[ \t]+                  { columnNbr+=yyleng; }
"\n"                    { lineNbr++; columnNbr=1; }
.                       {   
                            char msg[20];
                            sprintf(msg,"lexical error <%s>",yytext);
                            yyerror(msg);
                            columnNbr+=yyleng;
                            
                        }

%%
