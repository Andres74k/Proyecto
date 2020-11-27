#include "Cuenta.hpp"
#include <string>
#ifndef PLATINO_HPP
#define PLATINO_HPP

//Clase hija de clase cuenta, Estas son cuentas que no te cobran comision cuando sacas dinero
class Platino: public Cuenta {
    
public:
    //Constructor
    Platino(string n, string l, int num):Cuenta(n, l, num, 0, true){
        
    }
    
private:
};
    
#endif
