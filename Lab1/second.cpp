#include <iostream>
#include <string>
using namespace std;

void replace(string &input, char character) {
    for (auto &chr: input) {
        if (chr == character) {
            chr = '_';
        }
    }
}

int main() {
    string input;
    string character;
    
    while (true) {
        cout << "Enter a string: ";
        cin >> input;

        cout << "Enter character to replace or 'stop': ";
        cin >> character;
        if (character != "stop" && character.length() == 1) {
            replace(input, character[0]);
        }
        else if (character == "stop") {
            break;
        }
        cout << input << "\n";
    }
    return 0;
}