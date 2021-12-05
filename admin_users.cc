#include<cstdlib>
#include<string>
#include<fstream>
#include<iostream>
#include"admin_users.h"
using namespace std;

bool AdminUsers::addUsuario(Usuario a){
	string nom="usuarios.txt";
	//formato:idusuario,dni,contraseña\n
	ifstream fich(nom);
	string cad1,cad2,cad3;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		while(getline(fich,cad1,',')){
			if(cad1==a.getId()){
				fich.close();
				fich2.close();
				remove(nom2.c_str());
				return false;
			}
			getline(fich,cad2,',');
			getline(fich,cad3,'\n');
			fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
		}	
		fich.close();
		fich2.close();
		remove(nom.c_str());
		rename(nom2.c_str(),nom.c_str());
		return true;
	}
	else{
		ofstream fich(nom);
		fich<<a.getId()+','<<a.getDni()+','<<a.getContrasena()+'\n'<<endl;
		fich.close();
		return true;
	}
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

int comprobaridnoexiste(string id){
	string nom="usuarios.txt";
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
