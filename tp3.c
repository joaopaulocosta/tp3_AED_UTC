/** @brief NF16 - TP 3 – Listes chaînées
 *
 *
 *
 * @author João Paulo Costa
 * @since 17/04/15
 * @version 1.0
 */

#include <stdio.h>
#include <string.h>
#include "tp3.h"


/**
 * Function qui va créer la structure magasin
 *
 *@param nom string
 *@return une référence à la structure créée
 */
T_Magasin *creerMagasin(char * nom){
    T_Magasin * magasin =  malloc(sizeof(T_Magasin));
    magasin->nom = malloc(sizeof(strlen(nom)));
    strcpy(magasin->nom, nom);
    magasin->premier = NULL;
    return magasin;
}


/**
 * Function qui va créer une structure rayon
 *
 *@param nom string
 *@return une référence à la structure créée
 */
T_Rayon *creerRayon(char *nom){
    T_Rayon * rayon =  malloc(sizeof(T_Rayon));
    rayon->nom_rayon = malloc(sizeof(strlen(nom)));
    strcpy(rayon->nom_rayon, nom);
    rayon->nombre_produits = 0;
    rayon->premier = NULL;
    rayon->suivant = NULL;
    return rayon;
};

/**
 * Function qui va inserér le rayon dans la file de façon alphabétique
 *
 *@param magasin
 *@param rayon
 *@return 1 si la operation a été bien réussi et 0 si non
 */
int ajouter_rayon(T_Magasin * magasin, T_Rayon * rayon){
    if(magasin->premier == NULL){
        magasin->premier  = rayon;
        return 1;
    }
    else{
        T_Rayon * rayon_precedent = NULL;
        T_Rayon * rayon_courant = magasin->premier;
        while(1){

            int result = strcmp(rayon->nom_rayon, rayon_courant->nom_rayon);

            //verifie se déjà  il y a une rayonne avec le nouvelle nom
            if( result == 0){
                return 0 ;
            }
            else if(result < 0){
                if(rayon_precedent == NULL){
                    rayon->suivant = rayon_courant;
                    magasin->premier = rayon;
                }
                else{
                    rayon->suivant = rayon_courant;
                    rayon_precedent->suivant = rayon;
                }
                return 1;
            }
            else{
                if(rayon_courant->suivant == NULL){
                    rayon_courant->suivant = rayon;
                    return 1;
                }
            }
            rayon_precedent = rayon_courant;
            rayon_courant = rayon_courant->suivant;
        }
    }
};

/**
 * Function qui va chercher un rayon pour le nom
 *
 *@param nom
 *@param magasin
 *@return le adresse du rayon recherché, ou NULL si il n'a pas été trouve
 */
T_Rayon * chercher_rayon(char * nom, T_Magasin * magasin){

    T_Rayon * rayon_courant = magasin->premier;

    while(rayon_courant != NULL){
        //verifie se le nom du rayon courant est égal au nom du rayon recherché
        if(strcmp(nom, rayon_courant->nom_rayon) == 0){
            return rayon_courant ;
        }
        rayon_courant = rayon_courant->suivant;
    }
    return NULL;
}

/**
 * Function qui va afficher la file des rayons
 *
 *@param rayon
 */
void afficherMagasin(T_Magasin * magasin){
    T_Rayon * rayon = magasin->premier;
    while(rayon != NULL){
        int i = strlen(rayon->nom_rayon);
        printf("| %s", rayon->nom_rayon);
        for(; i < 19; i++)
            printf(" ");
        printf("| %d", rayon->nombre_produits );
        i = cont_dig(rayon->nombre_produits);
        for(; i < 19; i++)
            printf(" ");
        printf("|\n");

       rayon = rayon->suivant;
    }
}

/**
 * Function qui va créer une structure produit
 *
 *@param marque string
 *@param prix float
 *@param qualite char
 *@param quantite int
 *@return une référence à la structure créée
 */
T_Produit *creerProduit(char * marque, float prix, char qualite, int quantite){
    T_Produit * produit =(T_Produit *) malloc(sizeof(T_Produit));
    produit->marque = malloc(sizeof(strlen(marque)));
    strcpy(produit->marque, marque);
    produit->prix = prix;
    produit->qualite = qualite;
    produit->quantite_en_stock = quantite;
    produit->suivant = NULL;
    return produit;
}

/**
 * Function qui va compte le nombre de chiffres
 *
 *@param valor
 *@return le nombre de chirres du valeur de entrée
 */
int cont_dig(int valor){
    int contaDigitos = 0;
    if (valor == 0) contaDigitos = 1;
    else
            while (valor != 0)
           {
             contaDigitos = contaDigitos + 1;
               valor = valor / 10;
          }
       return contaDigitos;
}

/**
 * Function qui va inserér un produit dans la file des produits d'un rayon de façon alphabétique
 *
 *@param rayon
 *@param produit
 *@return 1 si la operation a été bien réussi et 0 si non
 */
