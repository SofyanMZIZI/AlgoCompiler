#include "analyse.h"
#include "syntax.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sementique.h"
int i=0;


int Y =0;
void Symbole_Suiv()
{
    l = l -> smbl_suiv;
}

void table_id()
{
	switch(tabTOKEN[l->smbl.CODE])
	{
		case  ALGO_TOKEN :
			Symbole_Suiv();
			store_prog();
			break;
		
		case  CONST_TOKEN :
			Symbole_Suiv();
			store_const();
			break;

		case VAR_TOKEN :
			Symbole_Suiv();
			store_var();
			break ;

		default :
			break;
	}
}

void store_prog(node *l)
{
    while((tabTOKEN[l->smbl.CODE]!=CONST_TOKEN)
			&&(tabTOKEN[l->smbl.CODE]!=VAR_TOKEN)
			&&(tabTOKEN[l->smbl.CODE]!=DEBUT_TOKEN))
	{
		if(tabTOKEN[l->smbl.CODE==ID_TOKEN)
		{
			strcpy((TAB_IDFS+i)->NOM,l->smbl.NOM);
			(TAB_IDFS+i)->TIDF=TALGO;
			i++;
		}
		Symbole_Suiv();
	}
	table_id(l);
}


void store_const()
{
	while(	(tabTOKEN[l->smbl.CODE]!=ALGO_TOKEN)
			&&(tabTOKEN[l->smbl.CODE]!=VAR_TOKEN)
			&&(tabTOKEN[l->smbl.CODE]!=DEBUT_TOKEN))
	{
		if(tabTOKEN[l->smbl.CODE]==ID_TOKEN)
		{
			strcpy((TAB_IDFS+i)->NOM,l->smbl.NOM);
			(TAB_IDFS+i)->TIDF=TCONST;
			Symbole_Suiv();
			if(tabTOKEN[l->smbl.CODE]==AFF_TOKEN)
			{
				Symbole_Suiv();
				(TAB_IDFS+i)->value=head->data->val;
			}
			i++;
		}
		Symbole_Suiv();
	}
	table_id(l);
}
                    
void store_var()
{
	while(	(tabTOKEN[l->smbl.CODE]!=CONST_TOKEN)
			&&(tabTOKEN[l->smbl.CODE]!=ALGORITHME_TOKEN)
			&&(tabTOKEN[l->smbl.CODE]!=DEBUT_TOKEN))
	{
		if(tabTOKEN[l->smbl.CODE]==ID_TOKEN){
             regle2();
			strcpy((TAB_IDFS+i)->NOM,l->smbl.NOM);

			(TAB_IDFS+i)->TIDF=TVAR;
			i++;
		}
		Symbole_Suiv();
	}
	table_id(l);
}

void affich()
{
	regle1();
	regle3();
	regle4();
	regle5();
	if(Y==0)
		printf("*******************Compilation sementique succeed*******************\n");
	else
		printf("*******************Compilation sementique erreur*******************\n");
}

void regle1()
{ 
	//chercher  identificateur titi non déclaré
    smbl=smbl_sem;
	while(tabTOKEN[l->smbl.CODE]!=DEBUT_TOKEN)
	{
		if(tabTOKEN[l->smbl.CODE]==ID_TOKEN)
			check();
		Symbole_Suiv();
	}
}
void check()
{
	int r=0; 

	for (int i = 0; i <NbrIDFS ; ++i)
		if(strcmp(head->data->nom,(TAB_IDFS+i)->NOM)==0)
            r=1;

	if(r==0)
	{
		printf("%s ---->Erreur declaration hors CONST and VAR  \n",head->data->nom);
		Y=1;
	}
}
void regle2()
{ 
	// chercher si il a une double déclaration
	int r=0;
	for (int i = 0; i <NbrIDFS ; ++i)
		if(strcmp(head->data->nom,(TAB_IDFS+i)->NOM)==0)
			r=1;
	
	if(r==1)
	{
		printf("%s------>erreur variable deja declarer\n ",head->data->nom);
		Y=1;
	}
}

void regle3()
{
    smbl=smbl_sem;
	while(tabTOKEN[l->smbl.CODE]!=DEBUT_TOKEN)
		Symbole_Suiv();

	while(tabTOKEN[l->smbl.CODE]!=FIN_TOKEN)
	{
		if(tabTOKEN[l->smbl.CODE]==ID_TOKEN)
		{
			int r=0;
			for (int i = 0; i <NbrIDFS ; ++i)
				if(strcmp(head->data->nom,(TAB_IDFS+i)->NOM)==0)
					r=1;

			if(r==0)
			{
				printf("%s ---->Erreur Variable non declarer  \n",l->smbl.NOM);
				Y=1;
			}
		}
		Symbole_Suiv();
	}
}


void regle4()
{
    smbl=smbl_sem;
	while(tabTOKEN[l->smbl.CODE]!=DEBUT_TOKEN)
		Symbole_Suiv();
	
	while(tabTOKEN[l->smbl.CODE]!=FIN_TOKEN)
	{
		if(tabTOKEN[l->smbl.CODE]==ID_TOKEN)
		{
			for (int i = 0; i <NbrIDFS ; ++i)
			{
				if((TAB_IDFS+i)->TIDF==1)
				{
					Symbole_Suiv();

					if(tabTOKEN[l->smbl.CODE]==AFF_TOKEN)
					{
						Symbole_Suiv();
						if(l->smbl.NOM!=(TAB_IDFS+i)->value)
						{
							printf("%s------>Erreur : Une constante ne peut changer de valeur dans le programme\n");
							Y=1;
						}
					}
				}
			}
		}
	}
}


if(tabTOKEN[l->smbl.CODE]==READ_TOKEN)
{
	Symbole_Suiv();
	Symbole_Suiv();
	if(tabTOKEN[l->smbl.CODE]==ID_TOKEN)
	{
		for (int i = 0; i <NbrIDFS ; ++i)
		{
			if(strcmp(l->smbl.NOM,(TAB_IDFS+i)->NOM)==0)
			{
				if((TAB_IDFS+i)->TIDF==1)
				{
					printf("%s ----------> constante	ne	peut changer	de	valeur a partire de READ\n",l->smbl.NOM);
					Y=1;
				}
			}
		}
	}
}


Symbole_Suiv();
{
}


void regle5()
{
	head=head_sem ;

	while(tabTOKEN[l->smbl.CODE]!=DEBUT_TOKEN)
		Symbole_Suiv();
	while(tabTOKEN[l->smbl.CODE]!=FIN_TOKEN)
	{
		if(tabTOKEN[l->smbl.CODE==ID_TOKEN)
			for (int i = 0; i <NbrIDFS ; ++i)
				if(strcmp(l->smbl.NOM,(TAB_IDFS+i)->NOM)==0)
					if((TAB_IDFS+i)->TIDF==0)
					{
						printf("%s ----------> nom	de	programme	non	autorisé\n",head->data->nom);
						Y=1;
					}
		Symbole_Suiv();
	}
}
