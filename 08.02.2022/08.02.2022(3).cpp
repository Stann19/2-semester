#include <iostream>
using namespace std;
/*Я считаю, что студенты выстроились по убыванию роста, т.е. при правильном вводе каждое следующие число меньше предыдущего*/

int proverka(int a, int num, int *i) {
    if (a != -1 && a < num) {
        *i = *i + 1;
    }
    return 0;
}

int main()
{
    int num, a, i;
    i = 0;
    num = -1;
    a = -1;
    while (num != 0) {
        cin >> num;
        proverka(a, num, &i);
        a = num;
    }
    cout << i;
    return 0;
}
