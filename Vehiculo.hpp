#ifndef VEHICULO
#define VEHICULO

#include <iostream>
using namespace std;

//clase Vehiculo
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
        /*
            * ride recibe un número de kilómetros recorridos
            * y los añade al vehículo.
            * @param km es la cantidad de kilómetros recorridos a añadir al vehículo.
        */
        void vehiculo_print();
        /*
            * vehiculo_print imprime la marca, modelo y kilómetros recorridos del vehículo.
        */
        //métodos para polimorfismo
        virtual void print() = 0;
        virtual void restock(float) = 0;
        virtual void stock_loss(float) = 0;
};

#endif //VEHICULO
