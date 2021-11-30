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
    cout << "enter the value of n\n";
    int n = CorrentInput();  // input n
    cout << "enter the value of m\n";
    int m = CorrentInput();  // input m
    int* S = new int[m]; // creating a pointer to a dynamic array of m elements 
    int** A = new int* [n]; // creating a one-dimensional array of pointers to one-dimensional arrays

    for (int i = 0; i < n; i++) {
        A[i] = new int[m]; // allocation of dynamic memory
    }
    cout << "full fill your array\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = CorrentInput(); // input values of array
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " "; // outputting an array to check if the input is correct
        }
        cout << "\n";
    }
    for (int j = 0; j < m; j++) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += A[i][j];
        }
        AddItem(S, j, temp); // adding a variable to a new dynamic array
    }
    int min = INT_MAX;
    for (int i = 0; i < m; i++) { // iteration over a new dynamic array
        if (S[i] < min) {
            min = S[i]; // assigning the smallest element of an array to variable min
        }
    }
    cout << min << "\n"; // output of smallest value
    // freeing heap 
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
