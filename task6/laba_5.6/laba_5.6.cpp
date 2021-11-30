#include <iostream>
using namespace std;

int f(int n) {
    // recursion exit conditions
    if (n % 10 > 0) {
        return n % 10;
    }
    if (n == 0) {
        return 0;
    }
    return f(n / 10);
}

int s(int p, int q) {
    int sum = 0;
    for (int i = p; i <= q; i++) {
        sum += f(i);
    }
    return sum;
}

int CorrentInput() {
    int a;
    while (!(cin >> a) || a > INT_MAX) {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Incorrect input, try again:\n";
    }
    return a;
}
int main() {
    cout << "enter p and q (if you wanna exit : write 0 0)\n";
    int p = CorrentInput(), q = CorrentInput(); // input p and q
    if (p < 0 && q < 0) { // exit conditions
        exit(0); 
    }
    cout << "\n" << s(p, q) << "\n";  // output 
    return 0;
}
