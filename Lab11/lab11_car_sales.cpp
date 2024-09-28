#include <cstdlib>

#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <map>

class Car {
    friend std::ostream &operator<<(std::ostream &out, const Car &car);
public:
    explicit Car(std::string m = "Ford", std::string l = "", int ml = 0) :
        model(std::move(m)),
        license(!l.empty() ? std::move(l) : (rand() % 2 ? "FOO-" : "BAR-") + std::to_string(rand() % 999 + 1)),
        mileage(ml > 0 ? ml : rand() % 10000) {}

    ~Car() { std::cout << model << " " << license << " deleted" << std::endl; }
    void Read();
    const std::string &GetLicense() const { return license; }

private:
    std::string model;
    std::string license;
    int mileage;
};

void Car::Read() {
    model = "Seat";
    license = (rand() % 2 ? "ZAP-" : "ZIP-") + std::to_string(rand() % 999 + 1);
    mileage = 10000 + rand() % 10000;
}

std::ostream &operator<<(std::ostream &out, const Car &car) {
    out << "Model: " << car.model << std::endl << "License: " << car.license << std::endl << "Mileage: " << car.mileage << std::endl;
    return out;
}

class Website {
public:
    explicit Website(std::string n = "carweb.com") : name(std::move(n)) {}
    ~Website() { std::cout << name << " deleted" << std::endl; }

    void add(const std::shared_ptr<Car> &car) {
        listing.push_back(car);
    }

    void print(std::ostream &out = std::cout) {
        out << name << std::endl;
        for (auto it = listing.begin(); it != listing.end();) {
            if (auto car = it->lock()) {
                out << *car;
                ++it;
            } else {
                it = listing.erase(it);
            }
        }
        out << name << " end of list" << std::endl;
    }

private:
    std::vector<std::weak_ptr<Car>> listing;
    std::string name;
};

class Dealer {
    friend std::ostream &operator<<(std::ostream &out, const Dealer &dealer);
public:
    explicit Dealer(std::string name_ = "John Doe") : name(std::move(name_)) {}
    ~Dealer() { std::cout << name << " deleted" << std::endl; }

    void buy() {
        auto car = std::make_shared<Car>();
        car->Read();
        add(car);
    }

    void sell() {
        std::cout << *this;
        std::cout << "Enter license of car you want to buy: " << std::flush;

        std::string license;
        std::cin >> license;

        auto ci = std::find_if(cars.begin(), cars.end(), [&license](const std::shared_ptr<Car> &c) {
            return c->GetLicense() == license;
        });

        if (ci != cars.end()) {
            cars.erase(ci);
        }
    }

    void add(const std::shared_ptr<Car> &car) {
        cars.push_back(car);
        for (auto &site : sites) {
            site->add(car);
        }
    }

    void add_site(const std::shared_ptr<Website> &site) {
        sites.push_back(site);
    }

private:
    std::string name;
    std::vector<std::shared_ptr<Car>> cars;
    std::vector<std::shared_ptr<Website>> sites;
};

std::ostream &operator<<(std::ostream &out, const Dealer &dealer) {
    out << dealer.name << "'s cars for sale" << std::endl;
    for (const auto &car : dealer.cars) {
        out << *car;
    }
    out << "End of " << dealer.name << "'s cars listing" << std::endl;
    return out;
}

void car_sales() {
    std::cout << "Car sales started" << std::endl;

    auto wa = std::make_shared<Website>("www.autos.com");
    auto wb = std::make_shared<Website>("www.bilar.com");
    auto a = std::make_shared<Dealer>("Alan Aldis");
    auto b = std::make_shared<Dealer>("Bill Munny");

    {
        auto wc = std::make_shared<Website>("www.cars.com");
        auto c = std::make_shared<Dealer>("Casey Ball");

        a->add_site(wa);
        a->add_site(wb);
        b->add_site(wb);
        b->add_site(wc);
        c->add_site(wa);
        c->add_site(wb);
        c->add_site(wc);

        a->buy();
        a->buy();
        a->buy();
        a->buy();

        b->buy();
        b->buy();
        b->buy();

        c->buy();
        c->buy();

        wa->print();
        wb->print();
        wc->print();

        std::cout << *a << *b << *c << std::endl;

        a->sell();

        std::cout << *a << *b << *c << std::endl;

        wa->print();
        wb->print();
        wc->print();
    }

    wa->print();
    wb->print();

    std::cout << "Car sales ended" << std::endl;
}

int main() {
    srand(time(nullptr));
    car_sales();
    return 0;
}
