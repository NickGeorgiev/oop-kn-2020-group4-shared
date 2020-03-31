#ifndef _COMPUTER_H
#define _COMPUTER_H
class Computer {
    private:

    char* brand;
    char* processor;
    char* video;
    char* hard_drive;
    double price;
    unsigned int quantity;
        
    public:

    Computer();
    Computer(const char* const brand, const char* const processor, 
            const char* const video, const char* const hard_drive, 
            const double& price, const unsigned int& quantity);
    Computer(const Computer&);
    ~Computer();
    friend std::ostream& operator <<(std::ostream&, const Computer&); 

    Computer& operator=(const Computer&);
    const char* const getBrand() const;
    const int getQuantity() const;
    void setQuantity(const int&);

    private:

    void copy(const char* const brand, const char* const processor, 
            const char* const video, const char* const hard_drive, 
            const double& price, const unsigned int& quantity);    
    void copyDymanicMemory(const char* const brand, const char* const processor, 
            const char* const video, const char* const hard_drive);
    void free();
};
#endif
