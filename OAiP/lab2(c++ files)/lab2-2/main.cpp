#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
    string line;
    ofstream output("output.txt");
    cout << "Введите строку, состоящую из чисел и слов: "; getline(cin, line);
    cout << "Вы ввели: " << line << endl;
    output << line;
    output.close();

    ifstream read("output.txt");
    string content;
    getline(read, content);
    read.close();
    
    cout << "Нечетные числа в файле: ";
    string part = "";
    bool found = false;
    int i = 0;
    
    while (i < content.length()) {
        while (i < content.length() && content[i] == ' ') {
            i++;
        }
        part = "";
        while (i < content.length() && content[i] != ' ') {
            part += content[i];
            i++;
        }
        if (!part.empty()) {
            bool isNum = true;
            for (char c : part) {
                if (!isdigit(c)) {
                    isNum = false;
                    break;
                }
            }
            
            if (isNum) {
                int num = stoi(part);
                if (num % 2 != 0) {
                    cout << num << " ";
                    found = true;
                }
            }
        }
    }
    
    return 0;
}
