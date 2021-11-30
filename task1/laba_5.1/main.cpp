#include <iostream>
#include "..\laba_5.1\Header.h"
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
    int n = CorrentInput();
    cout << "enter the value of m\n";
    int m = CorrentInput();
    int* S = new int[m];
    int** A = new int* [n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
    }
    cout << "full fill your array\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = CorrentInput();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    for (int j = 0; j < m; j++) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += A[i][j];
        }
        AddItem(S, j, temp);
    }
    int min = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (S[i] < min) {
            min = S[i];
        }
    }
    cout << min << "\n";
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
