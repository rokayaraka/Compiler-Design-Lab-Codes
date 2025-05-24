#include <bits/stdc++.h>
using namespace std;
string removeComment(string s)
{
    string commentFreeString;
    for (int i = 0; i< s.size(); i++)
    {
        if (s[i] == '/' && s[i + 1] == '/')
        {
            i++;
            while (true)
            {
                i++;
                if (s[i] == '\n')
                {
                    commentFreeString += s[i];
                    break;
                }
            }
        }
        else if (s[i] == '/' && s[i + 1] == '*')
        {
            i++;
            while (true)
            {
                i++;
                if (s[i] == '*' && s[i + 1] == '/')
                {
                    i++;
                    break;
                }
            }
        }
        else
        {
            commentFreeString += s[i];
        }
    }
    return commentFreeString;
}
int main()
{
    ifstream file("new.txt");
    if (!file)
    {
        cout << "File not found";
        return 1;
    }
    string line, fullString;
    while (getline(file, line))
    {
        fullString += line;
        fullString += '\n';
    }
    fullString = removeComment(fullString);
    cout << fullString;
}