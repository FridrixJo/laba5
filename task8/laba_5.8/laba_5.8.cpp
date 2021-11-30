#include <iostream>
using namespace std;

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

int func(int n) {
    int* A = new int[n]; // creating a new dynamic array with n elements
    for (int i = 0; i < n; i++) {
        A[i] = 0; // assigning values to array elements
    }
    int q = 0; // counter
    for (int j = 1; j <= n; j += 2) {
        if (n % j == 0) { // mandatory conditions
            AddItem(A, n + q, j); // push such element inot new array
            q++; // increase counter value 
        }
    }

    int max = INT_MIN;
    for (int i = 0; i < q; i++) { //iterating over an array
        if (max < A[i]) { 
            max = A[i]; // assigning the smallest element of an array to variable
        }
    }
    // recursion exit conditions
    if (n == 0) {
        return 0;
    }
    return max + func(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << func(n); // output the result
    return 0;
}
