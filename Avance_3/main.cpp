#include <iostream>
#include <string>
using namespace std;

#include "Cuenta.hpp"
#include "Estandard.hpp"
#include "Platino.hpp"
#include "Cajero.hpp"
#include "Banco.hpp"

//Estos menus reflejan las funciones que planeo utilizar en el programa completo


//void menu_cuenta (){
//    cout<<"1. Log in"<<endl;
//    cout<<"2. Sign up"<<endl;
//    cout<<"3. Menu del Banco"<<endl;
//};


//void menu_cliente (){
//    cout<<"1. Depositar"<<endl;
//    cout<<"2. Sacar Dinero"<<endl;
//    cout<<"3. Ver saldo"<<endl;
//    cout<<"4 Log out"<<endl;
//};


//void menu_banco () {
//    cout<<"1. Clientes en Total"<<endl;
//    cout<<"2. Dinero Total"<<endl;
//}




//Este main no es reflejo de mi programa final.
//Mi main final va a utilizar la clase banco.
//Como la clase banco utiliza composicion me resulto dificil acabarle en este avance
//Y el main solo esta diseñado para demostrar que ya tengo herencia y relacion.

int main() {
    //Creamos un objeto de clase Cajero para poder depositar o sacar dinero de un objeto
    //de clase Estandard o Platino (Que son clases hijas de Cuenta)
    Cajero cajero;
    
    //Creamos nuestra Cuenta platino.
    Platino c1("Andres","Celaya",0);
    
    //Esta funcion la utilize para verificar que la herencia de la clase "Cuenta" a la clase
    //"Platino" funcionara correctamente.
    string a = c1.get_loca();
    cout<<a<<endl;
    
    //La diferencia de una cuenta Estandard y Platino es que en la estandard te cobran
    //te cobran una comision del 10% cada vez que sacas dinero. y el cajero se encarga
    // de analizar esto.
    
    //Aqui podemos ver que la relacion entre la clase "Cajero" y "Cuenta" funcionan
    //correctamente.
    
    
    //Aqui no cobro comision
    cajero.depositar(c1,1000.5);
    double b = c1.get_saldo();
    cout<<b<<endl;
    cajero.sacar_dinero(c1,500);
    cout<<"tu_saldo_acutal_es:"<<c1.get_saldo()<<endl;
    
    
    //Aqui si cobro
    Estandard c2("Andres","Celaya",0);
    string a1 = c2.get_loca();
    cout<<a1<<endl;
    cajero.depositar(c1,1000.5);
    double b1 = c2.get_saldo();
    cout<<b1<<endl;
    cajero.sacar_dinero(c1,500);
    cout<<"tu_saldo_acutal_es:"<<c1.get_saldo()<<endl;
    
    return 0;
}

