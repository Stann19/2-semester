#include <iostream>
using namespace std;
//Я  считаю, что 1 введенный город-это начальный город

//Вводим матрицу вида 0 x1 x2..., где х1-расстояние между 1 и 2 городом
                    //x1 0  x3..., x3-расстояние между 2 и 3 городом
                    //x2 x3 0...
void input(int* a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

int check(int i, int arrindex[], int n) {
    for (int j = 0; j < n; j++) {
        if (i == arrindex[j] - 1) return 0;
    }
    return 1;
}

void min(int* a[], int n, int j, int k, int arrindex[]) {
    int* m = new int{ 10000 };
    int i = 0;
    int c = 0;
    int* b = a[j];
    for (i; i < n; i++) {
        if (b[i] < *m && b[i] != 0 && check(i, arrindex, n) == 1) {
            *m = b[i];
            c = i;
        };
    }
    arrindex[k + 1] = c + 1;
    delete m;
    if (k == n - 1) {
        return;
    };
    min(a, n, c, k + 1, arrindex);
}

void output(int arrindex[], int n) {
    for (int i = 0; i < n; i++)
        cout << arrindex[i] << " ";
}

int main()
{
    int n;
    int k = 0;
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    int* arrindex = new int[n] {1};
    input(a, n);
    min(a, n, 0, k, arrindex);
    output(arrindex, n);
}