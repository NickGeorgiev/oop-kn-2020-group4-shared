#include <iostream>
#include <string.h>

#include "Computer.h"

void Computer::copy(char *brand, char *processor, char *video, char *hardDrive, double price, int quantity)
{
    this->brand = new char[strlen(brand) + 1];
    this->processor = new char[strlen(processor) + 1];
    this->video = new char[strlen(video) + 1];
    this->hardDrive = new char[strlen(hardDrive) + 1];

    strcpy(this->brand, brand);
    strcpy(this->processor, processor);
    strcpy(this->video, video);
    strcpy(this->hardDrive, hardDrive);

    this->price = price;
    this->quantity = quantity;
}

Computer::Computer(char *brand, char *processor, char *video, char *hardDrive, double price, int quantity)
{
    this->copy(brand, processor, video, hardDrive, price, quantity);
}

Computer::Computer(Computer const &otherComputer)
{
    this->copy(otherComputer.brand, otherComputer.processor, otherComputer.video, otherComputer.hardDrive, otherComputer.price, otherComputer.quantity);
}

Computer::~Computer()
{
    if (brand != NULL)
    {
        delete[] brand;
    }

    if (processor != NULL)
    {
        delete[] processor;
    }

    if (video != NULL)
    {
        delete[] video;
    }

    if (hardDrive != NULL)
    {
        delete[] hardDrive;
    }
}

void Computer::print()
{
    std::cout << brand << " " << processor << " " << video << " " << hardDrive << " " << price << " " << quantity << std::endl;
}
