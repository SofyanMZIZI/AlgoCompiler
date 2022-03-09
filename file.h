#ifndef fichier_H_
#define fichier_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1

int isAlgoFile(char *pathFile) //tester si le fichier est d'extension ".algo"
{
    char *extension = ".algo";
    unsigned extL = strlen(extension);
    unsigned fileL = strlen(pathFile);
    
    for (size_t i=extL,j=fileL ; i>0 && j>0; i--,j--)
    {
        if (pathFile[j-1] != extension[i-1])
            return FALSE;
    }
    return TRUE;
}


FILE* openFile(char *pathFile)
{
    FILE* fichier = fopen(pathFile, "r");

    if (isAlgoFile(pathFile)==TRUE && fichier!=NULL)
    {
        fprintf(stdout, "Ouverture reussie.\n");
        return fichier;
    }
    else
    {
        fprintf(stderr, "ERREUR: file dosn't exist or ext file is not .algo\n");
        exit(-2);
    }
}



#endif
