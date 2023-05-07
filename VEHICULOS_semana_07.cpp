#include "pch.h"
#include <iostream>
#include <conio.h>
#include "Juego.h"

#define ANCHOVENTANA 84
#define ALTOVENTANA 49

using namespace std;
using namespace System;

int main()
{
    Console::SetWindowSize(ANCHOVENTANA, ALTOVENTANA);
    Console::CursorVisible = false;

    Juego* juego = new Juego();
    while (true) {
        juego->jugar();
        system("pause>0");
    }

    return 0;
}
