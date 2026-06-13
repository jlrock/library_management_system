#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

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

void emprestarExemplar(Livro* livro){
    livro->quantidadeDisponivel--;
}

void devolverExemplar(Livro* livro){
    livro->quantidadeDisponivel++;
}