int ajouterProduit(T_Rayon * rayon, T_Produit * produit){

     if(rayon->premier == NULL){
        rayon->premier  = produit;
        rayon->nombre_produits++;
        return 1;
    }
    else{
        T_Produit * produit_precedent = NULL;
        T_Produit * produit_courant = rayon->premier;
        while(1){

            int result = strcmp(produit->marque, produit_courant->marque);

            //verifie se déjà  il y a un produit avec la nouvelle marque
            if( result == 0){
                return 0 ;
            }
            else if(result < 0){
                if(produit_precedent == NULL){
                    produit->suivant = produit_courant;
                    rayon->premier = produit;
                }
                else{
                    produit->suivant = produit_courant;
                    produit_precedent->suivant = produit;
                }
                rayon->nombre_produits++;
                return 1;
            }
            else{
                if(produit_courant->suivant == NULL){
                    produit_courant->suivant = produit;
                    rayon->nombre_produits++;
                    return 1;
                }
            }
            produit_precedent = produit_courant;
            produit_courant = produit_courant->suivant;
        }
    }
}

/**
 * Function qui va afficher les produits d'un rayon
 *
 *@param rayon
 */
void afficherRayon(T_Rayon * rayon){
    T_Produit * produit_courant = rayon->premier;
    while(produit_courant != NULL){
        int i = strlen(produit_courant->marque);
        printf("| %s", produit_courant->marque);
        for(; i < 19; i++)
            printf(" ");
        printf("| %0.2f", produit_courant->prix);
        i = cont_dig((float)produit_courant->prix);
        for(; i < 6; i++)
            printf(" ");
        printf("| %c", produit_courant->qualite);
        i = 1;
        for(; i < 11; i++)
            printf(" ");
        printf("| %d", produit_courant->quantite_en_stock);
        i = cont_dig(produit_courant->quantite_en_stock);
        for(; i < 21; i++)
            printf(" ");
        printf("|\n");
        produit_courant = produit_courant->suivant;
    }
}

/**
 * Function qui va retirer un produit dans la file des produits d'un rayon
 *
 *@param rayon
 *@param nom_produit
 *@return 1 si la operation a été bien réussi et 0 si non
 */
int retirerProduit(T_Rayon *rayon, char* nom_produit){
    if(rayon->premier == NULL){
        return 0;
    }
    else{
        T_Produit * produit_precedent = NULL;
        T_Produit * produit_courant = rayon->premier;
        while(produit_courant != NULL){
            int result = strcmp(produit_courant->marque, nom_produit);
            if(result == 0){
                if(produit_precedent == NULL && produit_courant->suivant == NULL){
                    free(produit_courant);
                    rayon->premier = NULL;
                }
                else if(produit_precedent == NULL && produit_courant->suivant != NULL){
                    rayon->premier = produit_courant->suivant;
                    free(produit_courant);
                }
                else if(produit_precedent != NULL && produit_courant->suivant == NULL){
                    produit_precedent->suivant = NULL;
                    free(produit_courant);
                }
                else{
                    produit_precedent->suivant = produit_courant->suivant;
                    free(produit_courant);
                }
                rayon->nombre_produits--;
                return 1;

            }
            else if(result > 0){
                return 0;
            }
            else{
                produit_precedent = produit_courant;
                produit_courant = produit_courant->suivant;
            }
        }
        return 0;
    }
}


/**
 * Function qui va supprimer un rayon dans la file des rayons du magasin
 *
 *@param magasin
 *@param nom_rayon
 *@return 1 si la operation a été bien réussi et 0 si non
 */
int supprimerRayon(T_Magasin *magasin, char *nom_rayon){
    if(magasin->premier == NULL){
        return 0;
    }
    else{
        T_Rayon * rayon_precedent = NULL;
        T_Rayon * rayon_courant = magasin->premier;
        while(rayon_courant != NULL){
            int result = strcmp(rayon_courant->nom_rayon,nom_rayon);
            if(result == 0){
                if(rayon_precedent == NULL && rayon_courant->suivant == NULL){
                    magasin->premier = NULL;
                    libererRayon(rayon_courant);
                    free(rayon_courant);

                }
                else if(rayon_precedent == NULL && rayon_courant->suivant != NULL){
                    magasin->premier = rayon_courant->suivant;
                    libererRayon(rayon_courant);
                    free(rayon_courant);
                }
                 else if(rayon_precedent != NULL && rayon_courant->suivant == NULL){
                    rayon_precedent->suivant = NULL;
                    libererRayon(rayon_courant);
                    free(rayon_courant);
                }
                else{
                    rayon_precedent->suivant = rayon_courant->suivant;
                    libererRayon(rayon_courant);
                    free(rayon_courant);
                }
                return 1;
            }
            else if(result > 0){
                return 0;
            }
            else{
                rayon_precedent = rayon_courant;
                rayon_courant = rayon_courant->suivant;
            }
        }
        return 0;
    }
}

/**
 * Function qui va liberer la file des produits du rayon
 *
 *@param rayon
 */
