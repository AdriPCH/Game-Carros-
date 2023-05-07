#pragma once
#include <iostream>
#include "Terrestre.h"

//flechas
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

using namespace std;
using namespace System;

class Persona : public Terrestre {

private:
	int vida = 1;

public:
	Persona():Terrestre(23,42,-1,1,3,3) {

	}
	~Persona(){}

	//getters
	int GetVida() {
		return vida;
	}




	//metodos
	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "   ";
		Console::SetCursorPosition(x, y + 1); cout << "   ";
		Console::SetCursorPosition(x, y + 2); cout << "   ";
	}

	void dibujar(int x, int y) {
		if (dx == 1) {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y);     cout << " 0 ";
		Console::SetCursorPosition(x, y + 1); cout << "/|\\";
		Console::SetCursorPosition(x, y + 2); cout << ") )";
		}

		if (dx == -1) {
			Console::ForegroundColor = ConsoleColor::Green;
			Console::SetCursorPosition(x, y);     cout << " 0 ";
			Console::SetCursorPosition(x, y + 1); cout << "/|\\";
			Console::SetCursorPosition(x, y + 2); cout << "( (";
		}

	}

	void moverPersona(char tecla) {
		borrar();

		switch (tecla)
		{
		case ARRIBA:
			if (y > 2) {
				y--;
				dy = 1;
			}
			break;

		case ABAJO:
			if (y < 44) {
				y++;
				dy = -1;
			}
			break;

		case DERECHA:
			if (x < 79) {
				x++;
				dx = 1;
			}
			break;

		case IZQUIERDA:
			if (x > 3) {
				x--;
				dx = -1;
			}
			break;
		}
		dibujar(x, y);
	}

	void disminuirVida() {
		vida--;
	}
};