#include <iostream>
#include <cmath>
using namespace std;

void my_personal_swap(int* a, int* b) {
	int s;
	if (a == nullptr || b == nullptr) {
		return;
	}
	else {
		s = *a;
		*a = *b;
		*b = s;
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	my_personal_swap(&a, &b);
	cout << a << " " << b << endl;
	my_personal_swap(&a, nullptr);
	my_personal_swap(nullptr, &b);
	my_personal_swap(nullptr, nullptr);
	return 0;
}

