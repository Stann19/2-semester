#include <iostream>
using namespace std;

int sequence_element1(int n);

int sequence_element2(int n);

int main()
{
    const int n = 16;
    cout << "M[n] = ";
    cout << sequence_element1(n);
    cout << '\n';
    cout << "F[n] = ";
    cout << sequence_element2(n);
}

int sequence_element2(int n) {
    if (n == 0) return 1;
    if (n > 0) {
        return n - sequence_element1(sequence_element2(n - 1));
    }
}

int sequence_element1(int n) {
    
    if (n == 0) return 0;
    if (n > 0) {
        return n - sequence_element2(sequence_element1(n - 1));
    }
}
