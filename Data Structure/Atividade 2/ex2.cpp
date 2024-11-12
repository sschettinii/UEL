#include <iostream>
using namespace std;

int main(){

    int mat_elemento,matriz[3][3];

    //Recebe os elementos da matriz
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            cout << "Digite o valor da matriz[" << i+1 << "][" << j+1 << "]: "; 
            cin >> mat_elemento;
            matriz[i][j] = mat_elemento;
        }
    
    //Printa a matriz
    for(int i=0;i<3;i++){
        cout << "\n";
        for(int j=0;j<3;j++){
            cout << matriz[i][j];
        }
    }

    //Verifica a simetria da matriz
    

    return 0;

}
