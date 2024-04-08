#ifndef CONFIG_H
#define CONFIG_H

// Declaración de la clase Config
class Config//
{
public:
    // Constructor de la clase Config que recibe varios parámetros para inicializar los valores de configuración
    Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrollador, int vidasTablero);

    // Métodos de acceso para obtener los valores de las variables miembro
    int getFilasTablero() const; // Obtiene el número de filas del tablero
    int getColumnasTablero() const; // Obtiene el número de columnas del tablero
    int getMinasTablero() const; // Obtiene el número de minas del tablero
    bool getModoDesarrollador() const; // Obtiene el estado del modo desarrollador
    int getVidasTablero() const; // Obtiene el número de vidas del tablero

    // Métodos mutadores para establecer los valores de las variables miembro
    void setFilasTablero(int filasTablero); // Establece el número de filas del tablero
    void setColumnasTablero(int columnasTablero); // Establece el número de columnas del tablero
    void setMinasTablero(int minasTablero); // Establece el número de minas del tablero
    void setModoDesarrollador(bool modoDesarrollador); // Establece el estado del modo desarrollador
    void setVidasTablero(int vidasTablero); // Establece el número de vidas del tablero

private:
    // Variables miembro que almacenan la configuración del juego
    int filasTablero; // Número de filas del tablero
    int columnasTablero; // Número de columnas del tablero
    int minasTablero; // Número de minas del tablero
    bool modoDesarrollador; // Estado del modo desarrollador
    int vidasTablero; // Número de vidas del tablero
};

// Termina la definición de la clase y evita la inclusión múltiple del archivo de encabezado
#endif // CONFIG_H
