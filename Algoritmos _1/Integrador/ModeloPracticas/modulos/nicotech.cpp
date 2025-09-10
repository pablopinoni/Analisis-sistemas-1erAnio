
#include <iostream>
#include <fstream>
#include <sstream>


/**
 * Auxiliar global functions
**/
void pauseConsole()
{
    std::cout << "Presione una tecla para continuar..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void clearConsole()
{
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN32) || defined(WIN64)
        system("cls");
    #endif // defined
}

//Estructura de C++ es una representación en memoria de lo que es un cliente
//Un tipo...
struct Customer 
{
    int code;
    std::string name;
    std::string surname;
    std::string address;
};

//Constante "Global": máximo de clientes permitidos
const int MAX_CUSTOMERS = 100;

// Función para mostrar el menú
void showMenu() 
{
    std::cout << "----- MENÚ -----" << std::endl;
    std::cout << "1. Dar de alta un cliente" << std::endl;
    std::cout << "2. Dar de baja un cliente" << std::endl;
    std::cout << "3. Modificar un cliente" << std::endl;
    std::cout << "4. Listar todos los clientes" << std::endl;
    std::cout << "5. Buscar un cliente por código" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Ingrese una opción: ";
}

/**
 * @brief Función para dar de alta un cliente
 * 
 * @param customers: arreglo que representa 
 *  todos los clientes del archivo en memoria.
 * @param numCustomers: número de clientes para verificar
 *  que no supere el máximo establecido en la constante global MAX_CUSTOMERS. 
 *  este parámetro se paso por referencia para que sea modificada siempre la misma
 *  variable.
 */
void create(Customer customers[], int& numCustomers) 
{  
    clearConsole();
    //verificar que no supere el máximo establecido en la constante global MAX_CUSTOMERS. 
    if (numCustomers >= MAX_CUSTOMERS) 
    {
        std::cout << "No se pueden agregar más clientes." << std::endl;
        return;
    }

    //creo una variable newCustomer del tipo "struct Customer"
    //esto es la representación en memoria de un cliente.
    Customer newCustomer;
    
    //en el código voy cargando un número incremental desde el 100, 
    //siempre tomando como punto de partida la cantidad de clientes
    //que están en el archivo.
    
    /**
     * @brief si el archivo fue abierto es porque existe entonces se crea 
     * el siguiente código autoincremental de lo contrario si no existe
     * se crea a partir de la posición del array con esto se evita el error
     * de códigos repetidos.
    */
    std::ifstream file("customers.csv");
    if (file.is_open()) 
    {
        newCustomer.code = customers[numCustomers-1].code + 1;
    }
    else
    {
       newCustomer.code = (numCustomers + 1) + 99; 
    }
    

    //espero por entrada de teclado el nombre del cliente y lo guardo
    //en la estructura newCustomer en el atributo (o variable) name
    std::cout << "Ingrese el nombre del cliente: ";
    std::cin >> newCustomer.name;

    //etc...
    std::cout << "Ingrese el apellido del cliente: ";
    std::cin >> newCustomer.surname;

    //en este caso usamos ignore() (una única vez) y getline para
    //poder persistir un string con espacios
    std::cout << "Ingrese la dirección del cliente: ";
    std::cin.ignore();
    std::getline(std::cin, newCustomer.address);

    //agrego al arreglo general de clientes el nuevo cliente
    //todo esto está en memoria, todavía falta guardar en el archivo
    //con la función save()
    customers[numCustomers] = newCustomer;
    numCustomers++;

    std::cout << "Cliente agregado correctamente." << std::endl;
    //pauseConsole();
}

// Función para dar de baja un cliente
void remove(Customer customers[], int& numCustomers) 
{
    clearConsole();
    int code;
    std::cout << "Ingrese el código del cliente a dar de baja: ";
    std::cin >> code;

    int position = -1;
    for (int i = 0; i < numCustomers; i++) 
    {
        if (customers[i].code == code) 
        {
            position = i;
            break;
        }
    }

    if (position != -1) 
    {
        for (int i = position; i < numCustomers - 1; i++) 
        {
            customers[i] = customers[i + 1];
        }
        numCustomers--;
        std::cout << "Cliente eliminado correctamente." << std::endl;
    } 
    else 
    {
        std::cout << "Cliente no encontrado." << std::endl;
    }
    pauseConsole();
}

// Función para modificar un cliente
void update(Customer customers[], int numCustomers) 
{
    clearConsole();
    int code;
    std::cout << "Ingrese el código del cliente a modificar: ";
    std::cin >> code;

    int position = -1;
    for (int i = 0; i < numCustomers; i++) 
    {
        if (customers[i].code == code) 
        {
            position = i;
            break;
        }
    }

    if (position != -1) 
    {
        std::cout << "Cliente encontrado:" << std::endl;
        std::cout << "Código: " << customers[position].code << std::endl;
        std::cout << "Nombre: " << customers[position].name << std::endl;
        std::cout << "Apellido: " << customers[position].surname << std::endl;
        std::cout << "Dirección: " << customers[position].address << std::endl;

        std::cout << "Ingrese el nuevo nombre del cliente: ";
        std::cin >> customers[position].name;

        std::cout << "Ingrese el nuevo apellido del cliente: ";
        std::cin >> customers[position].surname;

        std::cout << "Ingrese la nueva dirección del cliente: ";
        std::cin.ignore();
        std::getline(std::cin, customers[position].address);

        std::cout << "Cliente modificado correctamente." << std::endl;
    } 
    else 
    {
        std::cout << "Cliente no encontrado." << std::endl;
    }
    pauseConsole();
}

