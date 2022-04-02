#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    int group;
    int ses[5];
};

void checking(student stud1[]) {
    int l = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (stud1[i].ses[j] == 2) {
                cout << stud1[i].name << " " << stud1[i].group << '\n';
                l++;
                break;
            }
        }
    }
    if (l == 0) cout << "There are no students with a mark of 2";
}

int main()
{
    student stud1[2];
    for (int i = 0; i < 2; i++) {
            cout << "name:";
            cin >> stud1[i].name;
            cout << "group:";
            cin >> stud1[i].group;
            cout << "ses:";
            for (int j = 0; j < 5; j++) {
                cin >> stud1[i].ses[j];
            }
    }
    checking(stud1);
    return 0;
}

