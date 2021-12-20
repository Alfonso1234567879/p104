#include<cstdlib>
#include<string>
#include<fstream>
#include<iostream>
#include"reservas.h"
using namespace std;

bool comprobarfechaa(string fech){
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
	return true;
}

int maxcantrams=7;//cantidad maxima de rams que puede reservar un usuario
int maxcantnucleos=6;//cantidad maxima de nucleos que puede reservar un usuario

int comprobaridusuarioexiste(string id){
	string nom="usuarios.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3;
	if(fich.is_open()){
		while(getline(fich,cad1,',')){
			if(cad1==id){
				fich.close();
				return(1);
			}
			getline(fich,cad2,',');
			getline(fich,cad3,'\n');
		}
	}
	else{
		fich.close();
		return(-1);
	}
}

int comprobaridmaquinaexiste(string id){
	string nom="maquinas.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3;
	if(fich.is_open()){
		while(getline(fich,cad1,',')){
			if(cad1==id){
				fich.close();
				return(1);
			}
			getline(fich,cad2,',');
			getline(fich,cad3,'\n');
		}
	}
	else{
		ofstream fich(nom);
		return(-1);
	}
}

int nlineas(string nom){
	ifstream fich(nom);
	int n=0;
	string cad;
	while(getline(fich,cad)){
		n++;
	}
	return n;
}

bool Reservas::addReserva(Usuario a,Maquina x,int cantidadareservardenucleos,int cantidadareservarderams,int duraciondereserva,string date){
	if(cantidadareservarderams<0){
		return false;
	}
	if(cantidadareservardenucleos<0){
		return false;
	}
	if(duraciondereserva>7 || duraciondereserva<0){
		return false;
	}
	bool checkfech;
	checkfech=comprobarfechaa(date);
	if(checkfech==false){return false;}
	string nom="reservas.txt";
	//formato:idusuario que hace la reserva,idmaquina sobre la que se reserva,fecha de reserva, duracion de esta,cantidad de nucleos, cantidad de rams
	ifstream fich(nom);
	string cad1,cad2,cad3,cad4,cad5,cad6;
	int i=0;
	if(fich.is_open()){
		int p;
		p=comprobaridmaquinaexiste(x.getID_maquina());
		if(p=1){
			int cantidadreservadaderams=0;
			int cantidadreservadadenucleos=0;
			ofstream fich2("temporal.txt");//fich2 temporalde reservas
			int nlin=nlineas(nom);
			for(i=0;i<nlin;i++){
				getline(fich,cad1,',');
			
				if(cad1==a.getId()){
					getline(fich,cad2,',');
					getline(fich,cad3,',');
					getline(fich,cad4,',');
					getline(fich,cad5,',');//cantidad de nucleos reservados
					cantidadreservadadenucleos=cantidadreservadadenucleos+atoi(cad5.c_str());
					if(cantidadreservadadenucleos>=maxcantnucleos){
						fich.close();
						fich2.close();
						remove("temporal.txt");
						cout<<"El usuario ya ha reservado el maximo numero de nucleos"<<endl;
						return(false);//error el usuario ya ha reservado el maximo numero de nucleos

					}
					getline(fich,cad6,'\n');//cantidad de rams reservadas
					cantidadreservadaderams=cantidadreservadaderams+atoi(cad6.c_str());
					if(cantidadreservadaderams>=maxcantrams){
						fich.close();
						fich2.close();
						remove("temporal.txt");
						cout<<"El usuario ha reservado el numero maximo de rams"<<endl;
						return(false);//error el usuario ya ha reservado el máximo numero de rams 
					} 
					fich2<<cad1+','<<cad2+','<<cad3+','<<cad4+','<<cad5+','<<cad6<<endl;
				}
				else{
					getline(fich,cad2,',');
					getline(fich,cad3,',');
					getline(fich,cad4,',');
					getline(fich,cad5,',');
					getline(fich,cad6,'\n');
					fich2<<cad1+','<<cad2+','<<cad3+','<<cad4+','<<cad5+','<<cad6<<endl;
				}
			}
			if(x.getNucleos()<cantidadareservardenucleos){
				fich.close();
				fich2.close();
				remove("temporal.txt");
				cout<<"La maquina no tiene suficientes nucleos"<<endl;
				return(false);//nucleos de la maquina insuficientes
			}
			if(x.getRams()<cantidadareservarderams){
				fich.close();
				fich2.close();
				remove("temporal.txt");
				cout<<"La maquina no tiene suficientes rams"<<endl;
				return(false);//rams de la maquina insuficientes
			}
			if(cantidadareservardenucleos+cantidadreservadadenucleos>maxcantnucleos){
				fich.close();
				fich2.close();
				remove("temporal.txt");
				cout<<"Esta intentando reservar mas nucleos de los disponibles"<<endl;
				return(false);//se quiere reservar más cantidad de nucleos de los disponibles					
			}
			if(cantidadreservadaderams+cantidadareservarderams>maxcantrams){
				fich.close();
				fich2.close();
				remove("temporal.txt");
				cout<<"Esta intentando reservar mas rams de las disponibles"<<endl;
				return(false);//se quiere reservar más cantidad de ram de los disponibles
			}
			fich2<<a.getId()+','<<x.getID_maquina()+','<<date+','<<duraciondereserva<<','<<cantidadareservardenucleos<<','<<cantidadareservarderams<<endl;
			fich.close();
			fich2.close();
			remove(nom.c_str());
			rename("temporal.txt",nom.c_str());
			ifstream fich3("maquinas.txt");//inicialmente este fichero y el de máquinas serán iguales
			int nuevosnucleos,nuevasrams;
			if(fich3.is_open()){
				ofstream fich4("temp.txt");
				nlin=nlineas("maquinas.txt");
				for(i=0;i<nlin;i++){
					getline(fich3,cad1,',');
					if(x.getID_maquina()==cad1){
						getline(fich3,cad2,',');//cantidad de nucleos
						nuevosnucleos=atoi(cad2.c_str())-cantidadareservardenucleos;
						getline(fich3,cad3,'\n');//cantidad de rams
						nuevasrams=atoi(cad3.c_str())-cantidadareservarderams;
						if((nuevosnucleos>0 && nuevasrams>0)||(nuevosnucleos==0 && nuevasrams>0)||(nuevosnucleos>0 && nuevasrams==0)){
							fich4<<cad1+','<<nuevosnucleos<<','<<nuevasrams<<endl;
						}
					}
					else{
						getline(fich3,cad2,',');
						getline(fich3,cad3,'\n');
						fich4<<cad1+','<<cad2+','<<cad3<<endl;
					}
				}
				fich3.close();
				fich4.close();
				remove("maquinas.txt");
				rename("temp.txt","maquinas.txt");
				cout<<"Reserva hecha"<<endl;
				return(true);
			}
			else{
				ofstream fich3("maquinas.txt");
				cout<<"No existe el fichero maquinas"<<endl;
				return(false);//no existe el fichero maquinas y recursos disponibles
			}	
		}
		else{
			fich.close();
			cout<<"No existe maquina con este id"<<endl;
			return(false);	
		}
	}
	else{
		ofstream fich(nom);
		cout<<"No existe el fichero reservas"<<endl;
		return(false);//no existe el fichero reservas
	}
}

