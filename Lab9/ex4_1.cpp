#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

class House{
private:
    string address;
    double area;
    int price;
public:
    House() : address(""), area(0.0), price(0) {};
    House(const string &addr, double ar, int pri) : address(addr), area(ar), price(pri) {}

    void setAddress(const string &addr) {address = addr;}
    void setArea(double ar) {area = ar;}
    void setPrice(int pr) {price = pr;}

    friend ostream& operator<<(ostream& os, const House& hs) {
        os << "Address: " << hs.address << " Size in m²: " << hs.area << " Price: " << hs.price;
        return os;
    }

    friend istream& operator>>(istream& is, House& hs) {
        string line;
        if (std::getline(is, line)) { 
            std::istringstream iss(line);  
            iss >> hs.address >> hs.area >> hs.price;
        }
        return is;
    }
};

int main() {
    vector<House> houses;
    
    cout << "Enter house 1 information: ";
    House house1;
    cin >> house1;
    houses.push_back(house1);

    for (auto& house : houses) {
        cout << house << endl;
    }
    return 0;
}