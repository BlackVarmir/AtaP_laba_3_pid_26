#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void fillMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(*(matrix + i) + j) = rand() % 201 - 100;
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(matrix + i) + j) << "\t";
        }
        cout << endl;
    }
}

int findMaxOnMainDiagonal(int** matrix, int n) {
    int maxElement = **matrix;
    for (int i = 1; i < n; i++) {
        if (*(*(matrix + i) + i) > maxElement) {
            maxElement = *(*(matrix + i) + i);
        }
    }
    return maxElement;
}

int findMinOnSecondaryDiagonal(int** matrix, int n) {
    int minElement = *(*(matrix)+(n - 1));
    for (int i = 1; i < n; i++) {
        if (*(*(matrix + i) + (n - 1 - i)) < minElement) {
            minElement = *(*(matrix + i) + (n - 1 - i));
        }
    }
    return minElement;
}

void Task1(int** matrix, int n) {
    int maxMain = findMaxOnMainDiagonal(matrix, n);
    int minSecondary = findMinOnSecondaryDiagonal(matrix, n);
    int difference = maxMain - minSecondary;
    cout << "Різниця: " << difference << endl;
}

void Task2(int** matrix, int n) {
    cout << "Вивід елементів у заданому порядку:" << endl;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                cout << *(*(matrix + i) + j) << " ";
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                cout << *(*(matrix + i) + j) << " ";
            }
        }
        cout << endl << endl;
    }
}

void Task3(int** matrix, int n) {
    int* minIndexes = new int[n];

    for (int i = 0; i < n; i++) {
        int minIndex = 0;
        for (int j = 1; j < n; j++) {
            if (*(*(matrix + i) + j) < *(*(matrix + i) + minIndex)) {
                minIndex = j;
            }
        }
        minIndexes[i] = minIndex;
    }

    cout << "Порядкові номери мінімальних елементів у рядках: ";
    for (int i = 0; i < n; i++) {
        cout << minIndexes[i] << " ";
    }
    cout << endl;

    delete[] minIndexes;
}

void Task4(int** matrix, int n) {
    int sumPositive = 0, countPositive = 0;
    int sumNegative = 0, countNegative = 0;
    int zeroCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value = *(*(matrix + i) + j);
            if (value > 0) {
                sumPositive += value;
                countPositive++;
            }
            else if (value < 0) {
                sumNegative += value;
                countNegative++;
            }
            else {
                zeroCount++;
            }
        }
    }

    double avgPositive = countPositive ? static_cast<double>(sumPositive) / countPositive : 0;
    double avgNegative = countNegative ? static_cast<double>(sumNegative) / countNegative : 0;

    cout << "Середнє додатніх: " << avgPositive << endl;
    cout << "Середнє від'ємних: " << avgNegative << endl;
    cout << "Кількість нулів: " << zeroCount << endl;
}

void Task5(int** matrix, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(*(matrix + i) + i) > *(*(matrix + j) + j)) {
                int temp = *(*(matrix + i) + i);
                *(*(matrix + i) + i) = *(*(matrix + j) + j);
                *(*(matrix + j) + j) = temp;
            }
        }
    }
    cout << "Матриця після сортування головної діагоналі:" << endl;
    printMatrix(matrix, n);
}

int main() {
    srand(time(0));
    int n, choice;
    cout << "Введіть розмірність матриці: ";
    cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    fillMatrix(matrix, n);
    printMatrix(matrix, n);

    do {
        cout << "\nМеню:\n";
        cout << "1 - Завдання 1\n";
        cout << "2 - Завдання 2\n";
        cout << "3 - Завдання 3\n";
        cout << "4 - Завдання 4\n";
        cout << "5 - Завдання 5\n";
        cout << "0 - Вихід\n";
        cout << "Виберіть пункт: ";
        cin >> choice;

        switch (choice) {
        case 1: 
            Task1(matrix, n); 
            break;
        case 2: 
            Task2(matrix, n); 
            break;
        case 3: 
            Task3(matrix, n); 
            break;
        case 4: 
            Task4(matrix, n); 
            break;
        case 5: 
            Task5(matrix, n); 
            break;
        case 0: 
            cout << "Вихід..." << endl; 
            break;
        default: 
            cout << "Некоректне введення. Спробуйте знову." << endl;
        }
    } while (choice != 0);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
