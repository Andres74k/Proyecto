//Proyecto de Andres Acevedo Caracheo
//A01706897
//
#ifndef BANCO_HPP
#define BANCO_HPP
#include "Cuenta.hpp"
#include "Estandard.hpp"
#include "Platino.hpp"
#include "Cajero.hpp"


//En esta clase banco es en donde se van a guardar todas las cuentas en un array de este tipo.
//Las cuentas son modificadas en el main y los datos son gaurdados aqui.

class Banco{
public:
    Banco(); //Constructor
    //Metodos de banco
    void agrega_cuenta_s(string, string);
    void agrega_cuenta_p(string, string);
    Cuenta cambiar_cuenta(int);
    void update_cuenta(Cuenta, int);
    int get_ID_cont();

    
private:
    //Declaro mis variables de instancia
    int ID_cont;
    Cuenta cuentas[100];
    
};

//Constructor por default
Banco::Banco(){
    ID_cont = 0;
}

//recibe el nombre y localidad del usuario y el banco los utiliza para crear un cuenta
//estandard con esos datos.
//la cuenta despues es guardada en nuestro array de cuentas.
void Banco::agrega_cuenta_s(string n, string l){
    ID_cont += 1;
    Estandard c (n,l,ID_cont);
    cuentas[ID_cont] = c;
}

//recibe el nombre y localidad del usuario y el banco los utiliza para crear un cuenta
//platino con esos datos.
//la cuenta despues es guardada en nuestro array de cuentas.
void Banco::agrega_cuenta_p(string n, string l){
    ID_cont += 1;
    Platino p(n,l,ID_cont);
    cuentas[ID_cont] = p;
}

//recibe el numero de ID de cuenta y regresa al main un objeto tipo cuenta para que pueda ser
//utilizado por el usuario
Cuenta Banco:: cambiar_cuenta(int id){
    return cuentas[id];
}

//recibe un objeto tipo cuenta y el ID de cuenta.
//Esta cuenta modificada en el main remplaza a la anitgua.
void Banco:: update_cuenta(Cuenta cuenta, int id){
    cuentas[id]=cuenta;
}

//Esta cuenta regresa el numero de posicion en que esta guardada la cuenta,
//para que el usuario sepa este numero de referencia
int Banco:: get_ID_cont(){
    return ID_cont;
}
#endif

