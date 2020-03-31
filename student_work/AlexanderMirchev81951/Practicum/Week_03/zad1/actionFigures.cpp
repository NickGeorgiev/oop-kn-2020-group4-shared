#include <iostream>
#include <cstring>

class ActionFigure {
    private:

    char* name;
    int power;

    public:

    ActionFigure() {}

    ActionFigure(const char* name, const int power) {
        setName(name);
        setPower(power);
    }

    ActionFigure(const ActionFigure& other) {
        setName(other.getName());
        setPower(other.getPower());
    }

    ~ActionFigure() {
        std::cout << "Deleting " << this->getName() << std::endl;
        delete[] this->name;
    }

    void operator = (const ActionFigure& other) {
        delete [] this->name;

        this->setName(other.getName());
        this->setPower(other.getPower());
    }

    bool operator > (const ActionFigure& other) const {
        return this->getPower() > other.getPower();
    }

    bool operator < (const ActionFigure& other) const {
        return this->getPower() < other.getPower();
    }
 
    ActionFigure operator + (const ActionFigure& other) const {
        // determines how many letters should be taken from each figure's names
        const size_t nameLength = 6;

        char* name = new char[nameLength];
        strncpy(name, this->getName(), nameLength/2);
        strncat(name, other.getName(), nameLength/2);

        int power = this->getPower() + other.getPower();

        ActionFigure result(name, power);
        return result;
    }

    char* getName() const {
        return this->name;
    }

    int getPower() const {
        return this->power;
    }

    void setName(const char* name) {
        char* newName = new char[strlen(name)+1];
        strcpy(newName, name);

        this->name = newName;
    }

    void setPower(const int power) {
        this->power = power;
    } 
};

std::ostream& operator <<(std::ostream& out, const ActionFigure& figure) {
    out << "Action Figure \n Name: " << figure.getName() << ", Power: " << figure.getPower()<<" ";
    return out;
}

int main() {

}
