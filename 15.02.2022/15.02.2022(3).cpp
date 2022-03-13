#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void vvod_massiva(int i, int n, int w, int h, char matrix[], int m_x[], int m_y[])
{
    for (i = 0; i < w * h; i++) {
        matrix[i] = '0';
    }
    for (int i = 0; i < n; i++) {
        do {
            m_x[i] = rand() % w;
            m_y[i] = rand() % h;
        } while (matrix[m_x[i] + m_y[i] * w] == '1');
        matrix[m_x[i] + m_y[i] * w] = '1';
    } 
}

void dislocation_move(int i, int j, int n, int m_x[], int m_y[], char matrix[], int *death, int *a, int w, int h) {
    for (i = 0; i < n; i++) {
        if (matrix[m_x[i] + m_y[i] * w] == '1' && h != 1) {
            int mov = rand() % 4;
            if (mov == 0 && matrix[m_x[i] + m_y[i] * w] == '1') {
                if (matrix[m_x[i] + 1 + m_y[i] * w] == '0') {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = '0';
                    m_x[i] = m_x[i] + 1;
                    matrix[m_x[i] + m_y[i] * w] = '1';
                }
            }
            else if (mov == 1 && matrix[m_x[i] + m_y[i] * w] == '1') {
                if (matrix[m_x[i] - 1 + m_y[i] * w] == '0') {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = '0';
                    m_x[i] = m_x[i] - 1;
                    matrix[m_x[i] + m_y[i] * w] = '1';
                }
            }
            else if (mov == 2 && matrix[m_x[i] + m_y[i] * w] == '1') {
                if (matrix[m_x[i] + (m_y[i] + 1) * w] == '0') {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = '0';
                    m_y[i] = m_y[i] + 1;
                    matrix[m_x[i] + m_y[i] * w] = '1';
                }
            }
            else if (mov == 3 && matrix[m_x[i] + m_y[i] * w] == '1') {
                if (matrix[m_x[i] + (m_y[i] - 1) * w] == '0') {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = '0';
                    m_y[i] = m_y[i] - 1;
                    matrix[m_x[i] + m_y[i] * w] = '1';
                }
            }
        }
        else if (matrix[m_x[i] + m_y[i] * w] == '1' && h == 1) {
            int mov = rand() % 2;
            if (mov == 0 && matrix[m_x[i] + m_y[i] * w] == '1') {
                if (matrix[m_x[i] + 1 + m_y[i] * w] == '0') {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = '0';
                    m_x[i] = m_x[i] + 1;
                    matrix[m_x[i] + m_y[i] * w] = '1';
                }
            }
            else if (mov == 1 && matrix[m_x[i] + m_y[i] * w] == '1') {
                if (matrix[m_x[i] - 1 + m_y[i] * w] == '0') {
                    *a = *a +1;
                    matrix[m_x[i] + m_y[i] * w] = '0';
                    m_x[i] = m_x[i] - 1;
                    matrix[m_x[i] + m_y[i] * w] = '1';
                }
            }
        }
    }
}

void proverka(int i, int j, int n, int m_x[], int m_y[], char matrix[], int w, int h, int *death) {
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (((m_x[i] - m_x[j]) * (m_x[i] - m_x[j]) + (m_y[i] - m_y[j]) * (m_y[i] - m_y[j]) == 1)) {
                if (matrix[m_x[i] + m_y[i] * w] == '1' && matrix[m_x[j] + m_y[j] * w] == '1') {
                    *death = *death + 2;
                }
                else if ((matrix[m_x[i] + m_y[i] * w] == '1' && matrix[m_x[j] + m_y[j] * w] == '2') || (matrix[m_x[i] + m_y[i] * w] == '2' && matrix[m_x[j] + m_y[j] * w] == '1')) {
                    *death = *death + 1;
                }
                matrix[m_y[i] * w + m_x[i]] = '2';
                matrix[m_y[j] * w + m_x[j]] = '2';
            }
        }
        if ((m_x[i] == w - 1 && matrix[m_x[i] + m_y[i] * w] == '1') || (h != 1 && (m_y[i] == h - 1 && matrix[m_x[i] + m_y[i] * w] == '1')) || (m_x[i] == 0 && matrix[m_x[i] + m_y[i] * w] == '1') || (h != 1 && (m_y[i] == 0 && matrix[m_x[i] + m_y[i] * w] == '1'))) {
            matrix[m_y[i] * w + m_x[i]] = '2';
            *death = *death + 1;
        }
    }
}

void dislocation_step(int i, int j, int n, int m_x[], int m_y[], char matrix[], int w, int h) {
    int death = 0;
    int step = 0;
    while (death < n) {
        int c = 0;
        int a = 0;
        proverka(i, j, n, m_x, m_y, matrix, w, h, &death);
        dislocation_move(i, j, n, m_x, m_y, matrix, &death, &a, w, h);
        if (a > 0) {
            step++;
        }

    }
    cout << '\n';
    cout << death;
    cout << '\n';
    cout << step;
}


int main()
{
    srand(time(NULL));
    const int w = 5;
    const int h = 5;
    int i = 0;
    int j = 0;
    char matrix[w * h];
    const int n = 4;
    int m_x[n];
    int m_y[n];
    vvod_massiva(i, n, w, h, matrix, m_x, m_y);
    for (int i = 0; i < w * h; i++) {
        if (i % w == 0) {
            cout << '\n';
        }
        cout << matrix[i];
    }
    cout << '\n';
    dislocation_step(i, j, n, m_x, m_y, matrix, w, h);
    cout << '\n';
    for (int i = 0; i < w * h; i++) {
        if (i % w == 0) {
            cout << '\n';
        }
        cout << matrix[i];
    }
    return 0;
}
