#include <iostream>
#include <cstring>
class ComputerShop;
class Computer
{
    size_t quantity;
    double price;
    char *brand;
    char *processor;
    char *video;
    char *harddrive;
    friend ComputerShop;

public:
    Computer()
        : brand(nullptr), processor(nullptr), video(nullptr), harddrive(nullptr), price(0), quantity(0) {}
    Computer(const char *newBrand, const char *newCPU, const char *newGPU, const char *newHDD, const double &newPrice, const size_t &newQuantity)
        : brand(new char[strlen(newBrand) + 1]),
          processor(new char[strlen(newCPU) + 1]),
          video(new char[strlen(newGPU) + 1]),
          harddrive(new char[strlen(newHDD) + 1]),
          price(newPrice),
          quantity(newQuantity)
    {
        strcpy(brand, newBrand);
        strcpy(processor, newCPU);
        strcpy(video, newGPU);
        strcpy(harddrive, newHDD);
    }
    Computer(const Computer &otherPC)
        : brand(new char[strlen(otherPC.brand) + 1]),
          processor(new char[strlen(otherPC.processor) + 1]),
          video(new char[strlen(otherPC.video) + 1]),
          harddrive(new char[strlen(otherPC.harddrive) + 1]),
          price(otherPC.price),
          quantity(otherPC.quantity)
    {
        strcpy(brand, otherPC.brand);
        strcpy(processor, otherPC.processor);
        strcpy(video, otherPC.video);
        strcpy(harddrive, otherPC.harddrive);
    }
    ~Computer()
    {
        delete[] harddrive;
        delete[] video;
        delete[] processor;
        delete[] brand;
    }
    bool operator==(const Computer &otherPC)
    {
        return strcmp(brand, otherPC.brand) == 0 && strcmp(processor, otherPC.processor) == 0 && strcmp(video, otherPC.video) == 0 && strcmp(harddrive, otherPC.harddrive) == 0 && price == otherPC.price;
    }
    Computer &operator=(const Computer &otherPC)
    {
        if (this != &otherPC)
        {
            delete[] harddrive;
            delete[] video;
            delete[] processor;
            delete[] brand;

            brand = new char[strlen(otherPC.brand) + 1];
            processor = new char[strlen(otherPC.processor) + 1];
            video = new char[strlen(otherPC.video) + 1];
            harddrive = new char[strlen(otherPC.harddrive) + 1];

            strcpy(brand, otherPC.brand);
            strcpy(processor, otherPC.processor);
            strcpy(video, otherPC.video);
            strcpy(harddrive, otherPC.harddrive);
            price = otherPC.price;
            quantity = otherPC.quantity;
        }
        return *this;
    }
    void printPC() const
    {
        std::cout << "\n_________________"
                  << "\nBrand: " << brand
                  << "\nCPU: " << processor
                  << "\nGPU: " << video
                  << "\nHDD: " << harddrive
                  << "\n$$$: " << price
                  << "\nIn stock: " << quantity;
    }
};
class ComputerShop
{
    char *name;
    Computer *list;
    size_t listSize;

public:
    ComputerShop()
        : name(nullptr),
          list(nullptr),
          listSize(0) {}
    ComputerShop(const char *newName, const size_t &newListSize, const Computer *newList)
        : name(new char[strlen(newName) + 1]),
          listSize(newListSize),
          list(new Computer[listSize])
    {
        strcpy(name, newName);
        for (size_t i = 0; i < newListSize; i++)
        {
            list[i] = newList[i];
        }
    }
    ~ComputerShop()
    {
        delete[] list;
        delete[] name;
    }
    void addPC(const Computer &newPC)
    {
        for (size_t i = 0; i < listSize; i++)
        {
            if (list[i] == newPC)
            {
                list[i].quantity++;
                return;
            }
        }

        listSize++;
        Computer *newList = new Computer[listSize];

        for (size_t i = 0; i < listSize - 1; i++)
        {
            newList[i] = list[i];
        }
        newList[listSize - 1] = newPC;

        delete[] list;
        list = newList;
    }
    void sellPC(const char *desiredBrand)
    {
        for (size_t i = 0; i < listSize; i++)
        {
            if (strcmp(list[i].brand, desiredBrand) == 0)
            {
                if (list[i].quantity > 0)
                {
                    std::cout << "\nPurchase successful! Expect shipping details via email.";
                    list[i].quantity--;
                    return;
                }
                else
                {
                    std::cout << "\nUnfortunately this PC currently isn't in stock.";
                }
            }
        }
    }
    void printList() const
    {
        std::cout << "\n" << name;
        for (size_t i = 0; i < listSize; i++)
        {
            std::cout << "\nPC[" << i << "]";
            list[i].printPC();
        }
    }
};
int main()
{
    Computer dell("Dell", "i5", "GTX1060", "3TB", 1000.90, 3);
    Computer acer("Acer", "i7", "GTX1080", "5TB", 1609.99, 1);
    Computer hp("HP", "i3", "GTX680", "2TB", 750.10, 2);
    Computer lenovo("Lenovo", "i5", "GTX1660", "6TB", 1559.19, 0);

    Computer dell2(dell);
    std::cout << "COPY_CONSTR EXAMPLE";
    dell2.printPC();

    size_t pcContainerSize = 3;
    Computer *pcContainer = new Computer[pcContainerSize]{dell, acer, hp};

    std::cout << "\n\nCOMPUTER_SHOP EXAMPLE";
    ComputerShop first("Ardes", pcContainerSize, pcContainer);
    first.printList();

    std::cout << "\n\nADD_PC/ NEW PC EXAMPLE";
    first.addPC(lenovo);
    first.printList();

    std::cout << "\n\nADD_PC/ EXISTING PC EXAMPLE";
    dell.printPC();
    first.addPC(dell);
    first.printList();

    std::cout << "\n\nSELL_PC/QUANTITY != 0 EXAMPLE";
    hp.printPC();
    first.sellPC("HP");
    first.printList();

    std::cout << "\n\nSELL_PC/QUANTITY == 0 EXAMPLE";
    lenovo.printPC();
    first.sellPC("Lenovo");
    return 0;
}
