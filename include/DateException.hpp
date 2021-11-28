#ifndef DateException
#define DateException

#include <iostream>
using namespace std;

class InvalidDateException: public exception{
    public:
        InvalidDateException(){
            cout<<"Invalid Date!"<<endl;
        }
        explicit InvalidDateException(const char*errorMsg){
            cout<<errorMsg<<endl;
        }
        template<class T>
        InvalidDateException(const char*errorMsg,T errorValue){
            cout<<errorMsg<<errorValue<<endl;
        }
};

#endif
