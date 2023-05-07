#pragma once
#include <iostream>
#include "Terrestre.h"

using namespace std;
using namespace System;

class Bicicleta : public Terrestre {
public:
	Bicicleta(int x, int y, int dx, int dy, int alto, int ancho) : Terrestre(x, y, dx, dy, alto, ancho) {

		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->alto = alto;
		this->ancho = ancho;
	}

	~Bicicleta() {};

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "      ";
		Console::SetCursorPosition(x, y + 1); cout << "      ";
	}

	void dibujar(int x, int y) {
		//bici es un 2x6
		// 
		//cuando vaya a la derecha
		if (dx == 1) {
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(x, y);     cout << " .._\\";
			Console::SetCursorPosition(x, y + 1); cout << "(o)(o)";
		}

		//cuando vaya a la izquierda
		else if (dx == -1) {
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(x, y);     cout << " /_..";
			Console::SetCursorPosition(x, y + 1); cout << "(o)(o)";
		}
	}

	void mover() {
		borrar();

		if (x > 75 || x < 3) { // 82-6=76
			dx *= -1;
		}
		x += dx;
		
		dibujar(x, y);
		
	}

};