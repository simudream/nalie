
#include "Lexer.h"
#include "Keyword.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string fileContent;
    string line;
    ifstream file ("./Examples/Source.js");
    if(file.is_open()) {
        while (getline (file, line)) {
            cout << line << '\n';
        }
        file.close();
    }
    // AJSC::Lexer* lexer = new AJSC::Lexer(fileContent);
    // while( lexer->getNextToken() )
    // {
    //   cout << lexer->m_currentToken;
    // }
    // if(lexer->m_currentToken == AJSC::EOF_)
    // {
    //   printf("wefefw%d", AJSC::EOF_);

    // }
    return 0;
}
