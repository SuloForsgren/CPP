#include <iostream>
#include <deque>
using namespace std;

class RunningAverage{
    private:
        deque<int> values;
    public:
        RunningAverage(int avg) {};

        void add_value(int value) {
            if (this->values.size() == 5) {
                this->values.pop_back();
            }
            this->values.push_front(value);
        }

        double get_average() {
            int sum = 0;
            for (auto value : this->values) {
                sum+=value;
            }
            return static_cast<double>(sum)/this->values.size();
        }
};


int main() {
    RunningAverage avg(5);
    int input = 0;
    while (true) {
        cout << "Enter number or zero to stop: ";
        cin >> input;

        if (input == 0) {
            break;
        }
        else {
            avg.add_value(input);
            cout << avg.get_average() << endl;
        }
    }
    return 0;
}