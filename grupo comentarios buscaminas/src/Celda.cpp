// Inclusi�n de la cabecera de la clase Celda
#include "Celda.h"
#include <iostream> // Inclusi�n de la librer�a de entrada/salida est�ndar
using namespace std;   // Utilizar el espacio de nombres est�ndar

// Constructor por defecto de la clase Celda
Celda::Celda()
{
}

// Constructor de la clase Celda con par�metros
// Recibe las coordenadas x e y y el estado de la mina
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)
{
    this->coordenadaX = coordenadaX;    // Asigna el valor de coordenadaX
    this->coordenadaY = coordenadaY;    // Asigna el valor de coordenadaY
    this->mina = estadoMina;            // Asigna el valor de estadoMina
    this->minaDescubierta = false;      // Inicializa el valor de minaDescubierta en false
}

// Funci�n para establecer la coordenada X de la celda
int Celda::setCoordenadaX(int coordenadaX)
{
    this->coordenadaX = coordenadaX;    // Asigna el valor de coordenadaX
}

// Funci�n para obtener la coordenada X de la celda
int Celda::getCoordenadaX()
{
    return this->coordenadaX;          // Devuelve el valor de coordenadaX
}

// Funci�n para establecer la coordenada Y de la celda
int Celda::setCoordenadaY(int coordenadaY)
{
    this->coordenadaY = coordenadaY;    // Asigna el valor de coordenadaY
}

// Funci�n para obtener la coordenada Y de la celda
int Celda::getCoordenadaY()
{
    return this->coordenadaY;          // Devuelve el valor de coordenadaY
}

// Funci�n para establecer el estado de la mina de la celda
bool Celda::setMina(bool estadoMina)
{
    if (this->getMina())              // Si ya hay una mina
    {
        return false;                 // No se puede establecer una mina
    }
    else{
        this->mina = estadoMina;      // Sino, asigna el valor de estadoMina
        return true;                 // Y devuelve true
    }
}

// Funci�n para obtener el estado de la mina de la celda
bool Celda::getMina()
{
    return this->mina;                // Devuelve el valor de mina
}

// Funci�n para establecer si la mina ha sido descubierta o no
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    this->minaDescubierta = minaDescubierta; // Asigna el valor de minaDescubierta
}

// Funci�n para obtener si la mina ha sido descubierta o no
bool Celda::getMinaDescubierta()
{
    return this->minaDescubierta;    // Devuelve el valor de minaDescubierta
}

// Funci�n para imprimir la celda con sus atributos
void Celda::imprimirCelda()
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
    // Imprime la celda con sus coordenadas y el estado de la mina
}
