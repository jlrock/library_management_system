#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila* criarFila() {

    Fila* fila = malloc(sizeof(Fila));

    if (fila == NULL) {
        printf("Falha na alocacao da fila.\n");
        return NULL;
    }

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

Reserva* criarReserva(char nome[], int codigo) {

    Reserva* r = malloc(sizeof(Reserva));

    if (r == NULL) {
        printf("Falha na alocacao da reserva.\n");
        return NULL;
    }

    r->codigoLivro = codigo;

    strcpy(r->nomeUsuario, nome);

    return r;
}

int filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

void enfileirarReserva(Fila* fila, Reserva* reserva) {

    NoFila* novo = malloc(sizeof(NoFila));

    if (novo == NULL) {
        printf("Erro na alocacao da reserva.\n");
        return;
    }

    novo->reserva = reserva;
    novo->proximo = NULL;

    if (filaVazia(fila)) {

        fila->inicio = novo;
        fila->fim = novo;

    } else {

        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

Reserva* desenfileirarReserva(Fila* fila) {

    if (filaVazia(fila)) {

        printf("A fila esta vazia. Nao ha reservas.\n");

        return NULL;
    }

    NoFila* temp = fila->inicio;

    Reserva* reserva = temp->reserva;

    fila->inicio = temp->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);

    return reserva;
}

void exibirReservas(Fila* fila) {

    if (filaVazia(fila)) {

        printf("A fila esta vazia. Nao ha reservas.\n");

        return;
    }

    NoFila* temp = fila->inicio;

    while (temp != NULL) {

        printf(
            "-> Usuario: %s | Codigo do livro: %d\n",
            temp->reserva->nomeUsuario,
            temp->reserva->codigoLivro
        );

        temp = temp->proximo;
    }
}

void salvarReservas(Fila *fila, const char *nomeArquivo) {

    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    NoFila *atual = fila->inicio;

    while (atual != NULL) {

        fprintf(
            arquivo,
            "%s;%d\n",
            atual->reserva->nomeUsuario,
            atual->reserva->codigoLivro
        );

        atual = atual->proximo;
    }

    fclose(arquivo);
}

Fila *carregarReservas(const char *nomeArquivo) {

    FILE *arquivo = fopen(nomeArquivo, "r");

    Fila *fila = criarFila();

    if (fila == NULL)
        return NULL;

    /* Arquivo ainda nao existe */
    if (arquivo == NULL)
        return fila;

    char nome[100];
    int codigo;

    while (fscanf(
        arquivo,
        "%99[^;];%d\n",
        nome,
        &codigo
    ) == 2) {

        Reserva *reserva =
            criarReserva(nome, codigo);

        if (reserva != NULL)
            enfileirarReserva(
                fila,
                reserva
            );
    }

    fclose(arquivo);

    return fila;
}

void freeFila(Fila *fila) {

    if (fila == NULL)
        return;

    NoFila *atual = fila->inicio;

    while (atual != NULL) {

        NoFila *proximo = atual->proximo;

        free(atual->reserva);

        free(atual);

        atual = proximo;
    }

    free(fila);
}

