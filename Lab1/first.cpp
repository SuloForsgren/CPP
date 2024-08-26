#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> integers;
    int index = 1;
    int length = 0;
    int input = 0;
    cout << "How many numbers you want to enter? ";
    cin >> length;
    for(int i = 0; i < length; i++) {
        cout << "Enter number" << "[" << index << "] ";
        cin >> input;
        integers.push_back(input);
    }
    cout << "You entered: ";
    for (auto number: integers) {
        cout << number;
        if (index < integers.size()) {
            std::cout << ",";
            index++;
        }
    }
    cout << "\n";
    return 0;
}