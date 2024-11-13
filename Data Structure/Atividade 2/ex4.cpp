#include <iostream>
using namespace std;

int main(){

    int mat_elemento,rows,columns;
    int matriz[3][3];
    
    //Recebe os elementos da matriz
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            cout << "Digite o valor da matriz[" << i << "][" << j << "]: "; 
            cin >> mat_elemento;
            matriz[i][j] = mat_elemento;
        }
    
    //Printa a matriz
    for(int i=0;i<3;i++){
        cout << "\n";
        for(int j=0;j<3;j++){
            cout << matriz[i][j] << " ";
        }
    }

    //Calcula determinante
    int determinante;
    determinante = matriz[0][0]*(matriz[1][1]*matriz[2][2]-matriz[1][2]*matriz[2][1]) - matriz[0][1]*(matriz[1][0]*matriz[2][2]-matriz[1][2]*matriz[2][0]) + matriz[0][2]*(matriz[1][0]*matriz[2][1]-matriz[1][1]*matriz[2][0]);
    cout << "\n" << "\n";
    cout << "Determinante =  " << determinante;
}
