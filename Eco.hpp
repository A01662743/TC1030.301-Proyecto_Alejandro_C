#ifndef ECO
#define ECO

#include <iostream>
#include "Vehiculo.hpp"
using namespace std;

//clase Eco, hereda de Vehiculo
class Eco: public Vehiculo{
    //métodos
    public:
        // Constructor
        Eco();
        Eco(string _marca, string _modelo);
        //metodos sobreescritos por polimorfismo
        void print();
        /*
            * vehiculo_print imprime la marca, modelo y kilómetros recorridos del vehículo.
        */
        void restock(float ignore);
        /*
            restock no hace nada para este tipo de vehículo.
            @param variable de recarga de combustible (no utilizada)
        */
        void stock_loss(float _km);
        /*
            stock_loss agrega kilómetros al vehículo.
            @param _km es la cantidad de kilómetros recorridos a agregar al vehículo.
        */
};

#endif //ECO
