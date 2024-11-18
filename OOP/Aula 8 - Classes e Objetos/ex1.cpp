#include <iostream>
using namespace std;

class Carros{
  private:

    string marca,modelo
    float valor,km
    int combustivel

  public:

    void init (string marca, string modelo, float valor, float km, int combustilvel){
      this->marca=marca;
      this->modelo=modelo;
      this->valor=valor;
      this->km=km;
      this->combustivel=combustivel;
    }

    string get_marca(){
      return marca;
    }
    string get_modelo(){
      return modelo;
    }
    float get_valor(){
      return valor;
    }
    float get_km(){
      return km;
    }
    int get_combustivel(){
      return combustivel;
    }
};

int main(){
    int opcao;
    cout << "Sistema cadastro de veículos" << endl << endl;
    cout << "1 - Adicionar novo carro" << endl;
    cout << "2 - Buscar carro" << endl;
    cin opcao;
    
    if (opcao == 1){
        
    }
    if (opcao == 2){
        
    }
    return 0;
}
