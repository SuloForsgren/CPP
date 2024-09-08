#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

class LimitedCounter : public Counter{
public:
    LimitedCounter(int value, int upperValue): value(value), upperValue(upperValue) {};

    void inc() override{
        if (value == upperValue){
            //Do nothing
        }
        else {
            ++value;
        }
    }

    void dec() override{
        if (value > 0) {
            --value;
        }
    }

    operator int() override{
        return value;
    }

private:
    int value;
    int upperValue;
};

class OverflowCounter : public Counter{
public:
    OverflowCounter(int value, int upperValue): value(value), upperValue(upperValue) {};

    void inc() override{
        if (value == upperValue) {
            value = 0;
        }
        else {
            ++value;
        }
    }
    void dec() override{
        if (value == 0) {
            value = upperValue;
        }
        else {
            --value;
        }
    }

    operator int() override{
        return value;
    }


private:
    int value;
    int upperValue;
};

// you need to implement this function
void UseCounter(Counter& ctr, int num) {
    if (num >= 0) {
        for (int i = 0; i < num; ++i) {
            ctr.inc();
        }
    }
    else {
        for (int i = 0; i < -num; ++i) {
            ctr.dec();
        }
    }
}

ostream& operator<<(ostream& os, Counter& ctr) {
    os << int(ctr);
    return os;
}


int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	cout << oc << endl;
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.dec();
	cout << oc << endl; // should display 8

	cout << lc << endl;
	lc.inc();
	cout << lc << endl;
	lc.dec();
	cout << lc << endl;
	for(int i = 0; i < 10; ++i) lc.inc();
	cout << lc << endl;
	UseCounter(lc, -9);
	cout << lc << endl;

	return 0;
}