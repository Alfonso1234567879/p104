#include<cstdlib>
#include<string>
#include<fstream>
#include<iostream>
#include"reservas.h"
#include"maquina.h"
#include"usuario.h"
using namespace std;

int comprobaruser(string id,string contrasena){
	string nom="usuarios.txt";
	ifstream f(nom);
	string cad1,cad2,cad3;
	if(f.is_open()){
		while(getline(f,cad1,',')){
			getline(f,cad2,',');
			getline(f,cad3,'\n');
			if(cad2==id && cad3==contrasena){
				cout<<"User encontrado\n"<<endl;
				f.close();
				return(1);//encontrado
			}
		}
	}
	else{
		cout<<"No existe el fichero"<<endl;
		return(-1);
	}
	cout<<"User no encontrado\n"<<endl;
	return(0);//no encontrado
}

int comprobaradmin(string id,string contrasena){
	string nom="administradores.txt";
	ifstream f(nom);
	string cad1,cad2,cad3;
	if(f.is_open()){
		while(getline(f,cad1,',')){
			getline(f,cad2,',');
			getline(f,cad3,'\n');
			if(cad2==id && cad3==contrasena){
				cout<<"Admin encontrado\n"<<endl;
				f.close();
				return(1);//encontrado
			}
		}
	}
	else{
		cout<<"No existe el fichero"<<endl;
		return(-1);
	}
		cout<<"Admin no encontrado\n"<<endl;
		return(0);//no encontrado
}

main(){
	cout<<"Bienvenido/a al sistema\n"<<endl;
	string id,contrasena;
	int resp,resp2;
	string c1,c2,c3;
	Usuario a("a","2","aww2");
	while(resp!=0){
		cout<<"Inicie sesion, ponga 1 si desea iniciar como usuario o 2 como administrador, o pulse 0 para salir\n"<<endl;
		cin>>resp;
		switch(resp){
			case 1:
				{
				cout<<"Ha elegido iniciar sesion como usuario\n"<<endl;
				cout<<"Introduzca su id\n"<<endl;
				cin>>id;
				cout<<"Introduzca su contrasena\n"<<endl;
				cin>>contrasena;
				int i;
				i=comprobaruser(id,contrasena);
				if(i!=1){
					cout<<"incorrecto\n"<<endl;
					return(-1);
				}
				if(i=1){
					cout<<"correcto\n"<<endl;
					ifstream fich("usuarios.txt");
					while(getline(fich,c1,',')){
						getline(fich,c2,',');
						getline(fich,c3,'\n');
						if(c1==id){
							a.setId(c1);
							a.setDni(c2);
							a.setContrasena(c3);
						}
					}
					fich.close();
				}
				while(resp2!=0){
					cout<<"1-Añadir reservas\n"<<endl;
					cout<<"2-Ver reservas\n"<<endl;
					cin>>resp2;
					switch(resp2){
						case 1:
						{
						string fecha,idmaquina;
						int duracion,cantidadnucleos,cantidadrams;
						cout<<"Introduzca la fecha que va a realizar la reserva\n"<<endl;
						cin>>fecha;
						cout<<"Introduzca el id de la maquina sobre la que se quiere realizar la reserva\n"<<endl;
						cin>>idmaquina;
						ifstream fich("maquinas.txt");
						Maquina x("a",1,2);
						while(getline(fich,c1,',')){
							getline(fich,c2,',');
							getline(fich,c3,'\n');
							if(c1==idmaquina){
							x.setID_maquina(c1);
							x.setNucleos(atoi(c2.c_str()));
							x.setRams(atoi(c3.c_str()));
							}
						}
						fich.close();
						cout<<"Introduzca la duracion de la reserva\n"<<endl;
						cin>>duracion;
						cout<<"Introduzca la cantidad de nucleos para la reserva\n"<<endl;
						cin>>cantidadnucleos;
						cout<<"Introduzca la cantidad de rams para la reserva\n"<<endl;
						cin>>cantidadrams;
						Reservas y(fecha,duracion,idmaquina,cantidadnucleos,cantidadrams);
						y.addReserva(a,x,cantidadnucleos,cantidadrams,duracion,fecha);
						}	
						break;

						case 2:
						{
							cout<<"Ha escogido ver reservas\n"<<endl;
							ifstream f("reservas.txt");
							string cad1,cad2,cad3,cad4,cad5,cad6;
							if(f.is_open()){
								while(getline(f,cad1,',')){
									getline(f,cad2,',');
									getline(f,cad3,',');
									getline(f,cad4,',');
									getline(f,cad5,',');
									getline(f,cad6,'\n');
									cout<<cad1+','<<cad2+','<<cad3+','<<cad4+','<<cad5+','<<cad6+'\n'<<endl;
								}
							}
							else{
							ofstream f("reservas.txt");
							}
						}	
						break;

						case 0:
						cout<<"Ha elegido salir\n"<<endl;
						break;

						default:
						cout<<"Tecla incorrecta vuelva a intentarlo\n"<<endl;
					}
				}
			}
			break;

			case 2:
			cout<<"Ha elegido iniciar sesion como administrador\n"<<endl;
			break;

			case 0:
			cout<<"Ha elegido salir del programa\n"<<endl;
			break;

			default:
			cout<<"Tecla incorrecta, vuelva a intentarlo\n"<<endl;
		}
	}
}
