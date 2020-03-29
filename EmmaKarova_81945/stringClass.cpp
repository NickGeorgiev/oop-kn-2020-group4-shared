#include <iostream>
#include "String.h"


int main ()
{
    String name(20,"emma");
    std::cout << "--- Created ---\n" << name << "\n";
    
    name.push('s');
    std::cout << "\n--- Pushed ---\n" << name << "\n";
    
    String your;
    std::cout << "\nEnter your string: \n";
    std::cin >> your;
    std::cout << "\n--- You entered ---\n" << your;
   
    String surname(10,"karova");
    name.append(surname);
    std::cout << "\n--- Append ---\n" << name;
   
    your = your + your;
    std::cout << "\n--- Test for operator + and = ---\n" << your;
    
    your.resize(3);
    std::cout << "\n--- Resized N1 ---\n" << your;
    
    your.resize(12,'R');
    std::cout << "\n--- Resized N2 ---\n" << your;
    
    your += name;
    std::cout << "\n--- Test for operator += ---\n" << your;
   
    String none;
    std::cout << none._size();
    std::cout << "\n--- Test for empty() ---\n";
    none.empty();
    your.empty();
    std::cout << "\n--- Test for operator bool ---\n";
    if(none)
    {
        std::cout << "empty\n";
    }
    if(!your)
    {
        std::cout << "not empty\n";
    }

    std::cout << "\n--- Test for operator [] ---\n";
    std::cout << your[2] << std::endl;

    std::cout << "\n--- Test for at() ---\n";
    std::cout << your.at(2) << std::endl;

    std::cout << "\n--- Test for front() ---\n";
    std::cout << your.front() << std::endl;

    std::cout << "\n--- Test for back() ---\n";
    std::cout << your.back() << std::endl;

    return 0;
}