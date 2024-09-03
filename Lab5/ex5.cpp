#include <iostream>  
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>

using namespace std;

// Ordinary function
/*int randGen_1() {
    return rand() % 10 + 1;
}*/

// Function object
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

int main() {
    srand(time(NULL)); 

    vector<int> lotto(10);
    vector<int> vikingLotto(10);
    vector <int> euroJackpot(10);
    
    RandGen_2 genLotto(1, 10);
    RandGen_2 genVikingLotto(1, 10);
    RandGen_2 genEurojackpot(1, 50);

    generate(lotto.begin(), lotto.end(), genLotto);
    generate(vikingLotto.begin(), vikingLotto.end(), genVikingLotto);
    generate(euroJackpot.begin(), euroJackpot.end(), genEurojackpot);

    cout << "Lotto: ";
    copy(lotto.begin(), lotto.end(), ostream_iterator<int>(cout, " "));
    cout << std::endl;

    cout << "Viking lotto: ";
    copy(vikingLotto.begin(), vikingLotto.end(), ostream_iterator<int>(cout, " "));
    cout << std::endl;

    cout << "Eurojackpot: ";
    copy(euroJackpot.begin(), euroJackpot.end(), ostream_iterator<int>(cout, " "));
    cout << std::endl;

    vector<int> intersection(min(lotto.size(), vikingLotto.size()));
    auto it = set_intersection(lotto.begin(), lotto.end(), vikingLotto.begin(), vikingLotto.end(), intersection.begin());
    intersection.resize(it - intersection.begin());

    for_each(intersection.begin(), intersection.end(), printMatching);
    cout << endl;
    
    return 0;
}