#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ------------Global variables------------ */

int countProduit = 0, second = 4, countAchat = 0;

/* ----------------Structers--------------- */

struct produit
{
    int quantite;
    float prix;
    char nom[80], code[20];
};

struct achat
{
    int quantite;
    float prix, prixTTC;
    char nom[80], code[10];
    int year, month, day;
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

void printProduits(struct produit *allProduit)
{
    for (int i = 0; i < countProduit; i++)
    {
        lineBreak();
        printf("\n*-----------Produit numero : %d -----------*", i + 1);
        lineBreak();
        printf("\nNom \t: %s", allProduit[i].nom);
        printf("\nPrix\t: %.2lf DHs", allProduit[i].prix);
        printf("\nPrix TTC: %.2lf DHs", allProduit[i].prix + (allProduit[i].prix * 0.15));
        printf("\nQuantite: %d", allProduit[i].quantite);
    }
}

void printProduit(struct achat *allProduit, int x)
{
    lineBreak();
    printf("\n*-----------Produit numero : %d -----------*", x + 1);
    lineBreak();
    printf("\nNom \t: %s", allProduit[x].nom);
    printf("\nCode \t: %s", allProduit[x].code);
    printf("\nPrix\t: %.2lf DHs", allProduit[x].prix);
    printf("\nPrix TTC: %.2lf DHs", allProduit[x].prix + (allProduit[x].prix * 0.15));
    printf("\nQuantite: %d", allProduit[x].quantite);
    getch();
}

void printEtat(struct produit *allProduit, int x)
{
    if (x > 0)
    {
        for (int i = 0; i < x - 1; i++)
        {
            lineBreak();
            printf("\n*-----------Produit numero : %d -----------*", i + 1);
            lineBreak();
            printf("\nNom \t: %s", allProduit[i].nom);
            printf("\nPrix\t: %.2lf DHs", allProduit[i].prix);
            printf("\nPrix TTC: %.2lf DHs", allProduit[i].prix + (allProduit[i].prix * 0.15));
            printf("\nQuantite: %d", allProduit[i].quantite);
        }
    }
    else
    {
        system("color 4");
        printf("Aucun produit !!");
    }
}

void printAchat(struct achat *allAchat)
{
    lineBreak();
    printf("\n*-----------Achat numero : %d -----------*", countAchat);
    lineBreak();
    printf("\nNom \t: %s", allAchat[countAchat - 1].nom);
    printf("\nCode\t: %s", allAchat[countAchat - 1].code);
    printf("\nPrix\t: %.2lf DHs", allAchat[countAchat - 1].prix);
    printf("\nPrix TTC: %.2lf DHs", allAchat[countAchat - 1].prixTTC);
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

        printf("Nom de produit\t: ");
        scanf("%s", &allProduit[countProduit].nom);

        printf("Quantite de produit\t: ");
        scanf("%d", &allProduit[countProduit].quantite);

        printf("Prix de produit\t: ");
        scanf("%f", &allProduit[countProduit].prix);

        lineBreak();
        countProduit++;
        a = 0;
        printf("\n     *  *  *  Produit ajoute!  *  *  *");
        lineBreak();
        printf("\nVoulez-vous ajouter un autre medicament? ( 1 pour oui)\n");
        scanf("%d", &a);
    } while (a == 1);
}

void acheterProduit(struct produit *allProduit, struct achat *allAchat)
{
    if (countProduit == 0)
    {
        system("color 4");
        cleanConsole();
        lineBreak();
        printf("\n*--------------Aucun Produit -------------*");
        lineBreak();
        continu();
    }
    else
    {
        char code[20];
        int quantite, indice = -1;
        printf("Saisir la code de produit : ");
        scanf("%s", code);
        printf("Saisir la quantite de produit : ");
        scanf("%d", &quantite);

        for (int i = 0; i < countProduit; i++)
        {
            if (strcmp(allProduit[i].code, code) == 0)
            {
                indice = i;
            }
        }
        if (indice >= 0)
        {
            if (quantite > allProduit[indice].quantite)
            {
                cleanConsole();
                system("color 4");
                lineBreak();
                printf("\nQauntite insuffisant !!");
                lineBreak();
                getch();
            }
            else
            {
                allProduit[indice].quantite -= quantite;

                time_t seconds = time(NULL);
                struct tm *current_time = localtime(&seconds);

                strcpy(allAchat[countAchat].code, allProduit[indice].code);
                strcpy(allAchat[countAchat].nom, allProduit[indice].nom);
                allAchat[countAchat].prix = allProduit[indice].prix;
                allAchat[countAchat].prixTTC = allProduit[indice].prix + (allProduit[indice].prix * 0.15);
                allAchat[countAchat].quantite = quantite;
                allAchat[countAchat].year = current_time->tm_year + 1900;
                allAchat[countAchat].month = current_time->tm_mon + 1;
                allAchat[countAchat].day = current_time->tm_mday;
                countAchat++;
                printAchat(allAchat);
            }
        }
        else
        {
            cleanConsole();
            system("color 4");
            printf("Aucun produit par se code .");
            continu();
        }
    }
}

