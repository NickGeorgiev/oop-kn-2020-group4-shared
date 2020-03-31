#include <iostream>
#include <cstring>
#include "Computer.h"

Computer::Computer(const char* const brand, const char* const processor, 
            const char* const video, const char* const hard_drive, 
            const double& price, const unsigned int& quantity) {
            copy(brand, processor, video, hard_drive, price, quantity);
        }
Computer::Computer(): Computer("", "", "", "", 0, 0) {}
Computer::Computer(const Computer& computer): 
        Computer(computer.brand, computer.processor, computer.video, 
            computer.hard_drive, computer.price, computer.quantity) {}
Computer::~Computer() {
    free();
}
Computer& Computer::operator=(const Computer& computer) {
    free();
    copy(computer.brand, computer.processor, computer.video, 
        computer.hard_drive, computer.price, computer.quantity);
    return (*this);
}
const char* const Computer::getBrand() const {
    return this->brand;
}
const int Computer::getQuantity() const {
    return this->quantity;
}
void Computer::setQuantity(const int& quantity) {
    if(quantity >= 0) {
        this->quantity = quantity;
    }
}
std::ostream& operator <<(std::ostream& out, const Computer& computer) {
    out << computer.brand << " " << computer.processor << " " << computer.video << " " << 
        computer.hard_drive << " " << computer.price << " " << computer.quantity;
    return out;
}

void Computer::copy(const char* const brand, const char* const processor, 
            const char* const video, const char* const hard_drive, 
            const double& price, const unsigned int& quantity) {
                this->brand = new char[strlen(brand) + 1];
                this->processor = new char[strlen(processor) + 1];
                this->video = new char[strlen(video) + 1];
                this->hard_drive = new char[strlen(hard_drive) + 1];
                copyDymanicMemory(brand, processor, video, hard_drive);
                this->price = price;
                this->quantity = quantity;
        }
void Computer::copyDymanicMemory(const char* const brand, const char* const processor, 
            const char* const video, const char* const hard_drive) {
            strcpy(this->brand, brand);
            strcpy(this->processor, processor);
            strcpy(this->video, video);
            strcpy(this->hard_drive,hard_drive);
        }
void Computer::free() {
    delete[] hard_drive;
    delete[] video;
    delete[] processor;
    delete[] brand;
}
