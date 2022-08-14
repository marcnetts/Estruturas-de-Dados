#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

template <typename Tipo>
class Fila{
private:
    int fim, inic;
    unsigned qtde; //não tem na Fila
    unsigned tamanho;
    Tipo *v;

public:
    Fila(unsigned tam){
        tamanho = tam;
        v = new Tipo[tamanho];
        fim = -1; //substitui topo nesta op
        inic = 0;
        qtde = 0;
    }

    ~Fila(){
        delete []v;
    }

    bool insere(Tipo x){
        if (qtde != tamanho)
        {
            qtde++;
            fim = (fim + 1) % tamanho;
            v[fim] = x;
            return 1;
        }
        else
            return 0;
    }

    Tipo desenfila(){
        Tipo temp = v[inic];
        /*inic++;
        if (inic == tamanho)
            inic = 0;*/
        inic = (inic + 1) % tamanho;
        qtde = qtde - 1;
        return temp;
    }

    Tipo elementoDoTopo(){
        return v[inic];
    }

    bool filaCheia(){
        return qtde == tamanho;
    }

    bool filaVazia(){
        return qtde == 0;
    }

    int getInic(){
        return inic;
    }

    int getFim(){
        return fim;
    }

    int getQtde(){
        return qtde;
    }

    unsigned getTamanho(){
        return tamanho;
    }

    Tipo getValor(unsigned posicao){
        return v[posicao];
    }
};

#endif // FILA_H_INCLUDED
