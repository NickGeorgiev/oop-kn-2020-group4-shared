#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "String.h"

TEST_SUITE ("String class test suite") {

    // Universal test data

    const char* const EMPTY_STRING_DATA = "";
    const size_t EMPTY_STRING_SIZE = 0;
    const size_t EMPTY_STRING_CAPACITY = 4;

    const char* const TEST_STRING_DATA = "test";
    const size_t TEST_STRING_SIZE = 4;
    const size_t TEST_STRING_CAPACITY = 5;

    const int INCREMENT_ON_RESIZE = 2;

    // Helper functions

    void checkString(const String&, const char* const, const size_t&, const size_t&);
    void checkString(const String& actual, const String& expected);

    // Test cases

    TEST_CASE("Constructors") {
        SUBCASE("Default") {
            String string;
            checkString(string, EMPTY_STRING_DATA, 
                EMPTY_STRING_SIZE, EMPTY_STRING_CAPACITY);
        }
        SUBCASE("From char array") {
            String string(TEST_STRING_DATA);
            checkString(string, TEST_STRING_DATA, 
                TEST_STRING_SIZE, TEST_STRING_CAPACITY);
        }
        SUBCASE("Copy") {
            String str(TEST_STRING_DATA);
            String string(str);
            checkString(string, str);
        }
    }

    TEST_CASE("Selectors") {
        const String string(TEST_STRING_DATA);

        SUBCASE("Size") {
            CHECK(string.size() == TEST_STRING_SIZE);
        }
        SUBCASE("Capacity") {
            CHECK(string.size() == TEST_STRING_SIZE);
        }
        SUBCASE("C string") {
            CHECK(strcmp(string.c_str(), TEST_STRING_DATA) == 0);
        }
        SUBCASE("Front") {
            CHECK(string.front() == TEST_STRING_DATA[0]);
        }
        SUBCASE("Back") {
            CHECK(string.back() == TEST_STRING_DATA[TEST_STRING_SIZE - 1]);
        }
        SUBCASE("At") {
            const int pos = 2;
            CHECK(string.at(pos) == TEST_STRING_DATA[pos]);
        }
    }

    TEST_CASE("Direct mutators") {
        const char mutatorCharacter = 'a';

        SUBCASE("Front") {
            String string(TEST_STRING_DATA);
            CHECK(string.front() == *(TEST_STRING_DATA) );
            string.front() = mutatorCharacter;

            checkString(string, "aest", string.size(), string.capacity());
        }
        SUBCASE("Back") {
            String string(TEST_STRING_DATA);
            CHECK(string.back() == *(TEST_STRING_DATA + TEST_STRING_SIZE - 1) );
            string.back() = mutatorCharacter;

            checkString(string, "tesa", string.size(), string.capacity());
        }
        SUBCASE("At") {
            String string(TEST_STRING_DATA);
            const int pos = 2;
            CHECK(string.at(pos) == *(TEST_STRING_DATA + pos) );
            string.at(pos) = mutatorCharacter;
            
            checkString(string, "teat", string.size(), string.capacity());
        }
    }

    TEST_CASE("Empty") {
        SUBCASE("Is empty") {
            const String string;
            CHECK(string.empty() == true);
        }
        SUBCASE("Is not empty") {
            const String string(TEST_STRING_DATA);
            CHECK(string.empty() == false);
        }
    }

    TEST_CASE("Push") {
        const char toAppend = 'a';
        SUBCASE("Same capacity") {
            String string;
            string.push(toAppend);

            checkString(string, "a",  EMPTY_STRING_SIZE + 1, EMPTY_STRING_CAPACITY);
        }
        SUBCASE("Incremented capacity") {
            String string(TEST_STRING_DATA);
            string.push(toAppend);

            checkString(string, "testa",  TEST_STRING_SIZE + 1, TEST_STRING_CAPACITY * INCREMENT_ON_RESIZE);
        }
    }

    TEST_CASE("Append") {
        const char* const toAppendData = "aa";
        const String toAppend(toAppendData);

        SUBCASE("Same capacity") {
            String string;
            string.append(toAppend);

            checkString(string, "aa",  EMPTY_STRING_SIZE + toAppend.size(), EMPTY_STRING_CAPACITY);
        }
        SUBCASE("Incremented capacity") {
            String string(TEST_STRING_DATA);
            string.append(toAppend);

            checkString(string, "testaa",  TEST_STRING_SIZE + toAppend.size(), TEST_STRING_CAPACITY * INCREMENT_ON_RESIZE);
        }
        SUBCASE("Double incremented capacity") {
            String string(TEST_STRING_DATA);
            const String string1("test12");
            string.append(string1);

            checkString(string, "testtest12",  TEST_STRING_SIZE + string1.size(), TEST_STRING_CAPACITY * INCREMENT_ON_RESIZE * INCREMENT_ON_RESIZE);
        }
    }

    TEST_CASE("Resize") {
        SUBCASE("Larger new capacity than size") {
            String string(TEST_STRING_DATA);
            const size_t newCapacity = 8;
            string.resize(newCapacity);
            checkString(string, TEST_STRING_DATA, TEST_STRING_SIZE, newCapacity);
        }
        SUBCASE("Smaller new capacity than size") {
            String string(TEST_STRING_DATA);
            const size_t newCapacity = 2;
            string.resize(newCapacity);
            checkString(string, "t", newCapacity - 1, newCapacity);

        }
        SUBCASE("Same capacity") {
            String string(TEST_STRING_DATA);
            string.resize(TEST_STRING_CAPACITY);
            checkString(string, TEST_STRING_DATA, TEST_STRING_SIZE, TEST_STRING_CAPACITY);

        }
    }

    TEST_CASE("Resize with append") {
        const char toAppend = 'a';
        SUBCASE("Larger new capacity than size") {
            String string(TEST_STRING_DATA);
            const size_t newCapacity = 8;
            string.resize(newCapacity, toAppend);
            checkString(string, "testaaa", newCapacity - 1, newCapacity);
        }
        SUBCASE("Smaller new capacity than size") {
            String string(TEST_STRING_DATA);
            const size_t newCapacity = 2;
            string.resize(newCapacity, toAppend);
            checkString(string, "t", newCapacity - 1, newCapacity);

        }
        SUBCASE("Same capacity") {
            String string(TEST_STRING_DATA);
            string.resize(TEST_STRING_CAPACITY, toAppend);
            checkString(string, TEST_STRING_DATA, TEST_STRING_SIZE, TEST_STRING_CAPACITY);
        }
    }

    TEST_CASE("Shrink to fit") {
        SUBCASE("Larger capacity") {
            String string;
            string.shrink_to_fit();
            checkString(string, EMPTY_STRING_DATA, EMPTY_STRING_SIZE, 1);
        }
        SUBCASE("Same capacity") {
            String string(TEST_STRING_DATA);
            string.shrink_to_fit();
            checkString(string, TEST_STRING_DATA, TEST_STRING_SIZE, TEST_STRING_CAPACITY);
        }     
    }

    TEST_CASE("Operator =") {
        const String string(TEST_STRING_DATA);
        const String newString = string;
        checkString(newString, string);
    }

    TEST_CASE("Operator +") {
        const String string1("test1");
        const String string2("test2");
        checkString(string1 + string2, String("test1test2"));
    }

    TEST_CASE("Operator +=") {
        String string1("test1");
        const String string2("test2");
        string1 += string2;
        checkString(string1, String("test1test2"));
    }

    TEST_CASE("Operator []") {
        SUBCASE("Constant") {
            const String string(TEST_STRING_DATA);
            CHECK(string[0] == TEST_STRING_DATA[0]);
            CHECK(string[3] == TEST_STRING_DATA[3]);
        }
        SUBCASE("Mutating") {
            String string(TEST_STRING_DATA);
            CHECK(string[0] == TEST_STRING_DATA[0]);
            CHECK(string[3] == TEST_STRING_DATA[3]);
            string[2] = 'a';
            checkString(string, "teat", 4, 5);
        }
    }
    
    TEST_CASE("Explicit operator bool") {
        SUBCASE("True") {
            const String _true(TEST_STRING_DATA);
            CHECK(bool(_true));
        }
        SUBCASE("False") {
            const String _false(EMPTY_STRING_DATA);
            CHECK(!bool(_false));
        }
    }

    // Helper function implementations
    void checkString(const String& actual, const char* const expectedData, 
            const size_t& expectedSize, const size_t& expectedCapacity) {
        CHECK(strcmp(expectedData, actual.c_str()) == 0);
        CHECK(expectedSize == actual.size());
        CHECK(expectedCapacity == actual.capacity());
    }

    void checkString(const String& actual, const String& expected) {
        checkString(actual, expected.c_str(), expected.size(), expected.capacity());
    }
}
