﻿void AddItem(int*& arr, int size, const int item) {
    int* newArray = new int[size + 1]; // создание нового динамического массива с size + 1 элементов
    for (int i = 0; i < size; i++) {
        newArray[i + 1] = arr[i]; // копирование элементов в новый массив с 1-ой позиции
    }
    newArray[0] = item; // присваивание нулевой позиции массива переменной 
    size++; // увеличение размерности массива на одну единицу
    delete[] arr; // чистка динамической памяти старого массива
    arr = newArray; // подмена указателей
} 

