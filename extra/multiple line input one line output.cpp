#include<bits/stdc++.h>
using namespace std;

int main()
{

    string line;
    string Merge;
    while(true)
    {
        getline(cin,line);
        if(line.empty())
        {
            break;
        }
        Merge+=line;
    }
    cout<<Merge<<endl;
}
