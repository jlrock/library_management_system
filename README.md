# Sistema de Gerenciamento de Biblioteca

## Equipe:
- Gustavo de Melo Timbó
- João Lucas Simões Rocha da Silveira
- José Moisés da Silva Lima 

## Descrição: 
O projeto é um sistema gerenciador de acervo bibliotecário desenvolvido em linguagem C e executado via terminal. Ele se baseia em 3 tipos abstratos de dados (TAD's):

- Livro
- Reserva
- Empréstimo

E implementa 3 estruturas de dados em sua composição:

- Árvore Binária de Busca (ABB): Armazena e organiza cada livro da biblioteca em função do código;
- Fila: Armazena as reservas dos livros que não possuem exemplares disponíveis;
- Lista encadeada: Armazena o histórico de empréstimos realizados.

## Como compilar:
```bash
gcc main.c livro.c arvore.c fila.c lista.c -o biblioteca
```

## Como executar:
```bash
biblioteca.exe
```

## Exemplos de uso:
### Exemplo 1:
```text
//=============================================//
                 MENU PRINCIPAL
//=============================================//
a. Cadastrar novo livro
b. Buscar livro por codigo
c. Listar livros em ordem crescente de codigo
d. Listar livros em pre-ordem
e. Listar livros em pos-ordem
f. Realizar emprestimo de livro
g. Devolver livro
h. Exibir fila de reservas
i. Exibir historico de emprestimos
j. Exibir quantidade de livros cadastrados
k. Exibir altura da arvore
q. Sair
a

Cadastro de Livro
Insira o codigo do livro: 123
Insira o titulo do livro: A Menina que roubava livros 
Insira o nome do autor: Markus Zusak
Insira o ano de publicacao: 2000
Insira a quantidade total de livros: 50
Livro inserido com sucesso
Pressione [ENTER] para continuar.
```

### Exemplo 2:
```text
Emprestimo de Livro
Insira o codigo do livro: 234
Insira o nome do usuario: Pedro
Nao ha exemplares disponiveis
Digite 1 para fazer uma reserva ou qualquer outro numero para nao fazer: 1
Uma reserva foi criada
Pressione [ENTER] para continuar.
```

### Exemplo 3:
```text
Usuario: JL
Codigo do livro: 234
Titulo do livro: HQ Homem Aranha

Usuario: Moises
Codigo do livro: 123
Titulo do livro: A Menina que roubava livros

Usuario: Gustavo
Codigo do livro: 345
Titulo do livro: Manga One Piece
Pressione [ENTER] para continuar.
```

## Funcionalidades extras implementadas:
- Armazenamento e reutilização dos dados em arquivos;
- Liberação adequada de memória antes de encerrar o sistema.

## Limitações conhecidas:
- O sistema utiliza uma única fila de reservas para todos os livros existentes, logo, mesmo que o livro que uma pessoa deseja já esteja disponível, ela só poderá realizar o empréstimo quando for a primeira da fila;
