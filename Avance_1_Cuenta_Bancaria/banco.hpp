class banco {
public:
    banco();
    
    string get_name();
    
    void set_name(string);
private:
    string nombre;
};


banco:: banco(){
    nombre = "BBVA";
}
string banco::get_name(){
    return nombre;
}
void banco::set_name(string newname){
    nombre = newname;
}

