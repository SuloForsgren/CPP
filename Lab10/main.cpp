#include <iostream>  
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <stdexcept>

using namespace std;

class UniqueRng {
public:
    UniqueRng(const int min, const int max) : min(min), max(max) {}
    int operator()();
private:
    vector<int> numbers;
    const int min, max;
};

int UniqueRng::operator()() {
    if (numbers.size() == (max - min + 1)) {
        throw runtime_error("Unable to process\n");
    }
    int number;
    do {
        number = rand() % (max - min + 1) + min;
    } 
    while (find(numbers.begin(), numbers.end(), number) != numbers.end());
    numbers.push_back(number);
    return number;
}

void test_generator(UniqueRng &ur, int count) {
    try {
        for(int i = 0; i < count; i++) {
            cout << ur() << " ";
        }
        cout << endl;
    }
    catch(const runtime_error& e) {
        cout << "exception " << e.what() << endl;
    }

}

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