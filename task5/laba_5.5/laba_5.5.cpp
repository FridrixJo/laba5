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
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i + 1] = arr[i];
    }
    newArray[0] = item;
    size++;
    delete[] arr;
    arr = newArray;
}

void Averange(int** arr, const int size) {
    int k = size * size;
    double averange_value = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            averange_value += arr[i][j];
        }
    }
    averange_value /= k;
    cout << averange_value;
}

void Averange(int* arr, const int size) {
    int averange_value = 0;
    for (int i = 0; i < size; i++) {
        averange_value += arr[i];
    }
    averange_value /= size;
    cout << averange_value;

}

int main() {
    srand(time(NULL));
    int* B = new int[0];
    cout << "enter n\n";
    int n = CorrentInput();
    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    starline();
    int q = 0;
    for (int j = 1; j < n; j += 2) {
        for (int i = 0; i < n; i++) {
            int temp = 0;
            if (A[i][j] % 2) {
                temp = A[i][j];
                q++;
                AddItem(B, q, temp);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << B[i] << " ";
    }
    starline();
    cout << "the averange value of big array : ";
    Averange(A, n);
    starline();
    cout << "the averange value of new array : ";
    Averange(B, q);
    cout << "\n\n";
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
    A = nullptr;
    system("pause");
    return 0;
}
