//clase admin-maquina
#ifndef ADMINMAQUINA
#define ADMINMAQUINA
#include<cstdlib>
#include<string>
#include"admin.h"
#include"maquina.h"
using namespace std;
class AdminMaq:public Admin{

	public:
		AdminMaq(string idadmin,string dni,string contrasena):Admin(idadmin,dni,contrasena){};
		bool addMaq(Maquina a);
		int moodMaq(Maquina a);
		void deleteMaq(Maquina a);
		
};
#endif

