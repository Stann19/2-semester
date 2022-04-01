#include <iostream>
using namespace std;

int det(int arr[], unsigned N) {
    if (N == 1) return arr[0];
    int d = 0;
    int e;
    for (int i = 0; i < N; i++) {
        int* arr1 = new int[(N - 1) * (N - 1)];
        int l = 0;
        int m = 0;
        for (int j = 0; j < N * N; j++) {
            if (j == i + N * l) l++;
            else if (j > N - 1) {
                arr1[m] = arr[j];
                m++;
            }
        }
        if (i % 2 == 0) e = 1;
        else e = -1;
        d += e * arr[i] * det(arr1, N - 1);
        delete[] arr1;
    }
    delete[] arr;
    return d;
}

int main()
{
    unsigned N;
    cin >> N;
    int* arr = new int[N*N];
    for (int i = 0; i < N * N; i++) cin >> arr[i];
    cout << det(arr, N);
}
