#include <iostream>
#include "vagas.h"

using namespace std;

/*
Desenvolva uma aplicação que represente um Teatro.
As atividades incluem a configuração inicial do tamanho do teatro (fileiras x poltronas) bem como permita
apresentar um "menu" de atividades:
1 - vender ingresso: o usuário escolhe um lugar
2 - devolver ingresso: o usuário poderá devolver o ingresso adquirido
3 - realizar troca de lugar: o usuário poderá trocar o lugar adquirido por outro disponível.
4 - finalizar a aplicação
Obs: a aplicação deverá exibir ao usuário os lugares disponíveis e ocupados.
*/

void setCoordsAssento(int *maxLinha, int *maxCol, int *setLin, int *setCol, int msgExtra)
{
    //msgExtra 0, 1, 2
    const char *msgExtrasList[] = {
        "",
        " do assento original",
        " do assento a trocar"
    };

    do{
        cout << "Fileira" << msgExtrasList[msgExtra] << ": ";
        cin >> *setLin;
        cin.clear();
        if(*setLin <= 0 || *setLin > *maxLinha)
            cout << "Valor fora do alcance esperado. (0 - " << *maxLinha << ")" << endl;
    }while (*setLin <= 0 || *setLin > *maxLinha);
    do{
        cout << "Poltrona" << msgExtrasList[msgExtra] << ": ";
        cin >> *setCol;
        cin.clear();
        if(*setCol <= 0 || *setCol > *maxCol)
            cout << "Valor fora do alcance esperado. (0 - " << *maxCol << ")" << endl;
    }while (*setCol <= 0 || *setCol > *maxCol);
}

int main()
{
    int linha, coluna, opcao = 0;
    do{
        cout << "Fileiras do teatro: ";
        cin >> linha;
        if (linha <= 0)
            cout << "Valor invalido, digite um numero positivo.\n";
    }while (linha <= 0);
    do{
        cout << "Poltronas por fila do teatro: ";
        cin >> coluna;
        if (coluna <= 0)
            cout << "Valor invalido, digite um numero positivo.\n";
    }while (linha <= 0);

    cout << endl;

    Vagas<int> teatro(linha,coluna);
    while (opcao != 4)
    {
        cout << "\nTeatro Mozart\n";
        cout << teatro.getVagasOcup() << " pessoas\n\n";

        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
                cout << teatro.getVaga(i, j) << " ";
            cout << endl;
        }
		cout << endl;
        cout << "1 - Vender Ingresso" << endl;
        cout << "2 - Devolver Ingresso" << endl;
        cout << "3 - Trocar vaga de lugar" << endl;
        cout << "4 - Sair" << endl;

        cin >> opcao;
        cin.clear();
        cout << endl;

        switch (opcao)
        {
            int aux_x, aux_y, aux_z, aux_a;

            case 1:
                setCoordsAssento(&linha, &coluna, &aux_x, &aux_y, 0);
                if (teatro.getVaga(aux_x-1, aux_y-1) == 0)
                    teatro.insereVaga(aux_x-1, aux_y-1);
                else
                    cout << "Vaga ja tem pessoas!\n";
                break;

            case 2:
                setCoordsAssento(&linha, &coluna, &aux_x, &aux_y, 0);
                if (teatro.getVaga(aux_x-1, aux_y-1) == 1)
                    teatro.removeVaga(aux_x-1, aux_y-1);
                else
                    cout << "Vaga sem pessoas!\n";
                break;

            case 3:
                setCoordsAssento(&linha, &coluna, &aux_x, &aux_y, 1);
                if (teatro.getVaga(aux_x-1, aux_y-1) == 1)
                {
                    setCoordsAssento(&linha, &coluna, &aux_z, &aux_a, 2);

                    if (teatro.getVaga(aux_z-1, aux_a-1) == 0)
                    {
                        teatro.removeVaga(aux_x-1, aux_y-1);
                        teatro.insereVaga(aux_z-1, aux_a-1);
                    }
                    else
                        cout << "Vaga ja tem pessoas!\n";
                }
                else
                    cout << "Vaga sem pessoas!\n";
                break;

            default:
                break;
        }
    }
    return 0;
}
