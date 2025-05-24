#include <bits/stdc++.h>
using namespace std;

string toRemovecmnt(string s)
{
    int n = s.length();
    string res;
    bool s_line = false;

    for (int i = 0; i < n; ++i)
    {
        if (s_line)
        {
            if (s[i] == '\n')
                s_line = false;
            continue;
        }

        if (i + 1 < n && s[i] == '/' && s[i + 1] == '/')
        {
            s_line = true;
            i++;
            continue;
        }

        res += s[i];
    }

    return res;
}

int main()
{
    ifstream filename("new.txt", ios::in);
    if (!filename)
    {
        cout << "File not found" << endl;
        return 1;
    }

    string line;
    map<string, int> tokens;

    while (getline(filename, line))
    {
        string cleaned_line = toRemovecmnt(line);
        cout << cleaned_line << endl;
    }

    filename.close();
    return 0;
}
