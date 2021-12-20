#include<cstdlib>
#include<string>
#include<fstream>
#include<iostream>
#include"admin_users.h"
using namespace std;

bool comprobardnii(string dni){
	string numeros,letra;
	if(dni.length()!=9){
		cout<<"Error el dni debe tener 9 digitos, 8 numeros 1 letra\n"<<endl;
		return false;
	}
	numeros=dni.substr(0,8);
	letra=dni.substr(8,1);
	if(!isdigit(numeros[0]) || !isdigit(numeros[1]) || !isdigit(numeros[2]) || !isdigit(numeros[3]) || !isdigit(numeros[4]) || !isdigit(numeros[5]) || !isdigit(numeros[6]) || !isdigit(numeros[7])){
		cout<<"Los numeros estan mal introducidos, deben ser 8 numeros y no cualquier otro caracter\n"<<endl;
		return false;
	}
	if(isdigit(letra[0])){
		cout<<"La letra no puede ser un numero\n"<<endl;
		return false;
	}
	if(!isalpha(letra[0])){
		cout<<"La letra debe ser un caracter\n"<<endl;
		return false;
	}
	if(toupper(letra[0])!=letra[0]){
		cout<<"La letra debe ser mayuscula\n"<<endl;
		return false;
	}
	return true;
}

int nlineass(string nom){
	ifstream fich(nom);
	int n=0;
	string cad;
	while(getline(fich,cad)){
		n++;
	}
	return n;
}


int comprobardninoexiste(string dni){
	string nom="usuarios.txt";
	ifstream fich(nom);
	string cad;
	if(fich.is_open()){
		while(getline(fich,cad,',')){
			getline(fich,cad,',');
			if(cad==dni){
				fich.close();
				return(-1);//error por existencia de dni
			}
			getline(fich,cad,'\n');
		}
	}
	return(1);//dni correcto
	fich.close();
}

int comprobardninoexisteenadmindemaquinas(string dni){
	string nom="administradoresdemaquinas.txt";
	ifstream fich(nom);
	string cad;
	if(fich.is_open()){
		while(getline(fich,cad,',')){
			getline(fich,cad,',');
			if(cad==dni){
				fich.close();
				return(-1);//error por existencia de dni
			}
			getline(fich,cad,'\n');
		}
	}
	return(1);//dni correcto
	fich.close();
}

int comprobardninoexisteenadmindeusuarios(string dni){
	string nom="administradoresdemaquinas.txt";
	ifstream fich(nom);
	string cad;
	if(fich.is_open()){
		while(getline(fich,cad,',')){
			getline(fich,cad,',');
			if(cad==dni){
				fich.close();
				return(-1);//error por existencia de dni
			}
			getline(fich,cad,'\n');
		}
	}
	return(1);//dni correcto
	fich.close();
}

int comprobaridnoexiste(string id){
	string nom="usuarios.txt";
	ifstream fich(nom);
	string cad;
	if(fich.is_open()){
		while(getline(fich,cad,',')){
			if(cad==id){
				fich.close();
				return(-1);//error por existencia de id
			}
			getline(fich,cad,',');
			getline(fich,cad,'\n');
		}
	}
	return(1);//id correcto
	fich.close();
}

int comprobaridnoexisteenadminusuario(string id){
	string nom="administradoresdeusuarios.txt";
	ifstream fich(nom);
	string cad;
	if(fich.is_open()){
		while(getline(fich,cad,',')){
			if(cad==id){
				fich.close();
				return(-1);//error por existencia de id
			}
			getline(fich,cad,',');
			getline(fich,cad,'\n');
		}
	}
	return(1);//id correcto
	fich.close();
}

int comprobaridnoexisteenadminmaquina(string id){
	string nom="administradoresdemaquinas.txt";
	ifstream fich(nom);
	string cad;
	if(fich.is_open()){
		while(getline(fich,cad,',')){
			if(cad==id){
				fich.close();
				return(-1);//error por existencia de id
			}
			getline(fich,cad,',');
			getline(fich,cad,'\n');
		}
	}
	return(1);//id correcto
	fich.close();
}

