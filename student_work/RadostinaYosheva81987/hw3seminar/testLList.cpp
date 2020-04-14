#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "LList.h"

TEST_CASE("Adding element test")
{
    LList list;
    int arr[1] = {0};
    list.create(arr, 1);

    // SUBCASE("Add to the end"){
    //     list.addNewEnd(6);

    //     CHECK(list.getEndNodeData() == 6);
    // }

    SUBCASE("Add to the beginning"){
        list.addNewHead(3);

        CHECK(list.getHeadNodeData() == 3);
    }    
}

TEST_CASE("Reversing test"){
    LList list1;
    int arr[3] = {0, 5, 8};
    list1.create(arr, 1);

    LList list2(list1);
    list2.reverse();

    CHECK(list1.getHeadNodeData() == list2.getEndNodeData());
    
}

int main(){
    doctest::Context().run();
}