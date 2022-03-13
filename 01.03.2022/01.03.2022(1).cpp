#include <iostream>
using namespace std;

void entering() {
    int c;
    cin >> c;
    if (c == 0) return;
    else if (c % 2 != 0) {
        cout << " " << c << '\n';
    }
    return entering();
}

void main()
{
    entering();
}

