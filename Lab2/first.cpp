#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
    
int main() {
    string integers;
    int index = 0;
    while (true) {
        cout << "Enter a line with integers or “stop”: ";
        getline(cin, integers);

        if (integers == "stop") {
            break;
        }

        stringstream stream(integers);
        int number, sum = 0;

        while (stream >> number) {
            sum += number;
            index++;
        }    
        cout << "Total of " << index << " numbers "  << "is "<< sum << "\n";
    }
}