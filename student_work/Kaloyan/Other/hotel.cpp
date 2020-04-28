#include<string>
#include<functional>
#include<iostream>

struct Hotel {
    std::string name;
    size_t numberOfRooms;
    double priceOfRoom;
};

template<class TR, class TE>
TR reduce(TE* array, size_t length, std::function<TR(TR&, const TE&)> function, TR nullValue) {
    TR result = nullValue;
    for (int i = 0; i < length; i++) {
        result = function(result, array[i]);
    }
    return result;
}



int main () {
    Hotel hotel1{"first", 10, 25.5};
    Hotel hotel2{"first", 10, 25.5};
    Hotel hotel3{"first", 10, 25.5};

    Hotel arr[]{hotel1, hotel2, hotel3};

    std::cout << reduce<double, Hotel>(arr, 3, [](double& acc, const Hotel& hotel)->double{return acc + hotel.numberOfRooms * hotel.priceOfRoom;}, 0) << '\n';

    return 0;
}