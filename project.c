#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ------------Global variables------------ */

int count = 0, second = 4;

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
    for (int i = 0; i < count; i++)
    {
        lineBreak();
        printf("\n*-----------Produit number : %d -----------*", i + 1);
        lineBreak();
        printf("\nNom \t: %s", allProduit[i].nom);
        printf("\nPrix\t: %.2lf DHs", allProduit[i].prix);
        printf("\nPrix TTC: %.2lf DHs", allProduit[i].prix + (allProduit[i].prix * 0.15));
    }
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
        scanf("%s", &allProduit[count].code);

        printf("\nNom de produit\t: ");
        scanf("%s", &allProduit[count].nom);

        printf("\nQuantite de produit\t: ");
        scanf("%d", &allProduit[count].quantite);

        printf("\nPrix de produit\t: ");
        scanf("%f", &allProduit[count].prix);

        lineBreak();
        count++;
        a = 0;
        printf("\n***Produit ajoute!***");
        lineBreak();
        printf("\nVoulez-vous ajouter un autre medicament? ( 1 pour oui)\n");
        scanf("%d", &a);
    } while (a == 1);
}

void listerProduits(struct produit *allProduit)
{
    if (count == 0)
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
    for (int i = 0; i < count; i++)
    {
        strcpy(triProduit[i].nom, allProduit[i].nom);
        strcpy(triProduit[i].code, allProduit[i].code);
        triProduit[i].prix = allProduit[i].prix;
        triProduit[i].quantite = allProduit[i].quantite;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
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
    for (int i = 0; i < count; i++)
    {
        strcpy(triProduit[i].nom, allProduit[i].nom);
        strcpy(triProduit[i].code, allProduit[i].code);
        triProduit[i].prix = allProduit[i].prix;
        triProduit[i].quantite = allProduit[i].quantite;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
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
void menu(struct produit *allProduit)
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
        printf("\t3- Lister tout les produits .\n");
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
            listerProduits(allProduit);

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
    menu(&allProduit);
}
