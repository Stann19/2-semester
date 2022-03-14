#include <iostream>
using namespace std;

void max_number(int& a, int& i) {
	int b;
	cin >> b;
	if (b == 0) {
		cout << i;
		return;
	}
	if (a == b) i++;
	if (a < b) {
		a = b;
		i = 1;
	}
	max_number(a, i);
}

void main()
{
	int a = 0;
	int i = 0;
	max_number(a, i);
}

