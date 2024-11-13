#include <iostream>
using namespace std;

void troca_valores(int*a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 5, y = 10;
    cout << "Antes das trocas: x = " << x << ", y = " << y << endl;

    troca_valores(&x, &y);
    cout << "Depois das trocas: x = " << x << ", y = " << y << endl;

    return 0;
}
