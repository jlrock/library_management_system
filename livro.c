#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "lista.h"

Livro* criarLivro(int codigo, char titulo[], char autor[], int ano, int quantidadeTotal){
    Livro* livro = malloc(sizeof(Livro));

    if (livro == NULL) {
        printf("Erro ao alocar memória");
        return NULL;
    }

    livro->codigo = codigo;
    strcpy(livro->titulo, titulo);
    strcpy(livro->autor, autor);
    livro->ano = ano;
    livro->quantidadeTotal = quantidadeTotal;
    livro->quantidadeDisponivel = quantidadeTotal;
    return livro;
}

void exibirLivro(Livro* livro){
    printf("Titulo: %s\n", livro->titulo);
    printf("Ano de publicacao: %d\n", livro->ano);
    printf("Autor: %s\n", livro->autor);
    printf("Codigo: %d\n", livro->codigo);
    printf("Quantidade disponivel: %d\n", livro->quantidadeDisponivel);
    printf("Quantidade total: %d\n", livro->quantidadeTotal);
    printf("\n");
}

int obterCodigoLivro(Livro* livro){
    return livro->codigo;
}

int obterQuantidadeDisponivel(Livro* livro){
    return livro->quantidadeDisponivel;
}

Emprestimo *emprestarExemplar(Livro* livro, char nome[]){
    if (livro->quantidadeDisponivel > 0) {
        livro->quantidadeDisponivel--;
        return criarEmprestimo(nome, livro->codigo, livro->titulo);
    }

    return NULL;
}

void devolverExemplar(Livro* livro){
    if (livro->quantidadeDisponivel < livro->quantidadeTotal) {
        livro->quantidadeDisponivel++;
        printf("Devolucao efetuada\n");
    }
    else {
        printf("Nao exite emprestimo corrente desse livro\n");
    }
}
