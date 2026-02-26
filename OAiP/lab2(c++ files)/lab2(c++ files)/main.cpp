#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

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
    
    uintmax_t size1 = filesystem::file_size("FILE1.txt");
    uintmax_t size2 = filesystem::file_size("FILE2.txt");
    
    cout << "Размер файла FILE1 " << size1 << " байт" << endl;
    cout << "Размер файла FILE2 " << size2 << " байт" << endl;
    
    return 0;
}
