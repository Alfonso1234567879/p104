//usuario clase
#ifndef USUARIO
#define USUARIO
#include<cstdlib>
#include<string>
#include"persona.h"
using namespace std;
class Usuario:public Persona{
	private:
		string idusuario_;
	public:
		Usuario(string idusuario,string dni,string contrasena):Persona(dni,contrasena){
			setId(idusuario);
		}
		inline void setId(string cad){idusuario_=cad;}
		inline string getId(){return idusuario_;}
};
#endif
