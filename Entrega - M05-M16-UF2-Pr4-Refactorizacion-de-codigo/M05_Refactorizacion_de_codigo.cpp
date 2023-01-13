// M05_Refactorizacion_de_codigo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

//Atributos del enemigo1

int enemyLive = 1000;
string Enemyname = " 1 ";
bool enemyIsAlive = true;
int enemyDamage;

//Atributos el enemigo2

int enemyLive2 = 1000;
string Enemyname2 = "2";
bool enemyIsAlive2 = true;
int enemyDamage2;

//Atributos del heroe

string heroName;
int heroDamage;
int heroHP = 20000;
bool heroIsAlive = true;
string ataques;
int limite = 2;
int election;


void gameStart() {

	cout << "\nEl enemeigo " << Enemyname << " acaba de aparacer y tiene " << enemyLive << " de vida.\n";
	cout << "\nEl enemigo  " << Enemyname2 << " acaba de aparecer y tiene " << enemyLive2 << " de vida.\n";
	cout << "\nInserta el nombre del heroe que lo va a matar:";
	cin >> heroName;
	cout << " \nEl nombre del heroe es " << heroName << " \n";
}

//ESTO ES UN PARAMETRO POR REFERENCIA
bool checkenemyalive(int& enemyLive3, bool enemyIsAlive3) {
	if (enemyLive3 <= 0) {
		enemyLive3 = 0;
		cout << "\nHas derrotado al enemigo\n";
		return false;
	}
	else {
		return true;
	}
}


bool checkHeroStatus() {

	srand(time(NULL));
	enemyDamage = 250 + rand() % (2000 - 0);
	enemyDamage2 = 250 + rand() % (2000 - 0);

//ESTO ES UN PARAMETRO POR REFERENCIA
	enemyIsAlive2 = checkenemyalive(enemyLive2, enemyIsAlive2);

	if (enemyIsAlive2) {
		heroHP = heroHP - enemyDamage;
		cout << " \nEl enemigo 2 te ha hecho " << enemyDamage << " puntos de danyo y te quedan " << heroHP << " puntos de vida.\n";

	}
	
//ESTO ES UN PARAMETRO POR REFERENCIA
	
	enemyIsAlive = checkenemyalive(enemyLive, enemyIsAlive);

	if (enemyIsAlive) {
		heroHP = heroHP - enemyDamage;
		cout << " \nEl enemigo 1 te ha hecho " << enemyDamage << " puntos de danyo y te quedan " << heroHP << " puntos de vida.\n";

	}

	if (heroHP <= 0) {
		cout << "Has derrotado al heroe" << heroName << "\n";
		heroHP = 20000;
		return true;
	}


}

int electionEnemy() {

	cout << "\nIngrese a que enemigo quieres atacar [1/2]: ";
	cin >> election;
	return election;
}

//ESTO ES UN PARAMETRO POR REFERENCIA

int heroatack(int& enemyLive3) {
	enemyLive3 = enemyLive3 - heroDamage;
	return enemyLive3;
}

void electionattack() {

	
	if (election == 1)
	{
		cout << "\nHa seleccionado al enemigo 1\n";
	}
	else if (election == 2)
	{
		cout << " \nHa seleccionado al enemigo 2\n";
	}
	else {
		cout << "Usted ha ingresado una opcion incorrecta";
	}
	cout << "\nQue ataque quieres hacer (espada/magia/patada Te quedan " << limite << "): ";
	cin >> ataques;

	if (ataques == "espada") {
		heroDamage = 1000;
	}
	else if (ataques == "magia") {
		heroDamage = 500;
	}
	if (limite > 0) {
		if (ataques == "patada") {
			limite = limite - 1;
			heroDamage = 300;
		}
	}
	if (election == 1)
	{
		//ESTO ES UN PARAMETRO POR REFERENCIA
		heroatack(enemyLive);
	}
	else if (election == 2)
	{
		//ESTO ES UN PARAMETRO POR REFERENCIA
		heroatack(enemyLive2);
	}
	else if (limite == 0) {
		heroDamage = 0;
		cout << "no te quedan mas ataques especiales\n";
	}
	else {
		cout << "Has fallado el ataque\n";
		heroDamage = 0;
	}
	
	cout << "\nLa vida del enemigo 1 es:" << enemyLive << " \nLa vida del enemigo 2 es: " << enemyLive2;
}




int main() {

	gameStart();


	while ((enemyIsAlive || enemyIsAlive2) && heroIsAlive) {

		electionEnemy();

		electionattack();

		checkHeroStatus();

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
