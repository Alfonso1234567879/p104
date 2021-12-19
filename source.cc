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

int maxcantidadderams=7;//cantidad maxima de rams
int maxcantidaddenucleos=6;//cantidad maxima de nucleos

bool comprobardni(string dni){
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

bool comprobarfecha(string fech){
	if(fech.length()!=10){
		cout<<"Formato incorrecto, la longitud de la fecha debe de ser 10 digitos contando los caracteres separadores\n"<<endl;
		return false;
	}
	if(fech[2]!=fech[5]){
		cout<<"Los separadores deben de ser iguales\n"<<endl;
		return false;
	}
	if(fech[2]!='/' && fech[2]!='-'){
		cout<<"Los separadores solo pueden ser / o - de otra forma sera incorrecto\n"<<endl;
		return false;
	}
	string dia,mes,anio;

	dia=fech.substr(0,2);
	if(dia.length()!=2){
		cout<<"Tiene que introducir 2 digitos para el dia\n"<<endl;
		return false;
	}
	int d,m,a;
	mes=fech.substr(3,2);
	if(mes.length()!=2){
		cout<<"Tiene que introducir 2 digitos para el mes\n"<<endl;
		return false;
	}
	anio=fech.substr(6);
	if(anio.length()!=4){
		cout<<"Tiene que introducir 4 digitos para el anio\n"<<endl;
		return false;
	}
	if(!isdigit(dia[0]) || !isdigit(dia[1])){
		cout<<"Tiene que introducir 2 digitos numericos para el dia\n"<<endl;
		return false;
	}
	d=atoi(dia.c_str());
	if(!isdigit(mes[0]) || !isdigit(mes[1])){
		cout<<"Tiene que introducir 2 digitos numericos para el mes\n"<<endl;
		return false;
	}
	m=atoi(mes.c_str());
	if(!isdigit(anio[0]) || !isdigit(anio[1]) || !isdigit(anio[2]) || !isdigit(anio[3])){
		cout<<"Tiene que introducir 4 digitos numericos para el anio\n"<<endl;
		return false;
	}
	a=atoi(anio.c_str());
	if(m>12 || m<0){
		cout<<"Fecha incorrecta, mes no valido\n"<<endl;
		return false;
	}
	if(a!=2021){
		cout<<"El año debe de ser el actual (2021)\n"<<endl;
		return false;
	}
	if(d<0){
		cout<<"El dia debe de ser mayor de 0\n"<<endl;
		return false;
	}
	if(((m==1 && d>31) || (m==3 && d>31) || (m==5 && d>31) || (m==7 && d>31) || (m==9 && d>31) || (m==11 && d>31))){
		cout<<"Este mes no puede tener mas de 31 dias\n"<<endl;
		return false;
	}
	if((m==4 && d>30) || (m==6 && d>30) || (m==8 && d>30) || (m==10 && d>30) || (m==12 && d>30)){
		cout<<"Este mes no puede tener mas de 30 dias\n"<<endl;
		return false;
	}
	if(m==2 && d>28){
		cout<<"Febrero no tiene mas de 28 dias\n"<<endl;
		return false;
	}
	cout<<"Fecha correcta\n"<<endl;
	return true;
}

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

void crearficheros(){
	ifstream fich("reservas.txt");
	if(fich.is_open()){
		fich.close();
	}
	else{
		ofstream fich("reservas.txt");
		cout<<"Fichero reservas.txt creado\n"<<endl;
	}
	ifstream fich2("maquinas.txt");
	if(fich2.is_open()){
		fich2.close();
	}
	else{
		ofstream fich2("maquinas.txt");
		cout<<"Fichero maquinas.txt creado\n"<<endl;
	}
	ifstream fich3("usuarios.txt");
	if(fich3.is_open()){
		fich3.close();
	}
	else{
		ofstream fich3("usuarios.txt");
		cout<<"Fichero usuarios.txt creado\n"<<endl;
	}
	ifstream fich4("administradoresdeusuarios.txt");
	if(fich4.is_open()){
		fich4.close();
	}
	else{
		ofstream fich4("administradoresdeusuarios.txt");
		cout<<"Fichero administradoresdeusuarios.txt creado\n"<<endl;
	}
	ifstream fich5("administradoresdemaquinas.txt");
	if(fich5.is_open()){
		fich5.close();
	}
	else{
		ofstream fich5("administradoresdemaquinas.txt");
		cout<<"Fichero administradoresdemaquinas.txt creado\n"<<endl;
	}
	system("pause");
	system("cls");
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
	crearficheros();
	system("cls");
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
					system("pause");
					system("cls");
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
					system("pause");
					system("cls");
				}
				while(resp2!=0){
					system("cls");
					cout<<"1-Añadir reservas\n"<<endl;
					cout<<"2-Ver reservas\n"<<endl;
					cout<<"3-Ver maquinas y recursos disponibles\n"<<endl;
					cout<<"0-Salir\n"<<endl;
					cin>>resp2;
					switch(resp2){
						case 1:
						{
						system("cls");
						string fecha,idmaquina;
						int duracion,cantidadnucleos,cantidadrams;
						cout<<"Introduzca la fecha que va a realizar la reserva\n"<<endl;
						bool fechacorrecta=false;
						while(fechacorrecta==false){
							cin>>fecha;
							fechacorrecta=comprobarfecha(fecha);
							system("pause");
							system("cls");
							if(fechacorrecta==false){
								cout<<"Fecha incorrecta vuelva a introducirla\n"<<endl;
							}
						}
						cout<<"Introduzca el id de la maquina sobre la que se quiere realizar la reserva\n"<<endl;
						Maquina x("1a",1,2);
						while(x.getID_maquina()=="1a"){
							cin>>idmaquina;
							ifstream fich("maquinas.txt");
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
							if(x.getID_maquina()=="1a"){
								cout<<"La maquina no existe\n"<<endl;
								system("pause");
								system("cls");
								cout<<"Vuelva a introducir un id de maquina\n"<<endl;
								fich.close();
							}
						}
						while(duracion<0 || duracion>7){
							cout<<"Introduzca la duracion de la reserva,(en dias)\n"<<endl;
							cin>>duracion;
							if(duracion>8){
								cout<<"No puede reservar mas de 7 dias, vuelva a intentarlo\n"<<endl;
							}
							if(duracion<=0){
								cout<<"Esta intentando reservar un numero negativo o de 0 dias, vuelva a intentarlo\n"<<endl;
							}
							if(duracion>0 && duracion<=7){
								cout<<"Correcto\n"<<endl;
							}
							system("pause");
							system("cls");
						}
						cantidadnucleos=0;
						while(cantidadnucleos<=0){
							cout<<"Introduzca la cantidad de nucleos para la reserva\n"<<endl;
							cin>>cantidadnucleos;
							if(cantidadnucleos<=0){
								cout<<"Esta intentando reservar un numero negativo o de 0 nucleos, vuelva a intentarlo\n"<<endl;
							}
							system("pause");
							system("cls");
						}
						cantidadrams=0;
						while(cantidadrams<=0){
							cout<<"Introduzca la cantidad de rams para la reserva\n"<<endl;
							cin>>cantidadrams;
							if(cantidadrams<=0){
								cout<<"Esta intentando reservar un numero negativo o de 0 rams, vuelva a intentarlo\n"<<endl;
							}
							system("pause");
							system("cls");
						}
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
								cout<<"El formato de las reservas es: idusuario-fecha-duracion-cantidad de nucleos-cantidad de rams\n"<<endl;
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

						case 3:
						{
							system("cls");
							cout<<"Ha seleccionado ver maquinas\n"<<endl;
							ifstream f("maquinas.txt");
							string cad1,cad2,cad3;
							if(f.is_open()){
								cout<<"El formato de las maquinas es: id-nucleos-rams\n"<<endl;
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
						cout<<"Ha elegido salir\n"<<endl;
						cout<<"Que tenga un buen dia!!\n"<<endl;
						cout<<"Pulse una tecla para continuar\n"<<endl;
						system("pause");
						system("cls");
						exit(-1);
						break;

						default:
						cout<<"Tecla incorrecta vuelva a intentarlo\n"<<endl;
						system("pause");
						system("cls");
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
										system("pause");
										dninuevo="w";
										while(comprobardni(dninuevo)==false){
											system("cls");
											cout<<"Introduzca el dni del usuario\n"<<endl;
											cin>>dninuevo;
											if(comprobardni(dninuevo)==false){
												cout<<"Dni incorrecto,vuelva a intentarlo\n"<<endl;
												system("pause");
											}
										}
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
										dninuevo="w";
										while(comprobardni(dninuevo)==false){
											system("cls");
											cout<<"Introduzca el dni del admin\n"<<endl;
											cin>>dninuevo;
											if(comprobardni(dninuevo)==false){
												cout<<"Dni incorrecto,vuelva a intentarlo\n"<<endl;
												system("pause");
											}
										}
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
										dninuevo="w";
										while(comprobardni(dninuevo)==false){
											system("cls");
											cout<<"Introduzca el dni del admin\n"<<endl;
											cin>>dninuevo;
											if(comprobardni(dninuevo)==false){
												cout<<"Dni incorrecto,vuelva a intentarlo\n"<<endl;
												system("pause");
											}
										}
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
											cout<<"El formato es: id-dni-contrasena\n"<<endl;
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
											cout<<"El formato es: id-dni-contrasena\n"<<endl;
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
											cout<<"El formato es: id-dni-contrasena\n"<<endl;
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
									cout<<"Ha elegido salir\n"<<endl;
									cout<<"Que tenga un buen dia!!\n"<<endl;
									cout<<"Pulse una tecla para continuar\n"<<endl;
									system("pause");
									system("cls");
									exit(-1);
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
									string idnuevo;
									int nuevosnucleos,nuevasrams;
									cout<<"Introduzca el id de la maquina\n"<<endl;
									cin>>idnuevo;
									nuevosnucleos=0;
									while(nuevosnucleos<=0 || nuevosnucleos>maxcantidaddenucleos){
										cout<<"Introduzca la cantidad de nucleos\n"<<endl;
										cin>>nuevosnucleos;
										if(nuevosnucleos<=0){
											cout<<"El numero de nucleos debe ser mayor que 0, vuelva a intentarlo\n"<<endl;
										}
										if(nuevosnucleos>maxcantidaddenucleos){
											cout<<"El numero de nucleos debe ser menor o igual a: "<<maxcantidaddenucleos<<endl;
										}
										system("pause");
										system("cls");
									}
									nuevasrams=0;
									while(nuevasrams<=0 || nuevasrams>maxcantidadderams){
										cout<<"Introduzca la cantidad de rams\n"<<endl;
										cin>>nuevasrams;
										if(nuevasrams<=0){
											cout<<"El numero de rams debe ser mayor que 0, vuelva a intentarlo\n"<<endl;
										}
										if(nuevasrams>maxcantidadderams){
											cout<<"El numero de rams debe ser menor o igual a: "<<maxcantidadderams<<endl;
										}
										system("pause");
										system("cls");
									}
									maq.setID_maquina(idnuevo);
									maq.setNucleos(nuevosnucleos);
									maq.setRams(nuevasrams);
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
										cout<<"El formato es: idmaquina-nucleos-rams\n"<<endl;
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
									cout<<"Ha seleccionado salir\n"<<endl;
									cout<<"Que tenga un buen dia!!\n"<<endl;
									cout<<"Pulse una tecla para continuar\n"<<endl;
									system("pause");
									system("cls");
									exit(-1);
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
			cout<<"Que tenga un buen dia!!\n"<<endl;
			system("pause");
			break;

			default:
			system("cls");
			cout<<"Tecla incorrecta, vuelva a intentarlo\n"<<endl;
			system("pause");
		}
	}
}
