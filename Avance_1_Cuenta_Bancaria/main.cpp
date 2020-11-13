//  Avance_1_Cuenta_Bancaria
//
//  Created by Andrés Acevedo on 12/11/20.
//
//CASOS DE PRUEBA HASTA ABAJO
//
// Este programa es de una cuenta bancaria con funciones basicas
//Hay 3 diferentes clases que son la cuenta, el cliente y el banco


#include <iostream>
#include <string>
using namespace std;

#include "cuenta.hpp"
#include "banco.hpp"
#include "cliente.hpp"



// Estas primeras dos funciones son para darle el usuario las opciones que tiene.
//Como lo es ver su saldo, depositar, ver sus datos,etc
void menu () {
    cout<<"1. Ver saldo"<<endl;
    cout<<"2. Depositar"<<endl;
    cout<<"3. Sacar Dinero"<<endl;
    cout<<"4. Ver informacion de cliente"<<endl;
    cout<<"5. Modificar informacion del cliente"<<endl;
    cout<<"6. Salir"<<endl;
}


void menu2(){
    cout<<"1. Modificar Nombre"<<endl;
    cout<<"2. Modificar localidad"<<endl;
    cout<<"3. Cambiar nombre del banco"<<endl;
}


//Este es mi main el cual va a desplegar el menu y dar la opcion deseada al usuario.
//Todos los procedimientos se van a repetir hasta que el usuario escoga "Salir"
int main () {
    bool c = true;
    
    //aqui se estan creando los 3 objetos que se estan utilizando
    cuenta c1;
    banco b1;
    cliente cl1;
    
    //Y aqui se definen las variables que estare utilizando
    string nombre_b, nombre_c, localidad;
    int opcion,opcion2;
    double saldo, depos, withd;
    
    do {
        
        //En esta primera parte de codigo solo se despliega el menu y recibe la opcion
        //Esta opcion es validada para que no se puedan escoger opciones que no son
        nombre_b = b1.get_name();
        
        cout<<nombre_b<<endl;
        menu ();
        cout<<"\n";
        cout<<"Elige una opcion: "<<endl;
        cin>>opcion;
        cout<<"\n";
        
 
        //Aqui ya empezamos a checar la opcion que el usuario escogio para saber que hacer
        
        //Esta primera solo agarra el saldo guardado dentro de la clase "cuenta"
        if (opcion == 1){
            saldo = c1.get_saldo();
            cout<<"Tu saldo es: "<<endl;
            cout<<saldo<<endl;
            }
        
        //utilizamos la funcion depositar para sumar al saldo el valor que el usuario escogio
        else if (opcion == 2){
            cout<<"Cuanto dinero quieres depositar?"<<endl;
            cin>>depos;
            saldo = c1.depositar(depos);
            cout<<"Tu saldo es: "<<endl;
            cout<<saldo<<endl;
        }
        
        //usamos la funcion sacar_dinero que, primero valida que haya la cantidad necesaria y despues resta del saldo el dinero que se saco
        else if (opcion == 3){
            cout<<"Cuanto dinero quieres sacar?"<<endl;
            cin>>withd;
            saldo = c1.sacar_dinero(withd);
            cout<<"Tu saldo es: "<<endl;
            cout<<saldo<<endl;
        }
        
        //aqui le queremos dar sus datos al usuario
        //para eso recolecte los datos que queremos con los getters de cada clase y despues los imprimimos en pantalla.
        else if (opcion==4){
            nombre_c = cl1.get_name();
            localidad = cl1.get_loca();
            saldo = c1.get_saldo();
            cout<<"Nombre del banco: "<<nombre_b<<"\n"<<endl;
            cout<<"Nombre del dueño de cuenta: "<<nombre_c<<"\n"<<endl;
            cout<<"Lugar de localidad del propietario: "<<localidad<<"\n"<<endl;
            cout<<"Saldo: "<<saldo<<"\n"<<endl;
        }
        
        //Esta funcion es para cambiar la informacion de la cuenta.
        //primero desplegamos un segundo menu para saber que dato queremos cambiar.
        //y despues utilizamos los setters de la clase respectiva
        else if (opcion == 5){
            menu2();
            cin>>opcion2;
            if (opcion2 == 1){
                cout<<"Introduce el nombre nuevo"<<endl;
                cin>>nombre_c;
                cl1.set_name(nombre_c);
                cout<<"\n";
            }
            else if (opcion2 == 2){
                cout<<"Introduce tu nueva localidad"<<endl;
                cin>>localidad;
                cl1.set_loca(localidad);
                cout<<"\n";
            }
            else if (opcion2 == 3){
                cout<<"Introduce tu nombre de banco nuevo"<<endl;
                cin>>nombre_b;
                b1.set_name(nombre_b);
                cout<<"\n";
            }
            
            //Este solo es para validar la opcion
            else{
                cout<<"Opcion Invalida"<<endl;
            }
        }
        
        //Esta opcion es para romper la condicion del ciclo while y salirnos del loop
        else if (opcion ==6){
            c = false;
        }
        else {
            cout<<"Esa opcion no es valida"<<endl;
        }
        cout<<"\n";
    } while (c == true);
    return 0;
}


//Si es un caso de prueba diferente tienes que dar en salir para que de el resultado correcto

// CASO DE PRUEBA 1
//cin 2
//cin 1000
//cout Tu saldo es: 1000

// CASO DE PRUEBA 2
//cin 3
//cin 1000
//cout saldo insuficiente
//cout Tu saldo es: 0

//CASO DE PRUEBA  3
//cin 2
//cin 1000
//cin 3
//cin 500
//cout Tu saldo es: 500

//CASO DE PRUEBA 4
//cin 5
//cin 1
//cin Tunombre
//cin 4
//cout Nombre del banco: BBVA
//Nombre del dueño de cuenta: Tunombre
//Lugar de localidad del propietario: USA
//Saldo: 0
