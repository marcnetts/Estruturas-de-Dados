#ifndef ARVOREBINDEBUSCA_H_INCLUDED
#define ARVOREBINDEBUSCA_H_INCLUDED

using namespace std;

template <typename Tipo>
struct Node{
    Tipo info;
    Node<Tipo> *pEsq;
    Node<Tipo> *pDir;

};

template <typename Tipo>
struct Bst{
    Node<Tipo> *pRaiz;

    Bst(){
        pRaiz = NULL;
    }

    ~Bst(){
        tiraTudo(pRaiz);
    }

    void tiraTudo(Node<Tipo> *&t){
        if (t!=NULL){
            if(t->pEsq != NULL && t->pDir != NULL)
            {
                delete t;
            }
            else
            {
                if(t->pEsq != NULL)
                {
                    tiraTudo(t->pEsq);
                }
                if(t->pDir != NULL)
                {
                    tiraTudo(t->pDir);
                }
            }
        }
    }

    void insere(Node<Tipo> *&t, Tipo x){ //*&
        if(t==NULL){
            t = new Node<Tipo>;
            t->info = x;
            t->pEsq = NULL;
            t->pDir = NULL;
        }
        else{
            if(x < t->info){
                insere(t->pEsq, x);
            }
            else{
                insere(t->pDir,x);
            }
        }
    }

    //Node<Tipo> *remover(Node<Tipo> *t, Tipo v)
    void remover(Node<Tipo> *&t, Tipo v)
    {
        if (t != NULL){
            if (t->info > v){
                remover(t->pEsq, v);
            }
            else if (t->info < v)
                remover(t->pDir, v);

            else { //found you
                if (t->pEsq == NULL && t->pDir == NULL) {
                    //delete t;
                    //Node<Tipo> *aux = new Node<Tipo>;
                    //aux = t;
                    t = NULL;
                    //delete aux;
                    //if (t != NULL)
                    //    cout<<"processa o marcos\n";
                }
                else if (t->pEsq == NULL) {
                    Node <Tipo> *aux = t;
                    t = t->pDir;
                    delete aux;
                }
                else if (t->pDir == NULL) {
                    Node<Tipo> *aux = t;
                    t = t->pEsq;
                    delete aux;
                }
                else { //2 filhos
                    Node<Tipo> *aux = t->pEsq;
                    while (aux->pDir != NULL) {
                        aux = aux->pDir;
                    }
                    t->info = aux->info;
                    aux->info = v;
                    remover(t->pEsq, v); //"loop"
                }
            }
            //return 1;
        }
        //return 0;
        //return t; //recursivo
    }

    Tipo *getEsq(Node<Tipo> *t){
        return t->pEsq;
    }

    Tipo *getDir(Node<Tipo> *t){
        return t->pDir;
    }

    void preOrdem(Node<Tipo> *t){ //R-E-D
        if(t != NULL){
            cout<<t->info<<" ";
            preOrdem(t->pEsq);
            preOrdem(t->pDir);
        }
    }
    void posOrdem(Node<Tipo> *t){ //E-D-R
        if(t != NULL){
            posOrdem(t->pEsq);
            posOrdem(t->pDir);
            cout<<t->info<<" ";
        }
    }
    void emOrdem(Node<Tipo> *t){ //E-R-D
        if(t != NULL){
            emOrdem(t->pEsq);
            cout<<t->info<<" ";
            emOrdem(t->pDir);
        }
    }

    Tipo getMinimo(Node<Tipo> *t){ //E-E-E-X
        if(t != NULL)
        {
            if (t->pEsq != NULL)
                return getMinimo(t->pEsq);
            else
                return t->info;
        }
        return NULL;
    }

    Tipo getMaximo(Node<Tipo> *t){ //D-D-D-X
        if(t != NULL)
        {
            if (t->pDir != NULL)
                return getMaximo(t->pDir);
            else
                return t->info;
        }
        return NULL;
    }
};

#endif // ARVOREBINDEBUSCA_H_INCLUDED
