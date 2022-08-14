#include <iostream>
#include <windows.h> //só para cores
#include "hashing.h"
//Lista 9 por Marcos Henrique Ribeiro Zanetti

using namespace std;

/*
Construa uma aplicação para uma Tabela de Espalhamento (Hashing)  de números inteiros.
Para tal, utilize Lista Ordenada ou Árvore Binária de Busca, permitindo ao usuário, a partir de um menu, executar as seguintes tarefas:
1-inserir um novo número
2-realizar a busca de um elemento
3-excluir um elemento
4-exibir a tabela hashing
9-fim
*/

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //ListaOrdenada<int> lista;

    Hash dh;
    Node *aux;
    int opc, x, retornado;

    do{
        cout<<endl;
        SetConsoleTextAttribute(hConsole, 11);
        cout << "Tabela Hashing" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"1-Inserir numero"<<endl;
        cout<<"2-Buscar elemento"<<endl;
        cout<<"3-Excluir elemento"<<endl;
        cout<<"4-Exibir tabela"<<endl;
        cout<<"9-Sair"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            cout<<"Valor: ";
            cin>>x;
            dh.insere(x);
            break;

        case 2:
            cout<<"Elemento a buscar: ";
            cin>>x;
            retornado = dh.buscaElem(x);

            if(retornado == -1)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Elemento nao esta na lista."<<endl;
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
                cout<<x<<" esta na "<<retornado<<" posicao da lista h["<< dh.fht(x) <<"]."<<endl;
            break;

        case 3:
            cout<<"Elemento a remover: ";
            cin>>x;

            //if(dh.listaNumVazia(x))
            //    cout << "Lista vazia!" << endl;
            if(dh.remover(x) == 0)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Elemento nao esta em nenhuma lista."<<endl;
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
                cout<<"Removido."<<endl;
            break;

        case 4:
            cout<<endl<<"Elementos da lista:"<<endl;
            for (int i = 0; i < W; i++){ //W declarado no header
                aux = dh.h[i];
                cout << "h[" << i << "]->";
                if(dh.listaVazia(i))
                    cout << " (vazia)";
                else{
                    while (aux != NULL){
                        cout << aux->info << " ";
                        aux = aux->prox;
                    }
                }
                cout << endl;
            }
            cout<<endl;
            break;

        default:
            break;
        }

    }while(opc != 9);

    /*cout << "Tabela Hashing" << endl;
    Hash dh;
    dh.insere(54);
    dh.insere(15);
    dh.insere(7);
    dh.insere(78);
    dh.insere(14);
    dh.insere(95);
    dh.insere(21);
    dh.insere(46);
    dh.insere(33);
    dh.insere(9);
    dh.insere(62);
    dh.insere(87);

    for (int i = 0; i < W; i++){ //W declarado no header
        Node *aux = dh.h[i];
        cout << "h[" << i << "]->";
        while (aux != NULL){
            cout << aux->info << " ";
            aux = aux->prox;
        }
        cout << endl;
    }*/

    return 0;
}
