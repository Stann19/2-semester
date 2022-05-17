#include <iostream>
using namespace std;

void input(int a[], int n) {
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

int osnov(int a[], int n, int mem[]) {
	if (n == 1) {
		mem[n] = 1;
		return mem[n];
	}
	if (n > 1 && a[n - 1] > a[n - 2]) {
		mem[n - 1] = osnov(a, n - 1, mem) + 1;
		return mem[n - 1];
	}
	else mem[n - 1] = osnov(a, n - 1, mem);
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n] {0};
	input(a, n);
	int* mem = new int[n]{ 0 };
	cout << osnov(a, n, mem);
	delete[] a;
	delete[] mem;
}
