#include <iostream>
#include "filadupla.h"

//Fila Dupla Ex6 por Marcos Henrique Ribeiro Zanetti

using namespace std;

struct Cilindro{
    float altura;
    float raio;
};

float getVolumeCilindo(Cilindro temp){
    return 3.14 * temp.raio * temp.raio * temp.altura; //3,14 = pi
};

int main()
{
    /*6.Considere a figura geométrica Cone:
    a: altura
    r: raio
    V:volume calculado da seguinte forma: V=π*r²*h
    a)	Construa a estrutura Cilindro com os atributos acima e a função que retorne seu volume.
    b)	Construa uma aplicação que utilize uma dupla-fila e apresente um menu permitindo ao usuário as seguintes opções:
     inserir no início, remover do final e exibir o raio, a altura e o volume de cada cilindro pertencente à dupla-fila.
    */
    int opc;

    DuplaFila<Cilindro> pDuplaFila(10);
    Cilindro tempCilindro;

    do{
        cout<<"Cilindros\n\n";

        cout<<"1-Inserir cilindo no inicio da fila"<<endl;
        cout<<"2-Remover cilindo no final da fila"<<endl;
        cout<<"3-Raio, altura e volume de cada cilindro"<<endl;
        cout<<"9-Sair"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            do{
                cout<<"Altura: ";
                cin>>tempCilindro.altura;
                if (tempCilindro.altura <= 0)
                    cout<<"Valor invalido! Digite um numero maior que zero."<<endl;
            }while (tempCilindro.altura <= 0);

            do{
                cout<<"Raio: ";
                cin>>tempCilindro.raio;
                if (tempCilindro.raio <= 0)
                    cout<<"Valor invalido! Digite um numero maior que zero."<<endl;
            }while (tempCilindro.raio <= 0);
            //cout<<fixed<<" Altura "<<tempCilindro.altura<<"; Raio "<<tempCilindro.raio<<"; Volume "<<getVolume(tempCilindro)<<endl;

            pDuplaFila.insereTopo(tempCilindro);
            cout<<"Adicionado para a fila."<<endl;
            break;

        case 2:
            if (pDuplaFila.filaVazia())
                cout<<"Fila vazia..."<<endl;
            else{
                tempCilindro = pDuplaFila.removeFim();
                cout<<"Removido o cilindro de altura "<<tempCilindro.altura<<" e raio "<<tempCilindro.raio<<endl;
            }
            break;

        case 3:
            if (pDuplaFila.filaVazia())
                cout<<"Fila vazia..."<<endl;
            else{
                for (int i = 0; i < pDuplaFila.getQtde(); i++){
                    tempCilindro = pDuplaFila.getValor((i+pDuplaFila.getInic())%pDuplaFila.getTamanho());
                    cout<<fixed<<i+1<<" - Altura "<<tempCilindro.altura<<"; Raio "<<tempCilindro.raio<<"; Volume "<<getVolumeCilindo(tempCilindro)<<endl;
                }
            cout<<endl;
            }
            break;

        default:
            break;
        }
    }while (opc != 9);

    return 0;
}
