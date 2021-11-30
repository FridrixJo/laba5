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


