#pragma once

#include "../include/alumno_datos.h"
#include "../include/consola_utils.h"
#include <string>
#include <thread>
#include <chrono>

// Prototipos de funciones
void showTitle(bool encendido);
void blinkTitle(int veces, int milisegundos);
void showMainMenu(tGestionAlumnos& gestion);
int showOptionsMenu();
int showSubMenuManagement();
int showSubMenuListing();
int showSubMenuSorting();