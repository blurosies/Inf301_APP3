#include <stdio.h>
#ifndef ARBRES_H
#define ARBRES_H

/* Structure d'un noeud d'arbre */
struct noeud_s;
typedef struct noeud_s noeud;

/* Un arbre binaire est défini comme une référence vers le noeud racine de l'arbre.
 * Un arbre binaire vide est représenté par une référence NULL.
 * Un arbre binaire est une structure de données récursive.
 * Si il n'est pas vide, ses fils sont des arbres.
 */
typedef noeud* arbre;

struct noeud_s {
    char* valeur;
    arbre gauche;
    arbre droit;
};

struct element {
	arbre racine;
	struct element* suivant;
};
typedef struct element element_t;

struct file {
	element_t *tete;
};
typedef struct file file_t;

element_t * nv_element(arbre racine);

void ajoute_en_queue(file_t *file, arbre racine);

arbre defiler(file_t *file);

/* Crée un nouveau nœud et initialise ses champs à null */
noeud* nouveau_noeud(void);

/* Construit un arbre depuis le fichier ouvert f.
 * Fonction récursive (s'appelle elle-même pour la lecture des fils
 * gauche et droit).
 */
arbre lire_arbre(FILE *f);

int feuille(arbre racine);

/* Fonction d'affichage, à remplir */
void annexe_affiche(arbre racine , FILE *f);

void affiche_arbre(arbre *racine);


/* Macros pour de l'affichage uniquement si DEBUG est != 0 */
extern int DEBUG;

#define debug(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, ##__VA_ARGS__); } while (0)

#endif
