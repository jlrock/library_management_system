#ifndef LISTA_H
#define LISTA_H

typedef struct {
    char nomeUsuario[100];
    int codigoLivro;
    char tituloLivro[100];
} Emprestimo;

typedef struct NoLista {

    Emprestimo *emprestimo;

    struct NoLista *prox;

} NoLista;

typedef struct {
    NoLista *inicio;
} Lista;

Lista *criarLista();

Emprestimo *criarEmprestimo(
    char nome[],
    int codigo,
    char titulo[]
);

NoLista *encontrarNo(
    Lista *l,
    int index
);

void inserirEmprestimo(
    Lista *l,
    Emprestimo *e
);

void listarEmprestimos(
    Lista *l
);

int listaVazia(
    Lista *l
);

void freeLista(
    Lista *l
);

Lista *carregarEmprestimos(const char *nomeArquivo);
void salvarEmprestimos(Lista *lista, const char *nomeArquivo);


#endif