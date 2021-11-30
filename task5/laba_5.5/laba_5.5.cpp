#include <iostream>
using namespace std;

void starline() {
    cout << "\n\n************\n\n";
}

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

void Averange(int** arr, const int size) { // function for two-dimensional array
    int k = size * size; // get the quantity
    double averange_value = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            averange_value += arr[i][j]; // sum of all values
        }
    }
    averange_value /= k; // get the averange value
    cout << averange_value;
}

void Averange(int* arr, const int size) { // function fo one-dimensional array
    int averange_value = 0;
    for (int i = 0; i < size; i++) {
        averange_value += arr[i]; // sum of all values
    }
    averange_value /= size; // get the averange value
    cout << averange_value;

}

int main() {
    srand(time(NULL));
    int* B = new int[0]; // creating a pointer to a dynamic array of 0 elements 
    cout << "enter n\n";
    int n = CorrentInput();
    int** A = new int* [n]; // creating a one-dimensional array of pointers to one-dimensional arrays
    for (int i = 0; i < n; i++) {
        A[i] = new int[n]; // allocation of dynamic memory
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10; // random input of array
            cout << A[i][j] << " "; // and output for checking
        }
        cout << "\n";
    }
    starline();
    int q = 0;  // counter
    for (int j = 1; j < n; j += 2) {
        for (int i = 0; i < n; i++) {
            int temp = 0;
            if (A[i][j] % 2) {
                temp = A[i][j];
                q++; // increace value of counter
                AddItem(B, q, temp);  // push such element into new array
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << B[i] << " "; // output of new arrat
    }
    starline();
    cout << "the averange value of big array : ";
    Averange(A, n);
    starline();
    cout << "the averange value of new array : ";
    Averange(B, q);
    cout << "\n\n";
    // freeing heap
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
    A = nullptr;
    system("pause");
    return 0;
}
