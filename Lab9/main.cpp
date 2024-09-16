#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Observer;

class Subject {
public:
 virtual void Attach(Observer *o) = 0; // Set
 virtual void Notify() = 0;
};
// Abstract interface of Observer
class Observer {
public:
 virtual void Update() = 0;
};

class Person {
public:
    Person(const char *name = "nobody"): name(name) {};
    virtual ~Person() = default;
    
    virtual void identity() const {
        cout << name << endl;
    };

    virtual void interrogate() {
         //Does nothing really here..
    };
private:
    std::string name;
};

class Spy : public Person, public Subject {
public:
    Spy(const char *name, const char *alias, int resistance)
        : Person(name), alias(alias), resistance(resistance) {}

    void set_identity(const char *newAlias) {
        alias = newAlias;
    }

    void identity() const override{
        if (resistance > 0) {
            cout << "My name is: " << alias << endl;
        }
        else {
            cout << "My name is: ";
            Person::identity();
            cout << "My alias is: " << alias << endl;
        }
    }

    void Attach(Observer *o) override {
        observers.push_back(o);
    }

    void Notify() override {
        for (auto &observer:observers) {
            observer->Update();
        }
    }

    void interrogate() override{
        if (resistance > 0) {
            --resistance;
        }
        if (resistance == 0) {
            Notify();
        }
    }
private:
    string alias;
    int resistance;
    vector<Observer*> observers; 
};

class Judge: public Person, public Observer {
public:
    Judge(const char *name): Person(name) {}
    void Update() override {
        cout << "[My name is : "; 
        identity();
        cout << " I'm sending a spy to prison!]\n";
    }
    
private:

};

int main(int argc, char** argv) {
    Person agent("James Bond");
    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);
    Judge judge("Judge Barnhill");
    spy.Attach(&judge);
    spy2.Attach(&judge);
    
    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy.interrogate();
        spy.identity();
    
    }
    spy.set_identity("Bill Munny");
    spy.identity();
    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();
    
    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy2.interrogate();
        spy2.identity();
    }
    return 0;
}