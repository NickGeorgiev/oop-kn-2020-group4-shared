# include <iostream>
# include <cstring>

class SuperHero {
    char name[32];
    double power;

    public: 

    SuperHero() {
        strcpy(name, "");
        power = 0.0;
    }

    SuperHero(const char* _name, const double& _power) {
        strncpy(name, _name, 31);
    }

    SuperHero(const SuperHero& other) {
        strcpy(name, other.name);
        power = other.power;
    }
    
    SuperHero operator + (const SuperHero& other) {
        char nuName[2] = {name[0], other.name[0]};
        double nuPower = power + other.power;
        return SuperHero(nuName, nuPower);
    }

    bool operator < (const SuperHero& other) {
        return power < other.power;
    }

    bool operator > (const SuperHero& other) {
        return power > other.power;
    }
};

int main () {
    return 0;
}