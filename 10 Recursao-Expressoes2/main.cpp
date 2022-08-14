#include <iostream>
#include "pilhasrecurs.h"
using namespace std;

/*
Ex. 1: Calcule o mdc(64,14)
Ex. 2: Calcule s(10, 15)
Ex. 3: Calcule s2(10,15)
    Calcule s2(1,10)
Ex. 4: Calcule dig(532)
    Calcule dig(101)
Ex. 5: Calcule pot(2,5)
    Calcule pot(3,4)
*/
int main()
{
    cout<<"fib(6): "<<fib(6)<<endl;
    cout<<"mdc(64,14): "<<mdc(64,14)<<endl;
    cout<<"s(10,15): "<<s(10,15)<<endl;
    cout<<"s2(10,15): "<<s2(10,15)<<endl;
    cout<<"dig(532): "<<dig(532)<<endl;
    cout<<"dig(101): "<<dig(101)<<endl;
    cout<<"pot(2,5): "<<pot(2,5)<<endl;
    cout<<"pot(3,4): "<<pot(3,4)<<endl;

    char opc;
    int x, y;
    do{
        cout<<endl<<"1 - fib"<<endl;
        cout<<"2 - mdc"<<endl;
        cout<<"3 - s"<<endl;
        cout<<"4 - s2"<<endl;
        cout<<"5 - dig"<<endl;
        cout<<"6 - pot"<<endl;
        cout<<"0 - (sair)"<<endl;
        cin>>opc;

        switch(opc){
        case '1':
            cout<<"Valor: ";
            cin>>x;
            cout<<"fib("<<x<<"): "<<fib(x)<<endl;
            break;

        case '2':
            cout<<"Valor de x: ";
            cin>>x;
            cout<<"Valor de y: ";
            cin>>y;
            cout<<"mdc(x,y): "<<mdc(x,y)<<endl;
            break;

        case '3':
            cout<<"Valor de x: ";
            cin>>x;
            cout<<"Valor de y: ";
            cin>>y;
            cout<<"s(x,y): "<<s(x,y)<<endl;
            break;

        case '4':
            cout<<"Valor de x: ";
            cin>>x;
            cout<<"Valor de y: ";
            cin>>y;
            cout<<"s2(x,y): "<<s2(x,y)<<endl;
            break;

        case '5':
            cout<<"Valor: ";
            cin>>x;
            cout<<"dig(x): "<<dig(x)<<endl;
            break;

        case '6':
            cout<<"Valor de x: ";
            cin>>x;
            cout<<"Valor de y: ";
            cin>>y;
            cout<<"pot(x,y): "<<pot(x,y)<<endl;
            break;

        default:
            break;

        }

    }while (opc != '0');

    return 0;
}

