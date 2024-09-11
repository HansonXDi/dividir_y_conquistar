#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;

// función para imprimir un arreglo
void printArreglo(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

// para contar las lineas (el tamaño del arreglo)
int contarLineas(string nombreArchivo){
  ifstream archivo(nombreArchivo);
  string linea;
  int n = 0;
  while(getline(archivo, linea)){
    if(linea == "") break;
    n++;
  }
  archivo.close();
  return n;
}

// código de prueba
int main() {
  // contar el número de elementos
  int j = contarLineas("datasetSort.txt");
  cout << j << endl;
  // lectura de datos
  ifstream archivo("datasetSort.txt");
  string linea;
  int i = 0;
  // inicializacion del arreglo
  int data[j];
  while(getline(archivo, linea)){
    if(linea == "") break;
    data[i] = {stoi(linea)};
    i++;
  }
  archivo.close();

  // algoritmo en si
  int size = sizeof(data) / sizeof(data[0]);
  auto inicio = chrono::steady_clock::now();
  sort(data, data + size);
  auto fin = chrono::steady_clock::now();
  cout << "Arreglo ordenado de menor a mayor:\n";
  printArreglo(data, size);
  auto tiempo_final = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
  cout << "\nTiempo de ejecución: " << tiempo_final << " ms" << endl;
  return 0;
}