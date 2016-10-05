
/**
 *
 *
 *
 * @author Joao Paulo Costa
 * @since 17/04/15
 * @version 1.0
 */

/**
* @brief Structure qui stocke les donnees necessaires a la recherche de prix
*/
typedef struct{
    char * marque;
    float prix;
    char qualite;
    int quantite_en_stock;
    char * nom_rayon;
    struct T_Produit * suivant;
}T_Produit_Rayon;


/**
* @brief Structure qui stocke les donnees refere a un produit
*/
typedef struct{
    char * marque;
    float prix;
    char qualite;
    int quantite_en_stock;
    struct T_Produit * suivant;
}T_Produit;

/**
* @brief Structure qui stocke les donnees de un rayon et de ses produits
*/
typedef struct{
   char * nom_rayon;
   int nombre_produits;
   struct T_produit * premier;
   struct T_Rayon * suivant;
}T_Rayon;

/**
* @brief Structure principal, elle stocke les donnees du magasin,
*/
typedef struct{
    char * nom;
    struct T_Rayon * premier;
}T_Magasin;


/** Prototypes **/

T_Magasin *creerMagasin(char *nom);
T_Rayon *creerRayon(char *nom);
T_Produit *creerProduit(char * marque, float prix, char qualite, int quantite);
T_Rayon * chercher_rayon(char * nom, T_Magasin * magasin);

void afficherMagasin(T_Magasin * magasin);
void afficherRayon(T_Rayon * rayon);
void afficherProduit_Rayon(T_Produit_Rayon * file_produit_rayon);

int ajouter_rayon(T_Magasin * magasin, T_Rayon * rayon);
int ajouterProduit(T_Rayon * rayon, T_Produit * produit);
T_Produit_Rayon *  ajouterProduit_Rayon(T_Produit_Rayon * file_produit_rayon, T_Produit_Rayon * produit_rayon);

int retirerProduit(T_Rayon *rayon, char* nom_produit);
int supprimerRayon(T_Magasin *magasin, char *nom_rayon);

int cont_dig(int valor);
void rechercheProduits(T_Magasin *magasin, float prix_min, float prix_max);


void libererMagasin(T_Magasin * magasin);
void libererRayon(T_Rayon * rayon);
