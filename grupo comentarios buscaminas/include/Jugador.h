//Librerias y Encabezados
#ifndef JUGADOR_H
#define JUGADOR_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;

class Jugador//Clase jugador
{
    public: // metodos para la clase
        void menuJugador();
        void agregaJugador();
        void mostrarJugador();
        void modificarJugador();
        void buscarJugador();
        void borrarJugador();
        bool loginJugador();
        bool buscarLoginJugador(string user, string passw);
        //string getapodo();



    protected:

    private:    //Atributos privados y protegidos
        string id;
        string nombre;
        string apodo;
        string contrasena;
        int vidas;
        //int partidasJugadas;
};

#endif // JUGADOR_H

