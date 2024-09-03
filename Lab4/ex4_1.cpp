#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <algorithm>
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

    bool operator<(const House& other) const {
        return (price / area) < (other.price / other.area);
    }
};

int main() {
    vector<House> houses;
    
    //House 1 Information
    cout << "Enter house 1 information\n";
    string address;
    double area;
    int price;

    cout << "Enter address:";
    getline(cin, address);
    cout << "Enter area: ";
    cin >> area;
    cout << "Enter price: ";
    cin >> price;
    houses.emplace_back(address, area, price);

    //House 2 Information
    House house2;
    cout << "Enter house 2 information\n";
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    house2.setAddress(address);
    cout << "Enter area: ";
    cin >> area;
    house2.setArea(area);
    cout << "Enter price: ";
    cin >> price;
    house2.setPrice(price);
    cin.ignore();
    houses.push_back(house2);

    //House 3 Information
    House house3;
    cout << "Enter information for house 3 (using input operator):" << endl;
    cin >> house3;
    houses.push_back(house3);

    //House 4 and 5 Information
    House house4, house5;
    cout << "Enter house4 Information\n";
    cin.ignore();
    cin >> house4;
    houses.push_back(house4);

    cout << "Enter house5 Information\n";
    cin >> house5;
    houses.push_back(house5);

    sort(houses.begin(), houses.end());

    for (auto& house : houses) {
        cout << house << endl;
    }
    return 0;
}