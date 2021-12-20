#include<cstdlib>
#include<string>
#include<fstream>
#include<iostream>
#include"admin_maquina.h"
using namespace std;

int maxcantidadrams=7;//cantidad maxima de rams que puede reservar un usuario
int maxcantidadnucleos=6;

int comprobaridnoexistee(string id){
	string nom="maquinas.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3;
	if(fich.is_open()){
		while(getline(fich,cad1,',')){
			if(cad1==id){
				fich.close();
				return(-1);//error por existencia de id
			}
			getline(fich,cad2,',');
			getline(fich,cad3,'\n');
		}
	}
	return(1);//id correcto
	fich.close();
}

int nlineasss(string nom){
	ifstream fich(nom);
	int n=0;
	string cad;
	while(getline(fich,cad)){
		n++;
	}
	return n;
}

bool AdminMaq::addMaq(Maquina a){
	int checkid;
	checkid=comprobaridnoexistee(a.getID_maquina());
	if(a.getNucleos()>maxcantidadnucleos){
		cout<<"Error, esta introduciendo un numero mayor de nucleos al limite de nucleos establecido en el sistema\n"<<endl;
		return false;
	}
	if(a.getRams()>maxcantidadrams){
		cout<<"Error, esta introduciendo un numero mayor de rams al limite de rams establecido en el sistema\n"<<endl;
		return false;
	}
	if(checkid!=1){
		cout<<"La maquina con el id introducido ya existe\n"<<endl;
		return false;
	}
	if(a.getNucleos()<0){
		return false;
	}
	if(a.getRams()<0){
		return false;
	}
	string nom="maquinas.txt";
	//formato:idmaquina,nucleos,rams \n
	ifstream fich(nom);
	int nlin=nlineasss(nom);
	string cad1,cad2,cad3;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		for(int i=0;i<nlin;i++){
			getline(fich,cad1,',');
			if(cad1==a.getID_maquina()){
				fich.close();
				fich2.close();
				remove(nom2.c_str());
				return false;
			}
			getline(fich,cad2,',');
			getline(fich,cad3,'\n');
			fich2<<cad1+','<<cad2+','<<cad3<<endl;
		}	
		fich2<<a.getID_maquina()+','<<a.getNucleos()<<','<<a.getRams()<<endl;
		fich.close();
		fich2.close();
		remove(nom.c_str());
		rename(nom2.c_str(),nom.c_str());
		cout<<"Maquina anadida con exito\n"<<endl;
		return true;
	}
	else{
		ofstream fich(nom);
		fich<<a.getID_maquina()+','<<a.getNucleos()+','<<a.getRams()<<endl;
		fich.close();
		return true;
	}
}

int AdminMaq::moodMaq(Maquina a){
	string nom="maquinas.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3;
	int respuesta;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		while(getline(fich,cad1,',')){
			if(cad1==a.getID_maquina()){
				cout<<"Modificar id,pulse 1\n"<<endl;
				cout<<"Modificar nucleos,pulse 2\n"<<endl;
				cout<<"Modificar rams,pulse 3\n"<<endl;
				cin>>respuesta;
				while(respuesta!=1 || respuesta!=2 || respuesta!=3){
					cout<<"incorrecto"<<endl;
					cin>>respuesta;
				}	
				if(respuesta==1){
				cout<<"Ha escogido modificar id, introduzca el nuevo id\n"<<endl;
				cin>>cad1;
				while((comprobaridnoexistee(cad1))!=1){
					cout<<"Id incorrecto, vuelva a introducirlo\n"<<endl;
					cin>>cad1;
				}
				getline(fich,cad2,',');
				getline(fich,cad3,'\n');
				fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
				a.setID_maquina(cad1);
				}
				if(respuesta==2){
					cout<<"Ha escogido modificar nucleos, introduzca la nueva cantidad de nucleos\n"<<endl;
					getline(fich,cad2,',');
					cin>>cad2;
					getline(fich,cad3,'\n');
					fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
					a.setNucleos(atoi(cad2.c_str()));
				}
				if(respuesta==3){
					cout<<"Ha escogido modificar rams, introduzca la nueva cantidad\n"<<endl;
					getline(fich,cad2,',');
					getline(fich,cad3,'\n');
					cin>>cad3;
					fich2<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
					a.setRams(atoi(cad3.c_str()));
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

void AdminMaq::deleteMaq(Maquina a){
	string nom="maquinas.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3;
	int respuesta;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		while(getline(fich,cad1,',')){
			if(cad1==a.getID_maquina()){
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
