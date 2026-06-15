#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista *criarLista() {
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

NoLista *encontrarNo(Lista *l, int index) {
    NoLista *no = l->inicio;
    if (index >= 0) {
        for (int i = 0; i != index && no != NULL; i++) no = no->prox;
    } else {
        NoLista *noFrente = l->inicio;
        for (int i = 0; i != -index; i++) {
            if (noFrente == NULL) return NULL;
            noFrente = noFrente->prox;
        }
        while (noFrente != NULL) {
            noFrente = noFrente->prox;
            no = no->prox;
        }
    }
    return no;
}

void inserirEmprestimo(Lista *l, Emprestimo e) {
    NoLista *novo = malloc(sizeof(NoLista));
    novo->emprestimo = e;
    novo->prox = NULL;

    if (listaVazia(l)) {
        l->inicio = novo;
        return;
    }

    NoLista *ultimo = encontrarNo(l, -1);
    ultimo->prox = novo;
}

void listarEmprestimos(Lista *l) {
    NoLista *no = l->inicio;
    while (no != NULL) {
        printf("Usuário: %s\n", no->emprestimo.nomeUsuario);
        printf("Código do livro: %d\n", no->emprestimo.codigoLivro);
        printf("Título do livro: %s", no->emprestimo.tituloLivro);
        printf("\n");
        if (no->prox != NULL) printf("\n");
        no = no->prox;
    }
}

int listaVazia(Lista *l) {
    return l->inicio == NULL;
}

void freeLista(Lista *l) {
    NoLista *no = l->inicio;
    NoLista *prox = NULL;
    if (!listaVazia(l)) prox = l->inicio->prox;
    while (no != NULL) {
        free(no);
        no = prox;
        if (prox != NULL) prox = prox->prox;
    }
    free(l);
}
