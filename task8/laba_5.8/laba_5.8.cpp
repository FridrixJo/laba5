#include <iostream>
using namespace std;

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

int func(int n) {
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = 0;
    }
    int q = 0;
    for (int j = 1; j <= n; j += 2) {
        if (n % j == 0) {
            AddItem(A, n + q, j);
            q++;
        }
    }

    int max = INT_MIN;
    for (int i = 0; i < q; i++) {
        if (max < A[i]) {
            max = A[i];
        }
    }
    if (n == 0) {
        return 0;
    }
    return max + func(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << func(n);
    return 0;
}
