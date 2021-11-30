#include <iostream>
using namespace std;

int CurrentInput() {
    int a;
    while (!(cin >> a) || a < INT_MIN || a > INT_MAX) {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Incorrect input, try again:\n";
    }
    return a;
}

long long f(long long k,long long n,long long m) {
    // recursion exit conditions
    if (n == 0) {
        return 1;
    }
    long long x = f(k, n / 2, m);
    if (n % 2 == 0) {
        return (x*x) % m;
    }
    return (k*x*x) % m;
}

int main() {

    cout << "enter the value of k\n";
    long long k = CurrentInput(); // input k
    cout << "enter the value of n\n"; 
    long long n = CurrentInput(); // input n
    cout << "enter the value of t\n";
    int t = CurrentInput(), m = 1; // input t

    if (k == 0 && n == 0 && t == 0) {
        exit(0); // exit conditions
    }

    for (int i = 0; i < t; i++) {
        m = m * 10;
    }
    k %= m;

    cout << "the result : " << f(k, n, m) << "\n"; // output of the result

    system("pause");
    return 0;
}