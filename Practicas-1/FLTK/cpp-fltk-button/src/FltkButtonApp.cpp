#include "FltkButtonApp.h"

/**
 * El constructor crea la ventana y los widgets, los posiciona y les asigna
 * el callback correspondiente.
 */
FltkButtonApp::FltkButtonApp() 
{
    // Crear la ventana principal con un tamaño de 300x200 y un título.
    mainWindow = new Fl_Window(300, 200, "Object Oriented FLTK App");
    mainWindow->color(fl_rgb_color(240, 240, 240)); // Un color de fondo suave.

    // Crear el botón. Se posiciona en (100, 80) con un tamaño de 100x40.
    actionButton = new Fl_Button(100, 80, 100, 40, "Presioname");
    actionButton->box(FL_ROUNDED_BOX);
    actionButton->color(fl_rgb_color(59, 130, 246));
    actionButton->labelcolor(FL_WHITE);
    actionButton->labelfont(FL_HELVETICA_BOLD);

    // Crear la caja de texto que mostrará el resultado.
    // Inicialmente está vacía.
    outputBox = new Fl_Box(50, 20, 200, 40, "");
    outputBox->labelsize(24);
    outputBox->labelfont(FL_HELVETICA_BOLD);
    outputBox->labelcolor(fl_rgb_color(30, 30, 30));

    // Asignar el callback al botón.
    // Le pasamos la función estática y un puntero 'this' a la instancia actual
    // para que el callback sepa a qué objeto pertenece.
    actionButton->callback(button_callback_static, this);

    // Indicar a FLTK que todos los widgets añadidos a partir de ahora
    // no estarán dentro de esta ventana.
    mainWindow->end();
}

/**
 * El método show() simplemente invoca el método show() de la ventana principal.
 */
void FltkButtonApp::show() 
{
    mainWindow->show();
}

/**
 * Este es el manejador de eventos real. Es un método de la clase y tiene
 * acceso a todos los miembros (como outputBox).
 */
void FltkButtonApp::button_callback() 
{
    outputBox->label("Hola");
    // Opcional: Redibujar la caja para asegurar que el cambio es visible inmediatamente.
    outputBox->redraw();
}

/**
 * El callback estático convierte el puntero 'data' de nuevo a un puntero
 * de tipo FltkButtonApp y luego llama al método de la instancia.
 */
void FltkButtonApp::button_callback_static(Fl_Widget* widget, void* data)
{
    FltkButtonApp* app = static_cast<FltkButtonApp*>(data);
    app->button_callback();
}