void listerProduits(struct produit *allProduit)
{
    if (countProduit == 0)
    {
        system("color 4");
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
                temp = triProduit[i];
                triProduit[i] = triProduit[j];
                triProduit[j] = temp;
            }
        }
    }

    printProduits(triProduit);

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
                temp = triProduit[i];
                triProduit[i] = triProduit[j];
                triProduit[j] = temp;
            }
        }
    }

    printProduits(triProduit);

    lineBreak();
    lineBreak();
    continu();
}

void etatProduit(struct produit *allProduit)
{
    if (countProduit == 0)
    {
        system("color 4");
        cleanConsole();
        lineBreak();
        printf("\n*--------------Aucun Produit -------------*");
        lineBreak();
        continu();
    }
    else
    {
        cleanConsole();
        struct produit etatProduit[100];
        int a = 0;
        for (int i = 0; i <= countProduit; i++)
        {
            if (allProduit[i].quantite < 3 && countProduit != 0)
            {
                // copie le produit dans un variable temporaire
                strcpy(etatProduit[a].nom, allProduit[i].nom);
                strcpy(etatProduit[a].code, allProduit[i].code);
                etatProduit[a].prix = allProduit[i].prix;
                etatProduit[a].quantite = allProduit[i].quantite;
                a++;
            }
        }

        printEtat(&etatProduit, a);

        lineBreak();
        lineBreak();
        continu();
    }
}

void rechercheProduit(struct produit *allProduit)
{
    if (countProduit == 0)
    {
        system("color 4");
        cleanConsole();
        lineBreak();
        printf("\n*--------------Aucun Produit -------------*");
        lineBreak();
        continu();
    }
    else
    {
        int x = -1;
        char code[20];
        printf("\nSaisir le code de produit: ");
        scanf("%s", code);
        for (int i = 0; i < countProduit; i++)
        {
            if (strcmp(allProduit[i].code, code) == 0)
            {
                x = i;
            }
        }
        if (x >= 0)
        {
            printProduit(allProduit, x);
        }
        else
        {
            system("color 4");
            printf("Erreur");
            getch;
        }
    }
}

void alimenterProduit(struct produit *allProduit)
{
    if (countProduit == 0)
    {
        system("color 4");
        cleanConsole();
        lineBreak();
        printf("\n*--------------Aucun Produit -------------*");
        lineBreak();
        continu();
    }
    else
    {
        char code[20];
        int qunatite, x = -1;
        printf("\nSaisie le code de produit : ");
        scanf("%s", code);
        printf("Saisir la qunatite : ");
        scanf("%d", &qunatite);
        for (int i = 0; i < countProduit; i++)
        {
            if (strcmp(allProduit[i].code, code) == 0)
            {
                x = i;
            }
        }
        if (x >= 0)
        {
            allProduit[x].quantite += qunatite;
        }
        else
        {
            system("color 4");
            printf("Aucun produit par se code.");
            getch();
        }
    }
}

void supprimerProduit(struct produit *allProduit)
{
    if (countProduit == 0)
    {
        system("color 4");
        cleanConsole();
        lineBreak();
        printf("\n*--------------Aucun Produit -------------*");
        lineBreak();
        continu();
    }
    else
    {
        char code[20];
        int x = -1;
        printf("Saisir le code de produit pour supprimer : ");
        scanf("%s", code);
        for (int i = 0; i < countProduit; i++)
        {
            if (strcmp(allProduit[i].code, code) == 0)
            {
                x = i;
            }
        }
        if (x >= 0)
        {
            for (int i = x; i < countProduit; i++)
            {
                strcpy(allProduit[i].nom, allProduit[i + 1].nom);
                strcpy(allProduit[i].code, allProduit[i + 1].code);
                allProduit[i].prix = allProduit[i + 1].prix;
                allProduit[i].quantite = allProduit[i + 1].quantite;
            }
            countProduit--;
            cleanConsole();
            lineBreak();
            system("color 2");
            printf("\nLe produit '%s' est supprimer avec succes", code);
            lineBreak();
            getch();
        }
    }
}

