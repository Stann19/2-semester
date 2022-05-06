#include <iostream>
using namespace std;

struct object {
    double load;
    double utility;
    double alpha;
};

void input(object a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Load ";
        cin >> a[i].load;
        cout << "utility ";
        cin >> a[i].utility;
        a[i].alpha = (a[i].utility) / (a[i].load);
    }
}

void osnov(object a[], int n, int dload) {
    double sum_utility = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            if (a[i].alpha < a[j].alpha) {
                object b;
                b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    int i = 0;
    while (a[i].load <= dload) {
        cout << a[i].load << " " << a[i].utility << " " << '\n';
        dload -= a[i].load;
        sum_utility += a[i].utility;
        i++;
    }
    if (i < n) {
        cout << dload << " " << dload * a[i].alpha << " " << '\n';
        sum_utility += dload * a[i].alpha;
    }
    cout << '\n' << "total utility: " << sum_utility;
    delete[] a;
}

int main()
{
    int n;
    cin >> n;
    int dload;
    cin >> dload;
    object* a = new object[n];
    input(a, n);
    osnov(a, n, dload);
    return 0;
}
