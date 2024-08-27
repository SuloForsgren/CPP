#include <iostream>
#include <deque>
using namespace std;

class RunningAverage{
private:
    deque<int> values;
    int max_size;
public:
    RunningAverage(int avg) : max_size(avg) {};

    void add_value(int value) {
        if (values.size() == max_size) {
            values.pop_back();
        }
        values.push_front(value);
    }

    double get_average() {
        int sum = 0;
        for (auto value : values) {
            sum+=value;
        }
        return static_cast<double>(sum)/values.size();
    }
};


int main() {
    RunningAverage avg(5);
    int input = 0;
    while (true) {
        cout << "Enter number or zero to stop: ";
        cin >> input;

        if (input == 0) {
            cout << "Final average " << avg.get_average() << endl;
            break;
        }
        else {
            avg.add_value(input);
            cout << avg.get_average() << endl;
        }
    }
    
    return 0;
}