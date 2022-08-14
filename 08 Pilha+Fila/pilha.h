#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

//Pilha por Marcos Henrique Ribeiro Zanetti

template <typename Tipo>
class Pilha{
private:
    Tipo *v;
    unsigned tamanho;
    int topo;

public:
    Pilha(unsigned tam){
        tamanho = tam;
        v = new Tipo[tamanho];
        topo = -1;
    }

    //Pilha<int> p(10);

    ~Pilha(){
        delete []v;
    }

    bool empilha(Tipo x){
        if (topo != tamanho-1)
        {
            topo++;
            v[topo] = x;
            return 1;
        }
        return 0;
    }

    Tipo desempilha(){
        Tipo temp = v[topo];
        topo--;
        return temp;
    }

    Tipo elementoDoTopo(){
        return v[topo];
    }

    bool pilhaCheia(){
        return topo == tamanho-1;
    }

    bool pilhaVazia(){
        return topo == -1;
    }

    unsigned getTopo(){
        return topo;
    }

    unsigned getTamanho(){
        return tamanho;
    }

    Tipo getValor(unsigned posicao){
        return v[posicao];
    }
};

#endif // PILHA_H_INCLUDED
