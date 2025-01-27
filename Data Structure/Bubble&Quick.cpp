#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
using namespace std;

struct Dish {
    int priority;
    int time;
    string name;
};

//Bubble
void bubbleSort(vector<Dish>& dishes) {
    int n = dishes.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((dishes[j].priority < dishes[j + 1].priority) ||
                (dishes[j].priority == dishes[j + 1].priority && dishes[j].time > dishes[j + 1].time)) {
                swap(dishes[j], dishes[j + 1]);
            }
        }
    }
}

// Quicksort
vector<Dish> quicksort(vector<Dish>& dishes) {
    if (dishes.size() <= 1) return dishes;

    Dish pivot = dishes[dishes.size() / 2];
    vector<Dish> left, right, middle;

    for (const auto& dish : dishes) {
        if (dish.priority > pivot.priority || (dish.priority == pivot.priority && dish.time < pivot.time)) {
            left.push_back(dish);
        } else if (dish.priority < pivot.priority || (dish.priority == pivot.priority && dish.time > pivot.time)) {
            right.push_back(dish);
        } else {
            middle.push_back(dish);
        }
    }

    vector<Dish> sortedLeft = quicksort(left);
    vector<Dish> sortedRight = quicksort(right);

    sortedLeft.insert(sortedLeft.end(), middle.begin(), middle.end());
    sortedLeft.insert(sortedLeft.end(), sortedRight.begin(), sortedRight.end());

    return sortedLeft;
}

int main() {
    ifstream file("restaurante_pratos.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return 1;
    }

    vector<Dish> dishes;
    string line;

    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string priorityStr, timeStr, name;
        if (!getline(ss, priorityStr, ',') || !getline(ss, timeStr, ',') || !getline(ss, name, ',')) {
            continue;
        }

        try {
            Dish dish;
            dish.priority = stoi(priorityStr);
            dish.time = stoi(timeStr);
            dish.name = name;
            dishes.push_back(dish);
        } catch (const invalid_argument& e) {
            cerr << "Formato de numero invalido na linha: " << line << endl;
            continue;
        } catch (const out_of_range& e) {
            cerr << "Numero fora do scopo na linha: " << line << endl;
            continue;
        }
    }

    file.close();

    if (dishes.empty()) {
        cerr << "Sem dados validos para processamento." << endl;
        return 1;
    }

    auto start = chrono::high_resolution_clock::now();

    // Bubble Sort
    vector<Dish> bubbleSortedDishes = dishes;
    bubbleSort(bubbleSortedDishes);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleSortDuration = end - start;
    cout << "Tempo de ordenacao bubblesort: " << bubbleSortDuration.count() << " segundos." << endl;

    start = chrono::high_resolution_clock::now();

    // Quicksort
    vector<Dish> quickSortedDishes = quicksort(dishes);

    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickSortDuration = end - start;
    cout << "Tempo de ordenacao quicksort: " << quickSortDuration.count() << " segundos." << endl;

    cout << "Resultado bubblesort: " << endl;
    for (const auto& dish : bubbleSortedDishes) {
        cout << dish.name << endl;
    }

    cout << "\nResultado Quicksort: " << endl;
    for (const auto& dish : quickSortedDishes) {
        cout << dish.name << endl;
    }

    return 0;
}