void statistique(struct produit *allProduit, struct achat *allAchat)
{
    if (countAchat != 0)
    {
        float totalAchat = 0, totalAchatTTC = 0, quantite = 0, minAchatQuantite = 0, maxAchatQuantite = 0;
        int year, day, month, prixMin, prixMax;
        prixMin = allAchat[0].prix;
        prixMax = allAchat[0].prix;
        char indiceMin[20], indiceMax[20], nomMax[80], nomMin[80];
        time_t seconds = time(NULL);
        struct tm *current_time = localtime(&seconds);
        year = current_time->tm_year + 1900;
        month = current_time->tm_mon + 1;
        day = current_time->tm_mday;
        for (int i = 0; i < countAchat; i++)
        {
            if (allAchat[i].year == year && allAchat[i].month == month && allAchat[i].day == day)
            {
                totalAchat += allAchat[i].prix * allAchat[i].quantite;
                totalAchatTTC += allAchat[i].prixTTC * allAchat[i].quantite;
                quantite += allAchat[i].quantite;

                if (allAchat[i].prix <= prixMin)
                {
                    prixMin = allAchat[i].prix;
                    strcpy(nomMin, allAchat[i].nom);
                }
                if (allAchat[i].prix >= prixMax)
                {
                    prixMax = allAchat[i].prix;
                    strcpy(nomMax, allAchat[i].nom);
                }
            }
        }
        for (int i = 0; i < countAchat; i++)
        {

            if (strcmp(allAchat[i].nom, nomMin) == 0)
            {
                minAchatQuantite += allAchat[i].quantite;
                strcpy(nomMin, allAchat[i].nom);
            }
            if (strcmp(allAchat[i].nom, nomMax) == 0)
            {
                maxAchatQuantite += allAchat[i].quantite;
                strcpy(nomMax, allAchat[i].nom);
            }
        }

        lineBreak();
        printf("\nLe total des prix des produits vendus en journee courante");
        lineBreak();
        printf("\nTotal: %.2lf\nTotalTTC: %.2lf", totalAchat, totalAchatTTC);

        lineBreak();
        printf("\nLa moyenne des prix des produits vendus en journee courante");
        lineBreak();
        printf("\nMoyen total: %.2lf\nMoyen total TTC: %.2lf\n", totalAchat / quantite, totalAchatTTC / quantite);

        lineBreak();
        printf("\nLe Max des prix des produits vendus en journee courante");
        lineBreak();
        printf("\nLe nom du produit : %s\nLe total : %.2lf\n\nLe total TTC: %.2lf\n", nomMax, maxAchatQuantite * prixMax, maxAchatQuantite * prixMax * 0.15);

        lineBreak();
        printf("\nLe Min des prix des produits vendus en journee courante");
        lineBreak();
        printf("\nLe nom du produit : %s\nLe total : %.2lf\n\nLe total TTC: %.2lf\n", nomMin, minAchatQuantite * prixMin, minAchatQuantite * prixMin * 0.15);

        continu();
    }
    else
    {
        system("color 4");
        cleanConsole();
        lineBreak();
        printf("\n*--------Aucun Achat maintenant-----------*");
        lineBreak();
        continu();
    }
}

void menu(struct produit *allProduit, struct achat *allAchat)
{
    int a;
    do
    {
        system("color 7");
        cleanConsole();
        lineBreak();
        printf("\n*------------------Menu-------------------*");
        lineBreak();
        printf("\n\t[1]- Ajouter produit .\n");
        printf("\t[2]- Lister tout les produits .\n");
        printf("\t[3]- Acheter un produit .\n");
        printf("\t[4]- Recherche .\n");
        printf("\t[5]- Etat du stock .\n");
        printf("\t[6]- Alimenter le stock .\n");
        printf("\t[7]- Supprimer un produit .\n");
        printf("\t[8]- Statistique de vente .\n");
        printf("\t[9]- Exit .\n");
        printf("*-----------------------------------------*\n");
        printf("=>");
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
            acheterProduit(allProduit, allAchat);
            break;
        case 4:
            rechercheProduit(allProduit);
            break;
        case 5:
            etatProduit(allProduit);
            break;
        case 6:
            alimenterProduit(allProduit);
            break;
        case 7:
            supprimerProduit(allProduit);
            break;
        case 8:
            statistique(allProduit, allAchat);
            break;
        case 9:
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
    menu(&allProduit, &allAchat);
}
