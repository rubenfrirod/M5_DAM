#include <iostream>
#include "EnemigoFinal.h"
#include "Personaje.h"
#include <conio.h>
using namespace std;

const int MAP_SIZE = 8;

// Función para imprimir el mapa en la consola
void ImMapa(char mapa[][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            std::cout << mapa[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Función que representa una batalla entre dos personajes
void batalla(Personaje& jugador, Personaje& enemigo) {
    bool turnoJugador = true;

    while (jugador.getHp() > 0 && enemigo.getHp() > 0) {
        if (turnoJugador) {
            cout << "Turno del jugador" << endl;
            int ataque = jugador.getAtack();
            enemigo.setHp(enemigo.getHp() - ataque);
            cout << "El jugador ataca al enemigo y le hace " << ataque << " puntos de daño." << endl;
        }
        else {
            cout << "Turno del enemigo" << endl;
            int ataque = enemigo.getAtack();
            jugador.setHp(jugador.getHp() - ataque);
            cout << "El enemigo ataca al jugador y le hace " << ataque << " puntos de daño." << endl;
        }

        turnoJugador = !turnoJugador;
    }

    if (jugador.getHp() <= 0) {
        cout << "El enemigo ha ganado." << endl;
    }
    else {
        cout << "El jugador ha derrotado al enemigo." << endl;
    }
}

int main() {
    srand(time(NULL));

    // Creación de los personajes (jugador y enemigos)
    Personaje jugador(100, 20, "Ruben", 0, 0);
    EnemigoFinal enemigo1(100, rand() % 10 + 1, "Enemigo1", 0, 0, 60, 20);
    EnemigoFinal enemigo2(100, rand() % 10 + 1, "Enemigo2", 0, 0, 60, 20);
    EnemigoFinal enemigo3(100, rand() % 10 + 1, "Enemigo3", 0, 0, 60, 20);
    EnemigoFinal enemigoFinal(150, rand() % 10 + 1, "EnemigoFinal", 0, 0, 50, 20);

    // Posicionamiento aleatorio de los enemigos en el mapa
    do {
        enemigo1.setPosicionX(rand() % MAP_SIZE);
        enemigo1.setPosicionY(rand() % MAP_SIZE);
    } while (enemigo1.getPosicionX() == jugador.getPosicionX() && enemigo1.getPosicionY() == jugador.getPosicionY());

    do {
        enemigo2.setPosicionX(rand() % MAP_SIZE);
        enemigo2.setPosicionY(rand() % MAP_SIZE);
    } while ((enemigo2.getPosicionX() == jugador.getPosicionX() && enemigo2.getPosicionY() == jugador.getPosicionY())
        || (enemigo2.getPosicionX() == enemigo1.getPosicionX() && enemigo2.getPosicionY() == enemigo1.getPosicionY()));

    do {
        enemigo3.setPosicionX(rand() % MAP_SIZE);
        enemigo3.setPosicionY(rand() % MAP_SIZE);
    } while ((enemigo3.getPosicionX() == jugador.getPosicionX() && enemigo3.getPosicionY() == jugador.getPosicionY())
        || (enemigo3.getPosicionX() == enemigo1.getPosicionX() && enemigo3.getPosicionY() == enemigo1.getPosicionY())
        || (enemigo3.getPosicionX() == enemigo2.getPosicionX() && enemigo3.getPosicionY() == enemigo2.getPosicionY()));

    do {
        enemigoFinal.setPosicionX(rand() % MAP_SIZE);
        enemigoFinal.setPosicionY(rand() % MAP_SIZE);
    } while ((enemigoFinal.getPosicionX() == jugador.getPosicionX() && enemigoFinal.getPosicionY() == jugador.getPosicionY())
        || (enemigoFinal.getPosicionX() == enemigo1.getPosicionX() && enemigoFinal.getPosicionY() == enemigo1.getPosicionY())
        || (enemigoFinal.getPosicionX() == enemigo2.getPosicionX() && enemigoFinal.getPosicionY() == enemigo2.getPosicionY())
        || (enemigoFinal.getPosicionX() == enemigo3.getPosicionX() && enemigoFinal.getPosicionY() == enemigo3.getPosicionY()));

    // Creación y configuración del mapa
    char mapa[MAP_SIZE][MAP_SIZE] = {
        {'*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*'}
    };

    // Colocar enemigos y jugador en el mapa
    mapa[enemigo1.getPosicionY()][enemigo1.getPosicionX()] = 'E';
    mapa[enemigo2.getPosicionY()][enemigo2.getPosicionX()] = 'E';
    mapa[enemigo3.getPosicionY()][enemigo3.getPosicionX()] = 'E';
    mapa[enemigoFinal.getPosicionY()][enemigoFinal.getPosicionX()] = 'F';

    int jugadorX = jugador.getPosicionX();
    int jugadorY = jugador.getPosicionY();

    char tecla;
    bool gameover = false;

    ImMapa(mapa);  // Mostrar el mapa inicialmente

    while (!gameover) {
        tecla = _getch();

        // Mover al jugador en función de la tecla presionada
        switch (tecla) {
        case 'w':
            if (jugadorY > 0) {
                jugadorY--;
            }
            break;

        case 's':
            if (jugadorY < MAP_SIZE - 1) {
                jugadorY++;
            }
            break;

        case 'a':
            if (jugadorX > 0) {
                jugadorX--;
            }
            break;

        case 'd':
            if (jugadorX < MAP_SIZE - 1) {
                jugadorX++;
            }
            break;

        case 'q':
            gameover = true;
            break;
        }

        system("cls");
        if (!gameover) {
            // Realizar acciones en función de la posición del jugador
            if (jugadorX == enemigo1.getPosicionX() && jugadorY == enemigo1.getPosicionY()) {
                batalla(jugador, enemigo1);
                if (jugador.getHp() > 0) {
                    enemigo1.setPosicionX(-1);
                    enemigo1.setPosicionY(-1);
                }
            }
            else if (jugadorX == enemigo2.getPosicionX() && jugadorY == enemigo2.getPosicionY()) {
                batalla(jugador, enemigo2);
                if (jugador.getHp() > 0) {
                    enemigo2.setPosicionX(-1);
                    enemigo2.setPosicionY(-1);
                }
            }
            else if (jugadorX == enemigo3.getPosicionX() && jugadorY == enemigo3.getPosicionY()) {
                batalla(jugador, enemigo3);
                if (jugador.getHp() > 0) {
                    enemigo3.setPosicionX(-1);
                    enemigo3.setPosicionY(-1);
                }
            }
            else if (jugadorX == enemigoFinal.getPosicionX() && jugadorY == enemigoFinal.getPosicionY()) {
                batalla(jugador, enemigoFinal);
                if (jugador.getHp() > 0) {
                    gameover = true;
                }
            }

            // Limpiar el mapa y colocar al jugador y enemigos en las nuevas posiciones
            for (int i = 0; i < MAP_SIZE; i++) {
                for (int j = 0; j < MAP_SIZE; j++) {
                    mapa[i][j] = '*';
                }
            }

            mapa[jugadorY][jugadorX] = 'R';

            if (enemigo1.getPosicionX() != -1 && enemigo1.getPosicionY() != -1) {
                mapa[enemigo1.getPosicionY()][enemigo1.getPosicionX()] = 'E';
            }

            if (enemigo2.getPosicionX() != -1 && enemigo2.getPosicionY() != -1) {
                mapa[enemigo2.getPosicionY()][enemigo2.getPosicionX()] = 'E';
            }

            if (enemigo3.getPosicionX() != -1 && enemigo3.getPosicionY() != -1) {
                mapa[enemigo3.getPosicionY()][enemigo3.getPosicionX()] = 'E';
            }

            ImMapa(mapa);  // Mostrar el mapa después de cada movimiento
        }
    }

    // Mostrar el resultado del juego
    if (jugador.getHp() <= 0) {
        cout << "El enemigo ha ganado." << endl;
    }
    else {
        cout << "Has derrotado al enemigo final" << endl;
        cout << "Has ganado el juego" << endl;
    }

    return 0;
}
