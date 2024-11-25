#include <iostream>

using namespace std;

const int LINHAS = 3;
const int COLUNAS = 5;

void somaTrizes(int m1[LINHAS][COLUNAS], int m2[LINHAS][COLUNAS],
                int resul[LINHAS][COLUNAS]) {
  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      resul[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

int main() {
  int A[LINHAS][COLUNAS];
  int B[LINHAS][COLUNAS];
  int C[LINHAS][COLUNAS];

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      cin >> B[i][j];
    }
  }

  somaTrizes(A, B, C);

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      cout << C[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
