#include <iostream>
#include "..\StaticLib\Header.h"
using namespace std;

int CorrentInput() {
    int a;
    while (!(cin >> a) || a <= 0 || a > INT_MAX) {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Incorrect input, try again:\n";
    }
    return a;
}

int main()
{
    cout << "enter the value of n\n";
    int n = CorrentInput();  // ввод n
    cout << "enter the value of m\n";
    int m = CorrentInput();  // ввод m
    int* S = new int[m]; //создание указателся на динамический массив из m элементов 
    int** A = new int* [n]; // создание одномерного массива указателей на одномерные массивы

    for (int i = 0; i < n; i++) {
        A[i] = new int[m]; // выделение динамической памяти
    }
    cout << "full fill your array\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = CorrentInput(); // ввод значений массива
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " "; // вывод массива для проверки правильности ввода
        }
        cout << "\n";
    }
    for (int j = 0; j < m; j++) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += A[i][j];
        }
        AddItem(S, j, temp); // добавление переменной в новый динамический массив
    }
    int min = INT_MAX;
    for (int i = 0; i < m; i++) { // перебор нового динамического массива
        if (S[i] < min) {
            min = S[i]; // присваивание наименьшего элемента массива к переменной min
        }
    }
    cout << min << "\n"; // вывод наименьшего значения
    // освобождение динамической пямяти 
    for (int i = 0; i < n; i++) {
        delete[] A[i]; 
    }
    delete[] S;
    delete[] A;
    A = NULL;
    S = NULL;
    system("pause");
    return 0;
}
