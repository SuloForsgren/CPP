#include <iostream>
#include <string>
#include <vector>
#include <memory>
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
    string getAddress() const {return address;}
};

class Apartment {
private:
    shared_ptr<House> housePtr;
    int apartmentNumber;
    int apartmentSize;
    int apartmentRent;
public:
    Apartment(shared_ptr<House> hPtr, int apNumber, int apSize, int apRent): 
    housePtr(hPtr), apartmentNumber(apNumber), apartmentSize(apSize), apartmentRent(apRent) {}

    bool operator<(const Apartment& other) const {
        return this->apartmentRent < other.apartmentRent;
    }

    void printApartment() const {
        cout << "Address: " << housePtr->getAddress()
        << "\nApartment number: " << apartmentNumber 
        << "\nApartment size: " << apartmentSize << "m²"
        << "\nApartment rent: " << apartmentRent << "€" << "\n\n";
    }
};

int main() {
    shared_ptr<House> house1 = make_shared<House>("talo1", 11.1, 10000);
    shared_ptr<House> house2 = make_shared<House>("talo2", 22.2, 20000);

    vector<Apartment> apartments;

    apartments.emplace_back(house1, 101, 250, 300000);
    apartments.emplace_back(house1, 102, 750, 650000);
    apartments.emplace_back(house1, 103, 400, 400000);

    apartments.emplace_back(house2, 201, 1250, 3000000);
    apartments.emplace_back(house2, 202, 1750, 6500000);
    apartments.emplace_back(house2, 203, 1400, 4000000);
    apartments.emplace_back(house2, 204, 950, 100000);

    sort(apartments.begin(), apartments.end());

    for (const auto& apartment:apartments) {
        apartment.printApartment();
    }

    return 0;
}