#include <iostream>
#include <windows.h> //só para cores
#include<string.h>
#include "pilha.h"

using namespace std;
/*
Um pangrama é uma frase que contém pelo menos uma vez cada uma das 26 letras do novo
alfabeto Português. Um exemplo de pangrama é: “UM PEQUENO JABUTI XERETA CHAMADO KYA
VIU DEZ CEGONHAS FELIZES E GRITOU IWUP, IWUP!”
Construa uma aplicação que recebe uma frase e verifica se ela é pangrama (utilize os
conceitos de listas e strings da linguagem C++)
*/
int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Pilha<char> p(26);
    string expr;
    char aux = '0';

    cout<<"Pangrama\n\n";
    cout<<"Digite a frase que deseja verificar:\n"<<endl;
    getline(cin, expr);

    for (int i = 0; i < expr.length() ; i++)
    {
        aux = expr.at(i);
        if ((aux >= 'a' && aux <= 'z') || (aux >= 'A' && aux <= 'Z'))
        {
            if(i == 0)
                SetConsoleTextAttribute(hConsole, 15);

            int letraExiste = 0;
            for(int j = 0; j <= p.getTopo(); j++) //getTopo() é o numero atual de elementos ineridos
            {
                if (aux == p.getValor(j) || aux == p.getValor(j) + 32 || aux == p.getValor(j) - 32) //'a' ou 'A'
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    letraExiste = 1;
                    break;
                }
            }
            cout<<aux;
            SetConsoleTextAttribute(hConsole, 15);
            if (!letraExiste)
                p.empilha(aux);
        }

        SetConsoleTextAttribute(hConsole, 10);
        if (p.pilhaCheia()){
            cout<<"\nFrase tem todas as letras do alfabeto!";
            break;
        }
    }

    SetConsoleTextAttribute(hConsole, 7);
    cout<<endl;
    cout<<p.getTopo()+1<<" letra(s) diferente(s)."<<endl;

    if (!p.pilhaCheia())
        cout<<"Frase NAO tem todas as letras."<<endl;

    return 0;
}
