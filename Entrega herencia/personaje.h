#pragma once
#include <iostream>

class Personaje
{

private:
	int hp;
	int atack;
	std::string name;
	int posicionX;
	int posicionY;
public: Personaje(int pHp, int pAtack, std::string pName, int pPosicionX, int pPosicionY);

	  //getters 
	  int getHp();
	  int getAtack();
	  std::string getName();
	  int getPosicionX();
	  int getPosicionY();

	  //setters 
	  void setHp(int pHp);
	  void setAtack(int pAtack);
	  void setName(std::string pName);
	  void setPosicionX(int pPosicionX);
	  void setPosicionY(int pPosicionY);

	  //metodos propios};

};