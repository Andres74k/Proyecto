#include "Cuenta.hpp"
#include <iostream>
using namespace std;

#ifndef CAJERO_HPP
//Proyecto de Andres Acevedo Caracheo
//A01706897
//
#define CAJERO_HPP


//Este objeto te permite sacar o depositar dinero de un objeto de tipo Cuenta
//Ademas analiza si tu cuenta es estandard o platino y te cobre respectivamente.

class Cajero {
public:
    //Metodos
    
    //recibe una objeto tipo cuenta y un double. auementa su saldo con setter de cuenta
    void depositar(Cuenta &c, double d){
        c.set_saldo(d);
    }
    
    //recibe un objeto tipo cuenta y un double. resta a su saldo con setter de cuenta
    //y verifica que tengas el dinero nesecario.
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
