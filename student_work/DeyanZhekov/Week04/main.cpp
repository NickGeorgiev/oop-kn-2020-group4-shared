#include <iostream>
#include <string.h>

#include "Computer.h"

int main()
{
    char *brand = new char[20];
    char *processor = new char[20];
    char *video = new char[20];
    char *hardDrive = new char[20];
    double price;
    int quantity;

    std::cout << "Enter brand: ";
    std::cin.getline(brand, 20);

    std::cout << "Enter processor: ";
    std::cin.getline(processor, 20);

    std::cout << "Enter video: ";
    std::cin.getline(video, 20);

    std::cout << "Enter hardDrive: ";
    std::cin.getline(hardDrive, 20);

    std::cout << "Enter price: ";
    std::cin >> price;

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    Computer computer = Computer(brand, processor, video, hardDrive, price, quantity);

    computer.print();
}