#include <iostream>
using namespace std;

void zamena(int n, int i, int a[], int c[]) {
    c[0] = (a[n - 1] + a[0] + a[1]) / 3;
    for (i = 1; i < n - 1; i++) {
        c[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
    }
    c[n - 1] = (a[n - 1] + a[0] + a[n - 2]) / 3;
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
}

int main()
{
    const int n = 5;
    int a[n];
    int i;
    int c[n];
    for (i=0; i<n; i++){
        cin >> a[i];
    }
    zamena(n , i, a, c);
    return 0;
}


