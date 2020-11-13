class cuenta {
public:
    cuenta();
    
    double get_saldo();
    double depositar(double);
    double sacar_dinero(double);
private:
    double saldo;
};


cuenta:: cuenta(){
    saldo = 0;
}
double cuenta::get_saldo(){
    return saldo;
}

double cuenta::depositar(double dept){
    saldo = saldo + dept;
    return saldo;
}

double cuenta::sacar_dinero(double retir){
    if (saldo<retir)
        cout<<"Saldo insuficiente"<<endl;
    else
        saldo = saldo - retir;
    return saldo;
}
