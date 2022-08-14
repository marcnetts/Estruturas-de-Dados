#ifndef PILHASEQ_H_INCLUDED
#define PILHASEQ_H_INCLUDED

template <typename Tipo>
struct Node{
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>
class PilhaSeq{
private:
    Node<Tipo> *topo;
    unsigned tamanho;

public:
    PilhaSeq(){
        topo = NULL;
        tamanho = 0;
    }

    /*
    ~PilhaSeq(){
        delete []v;
    }*/

    bool empilha(Tipo x){
        Node<Tipo> *aux = new Node<Tipo>;
        if (aux == NULL){
            return false;
        }
        aux->info = x;
        aux->prox = topo;
        topo = aux;
        tamanho++;

        return true;
    }

    Tipo desempilha(){
        Tipo temp = topo->info;
        Node<Tipo> *aux = topo;
        topo = topo->prox;
        delete aux;
        tamanho--;
        return temp;
    }

    Tipo elementoDoTopo(){
        return topo->info;
    }

    Node<Tipo> *getPontTopo(){
        return topo;
    }

    unsigned getTamanho(){
        return tamanho;
    }

    bool pilhaVazia(){
        return topo == NULL;
    }

};

#endif // PILHASEQ_H_INCLUDED
