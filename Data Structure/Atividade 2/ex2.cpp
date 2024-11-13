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

    //Verifica a simetria da matriz
    bool simetric = true;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(matriz[i][j] != matriz[j][i]){
                simetric = false;
            }
        }
    }
    
    //Retorna resultado
    if (simetric){
        cout << endl << endl << "A matriz é simetrica!";
    }
    else {
        cout << endl << endl << "A matriz nao e simetrica!";
    }
    return 0;
}
