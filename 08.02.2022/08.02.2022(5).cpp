#include <iostream>
using namespace std;
int proverka(int a1, int b1, int c1, int a2, int b2, int c2) {
    if (a2 * b1 != a1 * b2) {
        cout << "(" << (b2 * c1 - b1 * c2) / (a2 * b1 - a1 * b2) << ", " << (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2) << ")";
    }
    else {
        cout << 0;
    }
    return 0;
}

int main()
{
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    proverka(a1, b1, c1, a2, b2, c2);
    return 0;
}
