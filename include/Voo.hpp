#pragma once

#include <iostream>
#include "Date.hpp"

using namespace std;


class Voo{
    private:
        int numero;
        Date dataPartida;
        int duracao; //maybe Date class?
        string origem,destino;

    public:

        Voo(){}
        Voo(int numero,Date dataPartida,int duracao,string origem,string destino);

        //Setters
        void setNumero(int numero);
        void setDataPartida(Date dataPartida);
        void setDuracao(int duracao);
        void setOrigem(string origem);
        void setDestino(string destino);
        
        //Getters
        int getNumero() const;
        Date getDataPartida() const;
        int getDuracao() const;
        string getOrigem() const;
        string getDestino() const;
};
