#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    typedef bool(*value) (double*, int, int);
    value recursion;
    recursion = (value)GetProcAddress(load, "recursion");

    cout << "enter the value of n\n";
    double n;
    cin >> n; // input n
    double* X = new double[n]; // creating a pointer to a dynamic array of n elements 
    for (int i = 0; i < n; i++) {
        cout << "enter the value of the " << i + 1 << "th member of array\n";
        cin >> X[i]; // input values of array
    }

    if (recursion(X, 0, n)) {
        cout << "for all elements the condition is satisfied\n";
    }
    else {
        cout << "not for all elements the condition is satisfied\n";
    }
    // freeing heap 
    delete[] X;
    X = NULL;
    FreeLibrary(load);
    system("pause");
    return 0;
}
