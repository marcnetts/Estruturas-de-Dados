#ifndef VAGAS_H_INCLUDED
#define VAGAS_H_INCLUDED

template <typename VarType>
class Vagas{
private:
    VarType *posicao;
    int linha;
    int coluna;
    int tamanho;
    int vagasOcup;

public:
    Vagas(int lin, int col){
        linha = lin;
        coluna = col;
        tamanho = linha * coluna;
        vagasOcup = 0;
        posicao = new VarType[tamanho];
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
                posicao[i*coluna+j] = 0;
        }
    }

    ~Vagas(){
        delete []posicao;
    }

    void insereVaga(int lin, int col){
        if (posicao[lin*coluna+col] == 0){
            posicao[lin*coluna+col] = 1;
            vagasOcup++;
        }
    }

    void removeVaga(int lin, int col){
        if (posicao[lin*coluna+col] != 0){
            posicao[lin*coluna+col] = 0;
            vagasOcup--;
        }
    }

    VarType getVaga(int lin, int col){return posicao[lin*coluna+col];};
    int getLinha(){return linha;};
    int getColuna(){return coluna;};
    int getTamanho(){return tamanho;};
    int getVagasOcup(){return vagasOcup;};
};

#endif // VAGAS_H_INCLUDED
