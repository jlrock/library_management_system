#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "livro.h"

Arvore* criarArvore(){
    Arvore* arvore = malloc(sizeof(Arvore));

    if (arvore == NULL) {
        printf("Erro ao alocar memória");
    }

    arvore->raiz = NULL;

    return arvore;
}

NoArvore* criarNoArvore(Livro* livro) {
    NoArvore* no = malloc(sizeof(NoArvore));

    if (no == NULL) {
        printf("Erro ao alocar memória");
        return NULL;
    }

    no->livro = livro;
    no->direita = NULL;
    no->esquerda = NULL;

    return no;
}

void inserirLivroArvore(Arvore* arvore, Livro* livro){
    arvore->raiz = inserirLivroNoArvore(arvore->raiz, livro);
}

NoArvore* inserirLivroNoArvore(NoArvore* no, Livro* livro){
    if (no == NULL) {
        return criarNoArvore(livro);
    }

    if (obterCodigoLivro(livro) < obterCodigoLivro(no->livro)) {
        no->esquerda = inserirLivroNoArvore(no->esquerda, livro);
    }
    else if (obterCodigoLivro(livro) > obterCodigoLivro(no->livro)) {
        no->direita = inserirLivroNoArvore(no->direita, livro);
    }

    return no;
}

Livro* buscarLivroArvore(Arvore * arvore, int codigo){
    return buscarLivroNoArvore(arvore->raiz, codigo);
}

Livro* buscarLivroNoArvore(NoArvore * no, int codigo){
    if (no == NULL) {
        return NULL;
    }

    if(obterCodigoLivro(no->livro) == codigo) {
        return no->livro;
    }

    if (codigo < obterCodigoLivro(no->livro)) {
        return buscarLivroNoArvore(no->esquerda, codigo);
    }

    return buscarLivroNoArvore(no->direita, codigo);
}

void listarLivrosEmOrdem(Arvore * arvore) {
    listarLivrosEmOrdemNoArvore(arvore->raiz);
}

void listarLivrosEmOrdemNoArvore(NoArvore * no) {
    if (no != NULL) {
        listarLivrosEmOrdemNoArvore(no->esquerda);
        exibirLivro(no->livro);
        listarLivrosEmOrdemNoArvore(no->direita);
    }
}

void listarLivrosPreOrdem(Arvore * arvore) {
    listarLivrosPreOrdemNoArvore(arvore->raiz);
}

void listarLivrosPreOrdemNoArvore(NoArvore * no) {
    if (no != NULL) {
        exibirLivro(no->livro);
        listarLivrosPreOrdemNoArvore(no->esquerda);
        listarLivrosPreOrdemNoArvore(no->direita);
    }
}

void listarLivrosPosOrdem(Arvore * arvore) {
    listarLivrosPosOrdemNoArvore(arvore->raiz);
}

void listarLivrosPosOrdemNoArvore(NoArvore * no) {
    if (no != NULL) {
        listarLivrosPosOrdemNoArvore(no->esquerda);
        listarLivrosPosOrdemNoArvore(no->direita);
        exibirLivro(no->livro);
    }
}

int contarLivros(Arvore* arvore) {
    return contarLivrosNoArvore(arvore->raiz);
}

int contarLivrosNoArvore(NoArvore* no) {
    if (no == NULL)
        return 0;

    return 1 + contarLivrosNoArvore(no->esquerda) + contarLivrosNoArvore(no->direita);
}

int calcularAlturaArvore(Arvore* arvore) {
    return calcularAlturaNoArvore(arvore->raiz);
}

int calcularAlturaNoArvore(NoArvore* no) {
    if (no == NULL) {
        return - 1;
    }

    int altEsq = calcularAlturaNoArvore(no->esquerda);
    int altDir = calcularAlturaNoArvore(no->direita);

    if(altEsq > altDir) {
        return altEsq + 1;
    }

    return altDir + 1;
}

void salvarLivrosRec(FILE *arquivo, NoArvore *no) {
    if (no == NULL)
        return;

    fprintf(
        arquivo,
        "%d;%s;%s;%d;%d;%d\n",
        no->livro->codigo,
        no->livro->titulo,
        no->livro->autor,
        no->livro->ano,
        no->livro->quantidadeTotal,
        no->livro->quantidadeDisponivel
    );

    salvarLivrosRec(arquivo, no->esquerda);

    salvarLivrosRec(arquivo, no->direita);
}

void salvarLivros(Arvore *arvore, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    salvarLivrosRec(arquivo, arvore->raiz);

    fclose(arquivo);
}

Arvore* carregarLivros(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    Arvore *arvore = criarArvore();

    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidadeTotal;
    int quantidadeDisponivel;

    while (fscanf(
        arquivo,
        "%d;%99[^;];%99[^;];%d;%d;%d\n",
        &codigo,
        titulo,
        autor,
        &ano,
        &quantidadeTotal,
        &quantidadeDisponivel
    ) == 6) {

        Livro *livro = criarLivro(
            codigo,
            titulo,
            autor,
            ano,
            quantidadeTotal
        );

        if (livro != NULL) {
            livro->quantidadeDisponivel = quantidadeDisponivel;
            inserirLivroArvore(arvore, livro);
        }
    }

    fclose(arquivo);

    return arvore;
}