// Función para listar todos los clientes
void read(Customer customers[], int numCustomers) 
{
    clearConsole();
    
    if (numCustomers == 0) 
    {
        std::cout << "No hay clientes cargados." << std::endl;
        return;
    }

    for (int i = 0; i < numCustomers; i++) 
    {
        std::cout << "Código: " << customers[i].code << std::endl;
        std::cout << "Nombre: " << customers[i].name << std::endl;
        std::cout << "Apellido: " << customers[i].surname << std::endl;
        std::cout << "Dirección: " << customers[i].address << std::endl;
        std::cout << "-------------------" << std::endl;
    }
    pauseConsole();
}

// Función para buscar un cliente por código
void find(Customer customers[], int numCustomers) 
{
    clearConsole();
    int code;
    std::cout << "Ingrese el código del cliente a buscar: ";
    std::cin >> code;

    int position = -1;
    for (int i = 0; i < numCustomers; i++) 
    {
        if (customers[i].code == code) 
        {
            position = i;
            break;
        }
    }

    if (position != -1) 
    {
        std::cout << "Cliente encontrado:" << std::endl;
        std::cout << "Código: " << customers[position].code << std::endl;
        std::cout << "Nombre: " << customers[position].name << std::endl;
        std::cout << "Apellido: " << customers[position].surname << std::endl;
        std::cout << "Dirección: " << customers[position].address << std::endl;
    }
    else 
    {
        std::cout << "Cliente no encontrado." << std::endl;
    }
    pauseConsole();
}

// Función para guardar los clientes en un archivo CSV
void save(Customer customers[], int numCustomers) 
{
    clearConsole();
    std::ofstream file("customers.csv");
    if (file.is_open()) 
    {
        for (int i = 0; i < numCustomers; i++) 
        {
            file << customers[i].code << "," << customers[i].name << ","
                    << customers[i].surname << "," << customers[i].address << std::endl;
        }
        file.close();
        std::cout << "Clientes guardados en el archivo customers.csv." << std::endl;
    } 
    else 
    {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    pauseConsole();
}

// Función para cargar los clientes desde un archivo CSV
int loadCustomersFromFile(Customer customers[]) 
{
    /**
     * @brief abrir el archivo csv para lectura.
     */
    std::ifstream file("customers.csv");
    /**
     * @brief si el archivo fue abierto correctamente ejecuta la función.
     */
    if (file.is_open()) 
    {
        /**
         * @brief declaro una variable string linea, 
         * que representa una fila del archivo
         */
        std::string linea;

        //defino en 0 el contador de numero de clientes.
        int numCustomers = 0;

        /**
         * @brief inicio el ciclo while por cada 
         * línea que tenga el archivo, uso la función
         * getline para poder obtenerlas.
         */
        while (std::getline(file, linea)) 
        {
            //defino el flujo de cadena, para poder procesarlo después.
            std::istringstream iss(linea);
            //declaro una variable field que va a determinar cada campo
            //el campo es la intersección de la columna y la fila
            //es el dato.
            std::string field;

            /**
             * @brief con la función getline voy a obtener cada campo
             * usando como separador la coma para dividir ese dato.
             * entonces obtendré tantos campos como texto separado
             * entre comas halla en el archivo. Cada vez que ejecuto
             * la función getline, va a obtener un nuevo campo, osea: code,
             * name, surname hasta llegar a address.
             */
             
            /*obtengo el campo "code" y lo guardo en la 
            posisción correcta del arreglo. 
            También lo "casteo" (convierto)
            de string a entero:*/
            std::getline(iss, field, ',');
            customers[numCustomers].code = std::stoi(field);

            /*obtengo el campo "name":*/
            std::getline(iss, field, ',');
            customers[numCustomers].name = field;
            
            /*obtengo el campo "surname":*/
            std::getline(iss, field, ',');
            customers[numCustomers].surname = field;
            
            /*obtengo el campo "address":*/
            std::getline(iss, field, ',');
            customers[numCustomers].address = field;

            //incremento la cantidad de clientes.
            numCustomers++;
        }
        file.close();
        return numCustomers;
    } 
    else 
    {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 0;
    }
}

int main() 
{
    /**
     * @brief Declaro el arreglo (array) de  Clientes 
     * (tipo "estructura" Customer) con el tamaño definido
     * en la constante global => 100
     */
    Customer customers[MAX_CUSTOMERS];

    /**
     * @brief Declaro y defino una variable del numero de clientes
     * que ya están en el archivo, por eso usao la función
     * loadCustomersFromFile a la cual le paso como parámetro
     * el arreglo de customers para que trabaje con él. 
     * (lo pasa por referencia, aunque sintácticamente parezca por valor)
     */
    int numCustomers = loadCustomersFromFile(customers);
    std::cout << numCustomers << std::endl;
    
    /**
     * @brief definir variable option para poder usar en la carga
     * de opciones seleccionadas por el usuario del programa.
     */
    int option;
    do 
    {
        /**
         * @brief función para mostrar el menú en pantalla
         */
        showMenu();

        /**
         * @brief leer por entrada estándar lo que se ingresa
         * por teclado y guardarlo en la variable option.
         */
        std::cin >> option;

        /**
         * @brief Construct a new switch object with option variable.
         */
        switch (option) 
        {
            case 1:
                create(customers, numCustomers);
                clearConsole();
                break;
            case 2:
                remove(customers, numCustomers);
                break;
            case 3:
                update(customers, numCustomers);
                break;
            case 4:
                read(customers, numCustomers);
                break;
            case 5:
                find(customers, numCustomers);
                break;
            case 6:
                save(customers, numCustomers);
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (option != 6);

    return 0;
}

