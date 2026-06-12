#include <stdio.h>
#include <stdlib.h>
#include "Fila.c"

int main(){
    Fila* fila = criarFila();
    
    Reserva r1;
    strcpy(r1.nomeUsuario, "Joao");
    r1.codigoLivro=1234;
    Reserva r2;
    strcpy(r2.nomeUsuario, "Lucas");
    r2.codigoLivro=5678;

    enfileirarReserva(fila, r1);
    enfileirarReserva(fila, r2);

    exibirReservas(fila);
    return 0;
}