bool AdminUsers::addUsuario(Usuario a){
	int dnn=comprobardninoexiste(a.getDni());
	bool buendni;
	buendni=comprobardnii(a.getDni());
	if(buendni==false){
		return false;
	}
	if(dnn==-1){
		cout<<"dni perteneciente a otro usuario\n"<<endl;
		return false;
	}
	dnn=comprobardninoexisteenadmindeusuarios(a.getDni());
	if(dnn==-1){
		cout<<"dni perteneciente a otro admin\n"<<endl;
		return false;
	}
	dnn=comprobardninoexisteenadmindemaquinas(a.getDni());
	if(dnn==-1){
		cout<<"dni perteneciente a otro admin\n"<<endl;
		return false;
	}
	dnn=comprobaridnoexiste(a.getId());
	if(dnn==-1){
		cout<<"id perteneciente a otro usuario\n"<<endl;
		return false;
	}
	dnn=comprobaridnoexisteenadminusuario(a.getId());
	if(dnn==-1){
		cout<<"id perteneciente a otro admin\n"<<endl;
		return false;
	}
	dnn=comprobaridnoexisteenadminmaquina(a.getId());
	if(dnn==-1){
		cout<<"id perteneciente a otro admin\n"<<endl;
		return false;
	}
	string nom="usuarios.txt";
	//formato:idusuario,dni,contraseña\n
	ifstream fich(nom);
	string cad1,cad2,cad3;
	int nlin=0;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		nlin=nlineass(nom);
		for(int i=0;i<nlin;i++){
			getline(fich,cad1,',');
			if(cad1==a.getId()){
				fich.close();
				fich2.close();
				remove(nom2.c_str());
				cout<<"Usuario ya existente"<<endl;
				return false;
			}
			getline(fich,cad2,',');
			getline(fich,cad3,'\n');
			fich2<<cad1+','<<cad2+','<<cad3<<endl;
		}	
		fich2<<a.getId()+','<<a.getDni()+','<<a.getContrasena()<<endl;
		fich.close();
		fich2.close();
		remove(nom.c_str());
		rename(nom2.c_str(),nom.c_str());
		cout<<"Usuario introducido correctamente\n"<<endl;
		return true;
	}
	else{
		ofstream fich2(nom);
		fich2<<a.getId()+','<<a.getDni()+','<<a.getContrasena()<<endl;
		fich2.close();
		cout<<"Fichero de usuarios no existente, se ha creado e introducido al usuario\n"<<endl;
		return true;
	}
}

