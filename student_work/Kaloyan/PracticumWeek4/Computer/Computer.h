#ifndef _COMPUTER_H
#define _COMPUTER_H

class Computer {
    char* brand;
    char* cpu;
    char* gpu;
    char* drive;
    double price;
    int quantity;

    void copy(const Computer& other);

    public:

    void setStr(const int& x, const char* str);

    Computer();
    Computer(const char*, const char*, const char*, const char*, const double&, const int&);
    Computer(const Computer&);

    Computer& operator = (const Computer&);

    ~Computer();

    bool operator == (const Computer& other) const;
    int getQuantity () const;
    void changeQuantity (const int& n);
    void print() const;
};
# endif
