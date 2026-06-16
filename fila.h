#ifndef FILA_H
#define FILA_H
typedef struct {
    char nomeUsuario[100];
    int codigoLivro;
} Reserva;

typedef struct NoFila {

    Reserva* reserva;

    struct NoFila* proximo;

} NoFila;

typedef struct {

    NoFila* inicio;
    NoFila* fim;

} Fila;

Fila* criarFila();

Reserva* criarReserva(char nome[], int codigo);

int filaVazia(Fila* fila);

void enfileirarReserva(Fila* fila, Reserva* reserva);

Reserva* desenfileirarReserva(Fila* fila);

void exibirReservas(Fila* fila);

Fila *carregarReservas(const char *nomeArquivo);

void salvarReservas(Fila *fila, const char *nomeArquivo);

#endif