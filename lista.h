#ifndef LISTA_H
#define LISTA_H

typedef struct Emprestimo{
    char nomeUsuario[100];
    int codigoLivro;
    char tituloLivro[100];
}Emprestimo;

typedef struct NoLista{
    Emprestimo emprestimo;
    struct NoLista * proximo;
}NoLista;

typedef struct Lista{
    NoLista * inicio;
}Lista ;

Lista * criarLista();

void inserirEmprestimo(Lista* lista, Emprestimo* emprestimo);

void listarEmprestimo(Lista* lista);

int ListaVazia(Lista* lista);

#endif