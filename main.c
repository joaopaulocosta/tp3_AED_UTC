/** @brief NF16 - TP 3 – Listes chaînées
 *
 *
 *  Ce programme programme permettant la gestion d’un magasin et des rayons qui le constituent :
 *  un magasin est une entité contenant plusieurs rayons, et chaque rayon contient plusieurs produits.
 *
 * @author João Paulo Costa
 * @since 17/04/15
 * @version 1.0
 */

#include <stdio.h>
#include <string.h>
#include "tp3.h"


int main(){
    int menu = 0;
    T_Magasin * magasin = NULL;
    do{

        char nom[30], marque[30], qualite, nom_rayon[30];
        int quantite;
        float prix, prix_max, prix_min;
        printf("Menu\n");
        printf("1. Créer un magasin\n");
        printf("2. Ajouter un rayon au magasin\n");
        printf("3. Ajouter un produit dans un rayon\n");
        printf("4. Afficher les rayons du magasin\n");
        printf("5. Afficher les produits d'un rayon\n");
        printf("6. Retirer un produit\n");
        printf("7. Supprimer un rayon\n");
        printf("8. Rechercher un produit par prix\n");
        printf("9. Quitter \n");
        scanf("%d",&menu);
        //system("cls");
        switch(menu){
            case 1:
                if(magasin == NULL){
                    printf("Entrée avec le nom du magasin: \n");
                    scanf("%s", nom);
                    magasin = creerMagasin(nom);
                }
                else{
                    printf("Il est possible de créer soulement un magasin! \n");
                }
                break;
            case 2:
                //vérifier si déjà il y a un magasin cré
                if(magasin != NULL){
                    printf("Entrée avec le nom du rayon: \n");
                    scanf("%s", nom);
                    T_Rayon * rayon = creerRayon(nom);
                    //insere le rayon dans la file du magasin
                    if(ajouter_rayon(magasin, rayon)){
                            printf("l'opération a été réussi \n");
                    }
                    else{
                            printf("l'opération est annulée, car il y a un rayon avec ce nom. \n");
                    }
                }
                else{
                    printf("Pour créer un rayon est reauis un magasin cré!\n");
                }
                break;
            case 3:
                if(magasin == NULL)
                    printf("Pour créer un produit est reauis créer un magasin!\n");
                //vérifier si déjà il y a un rayon cré
                else if(magasin->premier == NULL){
                    printf("Pour créer un produit est reauis au moins un rayons!\n");
                }
                else{
                    printf("Entrée avec la marque du produit: \n");
                    scanf("%s", marque);
                    printf("Entrée avec le prix: \n");
                    scanf("%f", &prix);
                    scanf("%c", &qualite);
                    printf("Entrée avec la qualite: \n");
                    scanf("%c", &qualite);
                    printf("Entrée avec la quantite: \n");
                    scanf("%d", &quantite);

                    T_Produit * produit = creerProduit(marque, prix, qualite, quantite);

                    printf("Maintenant, entrée avec le nom du rayon: \n");
                    scanf("%s", nom_rayon);
                    T_Rayon * rayon = chercher_rayon(nom_rayon, magasin);
                    if(rayon == NULL){
                        printf("L'operation est annulée, il n'y a pas un rayon avec ce nom \n");
                        break;
                    }
                    else{
                       if(ajouterProduit(rayon, produit)){
                            printf("l'opération a été réussi \n");
                       }
                       else{
                            printf("l'opération est annulée, car il y a une rayonne avec ce nom. \n");
                       }
                    }
                }
                break;
            case 4:
                if(magasin == NULL)
                    printf("Pour effectuer cette opération est nécessaire créer un magasin!\n");
                //vérifier si déjà il y a un rayon cré
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette opération est nécessaire créer un rayon!\n");
                }
                else{
                    printf(" _________________________________________ \n");
                    printf("| Nome               | Nombre de produits | \n");
                    printf(" _________________________________________ \n");
                    afficherMagasin(magasin);
                    printf(" _________________________________________ \n");
                }
                break;
            case 5:
                if(magasin == NULL)
                    printf("Pour effectuer cette opération est nécessaire créer un magasin!\n");
                //vérifier si déjà il y a un rayon cré
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette opération est nécessaire créer un rayon!\n");
                }
                else{
                    printf("Entrée avec le nom du rayon: \n");
                    scanf("%s", nom_rayon);
                    T_Rayon * rayon= chercher_rayon(nom_rayon, magasin);
                    if(rayon == NULL){
                        printf("Il n'y a pas ce rayon. \n");
                        break;
                    }
                    else{
                        printf(" ____________________________________________________________________ \n");
                        printf("|       Marque       |   Prix   |  Qualité   |   Quantité en stock  | \n");
                        printf(" ____________________________________________________________________ \n");
                        afficherRayon(rayon);
                        printf(" ____________________________________________________________________ \n");
                    }
                }
                break;
            case 6:
                if(magasin == NULL)
                    printf("Pour effectuer cette opération est nécessaire créer un magasin!\n");
                //vérifier si déjà il y a un rayon cré
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette opération est nécessaire créer un rayon!\n");
                }
                else{
                    printf("Entrée avec le nom du rayon qui est le produit: \n");
                    scanf("%s", nom_rayon);
                    T_Rayon * rayon2 = chercher_rayon(nom_rayon, magasin);
                    if(rayon2 == NULL){
                        printf("Il n'y a pas ce rayon. \n");
                        break;
                    }
                    else{
                        printf("Maintenant entrée avec le nom du produit: \n");
                        scanf("%s", nom);
                        if(retirerProduit(rayon2, nom)){
                                printf("l'opération a été réussi \n");
                        }
                        else{
                            printf("l'opération est annulée, car le produit n'a été trouvé \n");
                        }
                    }
                }
                break;
            case 7:
                 if(magasin == NULL)
                    printf("Pour effectuer cette opération est nécessaire créer un magasin!\n");
                //vérifier si déjà il y a un rayon cré
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette opération est nécessaire créer un rayon!\n");
                }
                else{
                    printf("Entrée avec le nom du rayon qui sera supprimé: \n");
                    scanf("%s", nom_rayon);
                     if(supprimerRayon(magasin, nom_rayon)){
                                printf("l'opération a été réussi \n");
                        }
                        else{
                            printf("l'opération est annulée, car le produit n'a été trouvé \n");
                        }
                }
                break;
            case 8:
                 if(magasin == NULL)
                    printf("Pour effectuer cette opération est nécessaire créer un magasin!\n");
                //vérifier si déjà il y a un rayon cré
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette opération est nécessaire créer un rayons!\n");
                }
                else{
                    printf("Entrée avec le prix maximum: \n");
                    scanf("%f", &prix_max);
                    printf("Maintenant entrée avec le prix minimum: \n");
                    scanf("%f", &prix_min);
                    rechercheProduits( magasin, prix_min, prix_max);
                    break;
                }
            case 9:
                libererMagasin(magasin);
                break;
            default:
               printf("Option non valable\n");
        }

    }while (menu != 9);

    return 0;

}
