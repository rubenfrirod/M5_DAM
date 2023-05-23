#include "EnemigoFinal.h"

EnemigoFinal::EnemigoFinal(int pHp, int pAtack, std::string pName, int pPosicionX, int pPosicionY, int pSuperAttack, int pMegaPush)
    : Personaje(pHp, pAtack, pName, pPosicionX, pPosicionY) {
    superAttack = pSuperAttack;
    megaPush = pMegaPush;
}

// Getters
int EnemigoFinal::getSuperAttack() {
    return superAttack;
}

int EnemigoFinal::getMegaPush() {
    return megaPush;
}

// Setters
void EnemigoFinal::setSuperAttack(int pSuperAttack) {
    superAttack = pSuperAttack;
}

void EnemigoFinal::setMegaPush(int pMegaPush) {
    megaPush = pMegaPush;
}

