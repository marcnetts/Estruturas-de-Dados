#include <iostream>
#include <windows.h> //s� para cores
#include "pilhaseq.h"

//Express�o Matem�tica por Marcos Henrique Ribeiro Zanetti
/*
Segundo Tenembaum, �Estruturas de Dados Usando C, examine uma express�o matem�tica que inclui v�rios conjuntos
de par�nteses agrupados. Por exemplo: 7 - ( ( X * ( ( X + Y) / ( J - 3 ) ) + Y) / ( 4 - 2 . 5 ) ).
Queremos garantir que os par�nteses estejam corretamente agrupados, ou seja, desejamos verificar se:
1. Existe um n�mero igual de par�nteses esquerdos e direitos.
2. Todo par�ntese da direita est� precedido por um par�ntese da esquerda correspondente.
Express�es como ((A + B) ou A + B{, violam o crit�rio 1, e,
express�es como: )A + B(-C ou (A + B)) - (C + D violam o crit�rio 2.

Para solucionar esse problema, imagine cada par�ntese da esquerda como uma abertura de um escopo, e cada par�ntese
da direita como um fechamento de escopo.
Agora, alteremos ligeiramente o problema e suponhamos a exist�ncia de tr�s tipos diferentes de delimitadores de
escopo. Esses tipos s�o indicados por par�nteses ((e)), colchetes ([e]) e chaves ({e}). Um finalizador de escopo deve
ser do mesmo tipo de seu iniciador. Sendo assim, strings como: (A + B], [(A + B]), {A - (B]} s�o inv�lidas.
� necess�rio rastrear n�o somente quantos escopos foram abertos como tamb�m seus tipos. Estas informa��es s�o
importantes porque, quando um finalizador de escopo � encontrado, precisamos conhecer o s�mbolo com o qual o
escopo foi aberto para assegurar que ele seja corretamente fechado.
Uma pilha pode ser usada para rastrear os tipos de escopos encontrados. Sempre que um iniciador de escopo for
encontrado, ele ser� empilhado. Sempre que um finalizador de escopo for encontrado, a pilha ser� examinada. Se a
pilha estiver vazia, o finalizador de escopo n�o ter� um iniciador correspondente e a string ser�, consequentemente,
inv�lida. Entretanto, se a pilha n�o estiver vazia, desempilharemos e verificaremos se o item desempilhar corresponde
ao finalizador de escopo. Se ocorrer uma coincid�ncia, continuaremos. Caso contr�rio, a string ser� inv�lida. Quando
o final da string for alcan�ado, a pilha dever� estar vazia; caso contr�rio, existe um ou mais escopos abertos que ainda
n�o foram fechados, e a string ser� inv�lida.
*/

using namespace std;

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    PilhaSeq<char> p;
    string expr;
    char aux;
    bool expressaoRuim;

    SetConsoleTextAttribute(hConsole, 11);
    cout<<"Expressao Matematica\n\n";
    SetConsoleTextAttribute(hConsole, 15);

    do{
    cout<<"Digite a expressao que deseja verificar, \"0\" para sair:\n"<<endl;
    getline(cin, expr);
    cin.clear();

    if (expr != "0")
    {
        aux = 'a';
        expressaoRuim = 0;
        for (int i = 0; aux != '\0'; i++)
        {
            aux = expr[i];
            if (aux == '(' || aux == '[' || aux == '{')
            {
                if(p.empilha(aux) == 0)
                {
                    cout<<"Memoria cheia! Nao � possivel verificar a expressao; encerrando verificacao"<<endl;
                    aux = '\0';
                    break;
                }
                else
                    SetConsoleTextAttribute(hConsole, 11);
            }
            else if (aux == ')' || aux == ']' || aux == '}')
            {
                SetConsoleTextAttribute(hConsole, 11);
                if (p.pilhaVazia())
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    expressaoRuim = 1;
                }
                else if (aux == p.elementoDoTopo() + 1 || aux == p.elementoDoTopo() + 2)
                    p.desempilha();
                else
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    expressaoRuim = 1;
                }
            }

            cout<<aux;
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout<<endl;

        if (p.pilhaVazia() && !expressaoRuim)
            cout<<"Expressao valida."<<endl;
        else
            cout<<"Expressao invalida!!!"<<endl;
    }

    while(!p.pilhaVazia()){
        p.desempilha();
    }

    }while(expr != "0");
    return 0;
}
