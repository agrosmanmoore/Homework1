#include <iostream>
#include <vector>
#include <string>
#include <fstream>  

using namespace std;

// Función que crea una matriz y la muestra de forma tradicional
void make_matrix(int n) {
    vector<vector<int>> matriz(n, vector<int>(n, 0));
    int count = 0 - n;

    // Llena la matriz con valores consecutivos
    for (int i = 0; i < n; i++) {
        count += n;
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (count + j);
        }
    }

    // Muestra la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función que muestra la matriz con las posiciones de cada elemento
void print_matrix(int n) {
    vector<vector<int>> matriz(n, vector<int>(n, 0));
    int count = 0 - n;

    // Llena la matriz con valores consecutivos
    for (int i = 0; i < n; i++) {
        count += n;
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (count + j);
        }
    }

    // Muestra los elementos con su posición
    for (int i = 0; i < n * n; i++) {
        int row = i / n;
        int col = i % n;
        cout << "Matriz" << n << "[" << row << "][" << col << "] = " << matriz[row][col] << endl;
    }
}

int main() {
    make_matrix(3);  // Muestra la matriz de 3x3
    print_matrix(3); // Muestra la matriz con posiciones
    return 0;
}
