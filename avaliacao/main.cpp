#include <iostream>
#include <cstdlib>
#include "metodos.h"

using namespace std;


int main() {
  no *raiz = NULL;
  abrirArquivo(raiz);
  int valor;
  cout << "Digite um valor: ";
  cin >> valor;
  inserirArvoreBin(raiz, valor);
  printarArvore(raiz);
  deleteFolhas(raiz, valor);
  printarArvore(raiz);
  cout << "Digite um valor: ";
  cin >> valor;
  if(procurar(raiz, valor)) {
    cout << "O valor " << valor << " foi encontrado" << endl;
  } else {
    cout << "O valor " << valor << " não foi encontrado" << endl;
  }
  fecharArquivo(raiz);
  return 0;
}
