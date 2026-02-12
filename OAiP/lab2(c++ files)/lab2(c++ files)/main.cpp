#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("FILE1.txt");
    string line;
    bool even = false;
    
    fout << "1 2 3 4 5\n";
    fout << "6 7 8 9 10\n";
    fout << "11 12 13 14 15\n";
    fout << "16 17 18 19 20\n";
    fout.close();
    
    ifstream fin("FILE1.txt");
    ofstream fout2("FILE2.txt");

    while (getline(fin, line)) {
        if (even) {
            fout2 << line << endl;
        }
        even = !even;
    }
    
    fin.close();
    fout2.close();
    return 0;
}
