#include <iostream>
using namespace std;

void swap(int m[], int n1, int n2) {
	int tmp = m[n1];
	m[n1] = m[n2];
	m[n2] = tmp;
}

void change_max(int m[], int n, int i) {
	int max_root = i;
	if ((2 * i + 1 < n) && (m[max_root] < m[2 * i + 1])) max_root = 2 * i + 1;
	if ((2 * i + 2 < n) && (m[max_root] < m[2 * i + 2])) max_root = 2 * i + 2;
	if (max_root != i) {
		swap(m, i, max_root);
		change_max(m, n, max_root);
	}
	else return;
}

void osnova(int m[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) change_max(m, n, i); 
	for (int i = n - 1; i >= 0; i--){
		swap(m, 0, i);
		change_max(m, i, 0);
	}
}

int main()
{
	const int n = 10;
	int m[n];
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	osnova(m, n);
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << m[i] << '\t';
	}
}
