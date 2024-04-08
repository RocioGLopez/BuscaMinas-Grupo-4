/*
Directivas del preprocesador
 instrucción especial que se coloca en el código fuente de un programa y que el preprocesador interpreta
 antes de la compilación.
 contienen declaraciones de funciones, clases y variables que se utilizan en este código
*/
#include "Juego.h"
#include <fstream>
#include <unistd.h>

/*

 Genera un número aleatorio en el rango especificado por minimo y maximo.
minimo y maximo son entero para que al momento de establer dentro del tablero no tomen un lugar entre dos
celdas

*/

int Juego::aleatorio_en_rango(int minimo, int maximo)
	{
	    /*
	    Esta expresión escala el número aleatorio generado por rand() para que caiga dentro del rango especificado.
	    La división por RAND_MAX convierte el número aleatorio en un valor entre 0 y 1

	    */
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	}
	/*
	Genera un un numero aletaorio que se localize dentro del tablero
	para la fila


	*/
	int Juego::filaAleatoria()
	{
	    /*
	    Este es un método de la clase Juego que genera un número aleatorio en un rango específico
	    El uso de this-> indica que el método pertenece a la instancia actual de la clase Juego
        0: Este es el límite inferior del rango para el número aleatorio

        this->tablero.getAlturaTablero() - 1 Este es el límite superior del rango para el número aleatorio
	    */
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}
	/*
	Genera un un numero aletaorio que se localize dentro del tablero
	para la columna
	*/


	int Juego::columnaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}

	/*
	Este es el constructor de la clase (Juego){juegos.h}
	Inicializa el tablero, la cantidad de minas
	 Coloca las minas de manera aleatoria en el tablero

	*/

	Juego::Juego(Tablero tablero, int cantidadMinas)
	{
		this->tablero = tablero;
    // asigna el valor del parámetro cantidadMinas al miembro de datos cantidadMinas del objeto Juego
		this->cantidadMinas = cantidadMinas;
    //Este método coloca un número de minas
		this->colocarMinasAleatoriamente();
	}
    /*
    Este método coloca las minas de manera aleatoria en el tablero hasta que se coloquen todas las minas.
    */
	void Juego::colocarMinasAleatoriamente()
	{
		int x, y, minasColocadas = 0;

		while (minasColocadas < this->cantidadMinas)
		{
			x = this->columnaAleatoria();
			y = this->filaAleatoria();
			if (this->tablero.colocarMina(x, y))
			{
				minasColocadas++;
			}
		}
	}
    /*
    Estos métodos solicitan al usuario que ingrese la fila
    */
	int Juego::solicitarFilaUsuario()
	{
		int fila = 0;
		cout << "Ingresa la FILA en la que desea jugar: ";
		cin >> fila;
		return fila - 1;
	}
    /*
    Estos métodos solicitan al usuario que ingrese la columna en las que desea jugar.
    */
	int Juego::solicitarColumnaUsuario()
	{
		int columna = 0;
		cout << "Ingresa la COLUMNA en la que desea jugar: ";
		cin >> columna;
		return columna - 1;
	}
	/*
	Este método verifica si el jugador ha ganado el juego.
	Si no quedan celdas sin minas y sin descubrir, el jugador gana.
	*/

bool Juego::jugadorGana()
{
	// Declaramos una variable entera llamada conteo.
	int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();

	// Si el conteo es igual a 0, significa que todas las celdas que no contienen una mina han sido descubiertas
	if (conteo == 0)
	{
		// En este caso, el jugador ha ganado el juego, por lo que devolvemos true
		return true;
	}
	else
	{
		/*Si el conteo no es 0, significa que todavía hay celdas sin minas que no han sido descubiertas
		 En este caso, el juego aún no ha terminado, por lo que devolvemos false
		return false;
		*/
	}
}

    /*
    Finalmente, este es el método iniciar(), que inicia el juego
    Solicita al usuario que ingrese la fila y la columna, descubre la mina en esa posición y verifica
    si el jugador ha ganado o perdido. Si el jugador pierde, se imprime el mensaje “Perdiste el Juego”
    se muestra el tablero con todas las minas.
    Si el jugador gana, se imprime el mensaje “Ganaste el Juego” y se muestra el tablero con todas las minas.
    */



	void Juego::iniciar()
{
        // Declaramos dos variables enteras, fila y columna.
        int fila, columna;

        // Este es un bucle infinito que continuará hasta que se cumpla una de las condiciones de salida.
        while (true)
        {
		// Imprimimos el estado actual del tablero.
		this->tablero.imprimir();

		// Solicitamos al usuario que ingrese la fila y la columna en las que desea jugar.
		fila = this->solicitarFilaUsuario();
		columna = this->solicitarColumnaUsuario();

		/* Intentamos descubrir una mina en la posición especificada por el usuario
		Si no hay una mina en esa posición, respuestaAUsuario será verdadero
		Si hay una mina en esa posición, respuestaAUsuario será falso
		*/
		bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);

		// Si respuestaAUsuario es falso, significa que el usuario ha descubierto una mina y ha perdido el juego.
		if (!respuestaAUsuario)
		{
			// Imprimimos un mensaje informando al usuario que ha perdido el juego.
			cout << "Perdiste el Juego\n";

			// Cambiamos el modo del tablero a modo desarrollador para revelar todas las minas.
			this->tablero.setModoDesarrollador(true);

			// Imprimimos el tablero con todas las minas reveladas.
			this->tablero.imprimir();

			// Salimos del bucle infinito porque el juego ha terminado.
			break;
		}

		// Si el jugador ha descubierto todas las celdas que no contienen una mina, ha ganado el juego.
		if (this->jugadorGana())
		{
			// Imprimimos un mensaje informando al usuario que ha ganado el juego.
			cout << "Ganaste el Juego\n";

			// Cambiamos el modo del tablero a modo desarrollador para revelar todas las minas.
			this->tablero.setModoDesarrollador(true);

			// Imprimimos el tablero con todas las minas reveladas.
			this->tablero.imprimir();

			// Salimos del bucle infinito porque el juego ha terminado.
			break;
		}
	}
}
