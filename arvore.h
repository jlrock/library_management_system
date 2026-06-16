#ifndef ARVORE_H
#define ARVORE_H
#include "livro.h"

typedef struct NoArvore{
    Livro* livro;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

typedef struct Arvore{
    NoArvore* raiz;
} Arvore;

Arvore* criarArvore();
NoArvore* criarNoArvore();

void inserirLivroArvore(Arvore* arvore, Livro* livro);
NoArvore* inserirLivroNoArvore(NoArvore* no, Livro* livro);

Livro* buscarLivroArvore(Arvore * arvore, int codigo);

Livro* buscarLivroNoArvore(NoArvore * arvore, int codigo);

void listarLivrosEmOrdem(Arvore * arvore);

void listarLivrosPreOrdem(Arvore * arvore);

void listarLivrosPosOrdem(Arvore * arvore);

int contarLivros(Arvore* arvore);

int calcularAlturaArvore(Arvore* arvore);

void salvarLivrosRec(FILE *arquivo, NoArvore *no);

void salvarLivros(Arvore *arvore, const char *nomeArquivo);

void listarLivrosEmOrdemNoArvore(NoArvore * no);
void listarLivrosPreOrdemNoArvore(NoArvore * no);
void listarLivrosPosOrdemNoArvore(NoArvore * no);
int contarLivrosNoArvore(NoArvore* no);
int calcularAlturaNoArvore(NoArvore* no);
void limparArvore(Arvore * arvore);
void limparNoArvore(NoArvore *no);

Arvore* carregarLivros(const char *nomeArquivo);


#endif