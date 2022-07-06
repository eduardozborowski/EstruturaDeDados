/*
A partir de um arquivo txt, com números inteiros, um abaixo do outro, faça um programa em C++ que abra este arquivo e o popule em uma árvore binária 
de pesquisa. Entretanto, o código NÃO deve perrmitir números repetidos. Sugere-se que a árvore esteja balanceada e que se use um arquivo .h 
para os métodos de árvore.
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct no {
  int valor;
  no *esq;
  no *dir;
  int fb;
};
void inserirArvoreBin(no *&raiz, int valor) {
  if(raiz == NULL) {
    raiz = new no;
    raiz->valor = valor;
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->fb = 0;
  } else if(valor < raiz->valor) {
    inserirArvoreBin(raiz->esq, valor);
  } else if(valor > raiz->valor) {
    inserirArvoreBin(raiz->dir, valor);
  } else {
    cout << "Não é permitido números repetidos" << endl;
  }
}

void printarArvore(no *raiz) {
  if(raiz != NULL) {
    printarArvore(raiz->esq);
    cout << raiz->valor << endl;
    printarArvore(raiz->dir);
  }
}
void fecharArquivo(no *raiz) {
  if(raiz != NULL) {
    fecharArquivo(raiz->esq);
    fecharArquivo(raiz->dir);
    delete raiz;
  }
}
void abrirArquivo(no *&raiz) {
  ifstream arquivo;
  arquivo.open("arquivo.txt");
  int valor;
  while(arquivo >> valor) {
    inserirArvoreBin(raiz, valor);
  }
  arquivo.close();
}
void deleteFolhas(no *raiz, int valor) {
  if(raiz != NULL) {
    deleteFolhas(raiz->esq, valor);
    deleteFolhas(raiz->dir, valor);
    if(raiz->esq == NULL && raiz->dir == NULL && raiz->valor % valor == 0) {
      delete raiz;
    }
  }
}
no *procurar(no *raiz, int valor) {
  if(raiz != NULL) {
    if(raiz->valor == valor) {
      return raiz;
    } else if(valor < raiz->valor) {
      return procurar(raiz->esq, valor);
    } else {
      return procurar(raiz->dir, valor);
    }
  }
  return NULL;
}
