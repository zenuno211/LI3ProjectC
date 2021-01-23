#include "../include/produto.h"
#include "../include/produtos.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_PRODUTOS 200000

struct produtos{
    Produto* produtos;
    int nrProdutosValidos;
    int nrLinhasProdutos;
};

Produtos initProdutos(){
    Produtos p = (Produtos) malloc(sizeof(Produtos));
    p->produtos = (Produto*) malloc(sizeof(Produto) * MAX_PRODUTOS);
    p->nrProdutosValidos = 0;
    p->nrLinhasProdutos = 0;
    return p;
}

void incrementaNrLinhasProdutos(Produtos p){
    p->nrLinhasProdutos++;
}

int getNrLinhasProdutos(Produtos p){
    return p->nrLinhasProdutos;
}


Produtos addProduto(Produtos ps, Produto p){
    ps->produtos[ps->nrProdutosValidos] = p;
    (ps->nrProdutosValidos)++;
    return ps;
}

int getNumProdutosValidos(Produtos p){
    return p->nrProdutosValidos;
}

Produto* getProdutos(Produtos p){
    return p->produtos;
}


void destroyProdutos(Produtos p){
    for(int i = 0; i< (p->nrProdutosValidos); i++){
        destroyProduto(p->produtos[i]);
    }
    free(p->produtos);
    free(p);
}


int searchDown(int i, char letra, Produto * produtos){
    int check = 1;
    while(i > 0 && check){
        i--;
        char * ID = getIDProduto(produtos[i]);
        char l = ID[0];
        free(ID);
        if(letra != l) check = 0;
    }
    if (i == 0) return i;
    return i+1;

}


int searchUp(int i, char letra, Produto * produtos){
    int check = 1;
    while(produtos[i+1] && check){
        i++;
        char * ID = getIDProduto(produtos[i]);
        char l = ID[0];
        free(ID);
        if(letra != l) check = 0;
    }
    if (!produtos[i+1]) return i;
    return i;
}



int binSearchLetra(char letra, Produto * produtos, int left, int right){
    if (right >= left) { 
        int mid = left + (right - left) / 2;
        char * midID = getIDProduto(produtos[mid]);
        char idMid = midID[0];
        free(midID);
        if (idMid == letra)
            return mid; 
  
        if (idMid > letra)
            return binSearchLetra(letra, produtos, left, mid - 1); 
        
        return binSearchLetra(letra, produtos, mid + 1, right); 

    }

    return -1;
}