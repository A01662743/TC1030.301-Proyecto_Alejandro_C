#include <iostream>
using namespace std;

#ifndef VEHICULO
#define VEHICULO

class Vehiculo {
    //atributos
    protected:
        string marca;
        string modelo;
        float km_recorridos;
    //métodos
    public:
        //constructores
        Vehiculo();
        Vehiculo (string _marca, string _modelo);
        //getters
        string get_marca();
        string get_modelo();
        float get_km_recorridos();
        //setters
        void set_marca(string _marca);
        void set_modelo(string _modelo);
        void set_km_recorridos(float _km_recorridos);
        //métodos especiales
        void ride (float km);
        void vehiculo_print();
        //métodos para polimorfismo
        virtual void print() = 0;
        virtual void restock(float) = 0;
        virtual void stock_loss(float) = 0;
};

//constructores
Vehiculo::Vehiculo(){
    marca = "undefined";
    modelo = "undefined";
    km_recorridos = 0;
}
Vehiculo::Vehiculo (string _marca, string _modelo){
    marca = _marca;
    modelo = _modelo;
    km_recorridos = 0;
}
//getters
string Vehiculo::get_marca(){
    return marca;
}
string Vehiculo::get_modelo(){
    return modelo;
}
float Vehiculo::get_km_recorridos(){
    return km_recorridos;
}
//setters
void Vehiculo::set_marca(string _marca){
    marca = _marca;
}
void Vehiculo::set_modelo(string _modelo){
    modelo = _modelo;
}
void Vehiculo::set_km_recorridos(float _km_recorridos){
    km_recorridos = _km_recorridos;
}
//métodos especiales
void Vehiculo::ride (float km){
    km_recorridos = km + km_recorridos;
}
void Vehiculo::vehiculo_print(){
    cout << "marca: " << marca << endl;
    cout << "modelo: " << modelo << endl;
    cout << "kilómetros recorridos: " << km_recorridos << " km" << endl;
}
#endif VEHICULO

#ifndef ECO
#define ECO

class Eco: public Vehiculo{
    //métodos
    public:
        // Constructor
        Eco();
        Eco(string _marca, string _modelo);
        //metodos sobreescritos por polimorfismo
        void print();
        void restock(float _ignore);
        void stock_loss(float _km);
};

// Constructor
Eco::Eco(): Vehiculo(){
}
Eco::Eco(string _marca, string _modelo): Vehiculo(_marca, _modelo){
}
//metodos sobreescritos por polimorfismo
void Eco::print(){
    vehiculo_print(); 
}
void Eco::restock(float _ignore) {
    cout << endl << "no se puede recargar para este tipo de vehículo" << endl;
}
void Eco::stock_loss(float _km) {
    ride(_km);
    cout << endl << "kilometros agregados";
}

#endif ECO

#ifndef ELECTRIC
#define ELECTRIC

class Electric: public Vehiculo{
    //atributos
    private:
        float energy;
        float max_energy;
        float energy_per_km;
    //métodos
    public:
        // Constructores
        Electric();
        Electric(string _marca, string _modelo, float _energy, int _max_energy, float _energy_per_km);
        //getters
        float get_energy();
        float get_max_energy();
        float get_energy_per_km();
        //setters
        void set_energy(float _energy);
        void set_max_energy(float _max_energy);
        void set_energy_per_km(float _energy_per_km);
        //metodos sobreescritos por polimorfismo
        void print();
        void restock(float percent);
        void stock_loss(float _km);
};

// Constructores
Electric::Electric(): Vehiculo(){
    energy = 0;
    max_energy = 0;
    energy_per_km = 0;
}
Electric::Electric(string _marca, string _modelo, float _energy, int _max_energy, float _energy_per_km): Vehiculo(_marca, _modelo){
    energy = _energy;
    max_energy = _max_energy;
    energy_per_km = _energy_per_km;
}
//getters
float Electric::get_energy(){
    return energy;
}
float Electric::get_max_energy(){
    return max_energy;
}
float Electric::get_energy_per_km(){
    return energy_per_km;
}
//setters
void Electric::set_energy(float _energy){
    energy = _energy;
}
void Electric::set_max_energy(float _max_energy){
    max_energy = _max_energy;
}
void Electric::set_energy_per_km(float _energy_per_km){
    energy_per_km = _energy_per_km;
}
//metodos sobreescritos por polimorfismo
void Electric::print(){
    vehiculo_print();
    cout << "porcentaje de carga: " << energy << "%" << endl;
}
void Electric::restock(float percent){
    if (percent > 100 || percent <= 0 || percent < energy) {
        cout << "no es posible cargar al " << percent << "%" << endl;
    }
    else{
        energy = percent;
        cout << energy << "% de pila";
    }
}
void Electric::stock_loss(float _km){
    if (_km == 0 || _km*energy_per_km > (energy/100)*max_energy){
        cout << "no se puede realizar el viaje con la energia actual" << endl;
    }
    else {
        ride(_km);
        energy = energy - ((_km*energy_per_km)/max_energy)*100;
        cout << endl << energy << "% de pila";
    }
}

#endif ELECTRIC

#ifndef GAS
#define GAS

class Gas: public Vehiculo{
    //atributos
    private:
        float gas; // en litros
        int gas_max; // en litros
        float gas_per_km;
    //métodos
    public:
        // Constructores
        Gas();
        Gas(string _marca, string _modelo, float _gas, int _gas_max, float _gas_per_km);
        //getters
        float get_gas();
        int get_gas_max();
        float get_gas_per_km();
        //setters
        void set_gas(float _gas);
        void set_gas_max(int _gas_max);
        void set_gas_per_km(float _gas_per_km);
        //metodos sobreescritos por polimorfismo
        void print();
        void restock(float liters);
        void stock_loss(float _km);
};

// Constructores
Gas::Gas(): Vehiculo(){
    gas = 0;
    gas_max = 0;
    gas_per_km = 0;
}
Gas::Gas(string _marca, string _modelo, float _gas, int _gas_max, float _gas_per_km): Vehiculo(_marca, _modelo){
    gas = _gas;
    gas_max = _gas_max;
    gas_per_km = _gas_per_km;
}
//getters
float Gas::get_gas(){
    return gas;
}
int Gas::get_gas_max(){
    return gas_max;
}
float Gas::get_gas_per_km(){
    return gas_per_km;
}
//setters
void Gas::set_gas(float _gas){
    gas = _gas;
}
void Gas::set_gas_max(int _gas_max){
    gas_max = _gas_max;
}
void Gas::set_gas_per_km(float _gas_per_km){
    gas_per_km = _gas_per_km;
}
//metodos sobreescritos por polimorfismo
void Gas::print(){
    vehiculo_print();
    cout << "tanque: " << gas << " L" << endl;
}
void Gas::restock(float liters) {
    if (liters <= 0 || liters + gas > gas_max) {
        cout << "no es posible añadirle al tanque " << liters << " L" << endl;
    }
    else{
        gas = gas + liters;
        cout << "tu tanque contiene ahora " << gas << " L";
    }
}
void Gas::stock_loss(float _km) {
    if (_km == 0 || _km*gas_per_km > gas){
        cout << "no se puede realizar el viaje con la gasolina actual" << endl;
    }
    else{
        ride(_km);
        gas = gas - (_km*gas_per_km);
        cout << endl << "tu tanque contiene ahora " << gas << "L";
    }
}

#endif GAS
