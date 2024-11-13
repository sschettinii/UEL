#include <iostream>
using namespace std;

int main(){

    int mat_elemento,rows,columns;
    //Cria a matriz
    cout << "Digite a quantidade de linha(s) da matriz: ";
    cin >> rows;
    cout << "Digite a quantidade de coluna(s) da matriz: ";
    cin >> columns;
    int matriz[rows][columns];
    
    //Recebe os elementos da matriz
    for(int i=0;i<rows;i++)
        for(int j=0;j<columns;j++){
            cout << "Digite o valor da matriz[" << i+1 << "][" << j+1 << "]: "; 
            cin >> mat_elemento;
            matriz[i][j] = mat_elemento;
        }
    
    //Printa a matriz
    for(int i=0;i<rows;i++){
        cout << "\n";
        for(int j=0;j<columns;j++){
            cout << matriz[i][j] << " ";
        }
    }

    //Calcula matriz transposta
    int matriz_transposta[columns][rows];
    for(int i=0;i<columns;i++){
        for(int j=0;j<rows;j++){
            matriz_transposta[columns][rows] = matriz[rows][columns];
        }
    }

    //Printa matriz transposta
    for(int i=0;i<columns;i++){
        cout << "\n" << "\n";
        for(int j=0;j<rows;j++){
            cout << matriz_transposta[i][j] << " ";
        }
    }
    return 0;
}
