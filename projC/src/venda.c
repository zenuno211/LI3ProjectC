#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "../include/venda.h"


struct venda{
    char * produto;
    float preco;
    int num_unidades;
    int tipo_compra; // 0 = N; 1 = P
    char * cliente;
    int mes;
    int filial;     // 1 - 3
};

/*
codigo de produto
num int unidades (1 - 200)
N ou P (normal ou promoção)
codigo de cliente
mes (1-12)
filial (1-3)
preço unitario decimal (0.0 - 999.9)


*/

int validarVendas(char * venda, Cliente *clientes, Produto *produtos, int num_clientes, int num_produtos){
   
    char *prod = strtok(venda, " ");
    if (searchProduto(produtos, 0, num_produtos, prod) < 0){
        return 0;
    }
    
    char *preco = strtok(NULL, " ");
    if(!(atof(preco) >= 0.0 && atof(preco) <= 999.99)) return 0;

    char *unidades = strtok(NULL," ");
    if(!(atoi(unidades) >= 1 && atoi(unidades) <= 200)) return 0;

        char *tipo = strtok(NULL, " ");
    if(strcmp(tipo, "N") && strcmp(tipo, "P")){
        return 0;
    }

    char *cliente = strtok(NULL, " ");
    if(searchCliente(clientes, 0, num_clientes, cliente) < 0){
        return 0;
    }

    
    char *mes = strtok(NULL, " ");
    if(!(atoi(mes) >= 1 && atoi(mes) <= 12)) return 0;


    char *filial = strtok(NULL," \r\n");
    if(!(atoi(filial) >= 1 && atoi(filial) <= 3)) return 0;

    return 1;
}    


Venda addVenda(char * buffer){

    Venda venda = malloc(sizeof(struct venda));

    char *produto  = strtok (buffer, " ");

    char *precoS = strtok(NULL," ");
    float preco = atof(precoS);

    char *unidadeS = strtok(NULL, " ");
    int unidade = atoi(unidadeS);

    char *tipoCompra = strtok(NULL," ");
    int tipoBool;
    if( tipoCompra[0] == 'N') tipoBool = 0;
    else tipoBool = 1;

    char *cliente = strtok(NULL," ");

    char *mesS = strtok(NULL, " ");
    int mes = atoi(mesS);

    char *filialS = strtok(NULL, " ");
    int filial = atoi(filialS);


    venda->produto = strdup(produto);

    venda->num_unidades = unidade;

    venda->preco = preco;

    venda->tipo_compra = tipoBool;

    venda->cliente = strdup(cliente); 

    venda->mes = mes;

    venda->filial = filial;

    return venda;

}

int getMesV(Venda venda){
    return venda->mes;
}

char* getClienteV(Venda venda){
    return strdup(venda->cliente);
}

int getUnidadesV(Venda venda){
    return venda->num_unidades;
}

int getFilialV(Venda venda){
    return venda->filial;
}

float getPrecoV(Venda venda){
    return venda->preco;
}

int getTipoCompraV(Venda venda){
    return venda->tipo_compra;
}

char* getProdutoV(Venda venda){
    return strdup(venda->produto);
}

double getTotalV(Venda venda){
    return (venda->num_unidades) * (venda->preco);
}

void destroyVenda(Venda venda){
    free(venda->cliente);
    free(venda->produto);
    free(venda);
}   