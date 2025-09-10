#ifndef FLTK_BUTTON_APP_H
#define FLTK_BUTTON_APP_H

// Incluimos las cabeceras de los widgets de FLTK que vamos a utilizar.
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

/**
 * @class FltkButtonApp
 * @brief Encapsula toda la lógica y los widgets para una aplicación simple de FLTK.
 *
 * Esta clase crea y gestiona una ventana con un botón y una caja de texto.
 * Sigue un enfoque orientado a objetos para mantener el código organizado
 * y separar la lógica de la aplicación de la función principal `main`.
 */
class FltkButtonApp 
{
    public:
        /**
        * @brief Constructor de la clase FltkButtonApp.
        *
        * Inicializa la ventana y todos los widgets que contiene (botón, caja de texto),
        * establece sus propiedades y conecta las señales (callbacks).
        */
        FltkButtonApp();

        /**
        * @brief Muestra la ventana principal de la aplicación.
        */
        void show();

    private:
        /**
        * @brief Callback estático para el evento de clic del botón.
        *
        * FLTK requiere que las funciones de callback sean estáticas o globales.
        * Este método actúa como un puente para llamar a un método de la instancia.
        * @param widget El widget que originó el evento (el botón).
        * @param data Un puntero a la instancia de nuestra clase FltkButtonApp.
        */
        static void button_callback_static(Fl_Widget* widget, void* data);

        /**
        * @brief Método de instancia que maneja la lógica del clic del botón.
        *
        * Este método es llamado por el callback estático y contiene la lógica
        * real que se ejecuta cuando el usuario presiona el botón.
        */
        void button_callback();

        Fl_Window* mainWindow;   ///< Puntero a la ventana principal de la aplicación.
        Fl_Button* actionButton; ///< Puntero al botón que el usuario presionará.
        Fl_Box* outputBox;    ///< Puntero a la caja que mostrará el texto "Hola".
};

#endif // FLTK_BUTTON_APP_H
