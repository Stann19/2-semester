#include <iostream>
using namespace std;

int diveder(int b, int a) {
    if (a % 10 != 0) {
        diveder(b * 10, a / 10);
    }
    else return b;
}

int inverse_number(int a, int b) {
    if (a % 10 != 0)
        return (a % 10) * diveder(b, a / 10) + inverse_number(a / 10, b);
}

void main()
{
    int b = 1;
    int a;
    cin >> a;
    cout << inverse_number(a, b);
}

