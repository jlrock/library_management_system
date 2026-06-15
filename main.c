#include <stdio.h>
#include <stdlib.h>
#include "Lista/Lista.h"

int main() {
    Lista *l = criarLista();
    if (l == NULL) return 1;

    Emprestimo e1 = {"Gustavo", 1111, "Livro legal"};
    inserirEmprestimo(l, e1);
    Emprestimo e2 = {"João Lucas", 2222, "Livro doido"};
    inserirEmprestimo(l, e2);
    Emprestimo e3 = {"Moisés", 3333, "Livro bom"};
    inserirEmprestimo(l, e3);
    Emprestimo e4 = {"Bonfim", 4444, "Viagem ao Centro da Terra"};
    inserirEmprestimo(l, e4);
    listarEmprestimos(l);

    freeLista(l);
    l = NULL;

    return 0;
}
