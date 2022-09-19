#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ------------Global variables------------ */

int countProduit = 0, second = 4, countAchat=0;


/* ----------------Structers--------------- */

struct produit
{
    int quantite;
    float prix;
    char nom[80], code[10];
};

struct achat
{
    int quantite;
    float prix, prixTTC;
    char nom[80], code[10];
    struct tm dateAchat;
   // struct tm tm = *localtime(&t);
};

/* ----------------Function---------------- */

void lineBreak()
{
    printf("\n*-----------------------------------------*");
}

void cleanConsole()
{
    system("cls");
}

void continu()
{
    printf("\nAppuyez sur une touche...");
    getch();
}

// void printProduit(struct produit *allProduit)
// {
//     for (int i = 0; i < count; i++)
//     {
//         lineBreak();
//         printf("\n*-----------Produit number : %d -----------*", i + 1);
//         lineBreak();
//         printf("\nLe code de produit\t: %s", allProduit[i].code);
//         printf("\nLe nom de produit\t: %s", allProduit[i].nom);
//         printf("\nLa quantite de produit\t: %d", allProduit[i].quantite);
//         printf("\nLe prix de produit\t: %lf", allProduit[i].prix);
//     }
// }

void printProduit(struct produit *allProduit)
{
    for (int i = 0; i < countProduit; i++)
    {
        lineBreak();
        printf("\n*-----------Produit numero : %d -----------*", i + 1);
        lineBreak();
        printf("\nNom \t: %s", allProduit[i].nom);
        printf("\nPrix\t: %.2lf DHs", allProduit[i].prix);
        printf("\nPrix TTC: %.2lf DHs", allProduit[i].prix + (allProduit[i].prix * 0.15));
        printf("\nQuantite: %d", allProduit[i].quantite );
    }
}

void printAchat(struct achat *allAchat)
{
        lineBreak();
        printf("\n*-----------Achat numero : %d -----------*", countAchat);
        lineBreak();
        printf("\nNom \t: %s", allAchat[countAchat-1].nom);
        printf("\nCode\t: %s", allAchat[countAchat-1].code);
        printf("\nPrix\t: %.2lf DHs", allAchat[countAchat-1].prix);
        printf("\nPrix TTC: %.2lf DHs", allAchat[countAchat-1].prixTTC);
        printf("\nDate: %d-%02d-%02d %02d:%02d:%02d", allAchat[countAchat-1].dateAchat.tm_year+1900,allAchat[countAchat-1].dateAchat.tm_mon+1,allAchat[countAchat-1].dateAchat.tm_mday,allAchat[countAchat-1].dateAchat.tm_hour,allAchat[countAchat-1].dateAchat.tm_min,allAchat[countAchat-1].dateAchat.tm_sec);
        getch();

}

void ajouterProduit(struct produit *allProduit)
{
    int a;
    do
    {

        cleanConsole();
        lineBreak();
        printf("\n*--------------Ajouter Produit------------*");
        lineBreak();

        printf("\nCode de produit\t: ");
        scanf("%s", &allProduit[countProduit].code);

        printf("\nNom de produit\t: ");
        scanf("%s", &allProduit[countProduit].nom);

        printf("\nQuantite de produit\t: ");
        scanf("%d", &allProduit[countProduit].quantite);

        printf("\nPrix de produit\t: ");
        scanf("%f", &allProduit[countProduit].prix);

        lineBreak();
        countProduit++;
        a = 0;
        printf("\n***\tProduit ajoute! \t***");
        lineBreak();
        printf("\nVoulez-vous ajouter un autre medicament? ( 1 pour oui)\n");
        scanf("%d", &a);
    } while (a == 1);
}

void acheterProduit(struct produit *allProduit, struct achat *allAchat,time_t *t)
{
    char code[20];
    int quantite, indice;
    printf("Saisir la code de produit : ");
    scanf("%s",code);
    printf("Saisir la quantite de produit : ");
    scanf("%s",&quantite);
    indice=updateProduit(allProduit,code,quantite);

    if(indice>=0){

        strcpy(allAchat[countAchat].code,allProduit[indice].code);
        strcpy(allAchat[countAchat].nom,allProduit[indice].nom);
        allAchat[countAchat].prix=allProduit[indice].prix;
        allAchat[countAchat].prixTTC=allProduit[indice].prix+ (allProduit[indice].prix * 0.15);
        allAchat[countAchat].quantite=quantite;
        allAchat[countAchat].dateAchat=*localtime(&t);

        countAchat++;
        printAchat(allAchat);

    }else{
        printf("Aucun produit par se code .");
        getch();
    }
}

int updateProduit(struct produit *allProduit,char code[20], int quantit)
{
    int x=-1;
    for(int i=0;i<countProduit;i++){
        if(strcmp(allProduit[i].code,code)==0){
            x=i;
        }
    }
    if(x>=0){
        allProduit[x].quantite=allProduit[x].quantite-quantit;
    }
     return x;
}

