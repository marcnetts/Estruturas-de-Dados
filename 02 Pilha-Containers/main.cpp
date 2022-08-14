#include <iostream>
#include "pilha.h"

//containers por Marcos Henrique Ribeiro Zanetti

using namespace std;

struct CC{
    int codigo;
    int tamanho;
};

int main()
{
    /*Pilha de pátio de containers vazios*/
    cout << "Pilhas de Containers" << endl << endl;
    int tamPatio, posicP;
    int opc, valor;
    tamPatio = 10;

    Pilha<CC> *p[tamPatio];

    //Inicializando 10 pilhas de CC
    for (int i=0;i<tamPatio;i++)
        p[i] = new Pilha<CC>(5);

    CC conteiner;

    do{
        //Imprimindo "pilhas"
        for (int i = 0; i < tamPatio; i++)
            cout<<((*p[i]).getTopo() + 1)<<" ";
        cout<<"\n";
        for (int i = 0; i < tamPatio; i++)
            cout<<"__";
        cout<<"\n";

        cout<<"1-Empilhar"<<endl;
        cout<<"2-Desempilhar"<<endl;
        cout<<"3-Exibir todas pilhas"<<endl;
        cout<<"4-Exibir uma pilha"<<endl;
        cout<<"5-Elemento do topo"<<endl;
        cout<<"9-Sair"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            do{
                cout<<"Pilha a selecionar: ";
                cin>>posicP;
                if (posicP <= 0 || posicP > tamPatio)
                    cout<<"Valor invalido! ";
            }while(posicP <= 0 || posicP > tamPatio);

            if (p[posicP-1]->pilhaCheia()){
                cout<<"Pilha cheia..."<<endl;
                break;
            }
            do{
                cout<<"Codigo do novo conteiner: ";
                cin>>conteiner.codigo;
                if (conteiner.codigo <= 0)
                    cout<<"Valor deve ser maior que zero."<<endl;
            }while(conteiner.codigo <= 0);
            do{
                cout<<"Tamanho do novo conteiner: ";
                cin>>conteiner.tamanho;
                if (conteiner.tamanho <= 0)
                    cout<<"Valor deve ser maior que zero."<<endl;
            }while(conteiner.tamanho <= 0);

            //(*p[posicP-1]).pilhaVazia() é o mesmo que p[posicP-1]->pilhaVazia()
            if ((*p[posicP-1]).pilhaVazia() || p[posicP-1]->elementoDoTopo().tamanho == conteiner.tamanho)
            {
                p[posicP-1]->empilha(conteiner);
                cout<<"Sucesso"<<endl;
            }
            else
                cout << "Conteiner anterior com tamanho diferente! Abortando..." <<endl;
            break;

        case 2:
            do{
                cout<<"Pilha a selecionar: ";
                cin>>posicP;
                if (posicP == 0 || posicP > tamPatio)
                    cout<<"Valor invalido!";
            }while(posicP == 0 || posicP > tamPatio);

            if (p[posicP-1]->pilhaVazia()){
                cout<<"Pilha vazia..."<<endl;
                break;
            }
            conteiner = p[posicP-1]->desempilha();
            cout<<"Desempilha: Codigo "<<conteiner.codigo<<"; Tamanho "<<conteiner.tamanho<<endl;
            break;

        case 3:
            for(posicP=0; posicP<tamPatio; posicP++)
            {
                cout<<"Pilha "<<posicP<<": ";
                if (p[posicP]->pilhaVazia()){
                    cout<<"Pilha vazia."<<endl;
                    break;
                }
                cout<<endl<<"\t";
                for (int i=0; i <= p[posicP]->getTopo(); i++){
                    conteiner = p[posicP]->getValor(i);
                    cout<<i+1<<" Cod."<<conteiner.codigo<<" Tam."<<conteiner.tamanho<<endl;
                }
            }
            break;

        case 4:
            do{
                cout<<"Pilha a selecionar: ";
                cin>>posicP;
                if (posicP <= 0 || posicP > tamPatio)
                    cout<<"Valor invalido!";
            }while(posicP <= 0 || posicP > tamPatio);

            if (p[posicP-1]->pilhaVazia()){
                cout<<"Pilha vazia..."<<endl;
                break;
            }
            cout<<"Elementos da pilha: "<<endl;
            for (int i=0; i <= p[posicP-1]->getTopo(); i++){
                conteiner = p[posicP-1]->getValor(i);
                cout<<i+1<<"Cod."<<conteiner.codigo<<" Tam."<<conteiner.tamanho<<endl;
            }
            cout<<"\n";
            break;

        case 5:
            do{
                cout<<"Pilha a selecionar: ";
                cin>>posicP;
                if (posicP == 0 || posicP > tamPatio)
                    cout<<"Valor invalido!";
            }while(posicP == 0 || posicP > tamPatio);

            if (p[posicP-1]->pilhaVazia()){
                cout<<"Pilha vazia..."<<endl;
                break;
            }
            conteiner = p[posicP-1]->getValor(p[posicP-1]->getTopo());
            cout<<"Elemento do topo: Codigo "<<conteiner.codigo<<"; Tamanho "<<conteiner.tamanho<<endl;
            break;

        case 9:
            cout<<"Fim..."<<endl;
            break;

        default:
            cout<<"Opcao invalida!"<<endl;
            break;
        }
        cout<<"\n";

    }while (opc != 9);

    return 0;
}
