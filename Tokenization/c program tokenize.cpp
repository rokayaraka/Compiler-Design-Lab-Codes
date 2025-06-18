#include <bits/stdc++.h>
using namespace std;

// C/C++ keywords
const unordered_set<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

// Operators and special symbols
const unordered_set<string> operators = {
    "+", "-", "*", "/", "%", "++", "--", "==", "!=", ">", "<", ">=", "<=",
    "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "=", "+=", "-=", "*=",
    "/=", "%=", "<<=", ">>=", "&=", "^=", "|=", "->", ".", "?", ":"
};

const unordered_set<string> special_symbols = {
    ",", ";", "(", ")", "{", "}", "[", "]", "#", "\\", "\"", "'"
};

// Function to check if a string is a number (integer or floating point)
bool isNumber(const string& s) {
    if (s.empty()) return false;

    size_t i = 0;
    if (s[0] == '-') {
        if (s.length() == 1) return false;
        i = 1;
    }

    bool hasDecimal = false;
    for (; i < s.size(); i++) {
        if (s[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

// Function to check if a string is a valid identifier
bool isIdentifier(const string& s) {
    if (s.empty() || isdigit(s[0])) return false;

    for (char c : s) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

// Tokenize a line of code
vector<pair<string, string>> tokenize(const string& line) {
    vector<pair<string, string>> tokens;
    string current;

    for (size_t i = 0; i < line.size(); ) {
        char c = line[i];

        // Skip whitespace
        if (isspace(c)) {
            i++;
            continue;
        }

        // Handle string literals
        if (c == '"') {
            current += c;
            i++;
            while (i < line.size() && line[i] != '"') {
                current += line[i];
                i++;
            }
            if (i < line.size()) {
                current += line[i];
                i++;
            }
            tokens.emplace_back("STRING_LITERAL", current);
            current.clear();
            continue;
        }

        // Handle character literals
        if (c == '\'') {
            current += c;
            i++;
            while (i < line.size() && line[i] != '\'') {
                current += line[i];
                i++;
            }
            if (i < line.size()) {
                current += line[i];
                i++;
            }
            tokens.emplace_back("CHAR_LITERAL", current);
            current.clear();
            continue;
        }

        // Handle comments
        if (c == '/' && i + 1 < line.size()) {
            if (line[i+1] == '/') { // Single line comment
                return tokens; // Skip rest of the line
            }
            if (line[i+1] == '*') { // Multi-line comment start
                // For simplicity, we'll just skip until */
                i += 2;
                while (i + 1 < line.size() && !(line[i] == '*' && line[i+1] == '/')) {
                    i++;
                }
                i += 2;
                continue;
            }
        }

        // Handle operators and special symbols (including multi-character ones)
        bool isOp = false;
        for (int len = 3; len >= 1; len--) {
            if (i + len <= line.size()) {
                string potential_op = line.substr(i, len);
                if (operators.count(potential_op) || special_symbols.count(potential_op)) {
                    if (!current.empty()) {
                        tokens.emplace_back("UNKNOWN", current);
                        current.clear();
                    }
                    tokens.emplace_back(potential_op == ";" ? "SEMICOLON" :
                                       potential_op == "," ? "COMMA" :
                                       "OPERATOR", potential_op);
                    i += len;
                    isOp = true;
                    break;
                }
            }
        }
        if (isOp) continue;

        // Handle alphanumeric sequences (identifiers, keywords, numbers)
        if (isalnum(c) || c == '_') {
            current += c;
            i++;
        } else {
            // Unknown character
            if (!current.empty()) {
                tokens.emplace_back("UNKNOWN", current);
                current.clear();
            }
            current += c;
            tokens.emplace_back("UNKNOWN", current);
            current.clear();
            i++;
        }
    }

    // Add the last token if exists
    if (!current.empty()) {
        tokens.emplace_back("UNKNOWN", current);
    }

    // Classify the collected tokens
    for (auto& token : tokens) {
        if (token.first == "UNKNOWN") {
            if (keywords.count(token.second)) {
                token.first = "KEYWORD";
            } else if (isNumber(token.second)) {
                token.first = "NUMBER";
            } else if (isIdentifier(token.second)) {
                token.first = "IDENTIFIER";
            }
        }
    }

    return tokens;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    map<string, int> token_counts;
    map<string, set<int>> token_lines;

    string line;
    int line_number = 0;

    while (getline(file, line)) {
        line_number++;
        auto tokens = tokenize(line);

        for (const auto& token : tokens) {
            token_counts[token.first + ": " + token.second]++;
            token_lines[token.first + ": " + token.second].insert(line_number);
        }
    }

    // Print token statistics
    cout << "Token counts:" << endl;
    cout << "----------------------------------------" << endl;
    for (const auto& entry : token_counts) {
        cout << setw(20) << left << entry.first << " : " << entry.second << " occurrences";
        cout << " (Lines: ";
        for (int ln : token_lines[entry.first]) {
            cout << ln << " ";
        }
        cout << ")" << endl;
    }

    // Print summary by token type
    cout << "\nSummary by token type:" << endl;
    cout << "----------------------------------------" << endl;
    map<string, int> type_counts;
    for (const auto& entry : token_counts) {
        size_t colon = entry.first.find(':');
        string type = entry.first.substr(0, colon);
        type_counts[type] += entry.second;
    }

    for (const auto& entry : type_counts) {
        cout << setw(15) << left << entry.first << " : " << entry.second << endl;
    }

    return 0;
}
