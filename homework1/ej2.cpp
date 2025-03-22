#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>  // Para excepciones

using namespace std;

enum class Severidad {
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    DEBUG,
    SECURITY  // Nueva categoría de seguridad para los accesos
};

// Función para registrar mensajes con severidad
void logMessage(string msg, Severidad severidad) {
    string severidad_word;

    // Asignar la palabra correspondiente a la severidad
    switch (severidad) {
        case Severidad::INFO:
            severidad_word = "INFO";
            break;
        case Severidad::WARNING:
            severidad_word = "WARNING";
            break;
        case Severidad::ERROR:
            severidad_word = "ERROR";
            break;
        case Severidad::CRITICAL:
            severidad_word = "CRITICAL";
            break;
        case Severidad::DEBUG:
            severidad_word = "DEBUG";
            break;
        case Severidad::SECURITY:
            severidad_word = "SECURITY";
            break;
    }

    // Abrir el archivo de log en modo append (agregar)
    ofstream logFile;
    logFile.open("log.txt", ios::app);
    if (logFile.is_open()) {
        // Escribir en el archivo con el formato adecuado
        logFile << "[" << severidad_word << "] " << msg << endl;
        logFile.close();  // Cerrar el archivo después de escribir
    } else {
        cerr << "Error al abrir el archivo de log." << endl;
    }

    // También imprimir en consola
    cout << "[" << severidad_word << "] " << msg << endl;
}

// Función para registrar un mensaje de error con archivo y línea
void logMessage(string Mensage_de_Error, string Archivo, int Linea_de_Código) {
    string msg = Mensage_de_Error + " en: " + Archivo + " en la línea: " + to_string(Linea_de_Código);
    logMessage(msg, Severidad::ERROR);
}

// Función para registrar mensajes de acceso de usuario
void logMessage(string mensajeAcceso, string nombreUsuario) {
    string msg = mensajeAcceso + " | Usuario: " + nombreUsuario;
    logMessage(msg, Severidad::SECURITY);
}

int main() {
    try {
        // Registro de eventos con diferentes severidades
        logMessage("Este es un mensaje de Info", Severidad::INFO);
        logMessage("Este es un mensaje de Advertencia", Severidad::WARNING);
        logMessage("Este es un mensaje de Error", Severidad::ERROR);
        logMessage("Este es un mensaje Crítico", Severidad::CRITICAL);
        logMessage("Este es un mensaje de Depuración", Severidad::DEBUG);
        
        // Registro de eventos de seguridad
        logMessage("Access Granted", "admin_user");
        logMessage("Access Denied", "intruso01");

        // Simulación de un error en tiempo de ejecución
        // throw runtime_error("Se ha producido un error en el sistema"); esta linea se comenta para que no se detenga el programa, pero se puede descomentar para probar el registro de errores

    } catch (const exception& esep) {
        // Registrar el error con detalle del archivo y la línea
        logMessage(esep.what(), __FILE__, __LINE__);

        // Detener el programa con código de error
        return 1;
    }

    return 0;
}
