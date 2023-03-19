#ifndef MATRIZ_HPP_
#define MATRIZ_HPP_
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Matriz{

    public: 

        Matriz();
        
        void tamanho(int *tamanho);
        void transformar(int **matriz, string **matriz_string, int tamanho, int soma, int *total, int contador);
        void caminhar(int **matriz, int tamanho, int soma, int *total, int contador);
        void resultado(int *total);
        void imprimir(int **matriz, int tamanho);

};

#endif