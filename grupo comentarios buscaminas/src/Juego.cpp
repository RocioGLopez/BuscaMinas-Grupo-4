#include "Juego.h"
#include <fstream>
#include <unistd.h>
#include<fstream>
#include "Jugador.h"

int Juego::aleatorio_en_rango(int minimo, int maximo) // realizar de forma aleatoria los numeros que se muestran en tablero
	{
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	}

	int Juego::filaAleatoria() // crea valores al azar en filas
	{
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}

	int Juego::columnaAleatoria()// crea valores al azar en las columnas
	{
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}

	Juego::Juego(Tablero tablero, int cantidadMinas)//constructor del juego que traslada el tablero, cantidad de minas y que las coloca al azar
	{
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->colocarMinasAleatoriamente();
	}

	void Juego::colocarMinasAleatoriamente() // instera las minas de forma aleatoria en el tablero
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

	int Juego::solicitarFilaUsuario() // le solicita al jugador cuantas filas va crear en su tablero
	{

		int fila = 0;
		cout << "Ingresa la FILA en la que desea jugar " << " :";
		cin >> fila;
		return fila - 1;

	}

	int Juego::solicitarColumnaUsuario()//le solicita al jugador cuantas columnas va a crear en su tablero
	{
        Jugador jugador;
		int columna = 0;
		cout << "Ingresa la COLUMNA en la que desea jugar "  <<" :";
		cin >> columna;
		return columna - 1;

	}

	bool Juego::jugadorGana()// reconoce cuando el jugar gana sin encontrar una mina
	{
		int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
		if (conteo == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Juego::iniciar()// inicia el juego ejecutando sus constructores
	{
		int fila, columna;
		while (true) // realiza un ciclo while hasta que el jugador pierda o gane
		{
			this->tablero.imprimir();
			fila = this->solicitarFilaUsuario();
			columna = this->solicitarColumnaUsuario();
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
			if (!respuestaAUsuario) // se crea un if para indicarle al jugador si gano o perdio
			{
				cout << "Perdiste el Juego\n"; // si el valor es verdadero que encontro una mina le indica que perdio
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}

			if (this->jugadorGana()) // si es falso le indica que gano
			{
				cout << "Ganaste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}
		}
	}
	void Juego::dibujarPortada(string nombreArchivo)// crea la portada del juego
	{
        string line;
        //char userInput = ' ';
        ifstream myFile(nombreArchivo);
        if(myFile.is_open())
        {
            //Se obtiene la portada del juego
            while( getline(myFile, line))
            {
                cout << line << endl;
            }
            myFile.close();
            system("pause");
        }
        else
        {
            cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
            system("pause");
        }
	}
