#pragma once
#include <iostream>
#include <vector>
#include "Carro.h"
#include "Bus.h"
#include "Bicicleta.h"
#include "Persona.h"

using namespace std;
using namespace System;

class Juego {

private:
	Persona* persona = new Persona();
	vector<Carro*> carro;
	vector<Bus*> bus;
	vector<Bicicleta*> bicicleta;

public:
	Juego() {

		carro.push_back(new Carro(3, 8, 1, 1, 3, 9));
		bus.push_back(new Bus(60, 18, -1, 1, 4, 13));
		bicicleta.push_back(new Bicicleta(3, 30,1, -1, 4, 13));
	}

	~Juego() {};

	void dibujarBordes() {
		system("cls");
		Console::SetCursorPosition(1, 1);
		for (int i = 1; i <= 47; i++) { //alto-2
			Console::SetCursorPosition(1, i);
			for (int j = 1; j <= 82; j++) {//ancho -2
				if (i == 1 || i == 47) {//alto -2
					cout << (char)219;
				}
				else if (j == 1 || j == 82) { //ancho -2
					cout << (char)219;
				}
				else {
					cout << " ";
				}
			}
		}
	}
	

	//colisiones
	void colision() {

		//colision con carro
		for (int i = 0; i < carro.size(); i++) {
			if (persona->obtenerRectangulo().IntersectsWith(carro[i]->obtenerRectangulo())) {
				persona->borrar();
				persona->SetX(24);
				persona->SetY(42);
				persona->SetDX(1);
				persona->dibujar(persona->GetX(), persona->GetY());
				persona->disminuirVida();
			}
		}

		//colision bus
		for (int i = 0; i < bus.size(); i++) {
			if (persona->obtenerRectangulo().IntersectsWith(bus[i]->obtenerRectangulo())) {
				persona->borrar();					
				persona->SetX(24);
				persona->SetY(42);
				persona->SetDX(1);
				persona->dibujar(persona->GetX(), persona->GetY());
				persona->disminuirVida();
			}
		}

				//colision bici [la bici no mata]
		for (int i = 0; i < bicicleta.size(); i++) {
			if (persona->obtenerRectangulo().IntersectsWith(bicicleta[i]->obtenerRectangulo())) {
				persona->borrar();
				persona->SetX(24);
				persona->SetY(42);
				persona->SetDX(1);
				persona->dibujar(persona->GetX(), persona->GetY());
			}
		}
	}

	void moriste() {
		system("cls");
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(25, 10); cout << " Te atropellaron!!";
		system("pause>0");
		exit(0);
	}


	void jugar() {

		//le damos vidas a la persona
		

		char tecla;
		dibujarBordes();

		persona->dibujar(persona->GetX(), persona->GetY());

		while (persona->GetVida()>0) //mientras que persona tenga mas de 0 vidas ocurre lo siguente
		{
			if (kbhit()) {
				tecla = _getch();
				persona->moverPersona(tecla);
			}

			colision();

			for (int i = 0; i < carro.size(); i++) {
				carro[i]->mover();	
			}

			for (int i = 0; i < bus.size(); i++) {
				bus[i]->mover();
			}

			for (int i = 0; i < bicicleta.size(); i++) {
				bicicleta[i]->mover();
			}
			Console::SetCursorPosition(3, 2); cout << "vidas: " << persona->GetVida();
			

			_sleep(10);
		}
		
		moriste();
		
	}

};