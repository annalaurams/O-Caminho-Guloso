#include "matriz.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int main(){

  int **matriz;
  string **matriz_string;
  int tamanho = 0;
  int soma = 0, total = 0;

  Matriz matrix;

  matrix.tamanho(&tamanho);

  // Alocação dinâmica das matrizes

  matriz = new int *[tamanho];

  for (int i = 0; i < tamanho; i++){
    matriz[i] = new int[tamanho];
  }

  matriz_string = new string *[tamanho];

  for (int i = 0; i < tamanho; i++){
    matriz_string[i] = new string[tamanho];
  }

  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      matriz[i][j] = 1;
    }
  }

  matrix.transformar(matriz, matriz_string, tamanho, soma, &total);
  matrix.resultado(&total);

  return 0;
}