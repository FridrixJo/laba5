#include <iostream>
using namespace std;
void starline() {
    cout << "\n\n************\n\n";
}
void invers(double**& arr, const int size) {
    starline();
    double** A = new double* [size];
    for (int i = 0; i < size; i++) {
        A[i] = new double[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = arr[i][j];
        }
    }
    for (int i = size - 1; i >= 0; i--) {
        for (int j = size - 1; j >= 0; j--) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < size; i++) {
        delete[] A[i];
    }
    delete[] A;
    A = nullptr;
}
double CurrentInputDouble() {
    double a;
    while (!(cin >> a) || a < INT_MIN || a > INT_MAX) {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Incorrect input, try again:\n";
    }
    return a;
}

int CurrentInputInt() {
    int a;
    while (!(cin >> a) || a <= 0 || a > INT_MAX) {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Incorrect input, try again:\n";
    }
    return a;
}

int main() {
    srand(time(NULL));
    cout << "enter n\n";
    int n = CurrentInputInt();
    double** A = new double* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = CurrentInputDouble();
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    int q = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 0) {
                q++;
                cout << "the coordinates of " << q << "th zero are " << "[" << i << "," << j << "]\n";
            }
        }
    }
    invers(A, n);
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
    A = nullptr;
    return 0;
}
