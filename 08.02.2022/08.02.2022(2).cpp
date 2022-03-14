#include <iostream>
using namespace std;

int proverka(int *a, int num, int *j) {
    if (*a == num) {
        *j = *j + 1;
    }
    if (*a > num) {
        *a = num;
        *j = 1;
    }
    return 0;
}
int main()
{
    int n;
    int i;
    int num;
    int a;
    int j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> num;
        if (i == 1) {
            a = num;
            j = 0;
        }
        proverka(&a, num, &j);
    }
    cout << "Minimum number: "<< a << '\n' << "Its quantity: "<< j;
    return 0;
}
