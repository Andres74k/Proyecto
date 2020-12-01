#include "Cuenta.hpp"
#include <string>
#ifndef ESTANDARD_HPP
#define ESTANDARD_HPP

//Clase hija de clase cuenta, Esta cuenta te cobra cada vez que sacas dinero del cajero. (10% de lo que saques)
class Estandard: public Cuenta {
public:
    //Constructor
    Estandard(string n, string l, int num):Cuenta(n,l,num,0,false){
        
    }
private:

};
    
#endif
    
