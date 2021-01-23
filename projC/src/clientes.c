#include "../include/cliente.h"
#include "../include/clientes.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_CLIENTES 20000

struct clientes{
    Cliente* clientes;
    int nrClientesValidados;
    int nrLinhasClientes;
};


Clientes initClientes(){
    Clientes c = (Clientes) malloc(sizeof(Clientes));
    c->clientes = (Cliente*) malloc(sizeof(Cliente) * MAX_CLIENTES);
    c->nrClientesValidados = 0;
    c->nrLinhasClientes = 0;
    return c;
}

void incrementaNrLinhasClientes(Clientes c){
    c->nrLinhasClientes++;
}

int getNrLinhasClientes(Clientes c){
    return c->nrLinhasClientes;
}

Clientes addCliente(Clientes cs, Cliente c){
    cs->clientes[cs->nrClientesValidados] = c;
    (cs->nrClientesValidados)++;
    return cs;
}

int getNumClientesValidos(Clientes c){
    return c->nrClientesValidados;
}


Cliente* getClientes(Clientes c){
    return c->clientes;
}


void destroyClientes(Clientes c){
    for(int i = 0; i < (c->nrClientesValidados); i++){
        destroyCliente(c->clientes[i]);
    }
    free(c->clientes);
    free(c);
}