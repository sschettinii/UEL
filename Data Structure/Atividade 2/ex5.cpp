#include <iostream>
using namespace std;

int main(){

    int mat_elemento,rows1,columns1,rows2,columns2;
    //Cria a matriz 1
    cout << "Digite a quantidade de linha(s) da matriz: ";
    cin >> rows1;
    cout << "Digite a quantidade de coluna(s) da matriz: ";
    cin >> columns1;
    int matriz[rows1][columns1];
    
    //Recebe os elementos da matriz 1
    for(int i=0;i<rows1;i++)
        for(int j=0;j<columns1;j++){
            cout << "Digite o valor da matriz1[" << i << "][" << j << "]: "; 
            cin >> mat_elemento;
            matriz[i][j] = mat_elemento;
        }
    
    //Printa a matriz 1
    for(int i=0;i<rows1;i++){
        cout << "\n";
        for(int j=0;j<columns1;j++){
            cout << matriz[i][j] << " ";
        }
    }
    
    //Cria a matriz 2
    cout << "\n" << "\n";
    cout << "Digite a quantidade de linha(s) da matriz 2: ";
    cin >> rows2;
    cout << "Digite a quantidade de coluna(s) da matriz 2: ";
    cin >> columns2;
    int matriz2[rows2][columns2];
    
    //Recebe os elementos da matriz 2
    cout << "\n";
    for(int i=0;i<rows2;i++)
        for(int j=0;j<columns2;j++){
            cout << "Digite o valor da matriz2[" << i << "][" << j << "]: "; 
            cin >> mat_elemento;
            matriz2[i][j] = mat_elemento;
        }
    
    //Printa a matriz 2
    for(int i=0;i<rows2;i++){
        cout << "\n";
        for(int j=0;j<columns2;j++){
            cout << matriz2[i][j] << " ";
        }
    }
    
    //Verifica compatibilidade do produto
    if (columns1 != rows2){
        cout << "\n";
        cout << "As matrizes dadas nao podem ser multiplicadas!";
        return 0;
    }
    
    //Multiplica as matrizes
    
    return 0;
}
    
