#ifndef FILADUPLA_H_INCLUDED
#define FILADUPLA_H_INCLUDED

template <typename Tipo>
class DuplaFila{
private:
    int fim, inic;
    unsigned qtde; //não tem na Fila
    unsigned tamanho;
    Tipo *v;

public:
    DuplaFila(unsigned tam){
        tamanho = tam;
        v = new Tipo[tamanho];
        fim = -1; //substitui topo nesta op
        inic = 0;
        qtde = 0;
    }

    ~DuplaFila(){
        delete []v;
    }

    void insereFim(Tipo x){
        if (qtde != tamanho)
        {
            qtde++;
            fim = (fim + 1) % tamanho;
            v[fim] = x;
        }
    }

    void insereTopo(Tipo x){ //duplafila
        if (qtde != tamanho)
        {
            qtde++;
            inic = (inic - 1 + tamanho) % tamanho;
            v[inic] = x;
        }
    }

    Tipo removeInic(){
        Tipo temp = v[inic];
        inic = (inic + 1) % tamanho;
        qtde--;
        return temp;
    }

    Tipo removeFim(){ //duplafila
        Tipo temp = v[fim];
        fim = (fim - 1 + tamanho) % tamanho;
        qtde--;
        return temp;
    }

    Tipo elementoDoTopo(){
        return v[inic];
    }

    Tipo elementoDoFim(){
        return v[fim];
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

#endif // FILADUPLA_H_INCLUDED
