#include <iostream>

using namespace std;

struct notes{
    int vec_notas[4];
};


int main(){
    int counter=0,soma = 0,nota_temp,media;

    struct notes notas;

    for (int i=0;i<4;i++){
        cout << "Nota " << i << ": ";
        cin >> nota_temp;
        notas.vec_notas[i] = nota_temp;
    }

    for (int i=0;i<4;i++){
        soma += notas.vec_notas[i];
    }
    media = soma/4;
    
    if (media<4){
        cout << "Reprovado";
    }
    if (media >= 4 && media<6){
        cout << "Exame";
    }
    if (media >= 6){
        cout << "Aprovado";
    }
}
