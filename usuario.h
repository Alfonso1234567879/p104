//usuario clase

#ifndef USUARIO
#define USUARIO
#include<cstdlib>
#include<string>
using namespace std;
class Usuario:public Persona{
	private:
		string idusuario_;
	public:
		Usuario(string idusuario,string dni,string contrasena):Persona(dni,contrasena){
			setId(idusuario);
		}
		inline void setId(sting cad){idusuario_=cad;}
		inline string getId(){return idsuario_;}
};
#endif
