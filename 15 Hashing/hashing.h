#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

#define W 3

struct Node{
    int info;
    Node *prox;
};

struct Hash{
    Node *h[W]; //constante W

    Hash(){
    for (int i = 0; i < W; i++)
        h[i] = NULL;
    }

    ~Hash(){
        Node *aux = new Node;
        for(int i = 0; i < W; i++)
        {
            while(h[i] != NULL)
            {
                aux = h[i];
                h[i] = h[i]->prox;
                delete aux;
            }
        }
    }

    int fht(int x){ //funcao hashing table
        return x % W;
    }

    void insere(int x){
        Node *aux = new Node;
        Node *aux2;
        aux->info = x;
        int p = fht(x);

        if(h[p] == NULL || x <= h[p]->info){
            aux->prox = h[p];
            h[p] = aux;
        }
        else{
            aux2 = h[p];
            while (aux2->prox != NULL && x > aux2->prox->info){
                aux2 = aux2->prox;
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }

    bool remover(int x){
        Node *aux = new Node;
        int p = fht(x);
        aux = h[p];
        if(aux != NULL){
            if(aux->info == x)
            {
                h[p] = h[p]->prox;
                delete aux;
                return 1;
            }
            while (aux->prox != NULL && aux->prox->info <= x)
            {
                if(aux->prox->info == x)
                {
                    Node *aux2;
                    aux2 = aux->prox;
                    aux->prox = aux->prox->prox;
                    delete aux2;
                    return 1;
                }
                aux = aux->prox;
            }
        }
        return 0;
    }

    int buscaElem(int x){
        Node *aux = h[fht(x)];
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

    bool listaNumVazia(int numero){
        return listaVazia(fht(numero));
    }

    bool listaVazia(int lista){
        return h[lista] == NULL;
    }

} ;

#endif // HASHING_H_INCLUDED
