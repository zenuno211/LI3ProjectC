#include <stdlib.h>
#include <string.h>
#include "../include/venda.h"
#include "../include/faturacaoP.h"
#include "../include/faturacaoGlobal.h"



struct faturacaoG {
    GHashTable* faturas; 
    double faturacaoTotal[12];
    int vendasTotal[12];
    int nrLinhasVendas;
};  

FaturacaoG initFaturacaoG (){
    FaturacaoG f = (FaturacaoG) malloc(sizeof(struct faturacaoG));
    f->faturas = g_hash_table_new_full(g_str_hash, g_str_equal, free, destroyFaturacaoP);
    for( int i=0; i<12; i++){
        f->faturacaoTotal[i] = 0;
        f->vendasTotal[i] = 0;
    }
    f->nrLinhasVendas = 0;
    return  f;
}


FaturacaoG addFaturacaoG (Venda v, FaturacaoG g){
    char* id = getProdutoV(v);
    int mes = getMesV(v)-1;
    g->faturacaoTotal[mes] += getTotalV(v);
    g->vendasTotal[mes] += 1;
    
    FaturacaoP P = searchFaturas(id, g);
    if (!P){
        P = initFaturacaoP(v);
        g_hash_table_insert(g->faturas, id, P);
    } else {
        addFatura(P, v);    
        free(id);
    }


    return g;
}

int getNrLinhasVendas(FaturacaoG g){
    return g->nrLinhasVendas;
}

void incrementaNrLinhasVendas(FaturacaoG g){
    g->nrLinhasVendas++;
}

int getTotalUnidadesProdG(FaturacaoG G, char * id){
    FaturacaoP P = searchFaturas(id, G);
    if (P) return getQuantidadeVendidaProd(P);
    else return -1;
}

double getTotalFaturadoProdG(FaturacaoG G, char * id){
    FaturacaoP P = searchFaturas(id, G);
    if (P) return getTotalFaturadoProd(P);
    else return -1;
}

int getTotalVendas(FaturacaoG G){
    int total = 0;
    for( int i = 0; i < 12; i++){
        total += G->vendasTotal[i];
    }
    return total;
}

double getTotalFaturado(FaturacaoG G){
    double total = 0;
    for( int i = 0; i < 12; i++){
        total += G->faturacaoTotal[i];
    }
    return total;
}

double getTotalFaturadoMeses (FaturacaoG f, int mes1, int mes2) {
    double total = 0;
    int i;
    for (i = mes1-1; i < mes2; i++) 
        total += f->faturacaoTotal[i];

    return total;
}

int getTotalVendasMeses (FaturacaoG f, int mes1, int mes2) {
    int total = 0;
    int i;
    for (i = mes1; i <= mes2; i++) 
        total += f->vendasTotal[i - 1];

    return total;
}

int getNumFaturacaoP(FaturacaoG G){
    return g_hash_table_size(G->faturas);
}

void destroyFaturacaoG(FaturacaoG G){
    
    g_hash_table_destroy(G->faturas);
    free(G);

}

int prodVendidoFilial(FaturacaoG G, int filial, char ID[7]){
    FaturacaoP fatProd = g_hash_table_lookup(G->faturas, ID);
    int res = 0;
    if(fatProd){
        if(filial != 4){
            if(getQuantidadeVendidaProdFilial(fatProd, filial) > 0){
                res = 1;
            }
        } else res = 1;
    }

    return res;
}

FaturacaoP searchFaturas(char* id, FaturacaoG g){
    return g_hash_table_lookup(g->faturas, id);
}


GHashTable* getFaturas (FaturacaoG g){
    return g->faturas;
}