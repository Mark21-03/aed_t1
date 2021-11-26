#pragma once

#include <iostream>
#include <vector>
#include "Voo.hpp"

using namespace std;

class Aviao{
    private:
        string matricula;
        int capacidade;
        vector<Voo> plano;
    
    public:

    Aviao(){}
    Aviao(string matricula, int capacidade);
    Aviao(string matricula, int capacidade,vector<Voo> plano);

    void setPlanoVoo(const vector<Voo>& plano);
    void setCapacidade(int capacidade);
    void setMatricula(string matricula);

    string getMatricula() const;
    int getCapacidade() const;
    vector<Voo> getPlano() const;
};