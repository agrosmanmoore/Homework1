#include <iostream>
#include <chrono>

// Función recursiva NO constexpr (para medición en tiempo de ejecución)
bool compareStringsRuntime(const char* a, const char* b) {
    // Compara caracter por caracter en tiempo de ejecución. Si son iguales, sigue con el siguiente.
    // Si encuentra '\0' (fin de la cadena), termina la comparación.
    return (*a == *b) && (*a == '\0' || compareStringsRuntime(a + 1, b + 1));
}

// Función recursiva constexpr (para tiempo de compilación)
constexpr bool compareStringsCompileTime(const char* a, const char* b) {
    // Lo mismo que la función anterior, pero con constexpr, así que esto se evalúa en tiempo de compilación
    return (*a == *b) && (*a == '\0' || compareStringsCompileTime(a + 1, b + 1));
}

// Cadenas a comparar 
constexpr const char* texto1 = "Esta es una cadena de prueba con mas de sesenta y cuatro caracteres.";
constexpr const char* texto2 = "Esta es una cadena de prueba con mas de sesenta y cuatro caracteres.";
constexpr const char* texto3 = "Esta es una cadena distinta para probar la desigualdad entre cadenas.";

int main() {
    
    // Medición del tiempo de ejecución para compareStringsRuntime
    auto startTime = std::chrono::high_resolution_clock::now();
    bool iguales = compareStringsRuntime(texto1, texto2); 
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "[Ejecutado en tiempo de ejecución]\n";
    std::cout << "Resultado de comparación: " << (iguales ? "Iguales" : "Diferentes") << '\n';
    std::cout << "Tiempo de ejecución (función): " << elapsedTime.count() << " nanosegundos\n\n";

    // Medición del tiempo de ejecución para compareStringsCompileTime
    auto startTime2 = std::chrono::high_resolution_clock::now();
    constexpr bool resultado_constexpr = compareStringsCompileTime(texto1, texto2);
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto elapsedTime2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2);
    
    std::cout << "[Evaluado en tiempo de compilación]\n";
    std::cout << "Resultado de comparación: " << (resultado_constexpr ? "Iguales" : "Diferentes") << '\n';
    std::cout << "Tiempo de ejecución (evaluación en main): " << elapsedTime2.count() << " nanosegundos\n";

    return 0;
}

//Conclusion: Usando constexpr la comparasion es casi instantanea y mucho mas eficiente