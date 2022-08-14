#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED

template <typename Tipo>
struct Node{
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>
struct ListaOrdenada{
//private:
    Node<Tipo> *h; //*topo ou *header

//public:
    ListaOrdenada(){
        h=NULL;
    }

    ~ListaOrdenada(){
        Node<Tipo> *aux = new Node<Tipo>;
        while(h != NULL)
        {
            aux = h;
            h = h->prox;
            delete aux;
        }
    }

    bool listaVazia(){
        return h == NULL;
    }

    void insere(Tipo x){
        Node<Tipo> *aux = new Node<Tipo>;
        aux->info = x;
        if(h==NULL || x < h->info){
            aux->prox = h; //NULL
            h = aux;
        }
        else{
            Node<Tipo> *aux2 = new Node<Tipo>;
            aux2 = h;
            while(aux2->prox != NULL && x > aux2->prox->info){ //prox
                aux2 = aux2->prox;
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }

    bool remover(Tipo x){
        Node<Tipo> *aux = new Node<Tipo>;
        aux = h;
        if(aux->info == x)
        {
            h = h->prox;
            delete aux;
            return 1;
        }
        while (aux->prox != NULL && aux->prox->info <= x)
        {
            if(aux->prox->info == x)
            {
                Node<Tipo> *aux2;
                aux2 = aux->prox;
                aux->prox = aux->prox->prox;
                delete aux2;
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }

    int buscaElem(Tipo x){
        Node<Tipo> *aux = h;
        int indice = 0;
        while (aux != NULL && aux->info <= x)
        {
            indice++;
            if(aux->info == x)
                return indice;
            aux = aux->prox;
        }
        return -1;
    }

    Tipo *getRaiz()
    {
        return h;
    }

};

#endif // LISTAORDENADA_H_INCLUDED
