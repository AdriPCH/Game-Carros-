#pragma once
#include <iostream>
#include "Terrestre.h"

using namespace std;
using namespace System;

class Carro : public Terrestre {

public:
	Carro(int x, int y, int dx, int dy, int alto, int ancho) : Terrestre(x, y, dx, dy, alto, ancho) {

		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->alto = alto;
		this->ancho = ancho;
	}
	~Carro() {};


	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "        ";
		Console::SetCursorPosition(x, y + 1); cout << "         ";
		Console::SetCursorPosition(x, y + 2); cout << "        ";
	}

	void dibujar(int x, int y) {
		//carro es un 3x9
		// 
		//cuando vaya a la derecha
		if (dx == 1) {
			Console::ForegroundColor = ConsoleColor::Blue;
			Console::SetCursorPosition(x, y);     cout << "____|~\\_";
			Console::SetCursorPosition(x, y + 1); cout << "[____|_|-";
			Console::SetCursorPosition(x, y + 2); cout << " ()   ()";
		}

		//cuando vaya a la izquierda
		else if (dx == -1) {
			Console::ForegroundColor = ConsoleColor::Blue;
			Console::SetCursorPosition(x, y);     cout << "_/~|____";
			Console::SetCursorPosition(x, y + 1); cout << "-|_|____]";
			Console::SetCursorPosition(x, y + 2); cout << " ()   ()";
		}
	}

	void mover() {
			borrar();
			if (x > 72 || x < 3) { // 82-9=72
				dx *= -1;
			}
			x += dx;

			dibujar(x, y);
			_sleep(10);
		}

};