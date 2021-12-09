//clase reservas
#ifndef RESERVAS
#define RESERVAS
#include<cstdlib>
#include<string>
#include"usuario.h"
#include"maquina.h"
using namespace std;
class Reservas{

	private:
		string fecha_;//tipo de fecha será: 01-01-2000
		int duracion_;//en dias
		string idmaquina_;
		int cantidadnucleos_;
		int cantidadrams_;

	public:
		Reservas(string fecha,int duracion,string idmaquina,int cantidadnucleos,int cantidadrams){
			setFecha(fecha);
			setDuracion(duracion);
			setIdmaquina(idmaquina);
			setCantidadnucleos(cantidadnucleos);
			setCantidadrams(cantidadrams);
		};
		inline void setFecha(string cad){fecha_=cad;}
		inline string getFecha(){return fecha_;}

		inline void setDuracion(int x){duracion_=x;}
		inline int getDuracion(){return duracion_;}

		inline void setIdmaquina(string id){idmaquina_=id;}
		inline string getIdmaquina(){return idmaquina_;}

		inline void setCantidadnucleos(int x){cantidadnucleos_=x;}
		inline int getCantidadnucleos(){return cantidadnucleos_;}

		inline void setCantidadrams(int x){cantidadrams_=x;}
		inline int getCantidadrams(){return cantidadrams_;}

		bool addReserva(Usuario a,Maquina x,int cantidadareservardenucleos,int cantidadareservarderams,int duraciondereserva,string date);
		int moodReserva(Usuario a,Maquina x);
		void deleteReserva(Usuario a,Maquina x);
		void verReservas();
		
};
#endif
