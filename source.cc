#include<cstdlib>
#include<string>
#include<fstream>
#include<iostream>

main(){
	cout<<"Bienvenido/a al sistema\n"<<endl;
	string id,contrasena;
	int resp,resp2;
	
	while(resp!=0){
		cout<<"Inicie sesion, ponga 1 si desea iniciar como usuario o 2 como administrador, o pulse 0 para salir\n"<<endl;
		cin>>resp;
		switch(resp){
			case 1:
			cout<<"Ha elegido iniciar sesion como usuario\n"<<endl;
			cout<<"Introduzca su id\n"<<endl;
			cin>>id;
			cout<<"Introduzca su contrasena\n"<<endl;
			cin>>contrasena;
			int i=comprobaruser(id,contrasena);
			if(i!=1){
				cout<<"incorrecto\n"<<endl;
			}
			if(i=1){
				cout<<"correcto\n"<<endl;
				while(resp2!=0){
					cout<<"1-Añadir reservas\n"<<endl;
					cout<<"2-Ver reservas\n"<<endl;
					cin>>resp2;
					switch(resp2){
						case 1:

						break;

						case 2:

						break;

						case 0:

						break;

						default:
						cout<<"Tecla incorrecta vuelva a intentarlo"<<endl;
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

int comprobaruser(string id,string contrasena){
	string nom="usuarios.txt";
	ifstream f(nom);
	string cad1,cad2,cad3;
	if(f.is_open()){
		while(getline(f,cad1,',')){
			getline(f,cad2,',')
			getline(f,cad3,'\n')
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
			getline(f,cad2,',')
			getline(f,cad3,'\n')
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
