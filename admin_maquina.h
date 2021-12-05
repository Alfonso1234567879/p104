//clase admin-maquina
#include<cstdlib>
#include<string>
#include<fstream>
#include<iostream>
#include"admin_maquina.h"
using namespace std;

bool AdminMaq::addMaq(Maquina a){
	string nom="maquinas.txt";
	//formato:idmaquina,nucleos,rams \n
	ifstream fich(nom);
	string cad1,cad2,cad3;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		while(getline(fich,cad1,',')){
			if(cad1==a.getID_maquina()){
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
		fich<<a.getID_maquina()+','<<a.getNucleos()+','<<a.getRams()+'\n'<<endl;
		fich.close();
		return true;
	}
}

int comprobaridnoexiste(string id){
	string nom="maquinas.txt";
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
				while((comprobaridnoexiste(cad1))!=1){
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







