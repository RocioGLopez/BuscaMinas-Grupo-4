//estas directivas se aseguran que el encabezado TABLERO_H solo se incluya 1 vez durante la compilacion
#ifndef TABLERO_H//directiva para verificar si el simbolo TABLERO_H no ha sido definido antes
#define TABLERO_H//directiva para definir el simbolo TABLERO_H
#include <iostream>
#include <vector>
#include "Celda.h"

using namespace std;

//interfaz de la clase Tablero.h, prototipo de funciones utilizados para crear y administrar el Tablero del juego


class Tablero
{
    //atributos publicos
    public:
        Tablero();//contructor Tablero vacio o por defecto

        //segundo contructor que tiene 3 parametros que deben definirse al momento de uso
        Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);

        //metodos que se utilizaran como base, parte de la interfaz del header Tablero.h

        int getAlturaTablero();//Metodo set para establecer atributo de alturaTablero entera
        int setAlturaTablero(int alturaTablero);//Metodo get para obtener valor de atributo filasTablero entera

        int getAnchoTablero();//Metodo set para establecer atributo de anchoTablero entera
        int setAnchoTablero(int anchoTablero);//Metodo get para obtener valor de atributo anchoTablero entera

        bool getModoDesarrollador();//Metodo set para establecer atributo de modoDesarrollador booleano
        bool setModoDesarrollador(bool modoDesarrollador);//Metodo get para obtener valor de atributo modoDesarrollador booleano

        void imprimirSeparadorEncabezado();//metodo void que no devolvera valores, para imprir separador de encabezado
        void imprimirSeparadorFilas();//metodo void que no devolvera valores, para impimir separador filas
        void imprimirEncabezado();//metodo void que no devolvera valores, para imprimir encabezado
        void imprimir();//metodo void que no devolvera valores, para imprimir
        bool colocarMina(int x, int y);//metodo boolano que devolvera valores, para colocar la mina
        bool descubrirMina(int x, int y);//metodo booleano que devolvera valores, para descubrir la mina
        int contarCeldasSinMinasYSinDescubrir();//metodo int que devolvera valores, para conteo de celdas donde no hay minas

    //atributos protegidos
    protected:

    //atributos privados
    private:
        //definicion de variables
        int alturaTablero, anchoTablero;
        bool modoDesarrollador;

        //
        vector<vector<Celda> > contenidoTablero;

        string getRepresentacionMina(int x, int y);
        int minasCercanas(int fila, int columna);
};

#endif // TABLERO_H
