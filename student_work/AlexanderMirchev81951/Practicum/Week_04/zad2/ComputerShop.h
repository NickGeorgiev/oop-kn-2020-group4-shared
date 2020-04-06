#ifndef _COMPUTERSHOP_HH
#define _COMPUTERSHOP_HH
class ComputerShop{
    private:
    
    char* name;
    Computer* computers;
    size_t numberOfComputers;

    public:

    ComputerShop(const char* const, const Computer* const, const size_t&);
    ComputerShop(const ComputerShop&);
    ~ComputerShop();

    void addComputer(const Computer&);
    void printAllComputers(std::ostream&) const;
    void purchase(const char* const brand, const int desiredQuantity, std::ostream&);

    private:

    const int getComputerPositionByBrand(const char* const brandName) const;
    void copy(const char* const, const Computer* const, const size_t&);
    void freeMemory();
};
#endif