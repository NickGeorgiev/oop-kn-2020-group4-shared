#include <iostream>
#include <cstring>
using namespace std;
#include"homework.h"

	String::String()
	{
		str = nullptr;
		size_of_string = 0;
	}
	String::String(const String& copy) 
	{
		this->capacity = copy.capacity;
		this->size_of_string = copy.size_of_string;
		str = new char[this->capacity];
		strcpy(this->str, copy.str);
	}
	String::~String()
	{
		size_of_string = 0;
		capacity = 0;
		delete[] this->str;
		this->str = nullptr;
	}

	void String::input_string()
	{
		capacity = 200;
		str = new char[capacity + 1];
		cout << "Input string = ";
		cin.getline(str, 201);
		size_of_string = strlen(str);
	}


	void String::push(const char element) 
	{
		if (size_of_string + 1 >= capacity)
		{
			char* result = new char[2 * capacity]; 
			strcpy(result, str);
			delete[] str;
			str = result;
		}
		str[size_of_string++] = element;
		str[size_of_string] = 0;
	}

	int String::size() const
	{
		return size_of_string;
	}

	size_t String::_capacity() const
	{
		return capacity;
	}

	void String::empty()
	{
		if (size_of_string == 0)
			cout << "The string is empty ! " << endl;
	}

	void String::at()
	{
		int find, n, i;
		cout << endl;
		cout << "Input find = ";
		cin >> find;
		cout << "The letter at position = " << str[find - 1];
	}

	void String::front()
	{
		cout << "The first letter of the string is = " << str[0] << endl;
	}
	void String::back()
	{
		int size = strlen(str);
		cout << "The last letter of the string is = " << str[size - 1] << endl;
	}


	String& String::operator += (const String& str2)
	{
		while (this->size_of_string + str2.size_of_string >= capacity)
		{
			resize(str2.size_of_string);
		}
		this->size_of_string += str2.size_of_string;
		strcat(this->str, str2.str);
		return *this;  
	}

	String String::operator + (const String& object) 
	{
	
		String result(*this);
		result.size_of_string += object.size_of_string;
		result.capacity += object.capacity;
		char* temp = new char[result.capacity];
		strcpy(temp, result.str);
		strcat(temp, object.str);
		delete[] result.str;
		result.str = temp;
		return result;
	}


	String& String::operator = (const String& str2)
	{
		if (this != &str2)
		{
			this->capacity = str2.capacity;
			this->size_of_string = str2.size_of_string;
			delete[] str;
			str = new char[this->capacity];
			strcpy(this->str, str2.str);
		}
		return *this; 
	}
  
  String::operator bool () const
   {
    return size_of_string==0;
   }

	void String::append(const char* n2_string)
	{
		
		int size_n2 = strlen(n2_string);
		int size_both = size_n2 + size_of_string;

		if (size_both <= capacity)
		{
			for (int i = 0; i < size_n2; i++)
			{
				str[size_of_string + i] = n2_string[i];
			}
			str[size_both] = '\0';
			size_of_string = size_both;
		}
		else
		{
			while (capacity < size_both)
				capacity *= 2;

			char* n_string = new char[capacity];

			for (int i = 0; i < size_of_string; i++)
			{
				n_string[i] = str[i];
			}
			for (int i = 0; i < size_n2; i++)
			{
				n_string[size_of_string + i] = n2_string[i];
			}

			delete[] str;
			str = n_string;
			size_of_string = size_both;
		}
		cout << str << endl;
	}

	char* String::c_str() 
	{
		char* charArray = new char[size_of_string + 1];
		for (int i = 0; i < size_of_string; i++)
		{
			charArray[i] = str[i];
		}
		charArray[size_of_string] = 0;
		return charArray;
	}

	void String::resize(const int& size) 
	{

		capacity = size;
		char* new_string = new char[capacity];
		strncpy(new_string, str, capacity - 1);
		delete[] str;
		str = new_string;
		size_of_string = strlen(str);

	}

	void String::resize(int size, char elem)
	{

		resize(size);
		while (size_of_string < size)
		{
			push(elem);
		}
	}

	void String::shrink_to_fit()
	{
		resize(size_of_string + 1);
	}

	void String::print_string()
	{
		cout << str << endl;
	}

