#include "Aviao.hpp"


Aviao::Aviao(string matricula, int capacidade){
    this->matricula = matricula;
    this->capacidade = capacidade;
}

Aviao::Aviao(string matricula, int capacidade,vector<Voo> plano){
    this->matricula = matricula;
    this->capacidade = capacidade;
    this->plano = plano;
}
//Getters
string Aviao::getMatricula() const{return this->matricula;}

int Aviao::getCapacidade() const{return this->capacidade;}

vector<Voo> Aviao::getPlano() const{return this->plano;}

//Setters
void Aviao::setPlanoVoo(const vector<Voo>& plano){this->plano = plano;}

void Aviao::setCapacidade(int capacidade){this->capacidade = capacidade;}

void Aviao::setMatricula(string matricula){this->matricula = matricula;}



