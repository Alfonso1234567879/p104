//clase admin-usuarios
#ifndef ADMINUSERS
#define ADMINUSERS
#include<cstdlib>
#include<string>
#include"admin.h"
#include"usuario.h"
using namespace std;
class AdminUsers:public Admin{

	public:
		AdminUsers(string idadmin,string dni,string contrasena):Admin(idadmin,dni,contrasena){};
		bool addUsuario(Usuario a);
		int moodUsuario(Usuario a);
		void deleteUsuario(Usuario a);
		bool addAdmin(Admin a);
		int moodAdmin(Admin a);
		void deleteAdmin(Admin a);
		
};
#endif
