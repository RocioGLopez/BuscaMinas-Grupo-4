#include "Tablero.h" // Incluye la declaraci�n de la clase Tablero
#include <sstream> // Incluye la librer�a para trabajar con flujos de strings
#include <iostream> // Incluye la librer�a para entrada y salida est�ndar

using namespace std; // Usa el espacio de nombres est�ndar

// Definici�n del constructor por defecto de la clase Tablero
Tablero::Tablero()
{
}

// Definici�n del constructor con par�metros de la clase Tablero
Tablero::Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador)
{
    // Inicializaci�n de las variables de la clase con los valores proporcionados
    this->alturaTablero = alturaTablero;
    this->anchoTablero = anchoTablero;
    this->modoDesarrollador = modoDesarrollador;
    int x, y;
    // Creaci�n de la matriz de celdas que representa el tablero
    for (y = 0; y < this->alturaTablero; y++)
    {
        vector<Celda> fila;
        for (x = 0; x < this->anchoTablero; x++)
        {
            fila.push_back((Celda(x, y, false))); // Creaci�n de una celda y agregaci�n a la fila
        }
        this->contenidoTablero.push_back(fila); // Agregaci�n de la fila al tablero
    }
}

// M�todos para obtener y establecer la altura del tablero
int Tablero::getAlturaTablero()
{
    return this->alturaTablero;
}

int Tablero::setAlturaTablero(int alturaTablero)
{
    this->alturaTablero = alturaTablero;
}

// M�todos para obtener y establecer el ancho del tablero
int Tablero::getAnchoTablero()
{
    return this->anchoTablero;
}

int Tablero::setAnchoTablero(int anchoTablero)
{
    this->anchoTablero = anchoTablero;
}

// M�todos para obtener y establecer el modo desarrollador
bool Tablero::getModoDesarrollador()
{
    return this->modoDesarrollador;
}

bool Tablero::setModoDesarrollador(bool modoDesarrollador)
{
    this->modoDesarrollador = modoDesarrollador;
}

// M�todo para obtener la representaci�n de una celda en el tablero
string Tablero::getRepresentacionMina(int coordenadaX, int coordenadaY)
{
    // Obtiene la celda en las coordenadas especificadas
    Celda celdaTemporal = this->contenidoTablero.at(coordenadaY).at(coordenadaX);
    // Verifica si la celda tiene una mina descubierta o si est� en modo desarrollador
    if (celdaTemporal.getMinaDescubierta() || this->modoDesarrollador)
    {
        // Si la celda tiene una mina, devuelve "*"
        if (celdaTemporal.getMina())
        {
            return "*";
        }
        else
        {
            // Si no tiene mina, obtiene el n�mero de minas cercanas y lo devuelve como string
            int cantidadCelda = this->minasCercanas(coordenadaY, coordenadaX);
            string cantidadCeldaString = " ";
            stringstream ss;
            ss << cantidadCelda;
            ss >> cantidadCeldaString;
            return cantidadCeldaString;
        }
    }
    else
    {
        // Si la celda no ha sido descubierta ni est� en modo desarrollador, devuelve "?"
        return "?";
        //return "."; // Esto es un comentario, puede ser eliminado si se desea.
    }
}

// M�todo para contar la cantidad de minas cercanas a una celda
int Tablero::minasCercanas(int filaTablero, int columnaTablero)
{
    int contadorTablero = 0;
    int filaInicioTablero, filaFinTablero, columnaInicioTablero, columnaFinTablero;
    // Determina los l�mites para iterar sobre las celdas cercanas a la celda actual
    if (filaTablero <= 0)
    {
        filaInicioTablero = 0;
    }
    else
    {
        filaInicioTablero = filaTablero - 1;
    }

    if (filaTablero + 1 >= this->alturaTablero)
    {
        filaFinTablero = this->alturaTablero - 1;
    }
    else
    {
        filaFinTablero = filaTablero + 1;
    }

    if (columnaTablero <= 0)
    {
        columnaInicioTablero = 0;
    }
    else
    {
        columnaInicioTablero = columnaTablero - 1;
    }

    if (columnaTablero + 1 >= this->anchoTablero)
    {
        columnaFinTablero = this->anchoTablero - 1;
    }
    else
    {
        columnaFinTablero = columnaTablero + 1;
    }
    // Itera sobre las celdas cercanas y cuenta las minas
    int m;
    for (m = filaInicioTablero; m <= filaFinTablero; m++)
    {
        int l;
        for (l = columnaInicioTablero; l <= columnaFinTablero; l++)
        {
            if (this->contenidoTablero.at(m).at(l).getMina())
            {
                contadorTablero++;
            }
        }
    }
    return contadorTablero;
}

// M�todos para imprimir el tablero
void Tablero::imprimirSeparadorEncabezado()
{
    int m;
    for (m = 0; m <= this->anchoTablero; m++)
    {
        cout << "----";
        if (m + 2 == this->anchoTablero)
        {
            cout << "-";
        }
    }
    cout << "\n";
}

void Tablero::imprimirSeparadorFilas()
{
    int m;
    for (m = 0; m <= this->anchoTablero; m++)
    {
        if (m <= 1)
        {
            cout << "|---";
        }
        else
        {
            cout << "+---";
        }
        if (m == this->anchoTablero)
        {
            cout << "+";
        }
    }
    cout << "\n";
}

void Tablero::imprimirEncabezado()
{
    this->imprimirSeparadorEncabezado();
    cout << "|   ";
    int l;
    for (l = 0; l < this->anchoTablero; l++)
    {
        cout << "| " << l + 1 << " ";
        if (l + 1 == this->anchoTablero)
        {
            cout << "|";
        }
    }
    cout << "\n";
}

void Tablero::imprimir()
{
    this->imprimirEncabezado();
    this->imprimirSeparadorEncabezado();
    int x, y;
    for (y = 0; y < this->alturaTablero; y++)
    {
        cout << "| " << y + 1 << " ";
        for (x = 0; x < this->anchoTablero; x++)
        {
            cout << "| " << this->getRepresentacionMina(x, y) << " ";
            if (x + 1 == this->anchoTablero)
            {
                cout << "|";
            }
        }
        cout << "\n";
        this->imprimirSeparadorFilas();
    }
}

// M�todos para colocar y descubrir minas en el tablero
bool Tablero::colocarMina(int x, int y)
{
    return this->contenidoTablero.at(y).at(x).setMina(true);
}

bool Tablero::descubrirMina(int x, int y)
{
    this->contenidoTablero.at(y).at(x).setMinaDescubierta(true);
    Celda celda = this->contenidoTablero.at(y).at(x);
    if (celda.getMina())
    {
        return false;
    }
    return true;
}

// M�todo para contar la cantidad de celdas sin minas y sin descubrir en el tablero
int Tablero::contarCeldasSinMinasYSinDescubrir()
{
    int x, y, contador = 0;
    for (y = 0; y < this->alturaTablero; y++)
    {
        for (x = 0; x < this->anchoTablero; x++)
        {
            Celda celdaTemporal = this->contenidoTablero.at(y).at(x);
            if (!celdaTemporal.getMinaDescubierta() && !celdaTemporal.getMina())
            {
                contador++;
            }
        }
    }
    return contador;
}
