#include "lista.h"

#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidadeTotal;
    int quantidadeDisponivel;
} Livro;

Livro* criarLivro(int codigo, char titulo[], char autor[], int ano, int quantidadeTotal);

void exibirLivro(Livro* livro);

int obterCodigoLivro(Livro* livro);

int obterQuantidadeDisponivel(Livro* livro);

Emprestimo *emprestarExemplar(Livro* livro, char nome[]);

void devolverExemplar(Livro* livro);

#endif