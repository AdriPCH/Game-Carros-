#pragma once
#include <iostream>
#include "Terrestre.h"

using namespace std;
using namespace System;

class Bus : public Terrestre {

public:
	Bus(int x, int y, int dx, int dy, int alto, int ancho) : Terrestre(x, y, dx, dy, alto, ancho) {

		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->alto = alto;
		this->ancho = ancho;
	}
	~Bus() {};


	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "             ";
		Console::SetCursorPosition(x, y + 1); cout << "              ";
		Console::SetCursorPosition(x, y + 2); cout << "              ";
		Console::SetCursorPosition(x, y + 3); cout << "             ";
	}

	void dibujar(int x, int y) {
		//bus es un 4[alto]x13[largo]
		
		//cuando vaya a la derecha
		if (dx == 1) {
			Console::ForegroundColor = ConsoleColor::Red;
			Console::SetCursorPosition(x, y);     cout << " __________";
			Console::SetCursorPosition(x, y + 1); cout << "|[][][][]|_\\_";
			Console::SetCursorPosition(x, y + 2); cout << "|   |     )  |";
			Console::SetCursorPosition(x, y + 3); cout << " =-OO -- OO-=";
		}

		//cuando vaya a la izquierda
		else if (dx == -1) {
			Console::ForegroundColor = ConsoleColor::Red;
			Console::SetCursorPosition(x, y);     cout << "   __________";
			Console::SetCursorPosition(x, y + 1); cout << " _/_|[][][][]|";
			Console::SetCursorPosition(x, y + 2); cout << "|  (     |   |";
			Console::SetCursorPosition(x, y + 3); cout << " =-OO -- OO-=";
		}
	}

	void mover() {
		borrar();
		if (x > 67|| x < 3) { // 82-13=67
			dx *= -1;
		}
		x += dx;

		dibujar(x, y);
		_sleep(20);
	}

};