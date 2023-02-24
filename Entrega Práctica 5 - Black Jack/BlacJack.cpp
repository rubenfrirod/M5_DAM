// BlacJack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
using namespace std;

//Variables de uso
int picas[13];
int diamantes[13];
int corazones[13];
int treboles [13];
bool gameOver = false;

//Variables Jugador 1
string player1 = "Ruben";
int pointsPlayer1 = 0;
bool surrender1 = false;
bool winnerP1 = false;
bool loserP1 = false;
int chooseAS;

//Variables Jugador 2
string player2 = "Croupier";
int pointsPlayer2 = 0;
bool surrender2 = false;
bool winnerP2 = false;
bool loserP2 = false;



//Funciones

//Inicializa cualquier array con sus 12 posiciones a 1
//de esta forma, indicamos que todas las cartas están disponibles
//si una posición está a 0, esa carta ya está repartida y no se repite

void presentacion() {
                                    cout << "===========================================================================" << endl;
                                    cout << "=                               21 BLACK JACK                             =" << endl;
                                    cout << "=                                Bienvenido                               =" << endl;
                                    cout << "===========================================================================" << endl;
}

void inicializaArray(int(&pArray)[13]) {
    for (int i = 0; i < 13; i++) {
        pArray[i] = 1;
    }
}

//Comprueba aleatoriamente si ha de dar picas o diamantes
//y busca una carta al azar. Hasta que no encuentre una posición
// a 1, no asigna esa carta, cuyo valor es el indiceCarta + 1
void chooseCards(int& totalPoints, string player) {
    bool choosed = false;
    int indiceCarta = 0;
    string tipoPalo;
    while (!choosed) {

        //Elije una carta del 1 al 12
        indiceCarta = rand() % 12;
        //Comprueba las Copas
        int paloCarta = rand() % 4;
        if (paloCarta == 0) {
            if (picas[indiceCarta] == 1) {
                //devuelve la carta
                picas[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "Picas";
            }
            //Comprueba los diamantes
        }
        else if (paloCarta == 1){
            if(diamantes[indiceCarta] == 1) {
                diamantes[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "Diamantes";
            }
        }
        else if (paloCarta == 2) {
           if (corazones[indiceCarta] = 1){
               corazones[indiceCarta] = 0;
            choosed = true;
            tipoPalo = "Corazones";
           }
        }
        else if ( paloCarta == 3) {
            if(treboles[indiceCarta] = 1){
                treboles[indiceCarta] = 0;
            choosed = true;
            tipoPalo = "Treboles";
            }
        }

    }
    if (indiceCarta + 1 == 11) {
        if (player == player1) {
            cout << "\n Has sacado un AS , Que valor quieres darle 1/11" << endl;
            bool comprobacionAs = false;
            while (!comprobacionAs){
            cin >> chooseAS;
            if (chooseAS == 1) {
                indiceCarta = 0;
                comprobacionAs = true;
            } 
            else if (chooseAS == 11) {
                indiceCarta = 10;
                comprobacionAs = true;
            }
            else {
                cout << " | SELECCIONE UN VALOR CORRECTO | " << endl;
            }
           }
        }
        else if (player == player2) {
            if (indiceCarta + 11 == 21) {
                indiceCarta = 10;
            }
            else {
                indiceCarta = 0;
            }
        }
    }

    if (indiceCarta > 10) {
        totalPoints = 9;
    }


    totalPoints += indiceCarta + 1;
    cout << "\nEl jugador " << player << " ha sacado un " << indiceCarta + 1 << " de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
}

bool checkPoints(int& points, bool& winner, bool& loser) {
    if (points == 21) {
        winner = true;
        return true;
    }
    else if (points > 21) {
        loser = true;
        return true;
    }
    return false;
}

bool checkWhoWins(int points1, int points2, bool& winner2) {
    if (points2 > points1) {
        winner2 = true;
        return true;
    }
    else {
        return false;
    }
}

int main()

{
    presentacion();
    Sleep(500);
    inicializaArray(picas);
    inicializaArray(diamantes);
    inicializaArray(corazones);
    inicializaArray(treboles);

    srand(time(NULL));
    //primer reparto de cartas
    chooseCards(pointsPlayer1, player1);
    Sleep(100);
    chooseCards(pointsPlayer1, player1);
    Sleep(100);
    //Puede pasar que ganemos o perdamos nada más comenzar
    surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);
    Sleep(100);
    chooseCards(pointsPlayer2, player2);
    Sleep(100);
    while (!surrender1) {
        int choice = 0;
        //Comienza el juego con el jugador 1
        while (choice != 1 && choice != 2) {
            cout << "Tienes " << pointsPlayer1 << ".Quieres pedir carta?" << endl;
            cout << "1.- Sí" << endl;
            cout << "2.- No" << endl;
            cin >> choice;
            if (choice != 1 && choice != 2) {
                cout << "Por favor, elije una opción válida." << endl;
            }
        }
        if (choice == 1) {
            chooseCards(pointsPlayer1, player1);
            Sleep(100);
            surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);

            //comprueba si se ha pasado o ha ganado la partida
        }
        else {
            //Si no quiere carta, es turno de la banca
            surrender1 = true;
        }
    }
    //Termina el turno del jugador 1. Hay que comprobar si ha ganado (winnerP1) o perdido ya (loserP1), o si la banca tiene que tirar
    //if (winnerP1) {
    //  cout << "El jugador " << player1 << "gana y la banca pierde" << endl;
    //}
     if (loserP1) {
        cout << "El jugador " << player1 << "pierde y la banca gana" << endl;
    }
    else {
        //turno de la banca
        while (!surrender2) {
            chooseCards(pointsPlayer2, player2);
        
            surrender2 = checkPoints(pointsPlayer2, winnerP2, loserP2);
            if (!surrender2) {
                //Comprueba si la banca ya gana por puntos
                surrender2 = checkWhoWins(pointsPlayer1, pointsPlayer2, winnerP2);
            }
            
        }if (winnerP2 && winnerP1) {
            //EMPATAN
            cout << "La Banca y el jugador empatan" << endl;
        }
        else  if (winnerP2) {
            cout << "La banca gana y el jugador " << player1 << " pierde" << endl;
        }
        else if (loserP2) {
            cout << "La banca pierde y el jugador " << player1 << " gana" << endl;
        }
    }
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
