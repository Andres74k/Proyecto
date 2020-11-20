class banco {
public:
    
    banco();
    banco(string n): nombre_b(n){};
    string get_name();
    void set_name(string);
    
private:
    string nombre_b;
};


banco:: banco(){
    nombre_b = "";
}
string banco::get_name(){
    return nombre_b;
}
void banco::set_name(string newname){
    nombre_b = newname;
}
