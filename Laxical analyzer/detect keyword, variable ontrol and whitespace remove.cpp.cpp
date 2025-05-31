#include<bits/stdc++.h>
using namespace std;


const unordered_set<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};


vector<string> tokenize(const string& s) {
    vector<string> tokens;
    string token;
    for (char c : s) {
        if (isalnum(c) || c == '_') {
            token += c;
        } else if (!token.empty()) {
            tokens.push_back(token);
            token.clear();
        }
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}


bool isValidVariable(const string& token) {

    if (token.empty()) return false;
    if (!(isalpha(token[0]) || token[0] == '_')) return false;


    for (size_t i = 1; i < token.size(); i++) {
        if (!(isalnum(token[i]) || token[i] == '_')) return false;
    }
    if (keywords.count(token)) return false;
    return true;
}

int main() {
    ifstream file("newFile.txt");
    if (!file) {
        cout << "File not found" << endl;
        return 1;
    }

    map<string, int> keywordCount;
    set<string> variables;
    string line;

    cout << "Lines with spaces removed:\n\n";
    vector<string> originalLines;


    while (getline(file, line)) {
        originalLines.push_back(line);

        string noSpaces = line;
        noSpaces.erase(remove(noSpaces.begin(), noSpaces.end(), ' '), noSpaces.end());
        cout << noSpaces << "\n";
    }


    for (const auto& origLine : originalLines) {
        vector<string> tokens = tokenize(origLine);
        for (const auto& token : tokens) {
            if (keywords.count(token)) {
                keywordCount[token]++;
            } else if (isValidVariable(token)) {
                variables.insert(token);
            }
        }
    }

    cout << "\nKeywords and their frequency:\n\n";
    for (const auto& [kw, count] : keywordCount) {
        cout << kw << " " << count << "\n";
    }

    cout << "\nValid variables identifier:\n\n";
    for (const auto& var : variables) {
        cout << var << "\n";
    }

    return 0;
}
