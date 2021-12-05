//clase admin
#ifndef ADMIN
#define ADMIN
#include<cstdlib>
#include<string>
#include"persona.h"
using namespace std;
class Admin:public Persona{
	private:
		string idadmin_;
	public:
		Admin(string idadmin,string dni,string contrasena):Persona(dni,contrasena){
			setId(idadmin);
		}
		inline void setId(string cad){idadmin_=cad;}
		inline string getId(){return idadmin_;}
};
#endif
