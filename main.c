/** @brief NF16 - TP 3 � Listes cha�n�es
 *
 *
 *  Ce programme programme permettant la gestion d�un magasin et des rayons qui le constituent :
 *  un magasin est une entit� contenant plusieurs rayons, et chaque rayon contient plusieurs produits.
 *
 * @author Jo�o Paulo Costa
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
        printf("1. Cr�er un magasin\n");
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
                    printf("Entr�e avec le nom du magasin: \n");
                    scanf("%s", nom);
                    magasin = creerMagasin(nom);
                }
                else{
                    printf("Il est possible de cr�er soulement un magasin! \n");
                }
                break;
            case 2:
                //v�rifier si d�j� il y a un magasin cr�
                if(magasin != NULL){
                    printf("Entr�e avec le nom du rayon: \n");
                    scanf("%s", nom);
                    T_Rayon * rayon = creerRayon(nom);
                    //insere le rayon dans la file du magasin
                    if(ajouter_rayon(magasin, rayon)){
                            printf("l'op�ration a �t� r�ussi \n");
                    }
                    else{
                            printf("l'op�ration est annul�e, car il y a un rayon avec ce nom. \n");
                    }
                }
                else{
                    printf("Pour cr�er un rayon est reauis un magasin cr�!\n");
                }
                break;
            case 3:
                if(magasin == NULL)
                    printf("Pour cr�er un produit est reauis cr�er un magasin!\n");
                //v�rifier si d�j� il y a un rayon cr�
                else if(magasin->premier == NULL){
                    printf("Pour cr�er un produit est reauis au moins un rayons!\n");
                }
                else{
                    printf("Entr�e avec la marque du produit: \n");
                    scanf("%s", marque);
                    printf("Entr�e avec le prix: \n");
                    scanf("%f", &prix);
                    scanf("%c", &qualite);
                    printf("Entr�e avec la qualite: \n");
                    scanf("%c", &qualite);
                    printf("Entr�e avec la quantite: \n");
                    scanf("%d", &quantite);

                    T_Produit * produit = creerProduit(marque, prix, qualite, quantite);

                    printf("Maintenant, entr�e avec le nom du rayon: \n");
                    scanf("%s", nom_rayon);
                    T_Rayon * rayon = chercher_rayon(nom_rayon, magasin);
                    if(rayon == NULL){
                        printf("L'operation est annul�e, il n'y a pas un rayon avec ce nom \n");
                        break;
                    }
                    else{
                       if(ajouterProduit(rayon, produit)){
                            printf("l'op�ration a �t� r�ussi \n");
                       }
                       else{
                            printf("l'op�ration est annul�e, car il y a une rayonne avec ce nom. \n");
                       }
                    }
                }
                break;
            case 4:
                if(magasin == NULL)
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un magasin!\n");
                //v�rifier si d�j� il y a un rayon cr�
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un rayon!\n");
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
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un magasin!\n");
                //v�rifier si d�j� il y a un rayon cr�
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un rayon!\n");
                }
                else{
                    printf("Entr�e avec le nom du rayon: \n");
                    scanf("%s", nom_rayon);
                    T_Rayon * rayon= chercher_rayon(nom_rayon, magasin);
                    if(rayon == NULL){
                        printf("Il n'y a pas ce rayon. \n");
                        break;
                    }
                    else{
                        printf(" ____________________________________________________________________ \n");
                        printf("|       Marque       |   Prix   |  Qualit�   |   Quantit� en stock  | \n");
                        printf(" ____________________________________________________________________ \n");
                        afficherRayon(rayon);
                        printf(" ____________________________________________________________________ \n");
                    }
                }
                break;
            case 6:
                if(magasin == NULL)
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un magasin!\n");
                //v�rifier si d�j� il y a un rayon cr�
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un rayon!\n");
                }
                else{
                    printf("Entr�e avec le nom du rayon qui est le produit: \n");
                    scanf("%s", nom_rayon);
                    T_Rayon * rayon2 = chercher_rayon(nom_rayon, magasin);
                    if(rayon2 == NULL){
                        printf("Il n'y a pas ce rayon. \n");
                        break;
                    }
                    else{
                        printf("Maintenant entr�e avec le nom du produit: \n");
                        scanf("%s", nom);
                        if(retirerProduit(rayon2, nom)){
                                printf("l'op�ration a �t� r�ussi \n");
                        }
                        else{
                            printf("l'op�ration est annul�e, car le produit n'a �t� trouv� \n");
                        }
                    }
                }
                break;
            case 7:
                 if(magasin == NULL)
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un magasin!\n");
                //v�rifier si d�j� il y a un rayon cr�
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un rayon!\n");
                }
                else{
                    printf("Entr�e avec le nom du rayon qui sera supprim�: \n");
                    scanf("%s", nom_rayon);
                     if(supprimerRayon(magasin, nom_rayon)){
                                printf("l'op�ration a �t� r�ussi \n");
                        }
                        else{
                            printf("l'op�ration est annul�e, car le produit n'a �t� trouv� \n");
                        }
                }
                break;
            case 8:
                 if(magasin == NULL)
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un magasin!\n");
                //v�rifier si d�j� il y a un rayon cr�
                else if(magasin->premier == NULL){
                    printf("Pour effectuer cette op�ration est n�cessaire cr�er un rayons!\n");
                }
                else{
                    printf("Entr�e avec le prix maximum: \n");
                    scanf("%f", &prix_max);
                    printf("Maintenant entr�e avec le prix minimum: \n");
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
