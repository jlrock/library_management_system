#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"

Fila* criarFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila == NULL){
        printf("Falha na alocacao da fila.\n");
        return NULL;
    }
    fila->inicio=NULL;
    fila->fim=NULL;
    return fila;
}

int filaVazia(Fila* fila){
    return (fila->inicio==NULL);
}

void enfileirarReserva(Fila* fila, Reserva reserva){
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila));

    if(novo == NULL){
        printf("Erro na alocacao da reserva.\n");
        return;
    }
    novo->reserva = reserva;
    novo->proximo = NULL;
    if(filaVazia(fila)){
        fila->inicio=novo;
        fila->fim=novo;
    }
    else{
        fila->fim->proximo= novo;
        fila->fim=novo;
    }
}

Reserva desenfileirarReserva(Fila* fila){
    if(filaVazia(fila)){
        printf("A fila esta vazia. Nao ha reservas.\n");
        
        Reserva vazia;
        strcpy(vazia.nomeUsuario, "NO_USER");
        vazia.codigoLivro=-1;
        return vazia;
    }
    
    NoFila* temp=fila->inicio;
    fila->inicio=temp->proximo;
    
    if(fila->inicio==NULL){
        fila->fim=NULL;
    }
    temp->proximo=NULL;

    return temp->reserva;
}

void exibirReservas(Fila* fila){
    if(filaVazia(fila)){
        printf("A fila esta vazia. Nao ha reservas.\n");
        return ;
    }

    NoFila* temp = fila->inicio;
    while(temp!=NULL){
        printf("-> Usuario: %s | Codigo do livro: %d\n", temp->reserva.nomeUsuario, temp->reserva.codigoLivro);
        temp=temp->proximo;
    }
}