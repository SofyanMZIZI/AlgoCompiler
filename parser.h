/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ALGO_TOKEN = 258,
    CONST_TOKEN = 259,
    VAR_TOKEN = 260,
    DEBUT_TOKEN = 261,
    FIN_TOKEN = 262,
    SI_TOKEN = 263,
    ALORS_TOKEN = 264,
    SINON_TOKEN = 265,
    FINSI_TOKEN = 266,
    REPETER_TOKEN = 267,
    JUSQUA_TOKEN = 268,
    TANTQUE_TOKEN = 269,
    FINTANTQUE_TOKEN = 270,
    POUR_TOKEN = 271,
    DeA_TOKEN = 272,
    FINPOUR_TOKEN = 273,
    LIRE_TOKEN = 274,
    ECRIRE_TOKEN = 275,
    OR_TOKEN = 276,
    AND_TOKEN = 277,
    PLUS_TOKEN = 278,
    MOINS_TOKEN = 279,
    MULT_TOKEN = 280,
    DIV_TOKEN = 281,
    VIR_TOKEN = 282,
    AFF_TOKEN = 283,
    INF_TOKEN = 284,
    INFEG_TOKEN = 285,
    SUP_TOKEN = 286,
    SUPEG_TOKEN = 287,
    DIFF_TOKEN = 288,
    EGALE_TOKEN = 289,
    PO_TOKEN = 290,
    PF_TOKEN = 291,
    ID_TOKEN = 292,
    INT_TOKEN = 293,
    FLOAT_TOKEN = 294,
    STRING_TOKEN = 295,
    INT_TYPE_TOKEN = 296,
    FLOAT_TYPE_TOKEN = 297,
    STRING_TYPE_TOKEN = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
