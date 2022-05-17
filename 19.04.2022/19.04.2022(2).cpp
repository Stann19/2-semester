#include <iostream>
using namespace std;

void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int min(int a, int b) {
    if (b > a) {
        return a;
    }
    else {
        return b;
    }
}

int osnov(int a[], int n) {
    int E;
    if (n == 1) return E = 0;
    else if (n == 2) return abs(a[n - 1] - a[n - 2]);
    return E = min(osnov(a, n - 1) + abs(a[n - 1] - a[n - 2]), osnov(a, n - 2) + 3 * abs(a[n - 1] - a[n - 3]));
}

int main()
{
    int n;
    cin >> n;
    int* a = new int[n] {0};
    input(a, n);
    cout << osnov(a, n);
}
