//clase admin-usuarios
#ifndef ADMINUSERS
#define ADMINUSERS
#include<cstdlib>
#include<string>
using namespace std;
class AdminUsers:public Admin{

	public:
		AdminUsers(string idadmin,string dni,string contrasena):Admin(idadmin,dni,contrasena);
		bool addUsuario();
		int moodUsuario();
		void deleteUsuario();
		
};
#endif
