#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include "pilha.h"

using namespace std;

/*
Considerando uma pilha e uma fila, de números inteiros, construa uma aplicação que:
a) define uma pilha e uma fila de tamanho 20.
b) carrega a fila com números aleatórios compreendidos entre 35 e 78
b) exibe a fila
c) transfere todos os elementos da fila para a pilha
d) exibe a pilha
*/
int main()
{
    Fila<int> pFila(20);
    Pilha<int> pPilha(20);

    srand (time(NULL));
    for(int i = 0; i < 20; i++){
        pFila.insere(35 + (rand()%44));
    }

    cout<<"\n\nFila: \n";
    for(int i = 0; i < 20; i++){
        cout<<pFila.getValor(i)<<" ";
    }

    cout<<"\nTransferindo...";
    for(int i = 0; i < 20; i++){
        pPilha.empilha(pFila.desenfila());
    }

    cout<<"\n\nPilha:\n";
    for(int i = 0; i < 20; i++){
        cout<<pPilha.getValor(i)<<" ";
    }

    return 0;
}
