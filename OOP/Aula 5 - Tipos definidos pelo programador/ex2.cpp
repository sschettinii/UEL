/*
(1)-Estrutura, (2)-Matriz, (3)-Estrutura e Matriz

1 - (2)Seu nome é um endereco
2 - (2)Agrupam variaveis do mesmo tipo
3 - (1)Um item é chamado de membro
4 - (2)Um item é chamado de elemento
5 - (1)Agrupam variaveis de tipos diferentes
6 - (3)Agrupam matrizes e estruturas
*/

//1
#include <iostream>
using namespace std;

int main(){
    int matriz[3] = {1,2,3};
    cout << "Endereco da matriz: " << matriz << endl;
    return 0;
}

//2
#include <iostream>
using namespace std;

int main(){
    int matriz[3] = {1,2,3};
    for (int i=0;i<3;i++){
        cout << "Elemento " << i << ": " << matriz[i] << endl;
    }
    return 0;
}

//3
#include <iostream>
using namespace std;

struct Pessoa{
  int idade;
  string nome;  
};

int main(){
    Pessoa p = {25, "Joao"};
    cout << "Nome: " << p.nome << ", idade: " << p.idade << endl;
    return 0;
}

//4
#include <iostream>
using namespace std;

int main(){
    int matriz[3] = {1,2,3};
    cout << "Primeiro elemento da matriz: " << matriz[0] << endl;
    return 0;
}

//5
#include <iostream>
using namespace std;

struct Cartas{
    int value;
    string naipe;
};

int main(){
    Cartas carta = {8,"Paus"};
    cout << "Carta " << carta.value << " de " << carta.naipe << endl;
    return 0;
}

//6
#include <iostream>
using namespace std;

struct Estrutura{
    int matriz[3];
    string df_name;
    float temperatura;
};

int main(){
    Estrutura teste = {{1,2,3},"Matriz teste", 25.6};
    cout << "Endereco da Matriz: " << teste.matriz << " , nome da matriz: " << teste.df_name << " e a temperatura é de " << teste.temperatura << endl;
}
