#include <iostream>
using namespace std;

void input(int demon[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> *(demon + i);
    }
}

void counting(int demon[], int n, int p) {
    int k = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (p >= demon[i]) {
            p = p - demon[i];
            k++;
        }
    }
    cout << k;
}

int main()
{
    int n;
    int p;
    cin >> n;
    cin >> p;
    int* demon = new int[n];
    input(demon, n);
    counting(demon, n, p);
}