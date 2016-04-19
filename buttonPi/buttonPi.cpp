// buttonPi.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Program.h"

int main()
{
    Program* program = Program::getInstance();
    program->start();

    delete program;

    return 0;
}

