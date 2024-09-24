#include <iostream>  
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>

using namespace std;

class RandGen_2 {
public:
    RandGen_2(const int min, const int max) : min(min), max(max), numbers() {}
    int operator()();
private:
    vector<int> numbers;
    const int min, max;
};

int RandGen_2::operator()() {
    int number;
    do {
        number = rand() % (max - min + 1) + min;
    } 
    while (find(numbers.begin(), numbers.end(), number) != numbers.end());
    numbers.push_back(number);
    return number;
}

void printMatching(int element) {
    cout << element << "\n";
}
    
void test_generator(UniqueRng ur, int count);

int main(void) {
    UniqueRng randGen(5, 13);
    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13); // this will cause exception
    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70); // this will cause exception

    return 0;
}