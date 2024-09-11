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

// función para encontrar el punto de partición
int partition(int array[], int low, int high) {
  // el pivote es el elemento mas a la derecha
  int pivot = array[high];
  // puntero para el elemento mayor
  int i = (low - 1);
  // compara cada elemento del arreglo
  // con el pivote
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      // si un elemento mas pequeño que el pivote es
      // encontrado, lo intercambia con el elemento mayor
      // (el apuntado por i)
      i++;
      // intercambia el elemento en i con el elemento en j
      swap(&array[i], &array[j]);
    }
  }
  // intercambia el pivote con el elemento mayor en i
  swap(&array[i + 1], &array[high]);
  
  // retorna el punto de partición
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    // encuentra el pivote de tal forma que
    // los elementos menores que el pivote estén a la izquierda
    // los elementos mayores que el pivote estén a la derecha
    int pi = partition(array, low, high);

    // llamada recursvia a la izquierda del pivote
    quickSort(array, low, pi - 1);

    // llamada recursiva a la derecha del pivote
    quickSort(array, pi + 1, high);
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
  quickSort(data, 0, size - 1);
  auto fin = chrono::steady_clock::now();
  cout << "Arreglo ordenado de menor a mayor:\n";
  printArreglo(data, size);
  auto tiempo_final = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
  cout << "\nTiempo de ejecución: " << tiempo_final << " ns" << endl;
  return 0;
}