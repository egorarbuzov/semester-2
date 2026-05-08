#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);
    
    stack<char> st;
    bool correct = true;
    
    for (char c : input) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                correct = false;
                break;
            }
            
            char top = st.top();
            st.pop();
            
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                correct = false;
                break;
            }
        }
    }
    
    if (!st.empty()) {
        correct = false;
    }
    
    if (correct) {
        cout << "Скобки расставлены верно" << endl;
    } else {
        cout << "Скобки расставлены не верно" << endl;
    }
    
    return 0;
}
