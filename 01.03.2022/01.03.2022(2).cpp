#include <iostream>
using namespace std;

void entering() {
    int a;
    int b;
    cin >> a;
    if (a == 0) return;
    cout << " " << a << '\n';
    cin >> b;
    if (b == 0) return;
    entering();
}

void main()
{
    entering();
}

