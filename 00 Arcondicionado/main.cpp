#include <iostream>
#include "arcondicionado.h"

using namespace std;

int main()
{
    cout << "Controle do Ar Condicionado" << endl;
    int opc;
    Temperatura t1;
    do{
        cout << "Temperatura:" << t1.getTemperatura() << endl;
        cout << "1-aumentar" << endl;
        cout << "2-diminuir" << endl;
        cout << "9-sair" << endl;
        cout << "Selecione:";
        cin >> opc;
        switch (opc){
        case 1:
            t1.aumentar();
            break;
        case 2:
            t1.diminuir();

        case 9:
            cout<<"Fim....."<<endl;
            break;
        default:
            cout<<"Opcao invalida"<<endl;
            break;
        }
    }while (opc != 9);
    return 0;
}
