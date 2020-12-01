#ifndef BANCO_HPP
#define BANCO_HPP
#include "Cuenta.hpp"
#include "Estandard.hpp"
#include "Platino.hpp"
#include "Cajero.hpp"


//En esta clase banco es en donde se van a guardar todas las cuentas en un array.
//Y a travez de una funciones podre manipular las cuentas desde mi main

class Banco{
public:
    Banco();
    void agrega_cuenta_s(string, string);
    void agrega_cuenta_p(string, string);
    Cuenta cambiar_cuenta(int);
    void update_cuenta(Cuenta, int);
    int get_ID_cont();

    
private:
    int ID_cont;
    Cuenta cuentas[100];
    
};

Banco::Banco(){
    ID_cont = 0;
}

void Banco::agrega_cuenta_s(string n, string l){
    ID_cont += 1;
    Estandard c (n,l,ID_cont);
    cuentas[ID_cont] = c;
}

void Banco::agrega_cuenta_p(string n, string l){
    ID_cont += 1;
    Platino p(n,l,ID_cont);
    cuentas[ID_cont] = p;
}

Cuenta Banco:: cambiar_cuenta(int id){
    return cuentas[id];
}

void Banco:: update_cuenta(Cuenta cuenta, int id){
    cuentas[id]=cuenta;
}

int Banco:: get_ID_cont(){
    return ID_cont;
}
#endif

