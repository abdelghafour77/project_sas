#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// structers

struct produit{
    int quantite;
    float prix;
    char nom[60],code[10];
};

// functions

void lineBreak(){
    printf("\n*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*\n");
}
void cleanConsole(){
    system("cls");
}

void ajouterProduit(struct produit* allProduit,int *count){
cleanConsole();
lineBreak();
printf("\nCode de produit : ");
scanf("%s",&allProduit[*count].code);


printf("\nNom de produit : ");
scanf("%s",&allProduit[*count].nom);


printf("\nQuantite de produit : ");
scanf("%d",&allProduit[*count].quantite);


printf("\nPrix de produit : ");
scanf("%f",&allProduit[*count].prix);

cleanConsole();
lineBreak();
printf("Le produit etait ajouter avec succes !!");
lineBreak();
printf("%s\n",allProduit[*count].code);
printf("%s\n",allProduit[*count].nom);
printf("%d\n",allProduit[*count].quantite);
printf("%lf",allProduit[*count].prix);
count++;
lineBreak();
sleep(4);
cleanConsole();
}

void case2(){
cleanConsole();
lineBreak();
printf("\n hello2 \n");
lineBreak();
}
void defaultt(){
cleanConsole();
lineBreak();
printf("\n default \n");
lineBreak();
}

void main(){
    struct produit allProduit[100];
int count=0, a;

    do{
   //     cleanConsole();
        printf("choisir:\n");

        printf("1- ajouter un seul produit .\n");
        printf("2- plusieur produit .\n");
        printf("3- plusieur produit .\n");
        scanf("%d",&a);
        switch (a)
        {
            case 1:
              ajouterProduit(&allProduit,&count);
              break;

            case 2:
              case2();
              break;
            default:
             defaultt();
        }
    }while(1);
}
