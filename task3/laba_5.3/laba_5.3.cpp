#include <iostream>
#include <cmath>
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

void AddItem(int*& arr, int size, const int item) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i + 1] = arr[i];
    }
    newArray[0] = item;
    size++;
    delete[] arr;
    arr = newArray;
}


int main()
{
    srand(time(NULL));
    cout << "enter n\n";
    int n = CorrentInput();
    cout << "enter m\n";
    int m = CorrentInput();
    int* newArr = new int[0];
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    int q = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j && arr[i][j] % 2 == 0 && arr[i][j] != 0) {
                AddItem(newArr, q++, arr[i][j]);
            }
        }
    }
    if (q == 0) {
        cout << "there are no such elements\n";
    }
    else {
        int mulp = 1;
        for (int i = 0; i < q; i++) {
            mulp *= newArr[i];
        }
        cout << mulp << "\n";
    }


    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] newArr;
    arr = nullptr;
    newArr = nullptr;
    system("pause");
    return 0;
}
