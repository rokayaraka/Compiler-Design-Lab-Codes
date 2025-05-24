#include <bits/stdc++.h>
using namespace std;

const string keywords[32] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"

}; 

vector<string> toToken(string s)
{
    string s1;
    vector<string> tokens;
    string word;
    for (auto i : s)
    {
        if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
        {
            word += i;
        }
        else if (!word.empty())
        {
            tokens.push_back(word);
            word.clear();
        }
    }

    if (!word.empty())
    {
        tokens.push_back(word);
    }
    return tokens;
}

int main()
{
    ifstream file("newfile.txt");
    if (!file)
    {
        cout << "not found";
        return 1;
    }
    string line;
    map<string, int> tokens;
    while (getline(file, line))
    {
        vector<string> lineToken = toToken(line);
        for (auto token : lineToken)
        {
            tokens[token]++;
        }
    }

    cout << "Tokens and how many used : " << endl;

    for (auto i : tokens)
    {
        for (auto key : keywords)
        {
            if (i.first == key)
            {
                cout << i.first << " " << i.second << endl;
            }
        }
    }
}