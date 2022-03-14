#include <iostream>
using namespace std;

void average_number(int &sum, int &n) {
    int c;
    cin >> c;
    if (c == 0) {
        cout << sum/n;
        return;
    }
    sum += c;
    n += 1;
    average_number(sum, n);
}

void main()
{
    int sum = 0;
    int n = 0;
    average_number(sum, n);
}
