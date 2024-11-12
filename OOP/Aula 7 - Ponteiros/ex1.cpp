//Algoritmo que printa uma matriz acessada por ponteiros
#include <iostream>
using namespace std;

int main() {
    
    int matriz[2][2] = {{1,2},{3,4}};
    int* ponteiro;
    ponteiro = &matriz[0][0];
    
    for (int i=0;i<4;i++){
        cout << *(ponteiro+i);
    }
}
