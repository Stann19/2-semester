#include <iostream>
#include <cmath>
using namespace std;

int proverka(int f[], unsigned N) {
	int d = N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (f[i] == -f[j] && f[i] > 0 && i - j > 0 && d > i - j) d = i - j;
		}
	}
	if (d == N) d = 0;
	delete[] f;
	return d;
}

int main()
{
	unsigned N;
	cin >>  N;
	int* f = new int[N];
	for (int i = 0; i < N; i++) cin >> f[i];
	cout << proverka(f, N);
}
