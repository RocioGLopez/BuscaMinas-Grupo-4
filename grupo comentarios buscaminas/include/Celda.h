//estas directivas se aseguran que el encabezado CELDA_H solo se incluya 1 vez durante la compilacion
#ifndef CELDA_H//directiva para verificar si el simbolo CELDA_H no ha sido definido antes
#define CELDA_H//directiva para definir el simbolo CELDA_H

//interfaz de la clase Celda.h, prototipo de funciones utilizados para crear y administrar las celdas de juego

/*Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego
//Fecha: 17 marzo 2023*/

//clase celda
class Celda
{
    //atributos publicos
    public:
        Celda();//contructor vacio o por defecto
        //segundo contructor que tiene 3 parametros que deben definirse al momento de uso
        Celda(int coordenadaX, int coordenadaY, bool estadoMina);

        //metodos que se utilizaran como base, parte de la interfaz del header Celda.h

        int setCoordenadaX(int coordenadaX);//Metodo set para establecer atributo de coordenadaX entera
        int getCoordenadaX();//Metodo get para obtener valor de atributo coordenadaX entera

        int setCoordenadaY(int coordenadaY);//Metodo set para establecer atributo de coordenadaY entera
        int getCoordenadaY();//Metodo get para obtener valor de atributo coordenadaY entera

        bool setMina(bool estadoMina);//Metodo set para establecer atributo de estadoMina booleano
        bool getMina();//Metodo get para obtener valor de atributo estadoMina booleano

        bool setMinaDescubierta(bool minaDescubierta);//Metodo set para establecer atributo de minaDescubierta booleano
        bool getMinaDescubierta();//Metodo get para obtener valor de atributo minaDescubierta booleano


        void imprimirCelda();//metodo void que no devolvera valores, para imprimir celda
    //atributos protegidos para cuando se use la herencia
    protected:
    //atributos privados
    private:
        //definicion de variables
        int coordenadaX, coordenadaY;//variable enteras
        bool mina, minaDescubierta;//variable booleana
};//fin de la clase celda

#endif // CELDA_H, directiva de cierre de #ifndef (“if not defined” (si no está definido))
