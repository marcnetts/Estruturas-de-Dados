#ifndef ARCONDICIONADO_H_INCLUDED
#define ARCONDICIONADO_H_INCLUDED

class Temperatura{
private:
    int temperatura = 20;
    bool ligado = false;

public:
    void ligar(){
        ligado=true;
    }
    void desligar(){
        ligado = false;

    void aumentar(){
        temperatura++;
    }
    void diminuir(){
        temperatura--;
    }
    int getTemperatura(){
        return temperatura;
    }
    bool getLigado(){
        return ligado;
    }
};


#endif // ARCONDICIONADO_H_INCLUDED
