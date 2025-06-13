#include <iostream>
using namespace std;

#ifndef MOTOR
#define MOTOR

//clase Motor compuesta en Vehiculo
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

#endif //MOTOR
