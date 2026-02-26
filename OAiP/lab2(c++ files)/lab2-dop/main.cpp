#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream file2("FILE2_dop.txt");
    ifstream file1("FILE1_dop.txt");
    string content;
    
    while (getline(file1, content)) {
        if (content[0] == 'A') {
            file2 << content << "\n";
        }
    }
    file1.close();
    file2.close();
    
    ifstream file2_2("FILE2_dop.txt");
    string word;
    int word_amount = 0;
    while (file2_2 >> word) {
        cout << word << endl;
        word_amount++;
    }
    
    cout << "Количество слов: " << word_amount << endl;
    
    return 0;
}
