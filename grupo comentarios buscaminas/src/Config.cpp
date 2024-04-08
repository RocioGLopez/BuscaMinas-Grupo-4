#include <iostream> // librería estándar para entrada y salida de datos.
#include <unistd.h>
#include "Config.h" // Incluiye el archivo de cabecera donde se declara la clase Config.
using namespace std; // Usa el espacio de nombres std para no tener que usar 'std::'

// constructor de la clase Config.
Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    // Inicialización de los atributos con los valores pasados como argumento.
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}

// Método para mostrar y modificar la configuración del juego.
void Config::menuConfiguracion()
{
    int opciones; // Variable para almacenar la opción seleccionada por el usuario.
    int valorIngresado; // Variable para almacenar el valor ingresado por el usuario.
    bool repetir = true; // Variable para controlar el bucle de repetición.
    do
    {
        system("cls"); // Limpiar la pantalla, puede no ser portátil.
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl; // Mostrar mensaje de título del menú de configuración.
        cout << "\t\t-------------------"<< endl; // Mostrar separador.
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl; // Mostrar el número de filas actual del tablero.
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl; // Mostrar el número de columnas actual del tablero.
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl; // Mostrar el número de minas actual del tablero.
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl; // Mostrar el modo de juego actual.
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl; // Mostrar el número de vidas actual del jugador.
        cout << "\t\t6. Regresar al menu general" << endl; // Opción para regresar al menú principal.
        cout << "\n\t\tIngrese una opcion: "; // Solicitar al usuario que ingrese una opción.
        cin >> opciones; // Leer la opción ingresada por el usuario.
        if (opciones != 6) // Si la opción no es salir (6), solicitar al usuario que ingrese un nuevo valor.
        {
            cout << "\n\tIngrese el valor que desea cambiar: "; // Solicitar al usuario que ingrese el nuevo valor.
            cin >> valorIngresado; // Leer el nuevo valor ingresado por el usuario.
        }
        switch (opciones) // Evaluar la opción seleccionada por el usuario.
        {
        case 1: // Si la opción es 1, cambia el número de filas del tablero.
            {
                this->setfilasTablero(valorIngresado); // Llamar al método setfilasTablero para actualizar el número de filas.
                cout << "Filas del Tablero actualizadas" << endl; // Mostrar mensaje de confirmación.
                break; // Salir del switch.
            }
        case 2: // Si la opción es 2, cambiar el número de columnas del tablero.
            {
                this->setcolumnasTablero(valorIngresado); // Llamar al método setcolumnasTablero para actualizar el número de columnas.
                cout << "Columnas del Tablero actualizadas" << endl; // Mostrar mensaje de confirmación.
                break; // Salir del switch.
            }
        case 3: // Si la opción es 3, cambiar el número de minas del tablero.
            {
                this->setminasTablero(valorIngresado); // Llamar al método setminasTablero para actualizar el número de minas.
                cout << "Minas del Tablero actualizadas" << endl; // Mostrar mensaje de confirmación.
                break; // Salir del switch.
            }
        case 4: // Si la opción es 4, cambiar el modo de juego.
            {
                this->setmodoDesarrolladorTablero(valorIngresado); // Llamar al método setmodoDesarrolladorTablero para actualizar el modo de juego.
                cout << "Modo del Juego actualizado" << endl; // Mostrar mensaje de confirmación.
                break; // Salir del switch.
            }
        case 5: // Si la opción es 5, cambiar el número de vidas del jugador.
            {
                this->setvidasTablero(valorIngresado); // Llamar al método setvidasTablero para actualizar el número de vidas.
                cout << "Vidas del Juego actualizadas" << endl; // Mostrar mensaje de confirmación.
                break; // Salir del switch.
            }
        case 6: // Si la opción es 6, salir del bucle de repetición.
            repetir = false; // Establecer repetir a false para salir del bucle.
            break; // Salir del switch.
        }
        system("pause"); // Pausar la ejecución, puede no ser portátil.
    } while (repetir); // Repetir el bucle mientras repetir sea true.
}

// Métodos 'get' para obtener los valores de los atributos de la configuración.
int Config::getfilasTablero()
{
    return this->filasTablero; // Devolver el número de filas del tablero.
}

int Config::getcolumnasTablero()
{
    return this->columnasTablero; // Devolver el número de columnas del tablero.
}

int Config::getminasTablero()
{
    return this->minasTablero; // Devolver el número de minas del tablero.
}

bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero; // Devolver el modo de desarrollador del tablero.
}

int Config::getvidasTablero()
{
    return this->vidasTablero; // Devolver el número de vidas del jugador.
}

// Métodos 'set' para establecer nuevos valores a los atributos de la configuración.
void Config::setfilasTablero(int filasTablero)
{
    this->filasTablero = filasTablero; // Establecer el número de filas del tablero.
}

void Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero = columnasTablero; // Establecer el número de columnas del tablero.
}

void Config::setminasTablero(int minasTablero)
{
    this->minasTablero = minasTablero; // Establecer el número de minas del tablero.
}

void Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero = modoDesarrolladorTablero; // Establecer el modo de desarrollador del tablero.
}

void Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero = vidasTablero; // Establecer el número de vidas del jugador.
}
