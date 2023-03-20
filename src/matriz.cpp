#include "matriz.hpp"

Matriz :: Matriz(){
}

// Função que realiza a leitura da primeira linha do arquivo a qual contém o tamanho das matrizes

void Matriz ::  tamanho(int *tamanho){

  string posicao;

  ifstream arquivo;

  arquivo.open("dataset/input.data", ios::in);

  if (!arquivo){
    cout << "Erro ao abrir o arquivo." << endl;
  }

  else{
    getline(arquivo, posicao, ' ');
    *tamanho = atoi(posicao.c_str());
  }


}

// Função que percorre a matriz, caminhando pelo maior número

void Matriz :: caminhar(int **matriz, int tamanho, int soma, int *total, int contador){

  int linha = 0;
  int coluna = 0;

  soma += matriz[linha][coluna];

  cout << "\nNúmeros do caminho dessa matriz: " << matriz[linha][coluna] << " ";

  while ((linha != tamanho - 1) || (coluna != tamanho - 1)){

    int maior = 0;
    int lm = 0;
    int cm = 0;

    // Para Direita

    if ((coluna + 1 < tamanho) && (coluna != coluna + 1)){
      if((matriz[linha][coluna + 1] >= maior) && (matriz[linha][coluna + 1] != -1)){
        maior = matriz[linha][coluna + 1];
        lm = linha;
        cm = coluna + 1;
      }
    }

    // Para Diagonal Direita
    
    if ((coluna + 1 < tamanho) && (linha + 1 < tamanho)){
      if ((matriz[linha + 1][coluna + 1] >= maior) && (matriz[linha+ 1][coluna + 1] != -1)){
        maior = matriz[linha + 1][coluna + 1];
        lm = linha + 1;
        cm = coluna + 1;
      }
    }

    // Para Diagonal Esquerda

    if ((coluna - 1 >= 0) && (linha + 1 < tamanho)){
      if((matriz[linha + 1][coluna - 1] >= maior) && (matriz[linha + 1][coluna - 1] != -1)){
        maior = matriz[linha + 1][coluna - 1];
        lm = linha + 1;
        cm = coluna - 1;
      }
    }

    // Para Esquerda

    if ((linha != tamanho - 1) && (coluna - 1 >= 0)){
      if((matriz[linha][coluna - 1] >= maior) && (matriz[linha][coluna - 1] != -1)){
        maior = matriz[linha][coluna - 1];
        lm = linha;
        cm = coluna - 1;
      }
    }

    // Para baixo

    if ((linha + 1 < tamanho)){
      if((matriz[linha + 1][coluna] >= maior) && (matriz[linha + 1][coluna] != -1)){
        maior = matriz[linha + 1][coluna];
        lm = linha + 1;
        cm = coluna;
      }
    }

    matriz[linha][coluna] = -1;

    linha = lm;
    coluna = cm;

    soma += matriz[linha][coluna];

    cout << matriz[linha][coluna] << " ";
   
  }
  cout << endl;

  cout << "Soma matriz individual: " << soma << endl << endl;

  matriz[linha][coluna] = -1;
  
  *total+=soma; 
}

// Função que converte a matriz lida no formato string para uma matriz de números inteiros, para permitir a soma do percurso

void Matriz :: transformar(int **matriz, string **matriz_string, int tamanho, int soma, int *total, int contador){

  int aux1 = 0, aux2 = 0, controle = 0, auxiliar_cont = 1;
  string posicao, elemento;

  ifstream arquivo;

  arquivo.open("dataset/input.data", ios::in);

  if (!arquivo){
    cout << "Erro ao abrir o arquivo." << endl;
  }

  else{
    getline(arquivo, posicao, '\n');

    while (getline(arquivo, posicao, '\n')){

      if (posicao.empty()){
        for (int i = 0; i < tamanho; i++){
          for (int j = 0; j < tamanho; j++){
            matriz[i][j] = atoi(matriz_string[i][j].c_str());
          }
        }

        cout << "\t" << auxiliar_cont << "° MATRIZ" << endl << endl;

        imprimir(matriz, tamanho);
        caminhar(matriz, tamanho, soma, total, contador);
        imprimir(matriz, tamanho);

        cout << "-----------------------------------------------\n";

        aux2 = 0;
        aux1 = 0;

        contador++;
        auxiliar_cont++;
      
      }
      else{
        stringstream aux(posicao);

        while (getline(aux, elemento, ' ')){
          matriz_string[aux1][aux2] = elemento;
          aux2++;
        }

        aux1++;
        aux2 = 0;
      }
    }

    for (int i = 0; i < tamanho; i++){
      for (int j = 0; j < tamanho; j++){
        matriz[i][j] = atoi(matriz_string[i][j].c_str());
      }
    }

    cout << "\t" << auxiliar_cont <<"° MATRIZ" << endl << endl;

    imprimir(matriz, tamanho);
    caminhar(matriz, tamanho, soma, total, contador);
    imprimir(matriz, tamanho);
    cout << endl;

    cout << "-----------------------------------------------\n";

    contador++;
    auxiliar_cont++;
  
    aux2 = 0;
    aux1 = 0;

    arquivo.close();
  }
}


// Função que mostra a soma total do caminho de todas as matrizes juntas ao final da execução do código

void Matriz :: resultado(int *total){

  cout << "\nSoma do caminho total percorrido: " << *total << endl << endl;

}

// Função para imprimir a matriz 

void Matriz :: imprimir(int **matriz, int tamanho){

  int i, j;

    for (i = 0; i < tamanho; i++){
      for (j = 0; j < tamanho; j++){
        cout << matriz[i][j] << " ";
      }
      cout << endl;
    }
}