bool AdminUsers::addAdmin(Admin a){
	int dnn=comprobardninoexiste(a.getDni());
	if(dnn==-1){
		cout<<"dni perteneciente a otro usuario\n"<<endl;
		return false;
	}
	 dnn=comprobardninoexisteenadmindeusuarios(a.getDni());
	if(dnn==-1){
		cout<<"dni perteneciente a otro admin\n"<<endl;
		return false;
	}
	 dnn=comprobardninoexisteenadmindemaquinas(a.getDni());
	if(dnn==-1){
		cout<<"dni perteneciente a otro admin\n"<<endl;
		return false;
	}
	dnn=comprobaridnoexiste(a.getId());
	if(dnn==-1){
		cout<<"id perteneciente a otro usuario\n"<<endl;
		return false;
	}
	dnn=comprobaridnoexisteenadminusuario(a.getId());
	if(dnn==-1){
		cout<<"id perteneciente a otro admin\n"<<endl;
		return false;
	}
	dnn=comprobaridnoexisteenadminmaquina(a.getId());
	if(dnn==-1){
		cout<<"id perteneciente a otro admin\n"<<endl;
		return false;
	}
	int resss=3;
	string nom;
	while(resss!=0){
		system("cls");
		cout<<"Introduzca 1 para añadir admin de usuarios o 2 para admin de maquinas,o 0 para volver atras\n"<<endl;
		cout<<"Este mensaje/opcion le sale por si desea cambiar el tipo de administrador que va a añadir\n"<<endl;
		cin>>resss;
		switch(resss){
			case 1:
			{
				system("cls");
				cout<<"Ha elegido añadir en admin de usuarios\n"<<endl;
				nom="administradoresdeusuarios.txt";
				ifstream fich(nom);
				string cad1,cad2,cad3;
				int nlin=0;
				if(fich.is_open()){
					string nom2="temporal.txt";
					ofstream fich2(nom2);
					nlin=nlineass(nom);
					for(int i=0;i<nlin;i++){
						getline(fich,cad1,',');
						if(cad1==a.getId()){
							fich.close();
							fich2.close();
							remove(nom2.c_str());
							cout<<"Admin ya existente ya existente"<<endl;
							return false;
						}
						getline(fich,cad2,',');
						getline(fich,cad3,'\n');
						fich2<<cad1+','<<cad2+','<<cad3<<endl;
					}	
					fich2<<a.getId()+','<<a.getDni()+','<<a.getContrasena()<<endl;
					fich.close();
					fich2.close();
					remove(nom.c_str());
					rename(nom2.c_str(),nom.c_str());
					cout<<"Administrador introducido correctamente\n"<<endl;
					return true;
				}
				else{
					ofstream fich2(nom);
					fich2<<a.getId()+','<<a.getDni()+','<<a.getContrasena()<<endl;
					fich2.close();
					cout<<"Fichero de "<<nom<<" no existente, se ha creado e introducido al admin\n"<<endl;
					return true;
				}
			}
			break;

			case 2:
			{
				system("cls");
				cout<<"Ha elegido añadir en admin de maquinas\n"<<endl;
				nom="administradoresdemaquinas.txt";
				ifstream fich(nom);
				string cad1,cad2,cad3;
				int nlin=0;
				if(fich.is_open()){
					string nom2="temporal.txt";
					ofstream fich2(nom2);
					nlin=nlineass(nom);
					for(int i=0;i<nlin;i++){
						getline(fich,cad1,',');
						if(cad1==a.getId()){
							fich.close();
							fich2.close();
							remove(nom2.c_str());
							cout<<"Admin ya existente ya existente"<<endl;
							return false;
						}
						getline(fich,cad2,',');
						getline(fich,cad3,'\n');
						fich2<<cad1+','<<cad2+','<<cad3<<endl;
					}	
					fich2<<a.getId()+','<<a.getDni()+','<<a.getContrasena()<<endl;
					fich.close();
					fich2.close();
					remove(nom.c_str());
					rename(nom2.c_str(),nom.c_str());
					cout<<"Administrador introducido correctamente\n"<<endl;
					return true;
				}
				else{
					ofstream fich2(nom);
					fich2<<a.getId()+','<<a.getDni()+','<<a.getContrasena()<<endl;
					fich2.close();
					cout<<"Fichero de "<<nom<<" no existente, se ha creado e introducido al admin\n"<<endl;
					return true;
				}
			}
			break;

			case 0:
			{
				system("cls");
				cout<<"Ha elegido salir\n"<<endl;
			}
			break;

			default:
			cout<<"Tecla incorrecta vuelva a intentarlo"<<endl;
		}
	}
}

int AdminUsers::moodUsuario(Usuario a){
	string nom="usuarios.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3;
	int respuesta;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		while(getline(fich,cad1,',')){
			if(cad1==a.getId()){
				cout<<"Modificar id,pulse 1\n"<<endl;
				cout<<"Modificar dni,pulse 2\n"<<endl;
				cout<<"Modificar contraseña,pulse 3\n"<<endl;
				cin>>respuesta;
				while(respuesta!=1 || respuesta!=2 || respuesta!=3){
					cout<<"incorrecto"<<endl;
					cin>>respuesta;
				}	
				if(respuesta==1){
				cout<<"Ha escogido modificar id, introduzca el nuevo id\n"<<endl;
				cin>>cad1;
				while((comprobaridnoexiste(cad1))!=1){
					cout<<"Id incorrecto, vuelva a introducirlo\n"<<endl;
					cin>>cad1;
				}
				getline(fich,cad2,',');
				getline(fich,cad3,'\n');
				fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
				a.setId(cad1);
				}
				if(respuesta==2){
					cout<<"Ha escogido modificar dni, introduzca el nuevo dni\n"<<endl;
					getline(fich,cad2,',');
					cin>>cad2;
					while(comprobardninoexiste(cad2)!=1){
						cout<<"dni ya existente, vuelva a introducirlo\n"<<endl;
						cin>>cad2;
					}
					getline(fich,cad3,'\n');
					fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
					a.setDni(cad2);
				}
				if(respuesta==3){
					cout<<"Ha escogido modificar contraseña, introduzca la nueva contraseña\n"<<endl;
					getline(fich,cad2,',');
					getline(fich,cad3,'\n');
					cin>>cad3;
					fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
					a.setContrasena(cad3);
				}
			}
			else{
				getline(fich,cad2,',');
				getline(fich,cad3,'\n');
				fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;

			}
		}	
		fich.close();
		remove(nom.c_str());
		fich2.close();
		rename(nom2.c_str(),nom.c_str());
		return(0);//modificacion realizada
	}
	else{
		ofstream fich(nom);
		return(-1);//no existe fichero
	}
	return(1);//no se ha encontrado al usuario
}

