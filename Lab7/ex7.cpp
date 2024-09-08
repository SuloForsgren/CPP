#include <iostream>
#include <string>
using namespace std;

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

    string getName() const{
        return name;
    }
private:
    std::string name;
};

class Spy : public Person {
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
            cout << "My name is: " << getName() << "\nMy alias is: " << alias << endl;
        }
    }

    void interrogate() override{
        if (resistance > 0) {
            --resistance;
        }
    }
private:
    string alias;
    int resistance;
};


int main(int argc, char** argv) {
    Person agent("James Bond");
    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);
    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();
    
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