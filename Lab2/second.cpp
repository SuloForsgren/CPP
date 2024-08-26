#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

int main() {
    fs::path path;
    vector<string> names;
    string input;

    while (true) {
        cout << "Enter directory name: ";
        getline(cin, input);

        if (input.empty()) {
            break;
        }
        else {
            names.push_back(input);
        }
    }
    for (const auto name: names) {
        path /= name;   
    }
    
    fs::create_directories(path);
    ofstream outFile(path/"result.txt");
    fs::path absoluteFilePath = fs::absolute(path);
    outFile << absoluteFilePath <<"\n";
    for (auto name: names) {
        outFile << name << "\n";
    }
    outFile << path.relative_path();

    return 0;
}