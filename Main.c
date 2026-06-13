#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.c"
//importar as outras estruturas quando forem criadas

int main(){
    /*instanciar Arvore e Lista quando estiverem prontas 
    (talvez a Fila, pois ela só será utilizada caso aja reservas)*/
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

        switch (opcao)
        {
            //as acoes ainda serao implementadas
            case 'a':
                printf("Acao A\n");
                break;
            case 'b':
                printf("Acao B\n");
                break;
            case 'c':
                printf("Acao C\n");
                break;
            case 'd':
                printf("Acao D\n");
                break;
            case 'e':
                printf("Acao E\n");
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
    
    return 0;
}