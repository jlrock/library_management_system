#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Lista *criarLista() {

    Lista *l = malloc(sizeof(Lista));

    if (l == NULL) {
        printf("Erro ao alocar a lista.\n");
        return NULL;
    }

    l->inicio = NULL;

    return l;
}

Emprestimo *criarEmprestimo(
    char nome[],
    int codigo,
    char titulo[]
) {

    Emprestimo *e = malloc(sizeof(Emprestimo));

    if (e == NULL) {
        printf("Erro ao alocar o emprestimo.\n");
        return NULL;
    }

    strcpy(e->nomeUsuario, nome);

    e->codigoLivro = codigo;

    strcpy(e->tituloLivro, titulo);

    return e;
}

NoLista *encontrarNo(Lista *l, int index) {

    NoLista *no = l->inicio;

    if (index >= 0) {

        for (int i = 0; i != index && no != NULL; i++) {
            no = no->prox;
        }

    } else {

        NoLista *noFrente = l->inicio;

        for (int i = 0; i != -index; i++) {

            if (noFrente == NULL)
                return NULL;

            noFrente = noFrente->prox;
        }

        while (noFrente != NULL) {

            noFrente = noFrente->prox;

            no = no->prox;
        }
    }

    return no;
}

void inserirEmprestimo(Lista *l, Emprestimo *e) {

    NoLista *novo = malloc(sizeof(NoLista));

    if (novo == NULL) {

        printf("Erro ao alocar o no.\n");

        return;
    }

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

    if (listaVazia(l)) {

        printf("Nao ha emprestimos.\n");

        return;
    }

    NoLista *no = l->inicio;

    while (no != NULL) {

        printf(
            "Usuario: %s\n",
            no->emprestimo->nomeUsuario
        );

        printf(
            "Codigo do livro: %d\n",
            no->emprestimo->codigoLivro
        );

        printf(
            "Titulo do livro: %s\n",
            no->emprestimo->tituloLivro
        );

        if (no->prox != NULL)
            printf("\n");

        no = no->prox;
    }
}

int listaVazia(Lista *l) {

    return l->inicio == NULL;
}

void freeLista(Lista *l) {

    if (l == NULL)
        return;

    NoLista *atual = l->inicio;

    while (atual != NULL) {

        NoLista *prox = atual->prox;

        free(atual->emprestimo);

        free(atual);

        atual = prox;
    }

    free(l);
}

void salvarEmprestimos(Lista *lista, const char *nomeArquivo) {

    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    NoLista *atual = lista->inicio;

    while (atual != NULL) {

        fprintf(
            arquivo,
            "%s;%d;%s\n",
            atual->emprestimo->nomeUsuario,
            atual->emprestimo->codigoLivro,
            atual->emprestimo->tituloLivro
        );

        atual = atual->prox;
    }

    fclose(arquivo);
}

Lista *carregarEmprestimos(const char *nomeArquivo) {

    FILE *arquivo = fopen(nomeArquivo, "r");

    Lista *lista = criarLista();

    if (lista == NULL)
        return NULL;

    /* Arquivo ainda nao existe */
    if (arquivo == NULL)
        return lista;

    char nome[100];
    int codigo;
    char titulo[100];

    while (fscanf(
        arquivo,
        "%99[^;];%d;%99[^\n]\n",
        nome,
        &codigo,
        titulo
    ) == 3) {

        Emprestimo *e = criarEmprestimo(
            nome,
            codigo,
            titulo
        );

        if (e != NULL)
            inserirEmprestimo(lista, e);
    }

    fclose(arquivo);

    return lista;
}
