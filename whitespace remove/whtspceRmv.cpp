#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = " hi , my name is raka.. .. ";
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    cout << str << endl;
}