void listerProduits(struct produit *allProduit)
{
    if (countProduit == 0)
    {
        cleanConsole();
        lineBreak();
        printf("\n*--------------Aucun Produit -------------*");
        lineBreak();
        continu();
    }
    else
    {
        int a;
        cleanConsole();
        lineBreak();
        printf("\n*-------------List des Produit----------------*");
        lineBreak();
        printf("\n\t1- Selon l ordre alphabetique croissant du nom .\n");
        printf("\t2- Selon l ordre decroissant du prix .\n");
        printf("*-----------------------------------------*\n");
        printf("Choisir un numero : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            listerProduitsParNom(allProduit);
            break;
        case 2:
            listerProduitsParPrix(allProduit);
            break;
        }
    }
}

void listerProduitsParPrix(struct produit *allProduit)
{
    cleanConsole();
    struct produit triProduit[100];
    struct produit temp;
    for (int i = 0; i < countProduit; i++)
    {
        strcpy(triProduit[i].nom, allProduit[i].nom);
        strcpy(triProduit[i].code, allProduit[i].code);
        triProduit[i].prix = allProduit[i].prix;
        triProduit[i].quantite = allProduit[i].quantite;
    }

    for (int i = 0; i < countProduit - 1; i++)
    {
        for (int j = i + 1; j < countProduit; j++)
        {
            if (triProduit[i].prix < triProduit[j].prix)
            {
                // copie le produit dans un variable temporaire
                strcpy(temp.nom, triProduit[i].nom);
                strcpy(temp.code, triProduit[i].code);
                temp.prix = triProduit[i].prix;
                temp.quantite = triProduit[i].quantite;
                // changer la variable
                strcpy(triProduit[i].nom, triProduit[j].nom);
                strcpy(triProduit[i].code, triProduit[j].code);
                triProduit[i].prix = triProduit[j].prix;
                triProduit[i].quantite = triProduit[j].quantite;
                // changer la variable
                strcpy(triProduit[j].nom, temp.nom);
                strcpy(triProduit[j].code, temp.code);
                triProduit[j].prix = temp.prix;
                triProduit[j].quantite = temp.quantite;
            }
        }
    }

    printProduit(triProduit);

    lineBreak();
    lineBreak();
    continu();
}

void listerProduitsParNom(struct produit *allProduit)
{

    cleanConsole();
    struct produit triProduit[100];
    struct produit temp;
    for (int i = 0; i < countProduit; i++)
    {
        strcpy(triProduit[i].nom, allProduit[i].nom);
        strcpy(triProduit[i].code, allProduit[i].code);
        triProduit[i].prix = allProduit[i].prix;
        triProduit[i].quantite = allProduit[i].quantite;
    }

    for (int i = 0; i < countProduit - 1; i++)
    {
        for (int j = i + 1; j < countProduit; j++)
        {
            if (triProduit[i].nom[0] > triProduit[j].nom[0])
            {
                // copie le produit dans un variable temporaire
                strcpy(temp.nom, triProduit[i].nom);
                strcpy(temp.code, triProduit[i].code);
                temp.prix = triProduit[i].prix;
                temp.quantite = triProduit[i].quantite;
                // changer la variable
                strcpy(triProduit[i].nom, triProduit[j].nom);
                strcpy(triProduit[i].code, triProduit[j].code);
                triProduit[i].prix = triProduit[j].prix;
                triProduit[i].quantite = triProduit[j].quantite;
                // changer la variable
                strcpy(triProduit[j].nom, temp.nom);
                strcpy(triProduit[j].code, temp.code);
                triProduit[j].prix = temp.prix;
                triProduit[j].quantite = temp.quantite;
            }
        }
    }

    printProduit(triProduit);

    lineBreak();
    lineBreak();
    continu();
}
void menu(struct produit *allProduit, struct achat *allAchat, time_t *t)
{
    int a;
    do
    {
        cleanConsole();
        lineBreak();
        printf("\n*------------------Menu-------------------*");
        lineBreak();
        printf("\n\t1- Ajouter produit .\n");
        printf("\t2- Lister tout les produits .\n");
        printf("\t3- Acheter un produit .\n");
        printf("\t4- Exit .\n");
        printf("*-----------------------------------------*\n");
        printf("Choisir un numero : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            ajouterProduit(allProduit);
            break;
        case 2:
            listerProduits(allProduit);
            break;
        case 3:
            acheterProduit(allProduit,allAchat,t);
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    } while (1);
}

void main()
{
    struct produit allProduit[100];
    struct achat allAchat[100];
    time_t t = time(NULL);

    menu(&allProduit,&allAchat,&t);
}
