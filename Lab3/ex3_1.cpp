#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int integer = 0;
    string input;
    map<string, int> values;
    while (true) {
        cout << "Enter name or 'stop' or 'print': ";
        cin >> input;

        if (input.compare("stop") == 0) {
            break;
        }
        else if (input.compare("print") == 0) {
            map<string, int>::iterator it = values.begin();

            while (it != values.end()) {
                cout << it->first << " : " << it ->second << endl;
                it++;
            }
        }
        else {
            cout << "Enter integer: ";
            cin >> integer;
            values[input] = integer;
        }
    }

    return 0;
}