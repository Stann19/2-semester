#include <iostream>
using namespace std;

int dlina(int i, int (&c)[10], int a, int &b) {
	for (i = 0; a / 10 != 0; i++) {
		c[i] = a % 10;
		a = a / 10;
		b++;
	}
	c[b - 1] = a % 10;
	return 0;
}
int pouzirok(int b, int (&c)[10], int i, int j) {
	int d;
	for (i = 0; i < b - 1; i++) {
		for (j = 0; j < b - i - 1; j++) {
			if (c[j] > c[j + 1]) {
				d = c[j];
				c[j] = c[j + 1];
				c[j + 1] = d;
			}
		}
	}
	return 0;
}

int main()
{
	const int a = 4057;
	int b;
	int i;
	int j;
	b = 1;
	j = 0;
	i = 0;
	int c[10];
	dlina(i, c, a, b);
	pouzirok(b, c, i, j);
	for (i = 0; i<b; i++) {
		cout << c[i];
	}
	return 0;
}
