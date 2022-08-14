#include <iostream>
#include <windows.h> //s� para cores
#include "filadupla.h"

//Fila por Marcos Henrique Ribeiro Zanetti

using namespace std;

struct Documento{
    char nome[15];
    unsigned numPaginas;
};

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    unsigned tamQtdImpress, posicP;
    int opc;
    tamQtdImpress = 3;

    //Criando um vetor de numPaginas 3 de ponteiros p para fila
    DuplaFila<Documento> *p[tamQtdImpress];

    //Inicializando 3 filas de Impressoras
    for (int i=0;i<tamQtdImpress;i++)
        p[i] = new DuplaFila<Documento>(5);

    Documento graficaImp;

    do{
        //Imprimindo "filas"
        SetConsoleTextAttribute(hConsole, 11);
        cout<<"Grafica Fatec\n\n";
        SetConsoleTextAttribute(hConsole, 15);
        for (int i = 0; i < tamQtdImpress; i++)
        {
            if (p[i]->filaVazia())
                SetConsoleTextAttribute(hConsole, 10);
            else if (p[i]->filaCheia())
                SetConsoleTextAttribute(hConsole, 6);
            else
                SetConsoleTextAttribute(hConsole, 14);
            cout<<" "<<((*p[i]).getQtde())<<" ";
        }
        cout<<"\n";
        for (int i = 0; i < tamQtdImpress; i++)
        {
            if (p[i]->filaVazia())
                SetConsoleTextAttribute(hConsole, 10);
            else if (p[i]->filaCheia())
                SetConsoleTextAttribute(hConsole, 6);
            else
                SetConsoleTextAttribute(hConsole, 14);
            cout<<"###";
        }
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n\n";

        cout<<"1-Inserir arquivo em uma impressora"<<endl;
        cout<<"2-Inserir arquivo COM PRIORIDADE em uma impressora"<<endl;
        cout<<"3-Imprimir arquivo em uma impressora"<<endl;
        cout<<"4-Remover ultimo arquivo de uma impressora"<<endl;
        cout<<"5-Primeiro arquivo em uma impressora"<<endl;
        cout<<"6-Ultimo arquivo em uma impressora"<<endl;
        cout<<"7-Exibir uma impressora"<<endl;
        cout<<"9-Sair"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            do{
                cout<<"Impressora a selecionar: ";
                cin>>posicP;
                if (posicP <= 0 || posicP > tamQtdImpress)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"Valor invalido!"<<endl;
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }while(posicP <= 0 || posicP > tamQtdImpress);

            if (p[posicP-1]->filaCheia()){
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Impressora sobrecarregada!"<<endl;
                SetConsoleTextAttribute(hConsole, 15);
                break;
            }
            cout<<"Nome do arquivo: ";
            cin>>graficaImp.nome;
            do{
                cout<<"Numero de paginas deste arquivo: ";
                cin>>graficaImp.numPaginas;
                if (graficaImp.numPaginas <= 0)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"Valor invalido! Digite um numero maior que zero."<<endl;
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }while (graficaImp.numPaginas <= 0);

            p[posicP-1]->insereFim(graficaImp);
            cout<<"Adicionado para a impressora."<<endl;
            break;

        case 2:
            do{
                cout<<"Impressora a selecionar: ";
                cin>>posicP;
                if (posicP <= 0 || posicP > tamQtdImpress)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"Valor invalido!"<<endl;
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }while(posicP <= 0 || posicP > tamQtdImpress);

            if (p[posicP-1]->filaCheia()){
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Impressora sobrecarregada!"<<endl;
                SetConsoleTextAttribute(hConsole, 15);
                break;
            }
            cout<<"Nome do arquivo: ";
            cin>>graficaImp.nome;
            do{
                cout<<"Numero de paginas deste arquivo: ";
                cin>>graficaImp.numPaginas;
                if (graficaImp.numPaginas <= 0)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"Valor invalido! Digite um numero maior que zero."<<endl;
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }while (graficaImp.numPaginas <= 0);

            p[posicP-1]->insereTopo(graficaImp);
            cout<<"Adicionado com prioridade para a impressora."<<endl;
            break;

        case 3:
            do{
                cout<<"Impressora a imprimir: ";
                cin>>posicP;
                if (posicP <= 0 || posicP > tamQtdImpress)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"Valor invalido!"<<endl;
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }while(posicP <= 0 || posicP > tamQtdImpress);

            if (p[posicP-1]->filaVazia()){
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Impressora vazia..."<<endl;
                SetConsoleTextAttribute(hConsole, 15);
                break;
            }
            graficaImp = p[posicP-1]->removeInic();
            cout<<"Impresso o arquivo "<<graficaImp.nome<<" de "<<graficaImp.numPaginas<<" paginas."<<endl;
            break;

        case 4:
            do{
                cout<<"Impressora a remover ultimo arquivo: ";
                cin>>posicP;
                if (posicP <= 0 || posicP > tamQtdImpress)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"Valor invalido!"<<endl;
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }while(posicP <= 0 || posicP > tamQtdImpress);

            if (p[posicP-1]->filaVazia()){
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Impressora vazia..."<<endl;
                SetConsoleTextAttribute(hConsole, 15);
                break;
            }
            graficaImp = p[posicP-1]->removeFim();
            cout<<"Retirado o arquivo "<<graficaImp.nome<<" de "<<graficaImp.numPaginas<<" paginas."<<endl;
            break;

        case 5:
            do{
                cout<<"Impressora: ";
                cin>>posicP;
                if (posicP <= 0 || posicP > tamQtdImpress)
                    cout<<"Valor invalido! Digite um numero maior que zero."<<endl;
            }while(posicP <= 0 || posicP > tamQtdImpress);

            if (p[posicP-1]->filaVazia()){
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Impressora vazia..."<<endl;
                SetConsoleTextAttribute(hConsole, 15);
                break;
            }
            graficaImp = p[posicP-1]->elementoDoTopo();
            cout<<"Proximo doc a imprimir: "<<graficaImp.nome<<" com "<<graficaImp.numPaginas<<" paginas."<<endl;
            break;

        case 6:
            do{
                cout<<"Impressora: ";
                cin>>posicP;
                if (posicP <= 0 || posicP > tamQtdImpress)
                    cout<<"Valor invalido! Digite um numero maior que zero."<<endl;
            }while(posicP <= 0 || posicP > tamQtdImpress);

            if (p[posicP-1]->filaVazia()){
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Impressora vazia..."<<endl;
                SetConsoleTextAttribute(hConsole, 15);
                break;
            }
            graficaImp = p[posicP-1]->elementoDoFim();
            cout<<"Arquivo na ultima prioridade: "<<graficaImp.nome<<" com "<<graficaImp.numPaginas<<" paginas."<<endl;
            break;

        case 7:
            do{
                cout<<"Impressora: ";
                cin>>posicP;
                if (posicP <= 0 || posicP > tamQtdImpress)
                    cout<<"Valor invalido! Digite um numero maior que zero."<<endl;
            }while(posicP <= 0 || posicP > tamQtdImpress);

            if (p[posicP-1]->filaVazia()){
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Impressora vazia..."<<endl;
                SetConsoleTextAttribute(hConsole, 15);
                break;
            }
            cout<<"Arquivos: "<<endl;
            for (int i=0; i < p[posicP-1]->getQtde(); i++){
                graficaImp = p[posicP-1]->getValor((i+p[posicP-1]->getInic())%p[posicP-1]->getTamanho());

                if(i==0)
                    SetConsoleTextAttribute(hConsole, 14);
                cout<<"\t"<<i+1<<" - "<<graficaImp.nome<<" com "<<graficaImp.numPaginas<<" paginas"<<endl;
                SetConsoleTextAttribute(hConsole, 15);
            }
            cout<<"\n";
            break;

        case 9:
            cout<<"Fim..."<<endl;
            break;

        default:
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"Opcao invalida!"<<endl;
            SetConsoleTextAttribute(hConsole, 15);
            break;
        }
        cout<<"\n";

    }while (opc != 9);

    return 0;
}
