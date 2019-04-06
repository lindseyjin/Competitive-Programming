using namespace std;
#include <iostream>
#include <string>

int main (int argc, char* argv[]) {
    string line;
    cin >> line;
    int count = 0, val;
    bool unique = true;

    if (!cin.eof())
    for (int x = 0; x < line.length(); x++) {
        val = line.at(x) - 'a';
        if (count & (1 << val)) {
            unique = false;
            break;
        }
        count |= ( 1 << val);
    }
    
    if (unique == true) cout << "Unique" << endl;
    else cout << "Not unique" << endl;
    return 1;
}