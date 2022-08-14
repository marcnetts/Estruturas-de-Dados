#include <iostream>
#include "fila.h"
#include "pilha.h"

//Pilha e Fila Ex5 por Marcos Henrique Ribeiro Zanetti


using namespace std;

int main()
{
    /*
    5.	Considerando uma pilha e uma fila, de números inteiros, construa uma aplicação que permita ao usuários as
    seguintes opções, exibidas no formato de menu.
    a)	Inserção de dados na fila.
    b)	Exibição da fila
    c)	Remoção TODOS os elementos da fila; sendo que a cada remoção, caso o elemento removido seja um número
    múltiplo de 5, insira-o na pilha.
    d)	Exibir a pilha
    */

    Fila<int> pFila(20);
    Pilha<int> pPilha(20);
    int opc, x;

    do{
        cout<<"Pilhas e Filas\n\n";
        cout<<"1-Inserir numero na fila"<<endl;
        cout<<"2-Exibir fila"<<endl;
        cout<<"3-Limpar fila e passar multiplos de 5 para pilha"<<endl;
        cout<<"4-Eibir pilha"<<endl;
        cout<<"9-Sair"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            if (pFila.filaCheia())
                cout<<"Fila Cheia!";
            else
            {
                cout<<"Valor: ";
                cin>>x;
                pFila.insere(x);
            }
            break;

        case 2:
            cout<<"\nFila:\n";
            for(int i = 0; i < pFila.getQtde(); i++){
                cout<<pFila.getValor(i)<<" ";
            }
            cout<<"\n\n";
            break;

        case 3:
            cout<<"\nTransferindo...\n\n";
            while (pFila.filaVazia() == 0){
                if (pFila.getValor(pFila.getInic()) %5 == 0)
                {
                    if (pPilha.pilhaCheia())
                    {
                        cout<<"Pilha Cheia.";
                        pFila.desenfila();
                    }
                    else
                    pPilha.empilha(pFila.desenfila());
                }
                else
                    pFila.desenfila();
            }
            break;

        case 4:
            cout<<"\nPilha:\n";
            for(int i = 0; i < pPilha.getTopo() + 1; i++){
                cout<<pPilha.getValor(i)<<" ";
            }
            cout<<"\n\n";
            break;

        default:
            break;
        }
    }while(opc != 9);

    return 0;
}
