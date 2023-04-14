#pragma once
#include "lancha.h"
#include "iostream"

//constructor

lancha::lancha(int pVelocidad, int pRecorrido, int pNitro, std::string pNombre) {

    velocidad = pVelocidad;
    recorrido = pRecorrido;
    nitro = pNitro;
    nombre = pNombre; 
}

//getters 

int lancha::getVelocidad() {
return velocidad;
}

int lancha::getRecorrido() {
    return recorrido;
}

int lancha::getNitro() {
    return nitro;
}

std::string lancha::getNombre() {
    return nombre;
}

//setters 

void lancha::setVelocidad(int pVelocidad) {
velocidad = pVelocidad;
}

void lancha::setRecorrido(int pRecorrido) {
    recorrido = pRecorrido;
}

void lancha::setNitro(int pNitro) {
    nitro = pNitro;
}

void lancha::setNombre(std::string pNombre) {
    nombre = pNombre;
}

//metodos propios

int lancha::pVelocidadA( int dado) {
    velocidad = getVelocidad() + dado;
    return velocidad;
}

int lancha::distancia() {
    recorrido = getRecorrido() + (velocidad * 100);
    return recorrido;
}

void lancha::usoNitro(int opcion) { 
    if (getNitro() == 1) { 
        std::cout << "¿Quieres usar el nitro? (1: Sí, 2: No): "; 
        std::cin >> opcion; 
        if (opcion == 1) { 
            setNitro(0); 
            int aleatorio = rand() % 2; 
            if (aleatorio == 0) { 
                setVelocidad(getVelocidad() / 2); 
                std::cout << "La velocidad de " << getNombre() << " se ha dividido por la mitad" << std::endl;
            } else { 
                setVelocidad(getVelocidad() * 2); 
                std::cout << "La velocidad de " << getNombre() << " se ha multiplicado por dos" << std::endl; } 
        } 
    } 
}