//Estas son las librerias que se utilizaran para poder usar los diferentes comandos
#include <iostream>//libreria para habilitar las operaciones de entradas y salidas string
#include <unistd.h>//libreria para habilitar funciones
#include "Juego.h"//Archivo encabezado Juego.h para usar objetos
#include "Config.h"//Archivo encabezado Confi.h para usar objetos
#include "Jugador.h"//implentacion de clase Jugador.h
using namespace std;//Direcctiva de espacio, para simplificar el std::, esto se compilara antes

int main()//inicio del programa principal
{
    //constantes que especifican cantidades enteras
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    //constante de valor booleano
    const bool MODODESARROLLADOR = true;//verdadero = 1
    //constante entera de vidas
    const int VIDASTABLERO = 3;

    //Creacion de objeto Confi llamado configuracionJuego, con las constantes como argumentos
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    //Creacion de objeto Juego llamado juego, usando como argumentos los metodos get de configuracion juego,
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    juego.dibujarPortada("portada1.txt");//con esto la variable juego trae la portada


    srand(getpid());

    bool accesoJudador;
    Jugador jugadorRegistro;
    accesoJudador = jugadorRegistro.loginJugador();//metodo login de clase jugador
    if (accesoJudador)
    {
        //variable entera para opciones
        int opciones;
        //variable boolena verdadera
        bool repetir = true;







  //cilco do while para el menu
    do
    {
        system("cls");//comando para limpiar pantalla
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuaracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Ingresar Perfil de Jugador" << endl;
        cout << "\t\t4. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        //uso de switch para poder usar las opciones del menu
        switch (opciones)
        {
        case 1://caso uno entra a la configuracion del juego
            {
                configuracionJuego.menuConfiguracion();
                break;//cierra caso 1
            }
        case 2://caso 2
            {
              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
                juegoTemporal.iniciar();

                system("pause");//
                break;//cierra caso 2
            }
        case 3:
            {
                Jugador user;
                user.menuJugador();
                //Se crea una pausa
                system("pause");
                break;
            }



        case 4: repetir = false;
                break;//cierra caso 3
        }
    } while (repetir);// while para repetir el menu hasta que de opcion 3 y cambie a falso
    }
    system("cls");//limpia pantalla
    return 0;//fin del main
}
