#include <iostream>
#include <string>

using namespace std;

#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'
#define IS_OPEN(x) ((x) == OPEN_BRACKET)
#define IS_CLOSE(x) ((x) == CLOSE_BRACKET)
#define NO_BRACKETS_MSG "В строке нет скобок"

int main() {
    string text;
    cout << "Введите строку со скобками: ";
    getline(cin, text);
    
    int counter = 0;
    bool correct = true;
    bool hasBrackets = false;
    
    for (int i = 0; i < text.length(); i++) {
        if (IS_OPEN(text[i]) || IS_CLOSE(text[i])) {
            hasBrackets = true;
        }
        
        if (IS_OPEN(text[i])) {
            counter++;
        }
        else if (IS_CLOSE(text[i])) {
            counter--;
            if (counter < 0) {
                correct = false;
                break;
            }
        }
    }
    
    if (!hasBrackets) {
        cout << NO_BRACKETS_MSG << endl;
    }
    else if (correct && counter == 0) {
        cout << "Скобки расставлены правильно" << endl;
    } else {
        cout << "Скобки расставлены неправильно" << endl;
    }
    
    return 0;
}
