/*
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
*/

#include <iostream>
using namespace std;

// Classe Carro
class Carro {
private:
    char marca[50];
    char modelo[50];
    double valor;
    double kmRodados;
    char combustivel[20];

public:
    // Método para inserir os dados do carro
    void inserirDados() {
        cout << "Marca: ";
        cin >> marca;
        cout << "Modelo: ";
        cin >> modelo;
        cout << "Valor: ";
        cin >> valor;
        cout << "Quilometragem: ";
        cin >> kmRodados;
        cout << "Combustível: ";
        cin >> combustivel;
    }

    // Método para exibir os dados do carro
    void exibirDados() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Valor: R$ " << valor << endl;
        cout << "Quilometragem: " << kmRodados << " km" << endl;
        cout << "Combustível: " << combustivel << endl;
        cout << "--------------------------" << endl;
    }

    // Métodos para busca
    bool buscaPorMarcaOuModelo(const char* busca) {
        return (compararStrings(marca, busca) || compararStrings(modelo, busca));
    }

    bool buscaPorValor(double maxValor) {
        return valor <= maxValor;
    }

    bool buscaPorQuilometragem(double maxQuilometragem) {
        return kmRodados <= maxQuilometragem;
    }

    bool buscaPorCombustivel(const char* tipoCombustivel) {
        return compararStrings(combustivel, tipoCombustivel);
    }

private:
    // Função auxiliar para comparar strings
    bool compararStrings(const char* str1, const char* str2) {
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0') {
            if (str1[i] != str2[i]) {
                return false;
            }
            i++;
        }
        return str1[i] == '\0' && str2[i] == '\0';
    }
};

// Programa principal
int main() {
    Carro carros[10];
    int quantidade = 0;

    // Inserção de até 10 carros
    while (quantidade < 10) {
        cout << "\nCadastro do carro " << (quantidade + 1) << ":" << endl;
        carros[quantidade].inserirDados();
        quantidade++;

        char continuar;
        cout << "Deseja cadastrar outro carro? (s/n): ";
        cin >> continuar;
        if (continuar != 's' && continuar != 'S') {
            break;
        }
    }

    // Opções de busca
    int opcao;
    cout << "\nOpções de busca:" << endl;
    cout << "1 - Por Marca ou Modelo" << endl;
    cout << "2 - Por Valor Máximo" << endl;
    cout << "3 - Por Quilometragem Máxima" << endl;
    cout << "4 - Por Tipo de Combustível" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;

    if (opcao == 1) {
        char busca[50];
        cout << "Informe a Marca ou Modelo: ";
        cin >> busca;

        for (int i = 0; i < quantidade; i++) {
            if (carros[i].buscaPorMarcaOuModelo(busca)) {
                carros[i].exibirDados();
            }
        }
    } else if (opcao == 2) {
        double maxValor;
        cout << "Informe o valor máximo: ";
        cin >> maxValor;

        for (int i = 0; i < quantidade; i++) {
            if (carros[i].buscaPorValor(maxValor)) {
                carros[i].exibirDados();
            }
        }
    } else if (opcao == 3) {
        double maxQuilometragem;
        cout << "Informe a quilometragem máxima: ";
        cin >> maxQuilometragem;

        for (int i = 0; i < quantidade; i++) {
            if (carros[i].buscaPorQuilometragem(maxQuilometragem)) {
                carros[i].exibirDados();
            }
        }
    } else if (opcao == 4) {
        char tipoCombustivel[20];
        cout << "Informe o tipo de combustível: ";
        cin >> tipoCombustivel;

        for (int i = 0; i < quantidade; i++) {
            if (carros[i].buscaPorCombustivel(tipoCombustivel)) {
                carros[i].exibirDados();
            }
        }
    } else {
        cout << "Opção inválida!" << endl;
    }

    return 0;
}
