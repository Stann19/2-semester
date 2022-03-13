#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void vvod_massiva(int i, int j, int n, int w, int h, int matrix[], int m_x[], int m_y[])
{
    for (i = 0; i < w * h; i++) {
        matrix[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        do {
            m_x[i] = rand() % w;
            m_y[i] = rand() % h;
        } while (matrix[m_x[i] + m_y[i] * w] == 1);
        matrix[m_x[i] + m_y[i] * w] = 1;
    }
}

void dislocation_move(int i, int j, int n, int m_x[], int m_y[], int matrix[], int* death, int* a, int w, int h) {
    for (i = 0; i < n; i++) {
        if (matrix[m_x[i] + m_y[i] * w] == 1 && h != 1) {
            int mov = rand() % 4;
            if (mov == 0 && matrix[m_x[i] + m_y[i] * w] == 1) {
                if (matrix[m_x[i] + 1 + m_y[i] * w] == 0) {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = 0;
                    m_x[i] = m_x[i] + 1;
                    matrix[m_x[i] + m_y[i] * w] = 1;
                }
            }
            else if (mov == 1 && matrix[m_x[i] + m_y[i] * w] == 1) {
                if (matrix[m_x[i] - 1 + m_y[i] * w] == 0) {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = 0;
                    m_x[i] = m_x[i] - 1;
                    matrix[m_x[i] + m_y[i] * w] = 1;
                }
            }
            else if (mov == 2 && matrix[m_x[i] + m_y[i] * w] == 1) {
                if (matrix[m_x[i] + (m_y[i] + 1) * w] == 0) {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = 0;
                    m_y[i] = m_y[i] + 1;
                    matrix[m_x[i] + m_y[i] * w] = 1;
                }
            }
            else if (mov == 3 && matrix[m_x[i] + m_y[i] * w] == 1) {
                if (matrix[m_x[i] + (m_y[i] - 1) * w] == 0) {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = 0;
                    m_y[i] = m_y[i] - 1;
                    matrix[m_x[i] + m_y[i] * w] = 1;
                }
            }
        }
        else if (matrix[m_x[i] + m_y[i] * w] == 1 && h == 1) {
            int mov = rand() % 2;
            if (mov == 0 && matrix[m_x[i] + m_y[i] * w] == 1) {
                if (matrix[m_x[i] + 1 + m_y[i] * w] == 0) {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = 0;
                    m_x[i] = m_x[i] + 1;
                    matrix[m_x[i] + m_y[i] * w] = 1;
                }
            }
            else if (mov == 1 && matrix[m_x[i] + m_y[i] * w] == 1) {
                if (matrix[m_x[i] - 1 + m_y[i] * w] == 0) {
                    *a = *a + 1;
                    matrix[m_x[i] + m_y[i] * w] = 0;
                    m_x[i] = m_x[i] - 1;
                    matrix[m_x[i] + m_y[i] * w] = 1;
                }
            }
        }
    }
}

void proverka(int i, int j, int n, int m_x[], int m_y[], int matrix[], int w, int h, int* death) {
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (((m_x[i] - m_x[j]) * (m_x[i] - m_x[j]) + (m_y[i] - m_y[j]) * (m_y[i] - m_y[j]) == 1)) {
                if (matrix[m_x[i] + m_y[i] * w] == 1 && matrix[m_x[j] + m_y[j] * w] == 1) {
                    *death = *death + 2;
                }
                else if ((matrix[m_x[i] + m_y[i] * w] == 1 && matrix[m_x[j] + m_y[j] * w] == 2) || (matrix[m_x[i] + m_y[i] * w] == 2 && matrix[m_x[j] + m_y[j] * w] == 1)) {
                    *death = *death + 1;
                }
                matrix[m_y[i] * w + m_x[i]] = 2;
                matrix[m_y[j] * w + m_x[j]] = 2;
            }
        }
        if ((m_x[i] == w - 1 && matrix[m_x[i] + m_y[i] * w] == 1) || (h != 1 && (m_y[i] == h - 1 && matrix[m_x[i] + m_y[i] * w] == 1)) || (m_x[i] == 0 && matrix[m_x[i] + m_y[i] * w] == 1) || (h != 1 && (m_y[i] == 0 && matrix[m_x[i] + m_y[i] * w] == 1))) {
            matrix[m_y[i] * w + m_x[i]] = 2;
            *death = *death + 1;
        }
    }
}


