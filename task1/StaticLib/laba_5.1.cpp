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

