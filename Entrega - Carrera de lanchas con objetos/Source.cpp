#include <iostream>
#include "Lancha.h"
using namespace std;

string name1;
string name2;
int dado;
int opcion;
string saltar;

// Función que genera un número aleatorio entre 1 y 6


int lanzarDado() {
    return dado = rand() % (7 - 1) + 1;
}

// Función que muestra el mensaje de bienvenida
void presentacion() {

    cout << "===========================================================================" << endl;
    cout << "=                               JUEGO LANCHA                              =" << endl;
    cout << "=                                Bienvenido                               =" << endl;
    cout << "===========================================================================" << endl;

}

int main() {
    srand (time(NULL));

    presentacion();
    // Creamos dos objetos de la clase lancha, uno para cada jugador
    
    lancha lancha1(0, 0, 1,"Jugador 1");
    lancha lancha2(0, 0, 1,"Jugador 2");


    for (size_t i = 1; i <= 5; i++)
    {
        // Lanzar el dado para el jugador 1 y actualizar su velocidad
        int dado1 = lanzarDado();
        int velocidad1 = lancha1.getVelocidad() + dado1;
        lancha1.setVelocidad(velocidad1);
        cout << "\nEl " << lancha1.getNombre() << " ha sacado un " << dado1 << " y su velocidad ahora es " << velocidad1 << endl;
        cout << "\nEl jugador 1 lleva una distancia de " << lancha1.distancia() << " metros" << endl;

        lancha1.usoNitro(opcion);


        // Lanzar el dado para el jugador 2 y actualizar su velocidad
        int dado2 = lanzarDado();
        int velocidad2 = lancha2.getVelocidad() + dado2;
        lancha2.setVelocidad(velocidad2);
        cout << "\nEl " << lancha2.getNombre() << " ha sacado un " << dado2 << " y su velocidad ahora es " << velocidad2 << endl;
        cout << "\nEl jugador 2 lleva una distancia de " << lancha1.distancia() << " metros" << endl;

        lancha2.usoNitro(opcion);
        
    }

    cout << "\nAhora veremos el ganador\n " << endl;

    if (lancha1.getRecorrido() > lancha2.getRecorrido()) { 
        cout << " El ganador es " << lancha1.getNombre() << " Felicidades\n" << endl; }
    else { 
        cout << " El ganador es " << lancha2.getNombre() << " Felicidades\n" << endl; }

}


