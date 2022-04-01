#include <iostream>
#include <cmath>
using namespace std;

void locomotive(int arr[], unsigned N) {
    for (int i = N - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (i % 2 == 1) {
            cout << arr[i] << " ";
        }
    }
    delete[] arr;
}

int main()
{
    unsigned N;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    locomotive(arr, N);
}
