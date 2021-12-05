//calse maquina#ifndef MAQUINA_H
#define MAQUINA_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
class Maquina{
    private:
        string ID_maquina_;
        int nucleos_;
        int rams_;
    public:

        Maquina(string ID_maquina, int nucleos, int rams){
            ID_maquina_=ID_maquina;
            nucleos_=nucleos;
            rams_=rams;
        }

        void setID_maquina(string ID_maquina){
            ID_maquina_=ID_maquina;
        }

        string getID_maquina(){
            return ID_maquina_;
        }

        void setNucleos(int nucleos){
            nucleos_=nucleos;
        }

        int getNucleos(){
            return nucleos_;
        }

        void setRams(int rams){
            rams_=rams;
        }

        int getRams(){
            return rams_;
        }
        
};

#endif
