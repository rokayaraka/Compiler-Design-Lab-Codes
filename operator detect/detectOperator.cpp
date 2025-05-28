#include<bits/stdc++.h>
using namespace std;
const vector<string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=",
    "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "++", "--", "+=", "-=", "*=", "/=", "%="
};

vector<string> detectOperators(const string& line) {
    vector<string> found;
    for (const string& op : operators) {
        size_t pos = line.find(op);
        while (pos != string::npos) {
            found.push_back(op);
            pos = line.find(op, pos + 1);
        }
    }
    return found;
}
int main()
{
    ifstream file("operator.txt");
    if (!file) {
        cout << "File not found." << endl;
        return 1;
    }

      string line;
    map<string, int> operatorFreq;
    while(getline(file,line)){


    vector<string> ops = detectOperators(line);
        for (const string& op : ops) {
            operatorFreq[op]++;
        }
    }
    for (const auto& op : operatorFreq) {
        cout << op.first << " " << op.second << endl;
    }
    file.close();

}