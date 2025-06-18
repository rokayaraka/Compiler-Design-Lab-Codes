// (ab)*

#include<bits/stdc++.h>
using namespace std;

int Length(char x[]) {
    int len = 0;
    // Calculate length of string manually
    while (x[len] != '\0') {
        len++;
    }
    return len;
}
int main()
{

    char x[10000];
    int k=0;
    while(k<5){
            cin.getline(x,10000);
            int len =LENGTH(x);

            int count=0;
             if (len == 1 && x[0] == 'a') {
            cout << "Acceptable\n";
        } else {
            // Check if the string starts with 'a' and contains only 'b' after that
            if (x[0] == 'a') {
                for (int i = 1; i < len; i++) {
                    if (x[i] == 'b') {
                        count++;
                    }
                }
                if (count == len - 1) {
                    cout << "Acceptable\n";
                } else {
                    cout << "Not Acceptable\n";
                }
            } else {
                cout << "Not Acceptable\n";
            }
        }
        k++;
    }


    }
