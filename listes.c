#include "listes.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* fichier à compléter au besoin */

void init_liste_vide(liste_t *L){
    L->tete=NULL;
}
/*
 * Supprime toutes les cellules d'une liste L, sans faire de free sur
 * L elle-même.
 */
void liberer_liste(liste_t *L){
    cellule_t *curr=L->tete;
    while (curr != NULL){
        L->tete=L->tete->suivant;
        free(curr);
        curr=L->tete;
    }
}


int ajouter_tete(liste_t *L, string c)
{   /* retourne 0 si OK, 1 sinon  */
    cellule_t *new=malloc(sizeof(cellule_t));
    new->val = malloc(strlen(c)+1);
    strcpy(new->val,c);
    new->suivant = L->tete;
    L->tete = new;
    return 1;
}