int Reservas::moodReserva(Usuario a,Maquina x){
	int p=comprobaridmaquinaexiste(x.getID_maquina());
	if(p=-1){
		cout<<"La maquina no existe\n"<<endl;
		return(-3);
	}
	p=comprobaridusuarioexiste(a.getId());
	if(p=-1){
		cout<<"El usuario no existe\n"<<endl;
		return(-3);
	}
	string nom="reservas.txt";
	//formato:idusuario que hace la reserva,idmaquina sobre la que se reserva,fecha de reserva, duracion de esta,cantidad de nucleos, cantidad de rams
	ifstream fich(nom);
	string cad1,cad2,cad3,cad4,cad5,cad6;
	int respuesta;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		while(getline(fich,cad1,',')){
			getline(fich,cad2,',');
			if((cad1==a.getId())&&(cad2==x.getID_maquina())){
				cout<<"Modificar duracion,pulse 1\n"<<endl;
				cout<<"Modificar nucleos,pulse 2\n"<<endl;
				cout<<"Modificar rams,pulse 3\n"<<endl;
				cin>>respuesta;
				while(respuesta!=1 || respuesta!=2 || respuesta!=3){
					cout<<"incorrecto\n"<<endl;
					cin>>respuesta;
				}	
				if(respuesta==1){
				cout<<"Ha escogido modificar duracion,recuerde que no puede ser mas de 7 dias,y que las reservas son por dias, introduzca la nueva duracion\n"<<endl;
				cin>>cad1;
				while(atoi(cad1.c_str())>7 || atoi(cad1.c_str())<0){
					cout<<"Fecha incorrecta, vuelva a introducirla\n"<<endl;
					cin>>cad1;
				}
				getline(fich,cad3,',');
				getline(fich,cad4,',');
				getline(fich,cad5,',');
				getline(fich,cad6,'\n');
				fich2<<cad1+','<<cad2+','<<cad3+','<<cad4+','<<cad5+','<<cad6+'\n'<<endl;
				}
				if(respuesta==2){
					cout<<"Ha escogido modificar nucleos, introduzca la nueva cantidad de nucleos\n"<<endl;
					getline(fich,cad3,',');
					getline(fich,cad4,',');
					getline(fich,cad5,',');
					int c;
					cin>>c;
					int z;
					z=atoi(cad5.c_str());
					string c1,c2,c3;
					ifstream fich3("maquinasyrecursosdisponibles.txt");
					if(fich3.is_open()){
						ofstream fich4("temp.txt");
						while(getline(fich3,c1,',')){
							if(c1==x.getID_maquina()){
								getline(fich3,c2,',');//cantidad de nucleos disponibles
								if(c>atoi(c2.c_str())+z){
									fich3.close();
									fich2.close();
									fich.close();
									remove(nom2.c_str());
									remove(nom.c_str());
									return(-2);
								}
								else{
									getline(fich3,c3,'\n');
									fich4<<c1+','<<(atoi(c2.c_str())+z)-c<<','<<c3+'\n'<<endl;
								}	
							}
							else{
								fich4<<c1+','<<c2+','<<c3+'\n'<<endl;
							}
						}
						fich4.close();
						fich3.close();
						remove("maquinasyrecursosdisponibles");
						rename("temp.txt","maquinasyrecursosdisponibles");
					}
					else{
						cout<<"Archivo maquinasyrecusosdisponibles.txt no existe"<<endl;
						return(-1);
					}
					getline(fich,cad6,'\n');
					fich2<<cad1+','<<cad2+','<<cad3+','<<cad4+','<<c<<','<<cad6+'\n'<<endl;
				}
				if(respuesta==3){
					cout<<"Ha escogido modificar rams, introduzca la nueva cantidad\n"<<endl;
					getline(fich,cad3,',');
					getline(fich,cad4,',');
					getline(fich,cad5,',');
					getline(fich,cad6,'\n');
					int c;
					cin>>c;
					int z;
					z=atoi(cad6.c_str());
					string c1,c2,c3;
					ifstream fich3("maquinasyrecursosdisponibles.txt");
					if(fich3.is_open()){
						ofstream fich4("temp.txt");
						while(getline(fich3,c1,',')){
							getline(fich3,c2,',');
							if(c1==x.getID_maquina()){
								getline(fich3,c3,',');//cantidad de rams disponibles
								if(c>atoi(c3.c_str())+z){
									fich3.close();
									fich2.close();
									fich.close();
									remove(nom2.c_str());
									remove(nom.c_str());
									return(-2);
								}
								else{
									fich4<<c1+','<<c2<<','<<(atoi(c2.c_str())+z)-c<<'\n'<<endl;
								}	
							}
							else{
								fich4<<c1+','<<c2+','<<c3+'\n'<<endl;
							}
						}
						fich4.close();
						fich3.close();
						remove("maquinasyrecursosdisponibles");
						rename("temp.txt","maquinasyrecursosdisponibles");
					}
					else{
						cout<<"Archivo maquinasyrecusosdisponibles.txt no existe"<<endl;
						return(-1);
					}
					fich2<<cad1+','<<cad2+','<<cad3+','<<cad4+','<<cad5+','<<c<<'\n'<<endl;
				}
			}
			else{
				getline(fich,cad3,',');
				getline(fich,cad4,',');
				getline(fich,cad5,',');
				getline(fich,cad6,'\n');
				fich2<<cad1+','<<cad2+','<<cad3+','<<cad4+','<<cad5+','<<cad6+'\n'<<endl;
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
	return(1);//no se ha encontrado el archivo reservas
}

void Reservas::deleteReserva(Usuario a,Maquina x){
	int p=comprobaridmaquinaexiste(x.getID_maquina());
	if(p=-1){
		cout<<"La maquina no existe\n"<<endl;
		exit(-1);
	}
	p=comprobaridusuarioexiste(a.getId());
	if(p=-1){
		cout<<"El usuario no existe\n"<<endl;
		exit(-1);
	}
	string nom="reservas.txt";
	ifstream fich(nom);
	string cad1,cad2,cad3,cad4,cad5,cad6;
	int respuesta;
	int aux1,aux2;
	if(fich.is_open()){
		string nom2="temporal.txt";
		ofstream fich2(nom2);
		ifstream fich3("maquinasyrecursosdisponibles.txt");
		ofstream fich4("temp.txt");
		while(getline(fich,cad1,',')){
			getline(fich,cad2,',');
			if((cad1==a.getId())&&(cad2==x.getID_maquina())){
				getline(fich,cad3,',');
				getline(fich,cad4,',');
				getline(fich,cad5,',');
				aux1=atoi(cad5.c_str());
				getline(fich,cad6,'\n');
				aux2=atoi(cad6.c_str());
				while(getline(fich3,cad1,',')){
					getline(fich3,cad2,',');
					getline(fich3,cad3,'\n');
					if(cad1==x.getID_maquina()){
						fich4<<cad1+','<<aux1+atoi(cad2.c_str())<<','<<aux2+atoi(cad3.c_str())<<'\n'<<endl;
					}
					else{
						fich4<<cad1+','<<cad2+','<<cad3+'\n'<<endl;
					}
				}
				fich3.close();
				fich4.close();
				remove("maquinasyrecursosdisponibles.txt");
				rename("temp.txt","maquinasyrecursosdisponibles.txt");
			}
			else{
				getline(fich,cad3,',');
				getline(fich,cad4,',');
				getline(fich,cad5,',');
				getline(fich,cad6,'\n');	
				fich2<<cad1+','<<cad2+','<<cad3+','<<cad4+','<<cad5+','<<cad6+'\n'<<endl;

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
}


void Reservas::verReservas(){
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
