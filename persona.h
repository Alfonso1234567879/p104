//clase persona
#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Persona{
    private:
        string dni_;
        string contrasena_;
    public:

    Persona(string dni,string contrasena){
        dni_=dni;
        contrasena_=contrasena;   
    }

    void setDni(string dni){
        dni_=dni;
    }

    string getDni(){
        return dni_;
    }

    void setContrasena(string contrasena){
        contrasena_=contrasena;
    }

    string getContrasena(){
        return contrasena_;
    }

};

#endif
