#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    string surname;
    int age;
    int classh;
    int number;
    int marks[30]{0};
};

void add_mark(student* a, int mark) {
    (* a).number += 1;
    (* a).marks[(* a).number - 1] = mark;
}

void input(student* a, float s[], int i) {
    cout << "name:";
    cin >> (*a).name >> (*a).surname;
    cout << "age:";
    cin >> (*a).age;
    cout << "class:";
    cin >> (*a).classh;
    cout << "number of marks:";
    cin >> (*a).number;
    cout << "marks:";
    for (int j = 0; j < (*a).number; j++) {
        cin >> (*a).marks[j];
        s[i] += (*a).marks[j];
    }
}

void output(student* a, float s[], int i) {
    cout << "name: " << (*a).name << " " << (*a).surname << '\n';
    cout << "age: " << (*a).age << '\n';
    cout << "class: " << (*a).classh << '\n';
    cout << "number of marks: " << (*a).number << '\n';
    cout << "marks: ";
    for (int j = 0; j < (*a).number; j++) {
        cout << (*a).marks[j] << " ";
    }
    cout << '\n';
}

int main()
{
    student stud1[5];
    float s[5]{ 0.f };
    for (int i = 0; i < 5; i++) {
        input(&stud1[i], s, i);
    }
    for (int i = 0; i < 5; i++) {
        while (s[i] / stud1[i].number < 4.5) {
            add_mark(&stud1[i], 5);
            s[i] += stud1[i].marks[stud1[i].number - 1];
        }
    }
    for (int i = 0; i < 5; i++) {
        output(&stud1[i], s, i);
    }
    return 0;
}
