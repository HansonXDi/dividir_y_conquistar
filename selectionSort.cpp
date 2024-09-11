#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;

// función swap
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// función para imprimir un arreglo
void printArreglo(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      // escoge el elemento menor en cada iteración
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    // coloca al elemento menor en la posición correcta
    swap(&array[min_idx], &array[step]);
  }
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
  selectionSort(data, size);
  auto fin = chrono::steady_clock::now();
  cout << "Arreglo ordenado de menor a mayor:\n";
  printArreglo(data, size);
  auto tiempo_final = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
  cout << "\nTiempo de ejecución: " << tiempo_final << " ns" << endl;
  return 0;
}