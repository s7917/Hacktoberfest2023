#include <bits/stdc++.h>
using namespace std;

void prime(int n) {
    int i;
    for(i=2;i<n;i++) {
        if(n%i == 0) {
            cout << "Not prime" << endl;
            break;
        }
    }
    if(i == n) {
        cout << "Prime" << endl;
    }
}

// prints whether a number is prime or not
int main() {
    int n;
    cin >> n;
    prime(n);
    return 0;
}