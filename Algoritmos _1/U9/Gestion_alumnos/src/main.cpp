#include "../include/menu.h"
#include "../include/alumno_datos.h"
#include "../include/consola_utils.h"

int main() {
    clearConsole();
    tGestionAlumnos gestion;
    gestion.gestion.contador = 0;
    loadFromFile(gestion);
    blinkTitle(4, 500);
    pauseConsole();
    showMainMenu(gestion);
    return 0;
}