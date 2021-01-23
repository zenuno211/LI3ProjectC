#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<ctype.h>
#include<time.h>
#include "../include/controllerQueries.h"


static void menuListaProdutos(Produtos produtos, int maxPageSize){
    int listSize = getNumProdutosValidos(produtos);
    int nrPages = 0;

    if (listSize % maxPageSize == 0) nrPages = listSize/maxPageSize;
    else nrPages = (listSize/maxPageSize) + 1;

    int currentPage = 1;
    int pageSize = maxPageSize;

    int exit = 0;
    int option;
    int listLeft = 0;

    while(!exit){
        listLeft = (listSize - (pageSize * (currentPage - 1)));
        if (maxPageSize > listLeft) pageSize = listLeft;
        else pageSize = maxPageSize;

        showPageProdutos(getProdutos(produtos), currentPage, pageSize , nrPages, listSize);

        scanf(" %d", &option);

        switch(option){
            case 1:
                if (currentPage > 1) currentPage--;
                break;
            case 2:
                if (currentPage < nrPages ) currentPage++;
                break;
            case 3:
                exit = 1;
                break;
            default:
                break;
        }
    }
}

static void menuListaClientes(Clientes clientes, int maxPageSize){
    int listSize = getNumClientesValidos(clientes);
    int nrPages = 0;

    if (listSize % maxPageSize == 0) nrPages = listSize/maxPageSize;
    else nrPages = (listSize/maxPageSize) + 1;

    int currentPage = 1;
    int pageSize = maxPageSize;

    int exit = 0;
    int option;
    int listLeft = 0;

    while(!exit){
        listLeft = (listSize - (pageSize * (currentPage - 1)));
        if (maxPageSize > listLeft) pageSize = listLeft;
        else pageSize = maxPageSize;


        showPageClientes(getClientes(clientes), currentPage, pageSize , nrPages, listSize);

        scanf(" %d", &option);

        switch(option){
            case 1:
                if (currentPage > 1) currentPage--;
                break;
            case 2:
                if (currentPage < nrPages) currentPage++;
                break;
            case 3:
                exit = 1;
                break;
            default:
                break;
        }
    }
}

void menuQuery2(SGV sgv){
    char letter;
    int erro = 0;
    int next = 0;

    while (!next){
        showQ2P1(erro);
        scanf(" %c", &letter);
        toupper(letter);
        if (letter >= 'A' && letter <= 'Z') next = 1;
        else next = 0;
        erro = !next;
    }

    Produtos produtos = getProductsStartedByLetter(sgv, letter);

    menuListaProdutos(produtos, 64);

    destroyProdutos(produtos);

}


void menuQuery3(SGV sgv){
    int next = 0;
    int erro = 0;
    char buffer[7];
    int mes = -1;

    Produtos produtos = getProdutosSGV(sgv);

    getchar();
    while (!next){
        showQ3P1(erro);

        fgets(buffer, sizeof(buffer),stdin);
        if(searchProduto(getProdutos(produtos), 0, getNumProdutosValidos(produtos) ,buffer) < 0)
            next = 0;
        else next = 1;
        erro = !next;
    }
        
    next = 0;
    erro = 0;

    while (!next){
        showQ3P2(erro);
        scanf(" %d", &mes);
        next = (mes < 13 && mes > 0);
        erro = !next;
    }

    SalesAndProfitNP sap = getProductsSalesAndProfit(sgv, buffer, mes);

    showResultsQ3(sap.profitN,sap.salesN,sap.profitP,sap.salesP);

    getchar();
    getchar();


}


void menuQuery4(SGV sgv){
    int next = 0;
    int erro = 0;

    int filial = -1;

    while (!next){
        showQ4P1(erro);
        scanf(" %d", &filial);
        next = (filial >= 1 && filial <= 4);
        erro = !next;
    }

    Produtos produtos = getProductsNeverBought(sgv, filial);

    menuListaProdutos(produtos, 64);

    destroyProdutos(produtos);
}


void menuQuery5(SGV sgv){
    Clientes clientes = getClientsOfAllBranches(sgv);


    menuListaClientes(clientes, 64);

    destroyClientes(clientes);
}




void menuQuery6(SGV sgv){
    clock_t before = clock();
    ClientesAndProdutos cliEProd = getclientsAndProductsNeverBoughtCount(sgv);
    clock_t after = clock();

    showQ6(cliEProd.clientes, cliEProd.produtos, (double) (after-before)/CLOCKS_PER_SEC);

    getchar();
    getchar();
}


