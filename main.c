#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"
#include "livro.h"
#include "lista.h"
#include "fila.h"

char livros_file[] = "livros.txt";
char emprestimos_file[] = "emprestimos.txt";
char reservas_file[] = "reservas.txt";

int main(){
    Arvore* arvore = carregarLivros(livros_file);
    Lista * lista = carregarEmprestimos(emprestimos_file);
    Fila * fila = carregarReservas(reservas_file);

    char opcao;
    printf("\n//=============== SISTEMA DE GERENCIAMENTO DE BIBLIOTECA ===============//\n");
    printf("Bem vindo(a) ao nosso sistema de gerenciamento de biblioteca! Escolha entre as opcoes do menu abaixo:\n");
    do{
        printf("//=============================================//\n");
        printf("                 MENU PRINCIPAL\n");
        printf("//=============================================//\n");
        printf("a. Cadastrar novo livro\n");
        printf("b. Buscar livro por codigo\n");
        printf("c. Listar livros em ordem crescente de codigo\n");
        printf("d. Listar livros em pre-ordem\n");
        printf("e. Listar livros em pos-ordem\n");
        printf("f. Realizar emprestimo de livro\n");
        printf("g. Devolver livro\n");
        printf("h. Exibir fila de reservas\n");
        printf("i. Exibir historico de emprestimos\n");
        printf("j. Exibir quantidade de livros cadastrados\n");
        printf("k. Exibir altura da arvore\n");
        printf("q. Sair\n");

        scanf("%c", &opcao);
        getchar();

        printf("\n");

        switch (opcao)
        {
            case 'a': {
                printf("Cadastro de Livro\n");
                printf("Insira o codigo do livro: ");
                int codigo;
                scanf("%d", &codigo);
                getchar();
                if (buscarLivroArvore(arvore, codigo) != NULL) {
                    printf("Ja existe um livro com esse codigo\n");
                    break;
                }
                char titulo[100];
                printf("Insira o titulo do livro: ");
                fgets(titulo, sizeof(titulo), stdin);
                char autor[100];
                printf("Insira o nome do autor: ");
                fgets(autor, sizeof(autor), stdin);
                int ano;
                printf("Insira o ano de publicacao: ");
                scanf("%d", &ano);
                getchar();
                int qtdTotal;
                printf("Insira a quantidade total de livros: ");
                scanf("%d", &qtdTotal);
                getchar();
                Livro * livro = criarLivro(codigo, titulo, autor, ano, qtdTotal);
                if (livro == NULL) {
                    printf("Erro ao criar o livro\n");
                    break;
                }
                inserirLivroArvore(arvore, livro);
                printf("Livro inserido com sucesso\n");
                break;
            }
            case 'b': {
                printf("Buscar Livro\n");
                int codigo;
                printf("Insira o codigo do livro: ");
                scanf("%d", &codigo);
                getchar();
                Livro* livro = buscarLivroArvore(arvore, codigo);
                if (livro == NULL) {
                    printf("O livro nAo existe na biblioteca.\n");
                    break;
                }
                printf("\n\nDados do livro:\n");
                exibirLivro(livro);
                break;
            }
            case 'c':
                listarLivrosEmOrdem(arvore);
                break;
            case 'd':
                listarLivrosPreOrdem(arvore);
                break;
            case 'e':
                listarLivrosPosOrdem(arvore);
                break;
            case 'f': {
                printf("Emprestimo de Livro\n");
                int codigo;
                printf("Insira o codigo do livro: ");
                scanf("%d", &codigo);
                getchar();
                Livro * l = buscarLivroArvore(arvore, codigo);
                if (l == NULL) {
                    printf("Livro nao encontrado\n");
                    break;
                }
                char nome[100];
                printf("Insira o nome do usuario: ");
                fgets(nome, sizeof(nome), stdin);
                Emprestimo *e = emprestarExemplar(l, nome);
                if (e == NULL) {
                    printf("Nao ha exemplares disponiveis\n");
                    int opt;
                    printf("Digite 1 para fazer uma reserva ou qualquer outro numero para nao fazer: ");
                    scanf("%d", &opt);
                    getchar();
                    if (opt == 1) {
                        Reserva *r = criarReserva(nome, codigo);
                        enfileirarReserva(fila, r);
                        printf("Uma reserva foi criada\n");
                    } else {
                        printf("Reserva nao criada\n");
                    }
                    break;
                }
                inserirEmprestimo(lista, e);
                printf("Livro emprestado com sucesso\n");
                break;
            }
            case 'g': {
                printf("Devolucao de Livro\n");
                int codigo;
                printf("Digite o codigo do livro: ");
                scanf("%d", &codigo);
                getchar();
                Livro *l = buscarLivroArvore(arvore, codigo);
                if (l == NULL) {
                    printf("Livro nao encontrado\n");
                    break;
                }
                devolverExemplar(l);
                if (fila->inicio->reserva->codigoLivro == codigo) {
                    Reserva *r = desenfileirarReserva(fila);
                    Emprestimo *e = emprestarExemplar(l, r->nomeUsuario);
                    inserirEmprestimo(lista, e);
                    printf("Livro emprestado em decorrencia da reserva\n");
                }
                break;
            }
            case 'h':
                exibirReservas(fila);
                break;
            case 'i':
                listarEmprestimos(lista);
                break;
            case 'j':
                printf("Quantidade de livros cadastrados: %d\n", contarLivros(arvore));
                break;
            case 'k':
                printf("Altura da arvore: %d\n", calcularAlturaArvore(arvore));
                break;
            case 'q':
                printf("Obrigado, ate logo!\n");
                printf("Saindo...\n");
                break;
        
            default:
                printf("Ops... Opcao invalida. Tente novamente.\n");
                break;
        }
        printf("Pressione [ENTER] para continuar.\n");
        getchar();
    } while (opcao != 'q');
    
    salvarReservas(fila, reservas_file);
    freeFila(fila);
    salvarEmprestimos(lista, emprestimos_file);
    freeLista(lista);
    salvarLivros(arvore, livros_file);
    limparArvore(arvore);

    return 0;
}