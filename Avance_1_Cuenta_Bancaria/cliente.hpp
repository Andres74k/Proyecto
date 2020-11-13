class cliente {
public:
    cliente();
    
    string get_name();
    string get_loca();
    
    void set_name(string);
    void set_loca(string);

private:
    string nombre, localidad;
};


cliente:: cliente(){
    nombre = "Jhon Smith";
    localidad = "USA";
}
string cliente::get_name(){
    return nombre;
}

string cliente::get_loca(){
    return localidad;
}

void cliente::set_name(string newname){
    nombre = newname;
}

void cliente::set_loca(string newloca){
    localidad = newloca;
}


