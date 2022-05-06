#include <iostream>
using namespace std;

struct tim 
{
    int begin = 0, end = 0, num = 0;
};

void input(int t_n, tim t[]) {
    for (int i = 0; i < t_n; i++) {
        cin >> (t + i)->begin;
        cin >> (t + i)->end;
        ((t + i)->num) = i + 1;
    }
}

void output(int t_n, tim t[], int arr[]) {
    for (int i = 0; i < t_n; i++) {
        if (arr[i] == 1)
            cout << (t + i)->begin << " " << (t + i)->end << " " << ((t + i)->num) << '\n';

    }
    delete[] t;
    delete[] arr;
}

void osnov(int t_n, tim t[], int arr[]) {
    for (int i = 0; i < t_n; i++) {
        for (int j = i; j < t_n; j++) {
            if ((t + i)->end > (t + j)->end) {
                tim* a = new tim;
                *a = *(t + j);
                *(t + j) = *(t + i);
                *(t + i) = *a;
                delete a;
            }
        }
    }
    int j = 0;
    for (int i = 1; i < t_n; i++) {
        if ((t + i)->begin >(t + j)->end) {
            j = i;
            arr[i] = 1;
        }
    }
}


int main()
{
    int t_n;
    cin >> t_n;
    tim* t = new tim[t_n];
    int* arr = new int[t_n]{0};
    arr[0] = 1;
    input(t_n, t);
    osnov(t_n, t, arr);
    output(t_n, t, arr);
}
