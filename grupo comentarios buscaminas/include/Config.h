#ifndef CONFIG_H
#define CONFIG_H

// Declaraci�n de la clase Config
class Config//
{
public:
    // Constructor de la clase Config que recibe varios par�metros para inicializar los valores de configuraci�n
    Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrollador, int vidasTablero);

    // M�todos de acceso para obtener los valores de las variables miembro
    int getFilasTablero() const; // Obtiene el n�mero de filas del tablero
    int getColumnasTablero() const; // Obtiene el n�mero de columnas del tablero
    int getMinasTablero() const; // Obtiene el n�mero de minas del tablero
    bool getModoDesarrollador() const; // Obtiene el estado del modo desarrollador
    int getVidasTablero() const; // Obtiene el n�mero de vidas del tablero

    // M�todos mutadores para establecer los valores de las variables miembro
    void setFilasTablero(int filasTablero); // Establece el n�mero de filas del tablero
    void setColumnasTablero(int columnasTablero); // Establece el n�mero de columnas del tablero
    void setMinasTablero(int minasTablero); // Establece el n�mero de minas del tablero
    void setModoDesarrollador(bool modoDesarrollador); // Establece el estado del modo desarrollador
    void setVidasTablero(int vidasTablero); // Establece el n�mero de vidas del tablero

private:
    // Variables miembro que almacenan la configuraci�n del juego
    int filasTablero; // N�mero de filas del tablero
    int columnasTablero; // N�mero de columnas del tablero
    int minasTablero; // N�mero de minas del tablero
    bool modoDesarrollador; // Estado del modo desarrollador
    int vidasTablero; // N�mero de vidas del tablero
};

// Termina la definici�n de la clase y evita la inclusi�n m�ltiple del archivo de encabezado
#endif // CONFIG_H
