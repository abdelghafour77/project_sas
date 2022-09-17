#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int count=0;

// structers

struct produit{
    int quantite;
    float prix;
    char nom[60],code[10];
};

// functions

void lineBreak(){
    printf("\n*-----------------------------------------*\n");
}
void cleanConsole(){
    system("cls");
}
void ajouterProduits(struct produit* allProduit, int x){
    int number;
    printf("Combien des produit : ");
    scanf("%d",&number);
    for(int i=0; i<number;i++){
       ajouterProduit(allProduit,count,i);
        }
    }


    void ajouterProduit(struct produit* allProduit,int i){
    cleanConsole();
    lineBreak();
    if(i>-1){
        printf("*-----------Produit number : %d -----------*",i+1);
        lineBreak();
    }else{
        printf("*-------------Ajouter Produit-------------*");
        lineBreak();

    }
    printf("\nCode de produit : ");
    scanf("%s",&allProduit[count].code);


    printf("\nNom de produit : ");
    scanf("%s",&allProduit[count].nom);


    printf("\nQuantite de produit : ");
    scanf("%d",&allProduit[count].quantite);


    printf("\nPrix de produit : ");
    scanf("%f",&allProduit[count].prix);

    cleanConsole();
    lineBreak();
    printf("Le produit etait ajouter avec succes !!");
    lineBreak();
    printf("%s\n",allProduit[count].code);
    printf("%s\n",allProduit[count].nom);
    printf("%d\n",allProduit[count].quantite);
    printf("%lf",allProduit[count].prix);
    count++;
    lineBreak();
    sleep(4);
    cleanConsole();
}
void listerProduits(struct produit* allProduit){
    //printf("%d",count);
    //sleep(3);
    if(count==0){
        lineBreak();
        printf("*--------------Aucun Produit -------------*");
        lineBreak();
        sleep(4);
        cleanConsole();
    }else{
        for(int i=0;i<count;i++){
            lineBreak();
            printf("*-----------Produit number : %d -----------*",i+1);
            lineBreak();
            printf("Le code de produit: %s\n",allProduit[i].code);
            printf("Le nom de produit: %s\n",allProduit[i].nom);
            printf("La quantite de produit: %d\n",allProduit[i].quantite);
            printf("Le prix de produit: %lf\n",allProduit[i].prix);
        }

    lineBreak();
    lineBreak();
    sleep(4);

}

void defaultt(){
    cleanConsole();
    lineBreak();
    printf("\n default \n");
    lineBreak();
}

void main(){
    struct produit allProduit[100];
    int  a;

    do{
        printf("choisir:\n");
        printf("\t1- Ajouter un seul produit .\n");
        printf("\t2- Plusieur produit .\n");
        printf("\t3- Lister tout les produits .\n");
        scanf("%d",&a);
        switch (a)
        {
            case 1:
                ajouterProduit(&allProduit, -1);
                break;
            case 2:
                ajouterProduits(&allProduit,  -1);
                break;
            case 3:
                listerProduits(&allProduit);
                break;
            default:
                defaultt();
        }
    }while(1);
}
