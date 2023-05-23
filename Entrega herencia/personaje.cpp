#pragma once
#include "Personaje.h"
#include <iostream>

// Constructor
Personaje::Personaje(int pHp, int pAtack, std::string pName, int pPosicionX, int pPosicionY) {
    hp = pHp;
    atack = pAtack;
    name = pName;
    posicionX = pPosicionX;
    posicionY = pPosicionY;
}

// Getters
int Personaje::getHp() {
    return hp;
}

int Personaje::getAtack() {
    return atack;
}

std::string Personaje::getName() {
    return name;
}

int Personaje::getPosicionX() {
    return posicionX;
}

int Personaje::getPosicionY() {
    return posicionY;
}

// Setters
void Personaje::setHp(int pHp) {
    hp = pHp;
}

void Personaje::setAtack(int pAtack) {
    atack = pAtack;
}

void Personaje::setName(std::string pName) {
    name = pName;
}

void Personaje::setPosicionX(int pPosicionX) {
    posicionX = pPosicionX;
}

void Personaje::setPosicionY(int pPosicionY) {
    posicionY = pPosicionY;
}
