#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;

// Combina dos subarreglos L y M en arr
void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  vector<int> L(n1);
  vector<int> M(n2);
  
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
    
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
    
  int i = 0, j = 0, k = p;
  
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}


void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;
    
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

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
  mergeSort(data, 0, size - 1);
  auto fin = chrono::steady_clock::now();
  cout << "Arreglo ordenado de menor a mayor:\n";
  printArreglo(data, size);
  auto tiempo_final = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
  cout << "\nTiempo de ejecución: " << tiempo_final << " ns" << endl;
  return 0;
}