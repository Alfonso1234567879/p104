#include<cstdlib>
#include<string>
#include<fstream>
#include<iostream>
#include"reservas.h"
#include"maquina.h"
#include"usuario.h"
#include"admin_users.h"
#include"admin_maquina.h"
#include"admin.h"
using namespace std;

int comprobaruser(string id,string contrasena){
	string nom="usuarios.txt";
	ifstream f(nom);
	string cad1,cad2,cad3;
	if(f.is_open()){
		while(getline(f,cad1,',')){
			getline(f,cad2,',');
			getline(f,cad3,'\n');
			if(cad1==id && cad3==contrasena){
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

int comprobaradminmaquina(string id,string contrasena){
	string nom="administradoresdemaquinas.txt";
	ifstream f(nom);
	string cad1,cad2,cad3;
	if(f.is_open()){
		while(getline(f,cad1,',')){
			getline(f,cad2,',');
			getline(f,cad3,'\n');
			if(cad1==id && cad3==contrasena){
				cout<<"Admin encontrado\n"<<endl;
				f.close();
				return(1);//encontrado
			}
		}
	}
	else{
		cout<<"No existe el fichero"<<endl;
		ofstream f("administradoresdemaquinas.txt");
		return(-1);
	}
		cout<<"Admin no encontrado\n"<<endl;
		return(0);//no encontrado
}

int comprobaradminusuario(string id,string contrasena){
	string nom="administradoresdeusuarios.txt";
	ifstream f(nom);
	string cad1,cad2,cad3;
	if(f.is_open()){
		while(getline(f,cad1,',')){
			getline(f,cad2,',');
			getline(f,cad3,'\n');
			if(cad1==id && cad3==contrasena){
				cout<<"Admin encontrado\n"<<endl;
				f.close();
				return(1);//encontrado
			}
		}
	}
	else{
		cout<<"No existe el fichero"<<endl;
		ofstream f("administradoresdeusuarios.txt");
		return(-1);
	}
		cout<<"Admin no encontrado\n"<<endl;
		return(0);//no encontrado
}

main(){
	cout<<"Bienvenido/a al sistema\n"<<endl;
	string id,contrasena;
	int resp=3,resp2;
	string c1,c2,c3;
	Usuario a("a","2","aww2");
	AdminUsers au("as","32xx","as2");
	AdminMaq aq("s","s","s");
	Maquina maq("maq",1,1);
	while(resp!=0){
		cout<<"Inicie sesion, ponga 1 si desea iniciar como usuario o 2 como administrador, o pulse 0 para salir\n"<<endl;
		cin>>resp;
		switch(resp){
			case 1:
				{
				system("cls");
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
					system("cls");
					cout<<"1-Añadir reservas\n"<<endl;
					cout<<"2-Ver reservas\n"<<endl;
					cin>>resp2;
					switch(resp2){
						case 1:
						{
						system("cls");
						string fecha,idmaquina;
						int duracion,cantidadnucleos,cantidadrams;
						cout<<"Introduzca la fecha que va a realizar la reserva\n"<<endl;
						cin>>fecha;
						cout<<"Introduzca el id de la maquina sobre la que se quiere realizar la reserva\n"<<endl;
						cin>>idmaquina;
						ifstream fich("maquinas.txt");
						Maquina x("1a",1,2);
						while(getline(fich,c1,',')){
							getline(fich,c2,',');
							getline(fich,c3,'\n');
							if(c1==idmaquina){
							x.setID_maquina(c1);
							x.setNucleos(atoi(c2.c_str()));
							x.setRams(atoi(c3.c_str()));
							}
						}
						if(x.getID_maquina()=="1a"){
							cout<<"La maquina no existe\n"<<endl;
							fich.close();
							exit(-1);
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
						system("pause");
						}	
						break;

						case 2:
						{
							system("cls");
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
							cout<<"El fichero reservas.txt no existe"<<endl;
							ofstream f("reservas.txt");
							exit(-1);
							}
							system("pause");
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
				while(resp!=0){
					system("cls");
					cout<<"Ha elegido iniciar sesion como administrador\n"<<endl;
					cout<<"Inicie sesion, ponga 1 si desea iniciar como admin de usuario o 2 como admin de maquina, o pulse 0 para salir\n"<<endl;
					cin>>resp;
					switch(resp){
						case 1:
						{
							system("cls");
							cout<<"Introduzca su id\n"<<endl;
							cin>>id;
							cout<<"Introduzca su contrasena\n"<<endl;
							cin>>contrasena;
							int i;
							i=comprobaradminusuario(id,contrasena);
							if(i!=1){
								cout<<"incorrecto\n"<<endl;
								return(-1);
							}
							if(i=1){
								cout<<"correcto\n"<<endl;
								ifstream fich("administradoresdeusuarios.txt");
								while(getline(fich,c1,',')){
									getline(fich,c2,',');
									getline(fich,c3,'\n');
									if(c1==id){
										au.setId(c1);
										au.setDni(c2);
										au.setContrasena(c3);
									}
								}
								fich.close();
								if(au.getId()=="as"){
									cout<<"El admin no existe\n"<<endl;
									fich.close();
									exit(-1);
								}
							}
							int respp=4;
							while(respp!=0){
								system("cls");
								cout<<"Introduzca,para:\n"<<endl;
								cout<<"1-Añadir usuario\n"<<endl;
								cout<<"2-Añadir admin de usuarios\n"<<endl;
								cout<<"3-Añadir admin de maquinas\n"<<endl;
								cout<<"4-Ver administradores de usuarios\n"<<endl;
								cout<<"5-Ver administradores de maquinas\n"<<endl;
								cout<<"6-Ver usuarios\n"<<endl;
								cout<<"0-Salir\n"<<endl;
								cin>>respp;
								switch(respp){
									case 1:
									{
										system("cls");
										cout<<"Ha elegido añadir usuario:\n"<<endl;
										Usuario usu("as","32xx","as2");
										string idnuevo,dninuevo,contranueva;
										cout<<"Introduzca el id del usuario\n"<<endl;
										cin>>idnuevo;
										cout<<"Introduzca el dni del usuario\n"<<endl;
										cin>>dninuevo;
										cout<<"Introduzca la contrasena del usuario\n"<<endl;
										cin>>contranueva;
										usu.setId(idnuevo);
										usu.setDni(dninuevo);
										usu.setContrasena(contranueva);
										au.addUsuario(usu);
										system("pause");
									}
									break;

									case 2:
									{
										system("cls");
										cout<<"Ha elegido añadir administrador de usuarios\n"<<endl;
										string idnuevo,dninuevo,contranueva;
										cout<<"Introduzca el id del admin\n"<<endl;
										cin>>idnuevo;
										cout<<"Introduzca el dni del admin\n"<<endl;
										cin>>dninuevo;
										cout<<"Introduzca la contrasena del admin\n"<<endl;
										cin>>contranueva;
										au.setId(idnuevo);
										au.setDni(dninuevo);
										au.setContrasena(contranueva);
										au.addAdmin(au);
										system("pause");
									}
									break;

									case 3:
									{
										system("cls");
										cout<<"Ha elegido añadir administrador de maquinas\n"<<endl;
										string idnuevo,dninuevo,contranueva;
										cout<<"Introduzca el id del admin\n"<<endl;
										cin>>idnuevo;
										cout<<"Introduzca el dni del admin\n"<<endl;
										cin>>dninuevo;
										cout<<"Introduzca la contrasena del admin\n"<<endl;
										cin>>contranueva;
										aq.setId(idnuevo);
										aq.setDni(dninuevo);
										aq.setContrasena(contranueva);
										au.addAdmin(aq);
										system("pause");
									}

									break;

									case 4:
									{
										system("cls");
										cout<<"Ha escogido ver administradores de usuarios\n"<<endl;
										ifstream f("administradoresdeusuarios.txt");
										string cad1,cad2,cad3;
										if(f.is_open()){
											while(getline(f,cad1,',')){
												getline(f,cad2,',');
												getline(f,cad3,'\n');
												cout<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
											}
										}
										else{
											cout<<"El fichero administradoresdeusuarios.txt no existe"<<endl;
											ofstream f("administradoresdeusuarios.txt");
											exit(-1);
										}
										system("pause");
									}

									break;

									case 5:
									{
										system("cls");
										cout<<"Ha escogido ver administradores de maquinas\n"<<endl;
										ifstream f("administradoresdemaquinas.txt");
										string cad1,cad2,cad3;
										if(f.is_open()){
											while(getline(f,cad1,',')){
												getline(f,cad2,',');
												getline(f,cad3,'\n');
												cout<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
											}
										}
										else{
											cout<<"El fichero administradoresdemaquinas.txt no existe"<<endl;
											ofstream f("administradoresdemaquinas.txt");
											exit(-1);
										}
										system("pause");	
									}

									break;

									case 6:
									{
										system("cls");
										cout<<"Ha escogido ver usuarios\n"<<endl;
										ifstream f("usuarios.txt");
										string cad1,cad2,cad3;
										if(f.is_open()){
											while(getline(f,cad1,',')){
												getline(f,cad2,',');
												getline(f,cad3,'\n');
												cout<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
											}
										}
										else{
											cout<<"El fichero usuarios.txt no existe"<<endl;
											ofstream f("usuarios.txt");
											exit(-1);
										}
										system("pause");
									}
									break;

									case 0:

									system("cls");
									cout<<"Ha elegido salir\n"<<endl;
									break;

									default:
									cout<<"Tecla incorrecta, vuelva a intentarlo\n"<<endl;
								}
							}
					}	
					break;

					case 2:
					{
						system("cls");
						cout<<"Introduzca su id\n"<<endl;
						cin>>id;
						cout<<"Introduzca su contrasena\n"<<endl;
						cin>>contrasena;
						int i;
						i=comprobaradminmaquina(id,contrasena);
						if(i!=1){
							cout<<"incorrecto\n"<<endl;
							return(-1);
						}
						if(i=1){
							cout<<"correcto\n"<<endl;
							ifstream fich("administradoresdemaquinas.txt");
							while(getline(fich,c1,',')){
								getline(fich,c2,',');
								getline(fich,c3,'\n');
								if(c1==id){
									aq.setId(c1);
									aq.setDni(c2);
									aq.setContrasena(c3);
								}
							}
							fich.close();
							if(aq.getId()=="s"){
								cout<<"El admin no existe\n"<<endl;
								fich.close();
								exit(-1);
							}
						}
						int rr=4;
						while(rr!=0){
							system("cls");
							cout<<"Introduzca,para:\n"<<endl;
							cout<<"1-Añadir maquina\n"<<endl;
							cout<<"2-Ver maquinas\n"<<endl;
							cout<<"0-Salir\n"<<endl;
							cin>>rr;
							switch(rr){
								case 1:
								{
									system("cls");
									cout<<"Ha selecionado añadir maquina\n"<<endl;
									string idnuevo,nuevosnucleos,nuevasrams;
									cout<<"Introduzca el id de la maquina\n"<<endl;
									cin>>idnuevo;
									cout<<"Introduzca la cantidad de nucleos\n"<<endl;
									cin>>nuevosnucleos;
									cout<<"Introduzca la cantidad de rams\n"<<endl;
									cin>>nuevasrams;
									maq.setID_maquina(idnuevo);
									maq.setNucleos(atoi(nuevosnucleos.c_str()));
									maq.setRams(atoi(nuevasrams.c_str()));
									aq.addMaq(maq);
									system("pause");
								}
								break;

								case 2:
								{
									system("cls");
									cout<<"Ha seleccionado ver maquinas\n"<<endl;
									ifstream f("maquinas.txt");
									string cad1,cad2,cad3;
									if(f.is_open()){
										while(getline(f,cad1,',')){
											getline(f,cad2,',');
											getline(f,cad3,'\n');
											cout<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
										}
									}
									else{
										cout<<"El fichero maquinas.txt no existe"<<endl;
										ofstream f("maquinas.txt");
										exit(-1);
									}
									system("pause");
								}
								break;

								case 0:
								{
									system("cls");
									cout<<"Ha seleccionado salir\n"<<endl;
									system("pause");
								}
								break;

								default:
								system("cls");
								cout<<"Tecla incorrecta vuelva a intentarlo\n"<<endl;

							}
						}
					}
					break;
				}
			}
			break;

			case 0:
			system("cls");
			cout<<"Ha elegido salir del programa\n"<<endl;
			system("pause");
			break;

			default:
			system("cls");
			cout<<"Tecla incorrecta, vuelva a intentarlo\n"<<endl;
			system("pause");
		}
	}
}
