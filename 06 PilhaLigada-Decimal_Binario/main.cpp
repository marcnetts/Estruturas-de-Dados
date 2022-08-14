#include <iostream>
#include "pilhaseq.h"

using namespace std;

int main()
{
    PilhaSeq<bool> p; //pilha alocação encadeada
    int numtotal;
    cout<<"Decimal para Binario\n";
    cout<<"Digite o numero em decimal:\n"<<endl;
    cin>>numtotal;

    while (numtotal != 0){
        p.empilha(numtotal % 2);
        numtotal /= 2;
    }

    cout<<"Convertido para binario:\n"<<endl;
    if(p.pilhaVazia())
    {
        cout<<0;
    }
    else
    {
        while (p.pilhaVazia() == 0){
            cout<<p.desempilha();
        }
    }

    return 0;
}
