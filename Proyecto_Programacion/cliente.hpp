class cliente {
public:
    cliente();
    
    string get_name();
    string get_loca();
    int get_ID();
    
    void set_name(string);
    void set_loca(string);

private:
    string nombre_c, localidad;
    int ID;
};


cliente:: cliente(){
    nombre_c = "Jhon Smith";
    localidad = "USA";
    ID = 0;
}
string cliente::get_name(){
    return nombre_c;
}

string cliente::get_loca(){
    return localidad;
}

void cliente::set_name(string newname){
    nombre_c = newname;
}

void cliente::set_loca(string newloca){
    localidad = newloca;
}

int cliente::get_ID(){
    return ID;
}