int comprobardniadminnoexiste(string dni){
	string nom="administradores.txt";
	ifstream fich(nom);
	string cad;
	if(fich.is_open()){
		while(getline(fich,cad,',')){
			getline(fich,cad,',');
			if(cad==dni){
				fich.close();
				return(-1);//error por existencia de dni
			}
			getline(fich,cad,'\n');
		}
	}
	return(1);//dni correcto
	fich.close();
}

int comprobaridadminnoexiste(string id){
	string nom="administradores.txt";
	ifstream fich(nom);
	string cad;
	if(fich.is_open()){
		while(getline(fich,cad,',')){
			getline(fich,cad,',');
			if(cad==id){
				fich.close();
				return(-1);//error por existencia de id
			}
			getline(fich,cad,'\n');
		}
	}
	return(1);//id correcto
	fich.close();
}


int AdminUsers::moodAdmin(Admin a){
	string nom="administradores.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3;
	int respuesta;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		while(getline(fich,cad1,',')){
			if(cad1==a.getId()){
				cout<<"Modificar id,pulse 1\n"<<endl;
				cout<<"Modificar dni,pulse 2\n"<<endl;
				cout<<"Modificar contraseña,pulse 3\n"<<endl;
				cin>>respuesta;
				while(respuesta!=1 || respuesta!=2 || respuesta!=3){
					cout<<"incorrecto"<<endl;
					cin>>respuesta;
				}	
				if(respuesta==1){
				cout<<"Ha escogido modificar id, introduzca el nuevo id\n"<<endl;
				cin>>cad1;
				while((comprobaridadminnoexiste(cad1))!=1){
					cout<<"Id incorrecto, vuelva a introducirlo\n"<<endl;
					cin>>cad1;
				}
				getline(fich,cad2,',');
				getline(fich,cad3,'\n');
				fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
				a.setId(cad1);
				}
				if(respuesta==2){
					cout<<"Ha escogido modificar dni, introduzca el nuevo dni\n"<<endl;
					getline(fich,cad2,',');
					cin>>cad2;
					while(comprobardniadminnoexiste(cad2)!=1){
						cout<<"dni ya existente, vuelva a introducirlo\n"<<endl;
						cin>>cad2;
					}
					getline(fich,cad3,'\n');
					fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
					a.setDni(cad2);
				}
				if(respuesta==3){
					cout<<"Ha escogido modificar contraseña, introduzca la nueva contraseña\n"<<endl;
					getline(fich,cad2,',');
					getline(fich,cad3,'\n');
					cin>>cad3;
					fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
					a.setContrasena(cad3);
				}
			}
			else{
				getline(fich,cad2,',');
				getline(fich,cad3,'\n');
				fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;

			}
		}	
		fich.close();
		remove(nom.c_str());
		fich2.close();
		rename(nom2.c_str(),nom.c_str());
		return(0);//modificacion realizada
	}
	else{
		ofstream fich(nom);
		return(-1);//no existe fichero
	}
	return(1);//no se ha encontrado al admin
}

void AdminUsers::deleteUsuario(Usuario a){
	string nom="usuarios.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3;
	int respuesta;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		while(getline(fich,cad1,',')){
			if(cad1==a.getId()){
				getline(fich,cad2,',');
				getline(fich,cad3,'\n');
			}
			else{
				getline(fich,cad2,',');
				getline(fich,cad3,'\n');
				
				fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;

			}
		}	
		fich.close();
		remove(nom.c_str());
		fich2.close();
		rename(nom2.c_str(),nom.c_str());
		exit(0);//eliminacion realizada
	}
	else{
		ofstream fich(nom);
		exit(-1);//no existe fichero
	}
	exit(1);//no se ha encontrado al usuario
}


void AdminUsers::deleteAdmin(Admin a){
	string nom="administradores.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3;
	int respuesta;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		while(getline(fich,cad1,',')){
			if(cad1==a.getId()){
				getline(fich,cad2,',');
				getline(fich,cad3,'\n');
			}
			else{
				getline(fich,cad2,',');
				getline(fich,cad3,'\n');
				
				fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;

			}
		}	
		fich.close();
		remove(nom.c_str());
		fich2.close();
		rename(nom2.c_str(),nom.c_str());
		exit(0);//eliminacion realizada
	}
	else{
		ofstream fich(nom);
		exit(-1);//no existe fichero
	}
	exit(1);//no se ha encontrado al usuario
}
