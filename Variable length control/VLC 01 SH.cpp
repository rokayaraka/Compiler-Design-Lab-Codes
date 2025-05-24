//Variable length control:
#include<bits/stdc++.h>
using namespace std;
vector<string> toToken(string s)
{
    vector<string> tokens;
    string word;
    for(char i :s)
    {
        if((i>='a'&&i<='z')||(i>='A'&&i<='Z')||(i>='0'&&i<='9'))
        {
            word+=i;
        }
        else if(!word.empty())
        {
            tokens.push_back(word);
            word.clear();
        }

        if(!(i>='a'&&i<='z')||(i>='A'&&i<='Z')||(i>='0'&&i<='9')){
            string temp;
            temp+=i;
            tokens.push_back(temp);
        }
    }
    if(!word.empty()){
        tokens.push_back(word);
        word.clear();
    }
    return tokens;
}
string variableControl(string s,int length)
{
    string controledString;
    vector<string>tokens=toToken(s);
    for(auto i:tokens)
    {
        if(i.size()>length)
        {
            i.erase(length,i.size());
            controledString+=i;
        }
        else{
            controledString+=i;
        }
    }
    return controledString;

}

int main()
{
    int fixLength;
    cout<<"Enter variable max length:";
    cin>>fixLength;
    ifstream file("new.txt");
    if(!file){
        cout<<"file Not found\n";
        return 1;
    }
    string lineString,fullString;
    bool counter=false;
    while(getline(file,lineString)){
        if(counter)
        {
           
            fullString+=variableControl(lineString,fixLength);
            fullString+='\n';
            continue;
        }
        if((lineString=="{"|| lineString[lineString.size()-1]=='{')&& !counter)
        {
            counter=true;
            fullString+=lineString;
            fullString+='\n';
            continue;
           
        }
        fullString+=lineString;
        fullString+='\n';
       
    }
    cout<<fullString;

    file.close();

}
