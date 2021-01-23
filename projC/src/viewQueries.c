#include <stdio.h>
#include "../include/viewQueries.h"


void clearScreen(){
    printf("\e[1;1H\e[2J");
}

void showTitle(){
    clearScreen();
    printf("\n-----------------------------\n");
    printf("\n            SGV\n");
    printf("\n-----------------------------\n");
}

void showTime(double time){
    printf("Tempo demorado: %.3f ms\n", time*1000);
}

void showENTER(){
    printf("Pressione ENTER para continuar\n");
}
/*
page - nº1 da página a apresentar;
listSize - tamanho restante da lista
nrPages - numero de páginas

pageSize - tamanho da pagina (minimo entre tamanho da lista e tamanho maximo da página)
pageWidth - largura da página
*/

void showPageClientes(Cliente* clientes, int page, int pageSize, int nrPages, int listSize){
    showTitle();
    int index;
    int pageWidth = 8;
    int maxPageSize = 64;

    printf("Total de clientes: %d\n", listSize);


    for (int i = 0; i * pageWidth < pageSize; i++){
        for(int j = 0; (j < pageWidth) && (j + (i * pageWidth)  < pageSize) ; j++){
            index = j + (i * pageWidth) + (maxPageSize  * (page-1));
            char * ID = getIDCliente(clientes[index]);
            printf("%d - %s ", index + 1, ID);
            free(ID);
        }
        printf("\n");
    }
    printf("\n");

    printf("Página %d de %d\n", page, nrPages);
    if (page > 1) printf("1 - Página anterior ");
    if (page < nrPages) printf("2 - Página seguinte ");
    printf("3 - Retornar\n");
}

void showPageProdutos(Produto* produtos, int page, int pageSize, int nrPages, int listSize){
    showTitle();
    printf("\n");
    int index;
    int pageWidth = 8;
    int maxPageSize = 64;

    printf("Total de produtos: %d\n", listSize);

    for (int i = 0; i * pageWidth < pageSize; i++){
        for(int j = 0; (j < pageWidth) && (j + (i * pageWidth)  < pageSize) ; j++){
            index = j + (i * pageWidth) + (maxPageSize  * (page-1));
            char * ID = getIDProduto(produtos[index]);
            printf("%d - %s ", index + 1, ID);
            free(ID);
        }
        printf("\n");
    }
    printf("\n");


    printf("Página %d de %d\n", page, nrPages);
    if (page > 1) printf("1 - Página anterior ");
    if (page < nrPages) printf("2 - Página seguinte ");
    printf("3 - Retornar\n");
}

void showTabela(int quantidades[3][12], double time){
        
    char* meses[13] = {"        "," janeiro ", "fevereiro", "  março  ", "  abril  ", "  maio   ", "  junho  ", "  julho  ", "  agosto ", " setembro" , " outubro " , " novembro" , " dezembro"};
    char* filiais[3] = {"Filial 1", "Filial 2", "Filial 3"};
    int i;
    for(i = 0; i < 13; i++)
        printf("|%s|", meses[i]);
    printf("\n\n");


    int j, digits = 0, quant;
    for(i = 0; i < 3; i++){
        printf("|%s|", filiais[i]);
        for(j = 0; j < 12; j++){
            digits = 1;
            quant = quantidades[i][j];
            while(quant > 0){
            quant = quant/10;
            digits++;
            }
            if(digits > 1) digits--;
            if(digits == 1)
                printf("|    %d    |", quantidades[i][j]);
            else if(digits == 2)
                printf("|   %d    |", quantidades[i][j]);
            else if(digits == 3)
                printf("|   %d   |", quantidades[i][j]);  
            else if(digits == 4)
                printf("|   %d  |", quantidades[i][j]);
        }
        printf("\n\n");
    }
    showTime(time);
    showENTER();
}

void showQ2P1(int erro){
    if (erro) printf("Caracter inválido\n");
    printf("Insira uma letra: ");
}

void showQ3P1(int erro){
    if(erro) printf("Produto não encontrado\n");
    printf("Produto a procurar: ");
}
void showQ3P2(int erro){
    if(erro) printf("Mês inválido\n");
    printf("Mês a procurar: ");
}

void showResultsQ3(double profitN, int salesN, double profitP, int salesP){
    showTitle();
    printf("\nNormal:\n");
    printf("Número de vendas: %d\n", salesN);
    printf("Total faturado: %.2f\n", profitN);

    printf("\nPromoção:\n");
    printf("Número de vendas: %d\n", salesP);
    printf("Total faturado: %.2f\n", profitP);
    showENTER();
}

void showQ4P1(int erro){
    if (erro) printf("\nFilial inválida");
    printf("\n1 - Filial 1\n");
    printf("2 - Filial 2\n");
    printf("3 - Filial 3\n");
    printf("4 - Todas as Filiais\n");
}


void showQ6(int c, int p, double time){
    showTitle();
    printf("\nNúmero de clientes que não compraram: %d\n", c);
    printf("Número de produtos que não foram comprados: %d\n", p);
    showTime(time);
    showENTER();
}



void showQ7P1(int erro){
    if(erro) printf("\nCliente não encontrado");
    printf("\nCliente a procurar: ");
}


void showQ8P1(){
    printf("\nInsira o primeiro mês do intervalo: ");
}

void showQ8P2(){
    printf("\nInsira o segundo mês do intervalo: ");
}

void showResultsQ8(int sales, double profit, double time){
    printf("\nNúmero de vendas no intervalo: %d", sales);
    printf("\nTotal faturado no intervalo: %.2f\n", profit);
    showTime(time);
    showENTER();
}



void showQ9P1(int erro){
    if(erro) printf("\nProduto inválido");
        printf("\nInsira produto: ");
}

void showQ9P2(int erro){
    if(erro) printf("\nFilial inválida");
    printf("\nInsira filial (1-3): ");
}

void showResultsQ9(int N,int P, double time){
    printf("\n");
    showTime(time);
    printf("Número de compradores N: %d\n", N);
    printf("Número de compradores P: %d\n", P);
    printf("Insira 1 ou 2 para visualizar, 3 para retornar: ");
}

void showQ10P1(int erro){
    if(erro) printf("Cliente não encontrado\n");
    printf("Cliente a procurar: ");
}

void showQ10P2(int erro){
    if(erro) printf("Mês inválido\n");
    printf("Mês a procurar: ");
}

void showQ11P1(int erro){
    if(erro) printf("Número inválido\n");
    printf("Número de produtos a apresentar: ");
}

void showQ12P1(int erro){
    if(erro) printf("Cliente não encontrado\n");
    printf("Cliente a procurar: ");
}

void showQ12P2(int erro){
    if(erro) printf("Número inválido\n");
    printf("Número de produtos a apresentar: ");
}

