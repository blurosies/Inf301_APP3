#include "arbresphylo.h"
#include "arbres.h"
#include "listes.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// nb_esp et nb_carac sont égales a 0 par défaut si elles no sont pas fournies
void analyse_arbre(arbre racine, int *nb_esp, int *nb_carac){
       if (racine==NULL)
              return;
       if (feuille(racine))
              (*nb_esp)++;
       else
              (*nb_carac)++;
       analyse_arbre(racine->gauche,nb_esp,nb_carac);
       analyse_arbre(racine->droit,nb_esp,nb_carac);
       
}

/* ACTE II */
/* Recherche l'espece dans l'arbre. Modifie la liste passée en paramètre pour y
 * mettre les caractéristiques. Retourne 0 si l'espèce a été retrouvée, 1 sinon.
 */
int rechercher_espece(arbre racine, char *espece, liste_t *seq){

       if (racine==NULL)
              return 1;
       if ((strcmp(racine->valeur, espece) == 0)&& feuille(racine))
              return 0;

       if (rechercher_espece(racine->gauche, espece, seq) == 0)
              return 0;

       if (rechercher_espece(racine->droit, espece, seq) == 0) {
              ajouter_tete(seq, racine->valeur);
              return 0;
              }

       return 1;
}

//  Acte 3

/* Doit renvoyer 0 si l'espece a bien ete ajoutee, 1 sinon, et ecrire un
 * message d'erreur.
 */
int ajouter_espece(arbre *a, char *espece, cellule_t *seq) {
        if (seq != NULL && *a == NULL) { //creer un arbre contenant les carac de la sequence
            *a = nouveau_noeud();
            (*a)->valeur = seq->val;
            ajouter_espece(&(*a)->droit, espece, seq->suivant);

        } else if (seq != NULL && strcmp((*a)->valeur, seq->val) == 0) { 
            ajouter_espece(&(*a)->droit, espece, seq->suivant);

        } else if (seq != NULL && feuille(*a)) { 
            noeud* nv_arbre = nouveau_noeud();
            nv_arbre->valeur = (*a)->valeur;
            *a = nouveau_noeud();
            (*a)->valeur = seq->val;
            ajouter_espece(&(*a)->droit, espece, seq->suivant);
            (*a)->gauche = nv_arbre;

       } else if (seq != NULL){
            ajouter_espece(&(*a)->gauche, espece, seq);

       } else if (seq==NULL && *a == NULL) {
            *a = nouveau_noeud();
            (*a)->valeur = espece;

       } else {
            printf("Ne peut ajouter <%s>: possède les mêmes caractères que <%s>.\n", espece, (*a)->valeur);
            return 1;
        }
    
    return 0;
}

/* Doit afficher la liste des caractéristiques niveau par niveau, de gauche
 * à droite, dans le fichier fout.
 * Appeler la fonction avec fout=stdin pour afficher sur la sortie standard.
 */

void afficher_par_niveau(arbre racine, FILE *fout){ 
       if(racine==NULL){
              return;
       }
       int cpt=0, cpt_suivant=0 , cpt_arbre=1;
       file_t *stock=malloc(sizeof(file_t));
       element_t * temp =nv_element(racine);
       stock->tete=temp;
       while (stock->tete!=NULL && !feuille(stock->tete->racine)){
              arbre a=defiler(stock); 
              fprintf(fout,"%s " , a->valeur);
              cpt++;
              if (a->gauche!=NULL && !(feuille(a->gauche))){
                     ajoute_en_queue(stock, a->gauche);
                     cpt_suivant++;}
              if (a->droit!=NULL && !(feuille(a->droit))){
                     ajoute_en_queue(stock, a->droit);
                     cpt_suivant++;}
              if (cpt==cpt_arbre){
                     fprintf(fout,"\n");
              cpt_arbre=cpt_suivant;
              cpt_suivant=0;
              cpt=0;
              }
       }
       return;
}

// Acte 4

int ajouter_carac(arbre *a, char *carac, cellule_t *seq)
{
       printf ("<<<<< À faire: fonction ajouter_carac fichier " __FILE__ " >>>>>\n");
       return 0;
}