void libererRayon(T_Rayon * rayon){
    T_Produit * produit;
    while(rayon->premier != NULL){
       produit = rayon->premier;
       rayon->premier = produit->suivant;
       free(produit);
    }
}

/**
 * Function qui va liberer la memoria de la structure magasin
 *
 *@param magasin
 */
void libererMagasin(T_Magasin * magasin){
    if(magasin != NULL){
        T_Rayon * rayon = magasin->premier;
        T_Rayon * rayon_aux;
        while(rayon != NULL){
            rayon_aux = rayon;
            rayon = rayon->suivant;
            libererRayon(rayon_aux);
            free(rayon_aux);
        }
        free(magasin);
    }

}

/**
 * Function qui va rechercher tous les produits qui sont entre la fourchette de prix
 *
 *@param rayon
 */
void rechercheProduits(T_Magasin *magasin, float prix_min, float prix_max){
    T_Rayon * rayon_courant = magasin->premier;
    T_Produit_Rayon * produit_rayon, * file_produit_rayon = NULL;
    while(rayon_courant != NULL){
        T_Produit * produit_courant = rayon_courant->premier;
        while(produit_courant != NULL){
            if(produit_courant->prix >= prix_min && produit_courant->prix <= prix_max){
                produit_rayon = malloc(sizeof(T_Produit_Rayon));
                produit_rayon->marque = malloc(sizeof(strlen(produit_courant->marque)));
                strcpy(produit_rayon->marque,produit_courant->marque);
                produit_rayon->nom_rayon = malloc(sizeof(strlen(rayon_courant->nom_rayon)));
                strcpy(produit_rayon->nom_rayon, rayon_courant->nom_rayon);
                produit_rayon->prix = produit_courant->prix;
                produit_rayon->qualite = produit_courant->qualite;
                produit_rayon->quantite_en_stock = produit_courant->quantite_en_stock;
                produit_rayon->suivant = NULL;


                file_produit_rayon = ajouterProduit_Rayon(file_produit_rayon, produit_rayon);
            }
            produit_courant = produit_courant->suivant;

        }

        rayon_courant = rayon_courant->suivant;
    }
    afficherProduit_Rayon(file_produit_rayon);
}


/**
 * Function qui va inserir un element de façon alphabétique dans une file les elements de la structure
 * T_Produit_Rayon qui sont utilizés dans la fonction rechercheProduits
 *
 *@param file_produit_rayon
 *@param produit_rayon
 *@return une file avec les elements ordenné de façon alphabétique
 */
T_Produit_Rayon *  ajouterProduit_Rayon(T_Produit_Rayon * file_produit_rayon, T_Produit_Rayon * produit_rayon){

    if(file_produit_rayon == NULL){
        return produit_rayon;
    }
    else{
        T_Produit_Rayon * produit_rayon_precedent = NULL;
        T_Produit_Rayon * produit_rayon_courant = file_produit_rayon;
        while(produit_rayon_courant != NULL){
            int result = strcmp(produit_rayon_courant->marque, produit_rayon->marque);
            if(result < 0 && produit_rayon_courant->suivant == NULL){
                produit_rayon_courant->suivant = produit_rayon;
                break;
            }
            else if(result < 0 && produit_rayon_courant->suivant != NULL ){
                produit_rayon_precedent = produit_rayon_courant;
                produit_rayon_courant = produit_rayon_courant->suivant;
            }
            else if(result > 0 && produit_rayon_precedent == NULL){
                produit_rayon->suivant = produit_rayon_courant;
                file_produit_rayon = produit_rayon;
                break;
            }
             else if(result > 0 && produit_rayon_precedent != NULL){
                produit_rayon->suivant = produit_rayon_courant;
                produit_rayon_precedent->suivant = produit_rayon;
                break;
            }
        }
    }
    return file_produit_rayon;
}


/**
 * Function qui va afficher la file de elements utilisés dans la recherche de prix
 *
 *@param file_produit_rayon
 */
void afficherProduit_Rayon(T_Produit_Rayon * file_produit_rayon){

    printf(" ________________________________________________________________________\n");
    printf("|      Marque        |   Prix   | Quantité en Stock |        Rayon       |\n");
    printf(" ________________________________________________________________________\n");

    while(file_produit_rayon != NULL){
        printf("| %s", file_produit_rayon->marque);
        int i = strlen(file_produit_rayon->marque);
        for(; i < 19; i++)
            printf(" ");
        printf("| %0.2f", file_produit_rayon->prix);
        i = cont_dig((float)file_produit_rayon->prix);
        for(; i < 6; i++)
            printf(" ");
         printf("| %d", file_produit_rayon->quantite_en_stock);
        i = cont_dig(file_produit_rayon->quantite_en_stock);
        for(; i < 18; i++)
            printf(" ");
        printf("| %s", file_produit_rayon->nom_rayon);
        i = strlen(file_produit_rayon->nom_rayon);
        for(; i < 19; i++)
            printf(" ");
        printf("|\n");
        file_produit_rayon = file_produit_rayon->suivant;
    }
    printf(" ________________________________________________________________________\n");
}
