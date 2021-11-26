#include "Voo.hpp"


Voo::Voo(int numero,Date dataPartida,int duracao,string origem,string destino){
    this->numero = numero;
    this->dataPartida = dataPartida;
    this->duracao = duracao;
    this->origem = origem;
    this->destino = destino;
}

//Setters
void Voo::setNumero(int numero){this->numero = numero;}

void Voo::setDataPartida(Date dataPartida){this->dataPartida = dataPartida;}

void Voo::setDuracao(int duracao){this->duracao = duracao;}

void Voo::setOrigem(string origem){this->origem = origem;}

void Voo::setDestino(string destino){this->destino = destino;}

//Getters
int Voo::getNumero() const{return this->numero;}

Date Voo::getDataPartida() const{return this->dataPartida;}
    
int Voo::getDuracao() const{return this->duracao;}

string Voo::getOrigem() const{return this->origem;}

string Voo::getDestino() const{return this->destino;}
