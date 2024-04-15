//estas directivas se aseguran que el encabezado CONFI_H solo se incluya 1 vez durante la compilacion
#ifndef CONFIG_H//directiva para verificar si el simbolo CONFI_H no ha sido definido antes
#define CONFIG_H//directiva para definir el simbolo CONFI_H


//interfaz de la clase Confi.h, prototipo de funciones utilizados para crear y administrar la configuracion del juego

class Config
{
    //atributos publicos
    public:
        //contructor unico que tiene 5 parametros que deben definirse al momento de uso
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);

        //metodos que se utilizaran como base, parte de la interfaz del header Confi.h

        int getfilasTablero();//Metodo set para establecer atributo de filasTablero entera
        int setfilasTablero(int filasTablero);//Metodo get para obtener valor de atributo filasTablero entera

        int getcolumnasTablero();//Metodo set para establecer atributo de columnasTablero entera
        int setcolumnasTablero(int columnasTablero);//Metodo get para obtener valor de atributo columnasTablero entera

        int getminasTablero();//Metodo set para establecer atributo de minasTablero entera
        int setminasTablero(int minasTablero);//Metodo get para obtener valor de atributo minasTablero entera

        bool getmodoDesarrolladorTablero();//Metodo set para establecer atributo de modoDesarrolladorTablero booleano
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);//Metodo get para obtener valor de atributo modoDesarrolladorTablero booleano

        int getvidasTablero();//Metodo set para establecer atributo de vidasTablero entera
        int setvidasTablero(int vidasTablero);//Metodo get para obtener valor de atributo vidasTablero entera

        void menuConfiguracion();//metodo void que no devolvera valores, para entrar en el menu de configuracion

    //atributos privados
    private:

        //definicion de variables
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        bool modoDesarrolladorTablero;
        int vidasTablero;
};

#endif // CONFIG_H
