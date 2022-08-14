#include <iostream>
#include "arvorebindebusca.h"

using namespace std;

int main()
{
    /*
    Construa uma aplicação para uma Árvore Binária de Busca (BST) de números inteiros que permita ao
    usuário, a partir de um menu, executar as seguintes tarefas:
    1-inserir um novo número
    2-exibir a árvore na pré-ordem
    3-exibir a árvore ná pós-ordem
    4-exibir a árvore ná em ordem
    5-exibir o máximo dos números
    6-exibir o mínimo dos números
    7-excluir um elemento da árvore
    9-fim
    */

    Bst<int> t1;
    int opc, x;

    do{
        cout<<endl;
        cout<<"Arvore Binaria de Busca"<<endl;
        cout<<"1-Inserir numero"<<endl;
        cout<<"2-Exibir pre-ordem"<<endl;
        cout<<"3-Exibir pos-ordem"<<endl;
        cout<<"4-Exibir em  ordem"<<endl;
        cout<<"5-Exibir num maximo"<<endl;
        cout<<"6-Exibir num minimo"<<endl;
        cout<<"7-Remover"<<endl;
        cout<<"9-Sair"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            cout<<"Valor: ";
            cin>>x;
            t1.insere(t1.pRaiz,x);
            break;

        case 2:
            cout<<endl<<"PRE-ORDEM: "<<endl;
            t1.preOrdem(t1.pRaiz);
            break;

        case 3:
            cout<<endl<<"POS-ORDEM: "<<endl;
            t1.posOrdem(t1.pRaiz);
            break;

        case 4:
            cout<<endl<<"EM  ORDEM: "<<endl;
            t1.emOrdem(t1.pRaiz);
            break;

        case 5:
            cout<<endl<<"Numero maximo: "<<t1.getMaximo(t1.pRaiz)<<endl;
            break;

        case 6:
            cout<<endl<<"Numero minimo: "<<t1.getMinimo(t1.pRaiz)<<endl;
            break;

        case 7:
            cout<<endl<<"EM  ORDEM: "<<endl;
            t1.emOrdem(t1.pRaiz);
            cout<<endl<<"Numero a remover: "<<endl;
            cin>>x;

            t1.remover(t1.pRaiz, x);
            cout<<endl<<"EM  ORDEM: "<<endl;
            t1.emOrdem(t1.pRaiz);
            //if (t1.remover(t1.pRaiz, x) == 0) //se função não é void
            //    cout << "O numero nao existe na arvore" << endl;

            //cout<<endl<<"EM  ORDEM: "<<endl;
            //t1.emOrdem(t1.pRaiz);

            break;

        default:
            break;
        }

    }while(opc != 9);

    return 0;
}
