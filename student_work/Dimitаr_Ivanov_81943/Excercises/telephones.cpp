#include <iostream>

class Smartphone {
    char model[21];
    char OS[21];
    int price;

    public:

    //SETS

    // ПО ПОДРАЗБИРАНЕ
    void set_model() {
        std::cin >> model;
    }

    void set_OS() {
        std::cin >> OS;
    }

    void set_price() {
        std::cin >> price;
    }

    //С ПАРАМЕТРИ
    // void set_model(const char* elem) {
    //     strcpy(model,elem);
    // }

    // void set_OS(const char* elem) {
    //     strcpy(OS,elem);
    // }

    // void set_price(const int& elem) {
    //     price = elem;
    // }

    //GETS
    // void get_model() const {
    //     std::cout << model << ' ';
    // }

    // void get_OS() const {
    //     std::cout << OS << ' ';
    // }

    // void get_price() const {
    //     std::cout << price << ' ';
    // }

    const char* get_model() const {
        return model;
    }

    const char* get_OS() const {
        return OS;
    }

    const int get_price() const {
        return price;
    }

    void print() const {
        std::cout << model << ' ' << OS << ' ' << price << '\n';
    }

};

void sort_smartphones (Smartphone* smartphones, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (smartphones[i].get_price() > smartphones[j].get_price()) {
                // std::swap(smartphones[i].get_model(),smartphones[j].get_model()); // unrecogniseable by swap func
                // std::swap(smartphones[i].get_OS(),smartphones[j].get_OS());
                // std::swap(smartphones[i].get_price(),smartphones[j].get_price());

                // std::swap(smartphones[i].model,smartphones[j].model); // unaccessible
                // std::swap(smartphones[i].OS,smartphones[j].OS);
                // std::swap(smartphones[i].price,smartphones[j].price);

                std::swap(smartphones[i],smartphones[j]); // ZASHTO??????
            }
        }
    }
}

int main()
{
    Smartphone smartphones[20];

   int number;
   std::cin >> number;

   for (int i = 0; i < number; i++) {
       smartphones[i].set_model();
       smartphones[i].set_OS();
       smartphones[i].set_price();

   }

   for (int i = 0; i < number; i++) {
       smartphones[i].print();

   }

    // smartphones[0].set_model("samsung");
    // smartphones[0].set_OS("windows phone");
    // smartphones[0].set_price(799);

    sort_smartphones(smartphones, number);

    for (int i = 0; i < number; i++) {
       smartphones[i].print();

   }

    return 0;
}

/*

zadacha 3 test

3

samsung android9.1.1 1800
huawei android8 1000
lenovo windowsPhone 700

*/