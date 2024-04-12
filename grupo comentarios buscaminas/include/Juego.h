//estas directivas se aseguran que el encabezado JUEGO_H solo se incluya 1 vez durante la compilacion
#ifndef JUEGO_H//directiva para verificar si el simbolo JUEGO_H no ha sido definido antes
#define JUEGO_H//directiva para definir el simbolo JUEGO_H
#include "Tablero.h"

//interfaz de la clase Juego.h, prototipo de funciones utilizados para crear y administrar el juego


class Juego
{
//atributos privados
private:
	Tablero tablero;
	int cantidadMinas;

	int aleatorio_en_rango(int minimo, int maximo);
	int filaAleatoria();
	int columnaAleatoria();
	int vidas();


	//atributos publicos
public:

    //contructor que tiene 2 parametros que deben definirse al momento de uso
    Juego(Tablero tablero, int cantidadMinas);

    //metodos que se utilizaran como base, parte de la interfaz del header Juego.h


	void colocarMinasAleatoriamente();//metodo void que no devolvera valores, para imprimir en pantalla aleatoriamente la minas
	int solicitarFilaUsuario();//metodo int que devolvera valores enteros, para solicitar al usuario la fila que desea destapar
	int solicitarColumnaUsuario();//metodo int que devolvera valores enteros, para solicitar al usuario la columna que desea destapar
	bool jugadorGana();//metodo bool que devolvera valores booleano, para indicar que el jugador gano
	void iniciar();//metodo void que no devolvera valores, para  indicar que iniciara juego
	void dibujarPortada(string nombreArchivo);//metodo void que no devolvera valores, para dibujar la portada contien un parametro de nombre de archivo
};//fin de la clase Juego

#endif // JUEGO_H
