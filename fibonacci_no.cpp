#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

// prints the nth fibonacci number
int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}