void dislocation_step(int i, int j, int n1, int n2, int m_x1[], int m_y1[], int m_x2[], int m_y2[], int matrix1[], int matrix2[], int w, int h) {
    int death1 = 0;
    int death2 = 0;
    int step1 = 0;
    int step2 = 0;
    while (death1 < n1) {
        int a1 = 0;
        proverka(i, j, n1, m_x1, m_y1, matrix1, w, h, &death1);
        dislocation_move(i, j, n1, m_x1, m_y1, matrix1, &death1, &a1, w, h);
        if (a1 > 0) {
            step1++;
        }

    }
    while (death2 < n2) {
        int a2 = 0;
        proverka(i, j, n2, m_x2, m_y2, matrix2, w, h, &death2);
        dislocation_move(i, j, n2, m_x2, m_y2, matrix2, &death2, &a2, w, h);
        if (a2 > 0) {
            step2++;
        }

    }
    cout << '\n';
    cout << "death1: " << death1 << ' ' << "death2: " << death2;
    cout << '\n';
    cout << "step1: " << step1 << ' ' << "step2: " << step2;
    if (step1 >= step2) {
        cout << '\n';
        cout << "total steps:" << step1;
    }
    else if (step1 <= step2) {
        cout << '\n';
        cout << "total steps:" << step2;
    }
}


int main()
{
    srand(time(NULL));
    const int w = 7;
    const int h = 7;
    int i = 0;
    int j = 0;
    int matrix1[w * h];
    int matrix2[w * h];
    const int n1 = 7;
    const int n2 = 4;
    int m_x1[n1];
    int m_y1[n1];
    int m_x2[n2];
    int m_y2[n2];
    vvod_massiva(i, j, n1, w, h, matrix1, m_x1, m_y1);
    vvod_massiva(i, j, n2, w, h, matrix2, m_x2, m_y2);
    for (int i = 0; i < w * h; i++) {
        if (i % w == 0) {
            cout << '\n';
        }
        if (matrix2[i] != 0 && matrix1[i] == 0) {
            cout << ' ' << ' ' << matrix2[i] << '*' << '|';
        }
        else if (matrix1[i] != 0 && matrix2[i] == 0) {
            cout << ' ' << ' ' << matrix1[i] << ' ' << '|';
        }
        else if (matrix1[i] != 0 && matrix2[i] != 0) {
            cout << matrix1[i] << '&' << matrix2[i] << '*' << '|';
        }
        else if (matrix2[i] == 0 && matrix1[i] == 0) {
            cout << ' ' << ' ' << matrix2[i] << ' ' << '|';
        }
    }
    cout << '\n';
    dislocation_step(i, j, n1, n2, m_x1, m_y1, m_x2, m_y2, matrix1, matrix2, w, h);
    cout << '\n';
    for (int i = 0; i < w * h; i++) {
        if (i % w == 0) {
            cout << '\n';
        }
        if (matrix2[i] != 0 && matrix1[i] == 0) {
            cout << ' ' << ' ' << matrix2[i] << '*' << '|';
        }
        else if (matrix1[i] != 0 && matrix2[i] == 0) {
            cout << ' ' << ' ' << matrix1[i] << ' ' << '|';
        }
        else if (matrix1[i] != 0 && matrix2[i] != 0) {
            cout << matrix1[i] << '&' << matrix2[i] << '*' << '|';
        }
        else if (matrix2[i] == 0 && matrix1[i] == 0) {
            cout << ' ' << ' ' << matrix2[i] << ' ' << '|';
        }
    }
    return 0;
}
