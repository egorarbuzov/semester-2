#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string input;
    ofstream inputfile("input_dop.txt");
    cout << "Введите строку: ";
    getline(cin, input);
    inputfile << input;
    inputfile.close();
    
    ifstream readfile("input_dop.txt");
    string part;
    unsigned long size = 10000;
    string shortest;
    while (readfile >> part) {
        if (size > part.length()) {
            size = part.length();
            shortest = part;
        }
    }
    
    cout << "Самая короткая группа: " << shortest << endl;
    
    return 0;
}
