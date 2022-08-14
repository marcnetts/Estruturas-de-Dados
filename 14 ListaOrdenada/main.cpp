#include <iostream>
#include "listaordenada.h"

//Lista 8 por Marcos Henrique Ribeiro Zanetti
using namespace std;

int main()
{
    /*
    Construa uma aplicação para uma Lista Ordenada de números inteiros que permita ao
    usuário, a partir de um menu, executar as seguintes tarefas:
    1-inserir um novo número
    2-realizar a busca de um elemento
    3-excluir um elemento
    4-exibir a lista
    9-fim
    */
    ListaOrdenada<int> lista;
    int opc, x, retornado;
    Node<int> *aux;

    do{
        cout<<endl;
        cout<<"Lista Ordenada"<<endl;
        cout<<"1-Inserir numero"<<endl;
        cout<<"2-Buscar elemento"<<endl;
        cout<<"3-Excluir elemento"<<endl;
        cout<<"4-Exibir lista"<<endl;
        cout<<"9-Sair"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            cout<<"Valor: ";
            cin>>x;
            lista.insere(x);
            break;

        case 2:
            cout<<"Elemento a buscar: ";
            cin>>x;
            retornado = lista.buscaElem(x);

            if(retornado == -1)
                cout<<"Elemento nao esta na lista."<<endl;
            else
                cout<<x<<" esta na "<<retornado<<" posicao."<<endl;
            break;

        case 3:
            cout<<"Elemento a remover: ";
            cin>>x;

            if(lista.remover(x) == 0)
                cout<<"Elemento nao esta na lista."<<endl;
            else
                cout<<"Removido."<<endl;
            break;

        case 4:
            aux = lista.h;
            if(aux == NULL)
                cout<<"Lista vazia!"<<endl;
            else
            {
                cout<<endl<<"Elementos da lista:"<<endl;
                while (aux != NULL)
                {
                    cout<<aux->info<<" ";
                    aux = aux->prox;
                }
                cout<<endl;
            }
            break;

        default:
            break;
        }

    }while(opc != 9);

    return 0;
}
