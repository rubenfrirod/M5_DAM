#pragma once
#include "iostream"


class lancha

{
private:
    int velocidad;
    int recorrido;
    int nitro;
    std::string nombre;

public:
    //constructor    
    lancha(int pVelocidad, int pRecorrido, int pNitro, std::string pNombre);

    //getters 
    int getVelocidad();
    int getRecorrido();
    int getNitro();
    std::string getNombre();




    //setters     
    void setVelocidad(int pSpeed);
    void setRecorrido(int pFinalDistancy);
    void setNitro(int pNitro);
    void setNombre(std::string pNameRunner);

    //metodos propios
    int pVelocidadA(int dado);
    int distancia();
    void usoNitro(int opcion);
};


