#include "Cuenta.hpp"
#include <iostream>
using namespace std;

#ifndef CAJERO_HPP
#define CAJERO_HPP


//Este objeto te permite sacar o depositar dinero de un objeto de tipo Cuenta
//Ademas analiza si tu cuenta es estandard o platino y te cobre respectivamente.

class Cajero {
public:
    
    void depositar(Cuenta &c, double d){
        c.set_saldo(d);
    }
    
    void sacar_dinero(Cuenta &c, double d){
        if (c.get_saldo()>(d*1.1)){
            if (c.check_des() == false)
                c.set_saldo((d*1.1)*-1);
            else
                c.set_saldo(d*-1);
        }
        else{
            cout<<"Saldo Insuficiente"<<endl;
        }
    }
};

#endif
