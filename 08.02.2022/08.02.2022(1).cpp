#include <iostream>
using namespace std;

int proverka(int num, int *c)
{
    if (num % 2 == 0 && num >= *c) {
        *c = num;
    }
    return 0;
}

int main()
{
    int num = 1;
    int c;
    c = num;
    while (num != 0)
    { 
      cin >> num;
      proverka(num, &c);
    }
    if (c != 1) {
        cout << c;
    }
    else {
        cout << 0;
    }
    return 0;
}
