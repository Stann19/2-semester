#include <iostream>
using namespace std;

int proverka(double x, double y, double a, double b, double r) {
    if (pow((x - a), 2) + pow((y - b), 2) <= pow(r, 2)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}

int main()
{
    double x, y, a, b, r;
    cout << "Enter the coordinates of the point: ";
    cin >> x >> y;
    cout << "Enter the coordinates of the center of the circle: ";
    cin >> a >> b;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    proverka(x, y, a, b, r);
    return 0;
}
