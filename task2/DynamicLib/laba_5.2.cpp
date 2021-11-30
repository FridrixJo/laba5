#include <cmath>
extern "C" __declspec(dllexport) bool recursion(double* arr, int begin, int end) {
    int x = end - begin;

    if (x == 1) {
        return cos(arr[begin]) > 0 && cos(arr[end] > 0);
    }
    else if (x == 0) {
        return cos(arr[begin]) > 0;
    }
    x /= 3;

    return recursion(arr, begin, begin + x) && recursion(arr, begin + x + 1, end);
}