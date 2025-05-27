import nltk
import re

input_program = input("enter Your code: ");
input_program_token= nltk.wordpunct_tokenize(input_program);

print(input_program_token);


RE_Keywords = "auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|string|class|struc|include"
RE_Operators = "(\++)|(-)|(=)|(\*)|(/)|(%)|(--)|(<=)|(>=)"
RE_Numerals = "^(\d+)$"
RE_Special_Characters = "[\[@&~!#$\^\|{}\]:;<>?,\.']|\(\)|\(|\)|{}|\[\]|\""
RE_Identifiers = "^[a-zA-Z_]+[a-zA-Z0-9_]*"
RE_Headers = "([a-zA-Z]+\.[h])"

for token in input_program_token:
    if(re.findall(RE_Keywords,token)):
        print(token,"-->Keyword")
    elif(re.findall(RE_Operators,token)):
        print(token,"-->Operator")
    elif(re.findall(RE_Identifiers,token)):
        print(token,"-->Identifier")
    elif(re.findall(RE_Numerals,token)):
        print(token,"-->Numerals")
    elif(re.findall(RE_Special_Characters,token)):
        print(token,"-->Special Character")
    else:
        print("unknown value")