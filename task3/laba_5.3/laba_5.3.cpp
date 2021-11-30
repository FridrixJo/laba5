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
    int* newArray = new int[size + 1]; // creating a new dynamic array with size + 1 elements
    for (int i = 0; i < size; i++) {
        newArray[i + 1] = arr[i]; // copying elements to a new array from the 1st position
    }
    newArray[0] = item; // assigning the zero position of an array to a variable
    size++; // increasing the size of the array by one unit
    delete[] arr; // clearing heap of old array
    arr = newArray; // substitution of pointers
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
            arr[i][j] = rand() % 10; // random input of the array
            cout << arr[i][j] << " "; // and it's output
        }
        cout << "\n";
    }
    int q = 0; // size counter of new array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j && arr[i][j] % 2 == 0 && arr[i][j] != 0) { // required condition
                AddItem(newArr, q++, arr[i][j]); // push such element into new array
            }
        }
    }
    if (q == 0) {
        cout << "there are no such elements\n";
    }
    else {
        int mulp = 1;
        for (int i = 0; i < q; i++) {
            mulp *= newArr[i]; // counting the multiplication of array elements
        }
        cout << mulp << "\n";
    }

    // freeing heap
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
