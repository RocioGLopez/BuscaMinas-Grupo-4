#include <iostream> // librer�a est�ndar para entrada y salida de datos.
#include <unistd.h>
#include "Config.h" // Incluiye el archivo de cabecera donde se declara la clase Config.
using namespace std; // Usa el espacio de nombres std para no tener que usar 'std::'

// constructor de la clase Config.
Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    // Inicializaci�n de los atributos con los valores pasados como argumento.
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}

// M�todo para mostrar y modificar la configuraci�n del juego.
void Config::menuConfiguracion()
{
    int opciones; // Variable para almacenar la opci�n seleccionada por el usuario.
    int valorIngresado; // Variable para almacenar el valor ingresado por el usuario.
    bool repetir = true; // Variable para controlar el bucle de repetici�n.
    do
    {
        system("cls"); // Limpiar la pantalla, puede no ser port�til.
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl; // Mostrar mensaje de t�tulo del men� de configuraci�n.
        cout << "\t\t-------------------"<< endl; // Mostrar separador.
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl; // Mostrar el n�mero de filas actual del tablero.
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl; // Mostrar el n�mero de columnas actual del tablero.
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl; // Mostrar el n�mero de minas actual del tablero.
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl; // Mostrar el modo de juego actual.
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl; // Mostrar el n�mero de vidas actual del jugador.
        cout << "\t\t6. Regresar al menu general" << endl; // Opci�n para regresar al men� principal.
        cout << "\n\t\tIngrese una opcion: "; // Solicitar al usuario que ingrese una opci�n.
        cin >> opciones; // Leer la opci�n ingresada por el usuario.
        if (opciones != 6) // Si la opci�n no es salir (6), solicitar al usuario que ingrese un nuevo valor.
        {
            cout << "\n\tIngrese el valor que desea cambiar: "; // Solicitar al usuario que ingrese el nuevo valor.
            cin >> valorIngresado; // Leer el nuevo valor ingresado por el usuario.
        }
        switch (opciones) // Evaluar la opci�n seleccionada por el usuario.
        {
        case 1: // Si la opci�n es 1, cambia el n�mero de filas del tablero.
            {
                this->setfilasTablero(valorIngresado); // Llamar al m�todo setfilasTablero para actualizar el n�mero de filas.
                cout << "Filas del Tablero actualizadas" << endl; // Mostrar mensaje de confirmaci�n.
                break; // Salir del switch.
            }
        case 2: // Si la opci�n es 2, cambiar el n�mero de columnas del tablero.
            {
                this->setcolumnasTablero(valorIngresado); // Llamar al m�todo setcolumnasTablero para actualizar el n�mero de columnas.
                cout << "Columnas del Tablero actualizadas" << endl; // Mostrar mensaje de confirmaci�n.
                break; // Salir del switch.
            }
        case 3: // Si la opci�n es 3, cambiar el n�mero de minas del tablero.
            {
                this->setminasTablero(valorIngresado); // Llamar al m�todo setminasTablero para actualizar el n�mero de minas.
                cout << "Minas del Tablero actualizadas" << endl; // Mostrar mensaje de confirmaci�n.
                break; // Salir del switch.
            }
        case 4: // Si la opci�n es 4, cambiar el modo de juego.
            {
                this->setmodoDesarrolladorTablero(valorIngresado); // Llamar al m�todo setmodoDesarrolladorTablero para actualizar el modo de juego.
                cout << "Modo del Juego actualizado" << endl; // Mostrar mensaje de confirmaci�n.
                break; // Salir del switch.
            }
        case 5: // Si la opci�n es 5, cambiar el n�mero de vidas del jugador.
            {
                this->setvidasTablero(valorIngresado); // Llamar al m�todo setvidasTablero para actualizar el n�mero de vidas.
                cout << "Vidas del Juego actualizadas" << endl; // Mostrar mensaje de confirmaci�n.
                break; // Salir del switch.
            }
        case 6: // Si la opci�n es 6, salir del bucle de repetici�n.
            repetir = false; // Establecer repetir a false para salir del bucle.
            break; // Salir del switch.
        }
        system("pause"); // Pausar la ejecuci�n, puede no ser port�til.
    } while (repetir); // Repetir el bucle mientras repetir sea true.
}

// M�todos 'get' para obtener los valores de los atributos de la configuraci�n.
int Config::getfilasTablero()
{
    return this->filasTablero; // Devolver el n�mero de filas del tablero.
}

int Config::getcolumnasTablero()
{
    return this->columnasTablero; // Devolver el n�mero de columnas del tablero.
}

int Config::getminasTablero()
{
    return this->minasTablero; // Devolver el n�mero de minas del tablero.
}

bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero; // Devolver el modo de desarrollador del tablero.
}

int Config::getvidasTablero()
{
    return this->vidasTablero; // Devolver el n�mero de vidas del jugador.
}

// M�todos 'set' para establecer nuevos valores a los atributos de la configuraci�n.
void Config::setfilasTablero(int filasTablero)
{
    this->filasTablero = filasTablero; // Establecer el n�mero de filas del tablero.
}

void Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero = columnasTablero; // Establecer el n�mero de columnas del tablero.
}

void Config::setminasTablero(int minasTablero)
{
    this->minasTablero = minasTablero; // Establecer el n�mero de minas del tablero.
}

void Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero = modoDesarrolladorTablero; // Establecer el modo de desarrollador del tablero.
}

void Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero = vidasTablero; // Establecer el n�mero de vidas del jugador.
}
