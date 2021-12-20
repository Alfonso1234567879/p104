#include "usuario.h"
#include "admin_users.h"
#include "admin_maquina.h"
#include "reservas.h"
#include<gtest/gtest.h>
#include"admin_users.cc"
#include <fstream>

TEST(Usuario,prueba1){

    Usuario u("wwer","5555","contrasena");
    AdminUsers au("rrrr","57698776B","contrasena");
    ofstream fch("usuarios.txt");
    fch.close();
    bool resultado=au.addUsuario(u);

    EXPECT_FALSE(resultado);
}

TEST(Usuario,prueba2){
    Usuario u2("rooy","56674776J","contrasena");
    AdminUsers au2("tyrfrv","63839922L","cotrasena");
    ofstream fch("usuarios.txt");
    fch.close();
    bool resultado2=au2.addUsuario(u2);

    EXPECT_TRUE(resultado2);
}

TEST(Reservas,prueba1){
    
    Reservas r("24-12-2021",2,"idm",1,2);
    Usuario u3("werr","67463354L","cotrasena");
    Maquina x("wasdve",2,2);
    ofstream fch("reservas.txt");
    fch.close();
    bool resultado3=r.addReserva(u3,x,1,2,2,"11/12/2021");

    EXPECT_TRUE(resultado3);
}

TEST(Reservas,prueba2){
    
    Reservas r2("24-12-2021",1,"idm",1,2);
    Usuario u4("werr","67463354L","cotrasena");
    Maquina x("fvrgt",2,2);
    ofstream fch("reservas.txt");
    fch.close();

    bool resultado4=r2.addReserva(u4,x,-1,2,2,"11/11/2021");

    EXPECT_FALSE(resultado4);
}

TEST(Maquinas,prueba1){
    
    AdminMaq am1("fwrfv","34246789Q","gbet");
    Maquina x("fvrgt",2,2);
    ofstream fch("maquinas.txt");
    fch.close();
    bool resultado5=am1.addMaq(x);

    EXPECT_TRUE(resultado5);
}
TEST(Maquinas,prueba2){
    
    AdminMaq am2("fwffrfv","34246729Q","gfvgbet");
    Maquina x("fvrgt",-2,2);
    ofstream fch("maquinas.txt");
    fch.close();
    bool resultado6=am2.addMaq(x);

    EXPECT_FALSE(resultado6);
}
