#include <iostream>
#include <string.h>
class Computer
{
private:
    char *brand;
    char *processor;
    char *video; //GPU??!?
    char *hard_drive;
    double price;
    int quantity;

public:
    Computer(const char *new_brand, const char *new_processor, const char *new_video,
             const char *new_hard_drive, double new_price, int new_quantity);
    Computer(const Computer &other);
    ~Computer();
    Computer();
    void print()
    {
        std::cout << brand << std::endl;
        std::cout << processor << std::endl;
        std::cout << video << std::endl;
        std::cout << hard_drive << std::endl;
        std::cout << price << std::endl;
        std::cout << quantity << std::endl;
    }
    char *get_brand() const
    {
        return brand;
    }
    int get_quantity() const
    {
        return quantity;
    }
    int &set_quality()
    {
        return quantity;
    }
};

Computer::Computer() = default;
Computer::Computer(const char *new_brand, const char *new_processor, const char *new_video,
                   const char *new_hard_drive, double new_price, int new_quantity)
{
    brand = new (std::nothrow) char[strlen(new_brand) + 1];
    processor = new (std::nothrow) char[strlen(new_processor) + 1];
    video = new (std::nothrow) char[strlen(new_video) + 1];
    hard_drive = new (std::nothrow) char[strlen(new_hard_drive) + 1];
    strcpy(brand, new_brand);
    strcpy(processor, new_processor);
    strcpy(video, new_video);
    strcpy(hard_drive, new_hard_drive);
    price = new_price;
    quantity = new_quantity;
}

Computer::~Computer()
{
    if (brand != nullptr)
    {
        delete[] brand;
    }
    if (processor != nullptr)
    {
        delete[] processor;
    }
    if (video != nullptr)
    {
        delete[] video;
    }
    if (hard_drive != nullptr)
    {
        delete[] hard_drive;
    }
}
Computer::Computer(const Computer &other)
{
    brand = new (std::nothrow) char[strlen(other.brand) + 1];
    processor = new (std::nothrow) char[strlen(other.processor) + 1];
    video = new (std::nothrow) char[strlen(other.video) + 1];
    hard_drive = new (std::nothrow) char[strlen(other.hard_drive) + 1];
    strcpy(brand, other.brand);
    strcpy(processor, other.processor);
    strcpy(video, other.video);
    strcpy(hard_drive, other.hard_drive);
    price = other.price;
    quantity = other.quantity;
}
class Computer_Shop
{
private:
    char *name;
    Computer *computer_list;
    int size;

public:
    Computer_Shop(const char *new_name, Computer *new_computer_list, int current_size);
    ~Computer_Shop();
    void print_shop()
    {
        std::cout << name << std::endl;
        for (int i = 0; i < 3; i++)
        {
            computer_list[i].print();
        }
    }
    void add_PC(Computer new_PC)
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(new_PC.get_brand(), computer_list[i].get_brand()) == 0)
            {
                computer_list[i].set_quality()++;
            }
            return;
        }
        Computer *new_PCs = new Computer[size + 1];
        for (int i = 0; i < size; i++)
        {
            new_PCs[i] = computer_list[i];
        }
        size++;
        new_PCs[size] = new_PC;
        delete[] computer_list;
        computer_list = new_PCs;
    }
    void buy_PC(char *desired_brand)
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(desired_brand, computer_list[i].get_brand()) == 0)
            {
                if (computer_list[i].get_quantity >= 1)
                {
                    computer_list[i].set_quality()--;
                    return;
                }
            }
        }
    }
};

Computer_Shop::Computer_Shop(const char *new_name, Computer *new_computer_list, int current_size)
{
    name = new (std::nothrow) char[strlen(new_name) + 1];
    strcpy(name, new_name);
    const int size = current_size;
    computer_list = new Computer[size];
    for (int i = 0; i < size; i++)
    {
        computer_list[i] = new_computer_list[i];
    }
}

Computer_Shop::~Computer_Shop()
{
    if (name != nullptr)
    {
        delete[] name;
    }
    if (computer_list != nullptr)
    {
        delete[] computer_list;
    }
    size = 0;
}

int main()
{
    Computer dell("Dell", "i5", "GTX1060", "3TB", 1000.90, 3);
    Computer acer("Acer", "i7", "GTX1080", "5TB", 1609.99, 1);
    Computer hp("HP", "i3", "GTX680", "2TB", 750.10, 2);
    Computer pp("HP", "i3", "GTX680", "2TB", 750.10, 2);
    Computer pcs[4] = {dell, acer, hp, pp};
    dell.print();
    Computer_Shop shoppy("Tehnomarket", pcs, 4);
    shoppy.print_shop();
}
