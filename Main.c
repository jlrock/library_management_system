#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "livro.h"
#include "Fila.c"
//importar as outras estruturas quando forem criadas
char livros_file[] = "livros.txt";

int main(){
    /*instanciar Arvore e Lista quando estiverem prontas 
    (talvez a Fila, pois ela só será utilizada caso aja reservas)*/
    Arvore* arvore = carregarLivros(livros_file);
    listarLivrosEmOrdem(arvore);
    char opcao;
    printf("\n//============SISTEMA DE GERENCIAMENTO DE BIBLIOTECA============//\n");
    printf("Bem vindo(a) ao nosso sistema de gerenciamento de biblioteca! Escolha entre as opcoes do menu abaixo:\n");
    do{
        printf("//==================================//\n");
        printf("        ___M___E___N___U___\n");
        printf("//==================================//\n");
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
            //as acoes ainda serao implementadas
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
                gets(titulo);
                char autor[100];
                printf("Insira o nome do autor: ");
                gets(autor);
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
                    printf("O livro não existe na biblioteca.\n");
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
            case 'f':
                printf("Acao F\n");
                break;
            case 'g':
                printf("Acao G\n");
                break;
            case 'h':
                printf("Acao H\n");
                break;
            case 'i':
                printf("Acao I\n");
                break;
            case 'j':
                printf("Acao J\n");
                break;
            case 'k':
                printf("Acao K\n");
                break;
        
            case 'q':
                printf("Obrigado, ate logo! Saindo...\n");
                break;
        
            default:
                printf("Ops... Opcao invalida. Tente novamente.\n");
                break;
        }
        printf("Pressione [ENTER] para continuar.\n");
        getchar();
    } while (opcao != 'q');
    
    salvarLivros(arvore, livros_file);
    limparArvore(arvore);

    return 0;
}