
#include<bits/stdc++.h>
using namespace std;


int main() {
    string s;
    int state = 0, i = 0;
    char c;

    cout << "\nEnter a string: ";
    getline(cin, s);

    while (i < (int)s.length()) {
        c = s[i++];
        switch (state) {
            case 0:
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                    state = 2;
                else {
                    cout << "\n" << s << " is not recognised\n";
                    exit(0);
                }
                break;

            case 1:
                if (c == 'a')
                    state = 3;
                else if (c == 'b')
                    state = 4;
                else {
                    cout << "\n" << s << " is not recognised\n";
                    exit(0);
                }
                break;

            case 2:
                if (c == 'a') {
                    cout << "\n" << s << " is not recognised\n";
                    exit(0);
                }
                else if (c == 'b')
                    state = 2;
                else {
                    cout << "\n" << s << " is not recognised\n";
                    exit(0);
                }
                break;

            case 3:
                if (c == 'a')
                    state = 3;
                else if (c == 'b')
                    state = 2;
                else {
                    cout << "\n" << s << " is not recognised\n";
                    exit(0);
                }
                break;

            case 4:
                if (c == 'a') {
                    cout << "\n" << s << " is not recognised\n";
                    exit(0);
                }
                else if (c == 'b')
                    state = 5;
                else {
                    cout << "\n" << s << " is not recognised\n";
                    exit(0);
                }
                break;

            case 5:
                if (c == 'a') {
                    cout << "\n" << s << " is not recognised\n";
                    exit(0);
                }
                else if (c == 'b')
                    state = 2;
                else {
                    cout << "\n" << s << " is not recognised\n";
                    exit(0);
                }
                break;

            default:
                cout << "\n" << s << " is not recognised\n";
                exit(0);
        }
    }

    if (state == 0 || state == 1 || state == 3)
        cout << "\n" << s << " is accepted under rule 'a*'\n";
    else if (state == 2 || state == 4)
        cout << "\n" << s << " is accepted under rule 'a*b+'\n";
    else if (state == 5)
        cout << "\n" << s << " is accepted under rule 'abb'\n";

    return 0;
}
