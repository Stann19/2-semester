#include <iostream>
using namespace std;
/*Я считаю, что вводятся различные пары*/

int proverka(int x, int y, int *c1, int *c2, int *c3, int *c4) {
    if (x > 0 && y > 0) {
        *c1 = *c1 + 1; /*первая четверть*/
    }
    if (x < 0 && y > 0) {
        *c2 = *c2 + 1; /*вторая четверть*/
    }
    if (x < 0 && y < 0) {
        *c3 = *c3 + 1; /*третья четверть*/
    }
    if (x > 0 && y < 0) {
        *c4 = *c4 + 1; /*четвертая четверть*/
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "");
    int n, x, y, c1, c2, c3, c4;
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "x:";
        cin >> x;
        cout << "y:";
        cin >> y;
        proverka(x, y, &c1, &c2, &c3, &c4);
    }
    if (c1 > c2 && c1 > c3 && c1 > c4) {
        cout << "First quarter" << '\n' << "Number of points:" << c1 << '\n';
    }
    if (c1 < c2 && c2 > c3 && c2 > c4) {
        cout << "Second quarter" << '\n' << "Number of points:" << c2 << '\n';
    }
    if (c3 > c2 && c1 < c3 && c3 > c4) {
        cout << "Third quarter" << '\n' << "Number of points:" << c3 << '\n';
    }
    if (c4 > c2 && c4 > c3 && c4 > c1) {
        cout << "Fourth quarter" << '\n' << "Number of points:" << c4 << '\n';
    }
    else {
        cout << "0"; /*Если четвертей с набольшим количеством точек больше, чем одна, то выводит 0*/
    }
    return 0;
}

