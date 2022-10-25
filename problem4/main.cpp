#include <bits/stdc++.h>
using namespace std;

void binaryPrint(int n) {
    if (n / 2 != 0) binaryPrint(n / 2);
    cout << n % 2;
}

void numbers(string prefix, int k) {
    if (k == 0) {
        cout << prefix << "\n";
        return;
    }

    numbers(prefix + '0', k - 1);
    numbers(prefix + '1', k - 1);
}

int main() {
    binaryPrint(27);

    cout << "\n";

    numbers("00101", 2);
}