void menuQuery7(SGV sgv){
    int next = 0;
    int erro = 0;
    char buffer[6];

    
    Clientes clientes = getClientesSGV(sgv);
    
   
    clock_t before =  clock();
    while (!next){
        showQ7P1(erro);
        scanf(" %s", buffer);
        if(searchCliente(getClientes(clientes), 0, getNumClientesValidos(clientes), buffer) < 0)
            next = 0;
        else next = 1;
        erro = !next;
    }

    
    IntFilialMes qt = getProductsBoughtByClient(sgv,buffer);
    clock_t after = clock();

    showTabela(qt->quantidade, (double) (after-before)/CLOCKS_PER_SEC);

    getchar();
    getchar();

}

void menuQuery8(SGV sgv){
    int mes1, mes2;
    
    showQ8P1();
    scanf(" %d", &mes1);
    showQ8P2();
    scanf(" %d", &mes2);

    int sales;
    double profit;

    clock_t before = clock();
    SalesAndProfit sap = getSalesAndProfit(sgv, mes1, mes2);
    clock_t after = clock();

    showResultsQ8(sap.sales, sap.profit, (double) (after-before)/CLOCKS_PER_SEC);
    getchar();
    getchar();
}


void menuQuery9(SGV sgv){
    char buffer[7];
    int erro = 0;
    int next = 0;
    int filial = -1;

    Produtos produtos = getProdutosSGV(sgv);


    getchar();
    while (!next){
        showQ9P1(erro);

        fgets(buffer, sizeof(buffer),stdin);
        if(searchProduto(getProdutos(produtos), 0, getNumProdutosValidos(produtos) ,buffer) < 0)
            next = 0;
        else next = 1;
        erro = !next;
    }
    next = 0;
    erro = 0;

    while (!next){
        showQ9P2(erro);
        scanf(" %d", &filial);
        next = (filial >= 1 && filial <= 3);
        erro = !next;
    }

    clock_t before = clock();
    ProductBuyers pb = getProductBuyers(sgv, buffer, filial);
    clock_t after = clock();

    int option = -1;
    int exit = 0;

    while(!exit){
        showResultsQ9(pb->N,pb->P, (double) (after-before)/CLOCKS_PER_SEC);
        scanf(" %d", &option);
        switch(option){
            case 1:
                menuListaClientes(pb->clientsN, 64);
                break;
            case 2:
                menuListaClientes(pb->clientsP, 64);
                break;
            default:
                exit = 1;
                break;
        }
    }

    destroyProductBuyers(pb);
    
}

void menuQuery10(SGV sgv){
    int next = 0;
    int erro = 0;
    char buffer[12];
    int mes = -1;

    Clientes clientes = getClientesSGV(sgv);
   
    while (!next){
        showQ10P1(erro);
        scanf(" %s", buffer);
        if(searchCliente(getClientes(clientes), 0, getNumClientesValidos(clientes) ,buffer) < 0)
            next = 0;
        else next = 1;
        erro = !next;

    }
    next = 0;
    erro = 0;

    while (!next){
        showQ10P2(erro);
        scanf(" %d", &mes);
        next = (mes < 13 && mes > 0);
        erro = !next;
    }

    clock_t before = clock();
    Produtos produtos = getClientFavoriteProducts (sgv, buffer, mes);
    clock_t after = clock();


    showTime((double) (after-before)/CLOCKS_PER_SEC);
    showENTER();
    getchar();
    getchar();
    menuListaProdutos(produtos, 64);
    

    destroyProdutos(produtos);

}


void menuQuery11(SGV sgv){
    int next = 0;
    int erro = 0;
    int limit = -1;

    while (!next){
        showQ11P1(erro);
        scanf(" %d", &limit);
        next = (limit > 0);
        erro = !next;
    }

    //Produtos produtos = getTopSellProducts (SGV sgv, int limit);

    //menuListaProdutos(produtos, 30);

    //free(produtos);


}


/* TO FINISH
void menuQuery12(SGV sgv){
    int next = 0;
    int erro = 0;
    char buffer[12];
    int limit = -1;

    Clientes clientes = getClientesSGV(sgv);

    while (!next){
        showQ12P1(erro);
        scanf(" %s", buffer);
        if(searchCliente(getClientes(clientes), 0, getNumClientesValidos(clientes) ,buffer) < 0)
            next = 0;
        else next = 1;
        erro = !next;
    }
    next = 0;
    erro = 0;

    while (!next){
        showQ12P2(erro);
        scanf(" %d", limit);
        next = (limit > 0)
        erro = !next;
    }

    char * produtos[7] = getClientTopProfitProducts (sgv, buffer, limit);

    menuListaProdutos(produtos, 30);

    free(produtos);
}*/
