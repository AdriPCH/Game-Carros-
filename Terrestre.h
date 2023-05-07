#pragma once
#include <iostream>
#include <conio.h>
#using <System.Drawing.dll>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Terrestre {

protected:
	//atributos
	int x, y, dx, dy, alto, ancho;

public:
	Terrestre(int px, int py, int pdx, int pdy, int palto, int pancho) {
		x = px;
		y = py;
		dx = pdx;
		dy = pdy;
		alto = palto;
		ancho = pancho;
	}

	~Terrestre() {};

	//getters
	int GetX() {
		return x;
	}

	int GetY() {
		return y;
	}

	int GetDX() {
		return dx;
	}

	int GetDY() {
		return dy;
	}


	//setter
	void SetX(int valor) {
		x = valor;
	}

	void SetY(int valor) {
		y = valor;
	}

	void SetDX(int valor) {
		dx = valor;
	}

	void SetDY(int valor) {
		dy = valor;
	}

	//metodos virtual para poder ser sustituidos
	virtual void borrar() {}
	virtual void dibujar() {}

	Rectangle obtenerRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}

};

