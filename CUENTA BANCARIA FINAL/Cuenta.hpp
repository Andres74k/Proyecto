#include <string>
#include <iostream>
#ifndef CUENTA_HPP
#define CUENTA_HPP

class Cuenta {
public:
    Cuenta ();
    Cuenta(string, string, int, double, bool);
    
    string get_name();
    string get_loca();
    int get_ID();
    double get_saldo();
    bool check_des();
    
    void set_name(string);
    void set_loca(string);
    void set_saldo(double);

private:
    string nombre_c, localidad;
    int ID, saldo;
    bool descuento;
};
    
//Constructor
Cuenta::Cuenta(){
    ID = 0;
    saldo = 0;
    nombre_c = "";
    localidad = "";
    descuento = false;
}

Cuenta:: Cuenta(string n, string l, int num, double s, bool des){
    nombre_c = n;
    localidad = l;
    ID = num;
    saldo = s;
    descuento = des;
}

//Getters
string Cuenta::get_name(){
    return nombre_c;
}

string Cuenta::get_loca(){
    return localidad;
}
    
int Cuenta::get_ID(){
    return ID;
}
    
double Cuenta:: get_saldo(){
    return saldo;
}
    
bool Cuenta:: check_des(){
    return descuento;
}

 
//setters
void Cuenta:: set_name(string n){
    nombre_c = n;
}

void Cuenta:: set_loca(string l){
    localidad = l;
}
    
void Cuenta:: set_saldo(double s){
    saldo = (get_saldo() + s);
}

#endif
