#include <iostream>
#include <new>
using namespace std;

int* my_slightly_dumb_reallocation(int* source, unsigned n_old, unsigned n_new) {
	void* raw_memory = operator new(sizeof(int) * n_new);
	int* f_arr = new(raw_memory) int[n_new];
	if (source != nullptr) {
		if (n_new <= n_old) for (int i = 0; i < n_new; i++) f_arr[i] = *(source + i);
		if (n_old < n_new)  for (int i = 0; i < n_old; i++) f_arr[i] = *(source + i);
		delete[] source;
		return f_arr;
	}
}

int main()
{
	unsigned int n, i;
	cin >> n;
	int* a = my_slightly_dumb_reallocation(NULL, 0, n / 2);
	for (i = 0; i < n / 2; i++)
		cin >> a[i];
	a = my_slightly_dumb_reallocation(a, n / 2, n);
	for (; i < n; i++)
		cin >> a[i];
	int sum = 0;
	for (i = 0; i < n; i++)
		sum += a[i];
	cout << sum << endl;
	a = my_slightly_dumb_reallocation(a, n, n / 2);
	a = my_slightly_dumb_reallocation(a, n / 2, 0);
	a = my_slightly_dumb_reallocation(a, 0, 0);
	return 0;
}
