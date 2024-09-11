#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;

void print(string display, vector<vector<int> > matrix,
		int start_row, int start_column, int end_row,
		int end_column)
{
	cout << endl << display << " =>" << endl;
	for (int i = start_row; i <= end_row; i++) {
		for (int j = start_column; j <= end_column; j++) {
			cout << setw(10);
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return;
}

vector<vector<int> >
multiply_matrix(vector<vector<int> > matrix_A,
				vector<vector<int> > matrix_B)
{   
    
    int col_1 = matrix_A[0].size();
	int row_1 = matrix_A.size();
	int col_2 = matrix_B[0].size();
	int row_2 = matrix_B.size();

    vector<int> result_matrix_row(col_2, 0);
	vector<vector<int> > result_matrix(row_1,
									result_matrix_row);

    for(int i = 0; i < row_1; i++){
        for(int j = 0; j < col_2; j++){
            for(int k = 0; k < col_1; k++){
                result_matrix[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    return result_matrix;
}


int main(){
	ifstream archivo("datasetMatrix.txt");
	string linea;
	int i = 0;
	getline(archivo, linea);
	while(linea[i] != ' '){
		i++;
	}
	int ROW_1 = stoi(linea.substr(0, i));
	int COL_1 = stoi(linea.substr(i+1, linea.size()-1));

	vector<vector<int> > matrix_A;
	for(int i = 0; i < ROW_1; i++){
		getline(archivo, linea);
		vector<int> fila;
		int j = 0;
		for(int k = 0; k < linea.size(); k++){
			if(linea[k] == ' '){
				fila.push_back(stoi(linea.substr(j, k-j)));
				j = k+1;
			}
		}
		matrix_A.push_back(fila);
	}

	getline(archivo, linea);
	i = 0;
	while(linea[i] != ' '){
		i++;
	}
	int ROW_2 = stoi(linea.substr(0, i));
	int COL_2 = stoi(linea.substr(i+1, linea.size()-1));

	vector<vector<int> > matrix_B;
	for(int i = 0; i < ROW_2; i++){
		getline(archivo, linea);
		vector<int> fila;
		int j = 0;
		for(int k = 0; k < linea.size(); k++){
			if(linea[k] == '\0'){
				break;
			}
			if(linea[k] == ' '){
				fila.push_back(stoi(linea.substr(j, k-j)));
				j = k+1;
			}
		}
		matrix_B.push_back(fila);
	}
	archivo.close();

	print("Matriz A", matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);
	print("Matriz B", matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);
	auto inicio = chrono::steady_clock::now();
	vector<vector<int> > result_matrix(multiply_matrix(matrix_A, matrix_B));
	auto fin = chrono::steady_clock::now();
	print("Matriz resultante", result_matrix, 0, 0, ROW_1 - 1,
		COL_2 - 1);
	auto tiempo_final = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
	cout << "\nTiempo de ejecución: " << tiempo_final << " ns" << endl;
}