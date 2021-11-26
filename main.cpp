#include <iostream>
#include <vector>

#include "Date.hpp"
#include "Aviao.hpp"
#include "Voo.hpp"

using namespace std;

int main(){

    Date d("20-05-2010");
    cout<<d<<endl;

    Voo f(21368,d,12,"Lisboa","Porto");
    vector<Voo> v = {f};

    Aviao a("A13",213,v);

    string str = a.getPlano()[0].getOrigem();
    
    cout<<str<<endl;

}