#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float mean(float const psi[], float const pdf[], float const dv, unsigned const size)
{
	float sum = 0.f;
	for (int i = 0; i < size; i++) sum += psi[i] * pdf[i];
	return dv * sum;
}

float recursive_sum(float psi[], float pdf[], unsigned size, unsigned start, float const dv) {
	if (size == 1)
	{
		return psi[start] * pdf[start] * dv;
	}
	return recursive_sum(psi, pdf, size / 2, start, dv) + recursive_sum(psi, pdf, size - size / 2, start + size / 2, dv);
}

float close_variables(float psi[], float pdf[], unsigned size, float const dv) {
	float* f = new float[size];
	for (int i = 0; i < size; i++) {
		f[i] = psi[i] * pdf[i] * dv;
	}
	for (int j = 1; size/j >= 1; j *= 2) {
		for (int i = 0; i + j < size; i += 2) {
			f[i] += f[i + j];
		}

	}
	float sum = f[0];
	delete[] f;
	return sum;
}

float kehen_sum(float psi[], float pdf[], unsigned const size, float const dv) {
	float sum = 0.f;
	float t = 0.f;
	for (unsigned i = 1; i < size; i++) {
		float y = psi[i] * pdf[i] - t;
		float z = sum + y;
		t = (z - sum) - y;
		sum = z;
	}
	return dv * sum;
}

float fma_sum(float psi[], float pdf[], unsigned const size, float const dv) {
	float sum = 0.f;
	for (unsigned i = 0; i < size; i++) sum = fma(pdf[i], psi[i], sum);
	return dv * sum;
}

double double_sum(float psi[], float pdf[], unsigned const size, float const dv) {
	double sum = 0;
	for (unsigned i = 0; i < size; i++) sum += (double)pdf[i] * (double)psi[i];
	return (double)dv * sum;
}

void fill_array(float psi[], float pdf[], unsigned const size, float const dv, unsigned T) {
	float const f_pi = 3.14159265359f;
	for (int i = 0; i < size; i++) {
		psi[i] = abs(i * dv - size / 40);
		pdf[i] = exp(-(psi[i]) * (psi[i]) / T) / sqrt(T * f_pi);
	}
}

void locomotive(float psi[], float pdf[], unsigned const size, float const dv) {
	for (int T = 1; T <= 500; T += 5) {
		fill_array(psi, pdf, size, dv, T);
		cout << setprecision(10) << fixed;
		if (T == 1) cout << "recursive_sum:" << '\n';
		if (T % 20 == 0) cout << '\n';
		cout << recursive_sum(psi, pdf, size, 0, dv) << " ";
	}
	cout << '\n';
	for (int T = 1; T <= 500; T += 5) {
		fill_array(psi, pdf, size, dv, T);
		cout << setprecision(10) << fixed;
		if (T == 1) cout << "close_variables:" << '\n';
		if (T % 20 == 0) cout << '\n';
		cout << close_variables(psi, pdf, size, dv) << " ";
	}
	cout << '\n';
	for (int T = 1; T <= 500; T += 5) {
		fill_array(psi, pdf, size, dv, T);
		cout << setprecision(10) << fixed;
		if (T == 1) cout << "kehen_sum:" << '\n';
		if (T % 20 == 0) cout << '\n';
		cout << kehen_sum(psi, pdf, size, dv) << " ";
	}
	cout << '\n';
	for (int T = 1; T <= 500; T += 5) {
		fill_array(psi, pdf, size, dv, T);
		cout << setprecision(10) << fixed;
		if (T == 1) cout << "fma_sum:" << '\n';
		if (T % 20 == 0) cout << '\n';
		cout << fma_sum(psi, pdf, size, dv) << " ";
	}
	cout << '\n';
	for (int T = 1; T <= 500; T += 5) {
		fill_array(psi, pdf, size, dv, T);
		cout << setprecision(10) << fixed;
		if (T == 1) cout << "double_sum:" << '\n';
		if (T % 20 == 0) cout << '\n';
		cout << double_sum(psi, pdf, size, dv) << " ";
	}
}

int main()
{
	unsigned size = 20000;
	float const dv = 0.03f;
	float *psi = new float[size];
	float *pdf = new float[size];
	locomotive(psi, pdf, size, dv);
	return 0;
}

