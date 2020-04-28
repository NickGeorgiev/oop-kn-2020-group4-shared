#include<iostream>
#include<string>
#include<functional>

struct Product {
    std::string name;
    double price;
};

template<class T>
void map(T* array, const size_t& length, std::function<void(T&)> function) {
    for (int i = 0; i < length; i++) {
        function(array[i]);
    }
}

int main() {
    Product product1{"product1", 125.5};
    Product product2{"product2", 58.5};
    Product product3{"product3", 34.5};
    Product array[]{product1, product2, product3};

    map<Product>(array, 3, [](Product& product)->void{product.price += product.price/10.0;});
    map<Product>(array, 3, [](Product& product)->void{std::cout << product.name << ' ' << product.price << '\n';});
    map<Product>(array, 3, [](Product& product)->void{if(product.price < 55) product.price = 5.0; else product.price -= 50.0;});
    map<Product>(array, 3, [](Product& product)->void{std::cout << product.name << ' ' << product.price << '\n';});
}