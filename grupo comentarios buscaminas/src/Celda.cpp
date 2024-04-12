#include "Celda.h" //se manda a llamar al encabezado celda.h y su contenido dentro
#include <iostream>
using namespace std;
Celda::Celda() //Se inicializa el constructor llamado celda
{
}
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina) //Se envian los parametros hacia el constructor hacia la funci�n recibiendo coordenadas x,y y el boolean
{
    this->coordenadaX = coordenadaX;    //Puntero this para se�alar que la coordenada x equivale a la coordenada x, es decir guarda el contenido en memoria de coordenada x dentro de la coordenada
    this->coordenadaY = coordenadaY;
    this->mina = estadoMina;            //Guarda el contenido en memoria de la variable Mina dentro de estadoMina
    this->minaDescubierta = false;
}
int Celda::setCoordenadaX(int coordenadaX)  //Usando set se establece la coordenada x llamando los parametros de la funcion CoordenadaX
{
    this->coordenadaX = coordenadaX;
}
int Celda::getCoordenadaX()         //Llamamos el valor de la funcion privada con getCoordenadaX
{
    return this->coordenadaX;       //Regresamos o returna el valor en memoria de la coordenadaX
}
int Celda::setCoordenadaY(int coordenadaY) //Usando set se establece la coordenada y llamando los parametros de la funcion Coordenaday
{
    this->coordenadaY = coordenadaY; //Puntero que guarda en memoria los datos de la coordenada dentro del constructor
}
int Celda::getCoordenadaY() //Llamamos el valor de la funcion privada con getCoordenadaY
{
    return this->coordenadaY; //Regresamos o returna el valor en memoria de la coordenadaY
}
bool Celda::setMina(bool estadoMina)    //Se establece el valor de la mina con SetMina enviando los parametros de estadoMIna
{
    if (this->getMina())        //Si el valor de la mina es el valor de la funcion privada de Mina entonces
    {
        return false;          //regresa o returna que el valor es falso es decir, el booleando esta apagado
    }
    else{                           //De lo contrario
        this->mina = estadoMina;        //el valor de la mina guardado en memoria se pasara a estadoMina y se guardara en memoria
        return true;                //Para despues devolver que el boolean esta encendido, es verdadero.
    }
}
bool Celda::getMina()  //Se llama el valor de la funcion privada Mina, usando el get
{
    return this->mina;  //Regresa la variable usando el puntero guaradando en memoria el valor de mina
}
bool Celda::setMinaDescubierta(bool minaDescubierta) //Establece el valor de la MinaDescubierta utilizando el parametro enviado de minaDescubierta
{
    this->minaDescubierta = minaDescubierta; //el puntero guarda en memoria el valor de minaDescubierta en minaDescubierta
}
bool Celda::getMinaDescubierta()    //Se llama el valor de la funcion privada MinaDescubierta
{
    return this->minaDescubierta;   //Regresa el valor del puntero guardado en memoria de la variable minaDescubierta
}
void Celda::imprimirCelda()     //Constructor que imprime la celda
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n"; //Imprime el valor mostrado en pantalla
}   //cenda en, "Coordenada en x" , "Coordenada en y" y con mina valor de la variable mina.