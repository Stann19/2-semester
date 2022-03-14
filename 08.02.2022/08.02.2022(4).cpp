#include <iostream>
using namespace std;
/*Программа будет показывать правильный результат только при 4+ различных чисел
(как и требовалось по условию)*/

int proverka(int num, int i, int *max1, int *max2, int *min1, int *min2) {
    if (i == 1) {
        *max1 = num;
        *max2 = num;
        *min1 = num;
        *min2 = num;
    }
    if (*max1 != num && *max1 < num) {
        *max2 = *max1;
        *max1 = num;
    }
    if (*max2 != num && *max2 < num && num < *max1) {
        *max2 = num;
    }
    if (*min1 != num && *min1 > num) {
        *min2 = *min1;
        *min1 = num;
    }
    if (*min2 != num && *min2 > num && *min1 < num) {
        *min2 = num;
    }
    return 0;
}

int main()
{
    int n, num, max1, max2, min1, min2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        proverka(num, i, &max1, &max2, &min1, &min2);
    }
    cout << "The sum of the two maximum digits: " << max1 + max2 << '\n';
    cout << "The sum of the two minimum digits: " << min1 + min2;
    return 0;
}
