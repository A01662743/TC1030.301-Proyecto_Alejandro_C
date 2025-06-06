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
    cout << "   marca: " << marca << endl;
    cout << "   modelo: " << modelo << endl;
    cout << "   kilómetros recorridos: " << km_recorridos << " km" << endl;
}
#endif VEHICULO

#ifndef MOTOR
#define MOTOR

class Motor{
    //atributos
    private:
        string combustible;
        string design;
        int cilindros;
    public:
        //constructores
        Motor();
        Motor(string _combustible, string _design, int _cilindros);
        //getters
        string get_combustible();
        string get_design();
        int get_cilindros();
        //setters
        void set_combustible(string _combustible);
        void set_design(string _design);
        void set_cilindros(int _cilindros);
};

//constructores
Motor::Motor(){
    combustible = "undefined";
    design = "undefined";
    cilindros = 0;
}
Motor::Motor(string _combustible, string _design, int _cilindros){
    combustible = _combustible;
    design = _design;
    cilindros = _cilindros;
}
//getters
string Motor::get_combustible(){
    return combustible;
}
string Motor::get_design(){
    return design;
}
int Motor::get_cilindros(){
    return cilindros;
}
//setters
void Motor::set_combustible(string _combustible){
    combustible = _combustible;
}
void Motor::set_design(string _design){
    design = _design;
}
void Motor::set_cilindros(int _cilindros){
    cilindros = _cilindros;
}

#endif MOTOR

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
        void restock(float ignore);
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
    cout << endl;
}
void Eco::restock(float ignore) {
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
        Motor motor;
    //métodos
    public:
        // Constructores
        Electric();
        Electric(string _marca, string _modelo, float _energy, float _max_energy, float _energy_per_km, string _corriente, string _design);
        //getters
        float get_energy();
        float get_max_energy();
        float get_energy_per_km();
        Motor get_motor();
        //setters
        void set_energy(float _energy);
        void set_max_energy(float _max_energy);
        void set_energy_per_km(float _energy_per_km);
        void set_motor(string _corriente, string _design);
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
    motor = Motor();
}
Electric::Electric(string _marca, string _modelo, float _energy, float _max_energy, float _energy_per_km, string _corriente, string _design): Vehiculo(_marca, _modelo){
    energy = _energy;
    max_energy = _max_energy;
    energy_per_km = _energy_per_km;
    motor = Motor(_corriente, _design, 0);
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
Motor Electric::get_motor(){
    return motor;
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
void Electric::set_motor(string _corriente, string _design){
    motor.set_combustible(_corriente);
    motor.set_design(_design);
    motor.set_cilindros(0);
}
//metodos sobreescritos por polimorfismo
void Electric::print(){
    vehiculo_print();
    cout << "   porcentaje de carga: " << energy << "%" << endl;
    cout << "   motor: " << motor.get_combustible() << " " << motor.get_design() << endl;
    cout << endl;
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
        Motor motor;
    //métodos
    public:
        // Constructores
        Gas();
        Gas(string _marca, string _modelo, float _gas, int _gas_max, float _gas_per_km, string _combustible, string _design, int _cilindros);
        //getters
        float get_gas();
        int get_gas_max();
        float get_gas_per_km();
        Motor get_motor();
        //setters
        void set_gas(float _gas);
        void set_gas_max(int _gas_max);
        void set_gas_per_km(float _gas_per_km);
        void set_motor(string _combustible, string _design, int _cilindros);
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
    motor = Motor();
}
Gas::Gas(string _marca, string _modelo, float _gas, int _gas_max, float _gas_per_km, string _combustible, string _design, int _cilindros): Vehiculo(_marca, _modelo){
    gas = _gas;
    gas_max = _gas_max;
    gas_per_km = _gas_per_km;
    motor = Motor(_combustible, _design, _cilindros);
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
Motor Gas::get_motor(){
    return motor;
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
void Gas::set_motor(string _combustible, string _design, int _cilindros){
    motor.set_combustible(_combustible);
    motor.set_design(_design);
    motor.set_cilindros(_cilindros);
}
//metodos sobreescritos
void Gas::print(){
    vehiculo_print();
    cout << "   tanque: " << gas << " L" << endl;
    cout << "   tipo de combustible: " << motor.get_combustible() << endl;
    cout << "   motor: " << motor.get_design() << "-" << motor.get_cilindros() << endl;
    cout << endl;
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

#ifndef COCHERA
#define COCHERA

class Cochera {
    //atributos
    private:
        Vehiculo** vehiculos;
        int nvehiculos = 0;
        int capacidad;
    //métodos
    public:
        //constructores
        Cochera();
        Cochera(int _capacidad);
        //getters
        int get_capacidad();
        int get_nvehiculos();
        Vehiculo** get_vehiculos();
        //métodos especiales
        void addVehiculo(Vehiculo* v);
        int buscar_por_nombre(string _marca, string _modelo);
        void eliminar(string _marca, string _modelo);
        void print();
};

Cochera::Cochera() {
    capacidad = 0;
}

Cochera::Cochera(int _capacidad) {
    capacidad = _capacidad;
    vehiculos = new Vehiculo* [capacidad];
}

int Cochera::get_capacidad() {
    return capacidad;
}

int Cochera::get_nvehiculos() {
    return nvehiculos;
}

Vehiculo** Cochera::get_vehiculos() {
    return vehiculos;
}

void Cochera::addVehiculo(Vehiculo* v) {
    if(nvehiculos < capacidad) {
        vehiculos[nvehiculos] = v;
        nvehiculos++;
        cout << endl << "Vehículo agregado a la cochera." << endl << endl;
    }
    else{
        cout << endl <<"No se puede agregar más vehículos, cochera llena." << endl << endl;
    }
}

int Cochera::buscar_por_nombre(string _marca, string _modelo){
    for(int i = 0; i < nvehiculos; i++){
        if (vehiculos[i] -> get_marca() == _marca){
            if (vehiculos[i] -> get_modelo() == _modelo){
                return(i);
            }
        }
    }
    return -1;
}

void Cochera::eliminar(string _marca, string _modelo){
    int i = buscar_por_nombre(_marca, _modelo);
    string text;
    if (i == -1){
        text = "elemento no encontrado";
    }
    else{
        nvehiculos = nvehiculos - 1;
        for (int j = i; j < nvehiculos; j++) {
            if (j == capacidad - 1) {
                vehiculos[j] = nullptr; // Evitar puntero colgante
            }
            else{
            vehiculos[j] = vehiculos[j + 1];
            }
        }
        text = "elemento eliminado";
    }
    cout << endl << text << endl << endl;
}

void Cochera::print() {
    cout << endl << "Cochera con capacidad para " << capacidad << " vehículos." << endl;
    cout << "Número de vehículos en la cochera: " << nvehiculos << endl << endl;
    for(int i = 0; i < nvehiculos; i++) {
        cout << "Vehículo " << (i + 1) << ":" << endl;
        vehiculos[i]->print();
        cout << endl << endl;
    }
}

#endif COCHERA
