#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class MyString {
public:
	MyString(const string& str) : str(str) {
		cout << "constructor " << this << endl;
	}

	MyString(const vector<string>& strs) {
		cout << "constructor of vector<string>" << this << endl;
		for (const auto& str : strs) {
			this->str += str;
		}
	}

	MyString() { 
		cout << "default constructor" << this << endl;
	};


	MyString(const MyString& other)	{
		cout << "copy constructor" << this << endl;
		this->str = other.str;
	}

	MyString& operator=(const MyString& other) {
		cout << "assing constructor " << this << endl;
		this->str = other.str;
		return *this;
	}

	string getStr() {
		return str;
	}

	void setStr(string str)	{
		this->str = str;
	}

	void print() {
		cout << str << endl;
	}

	~MyString() { 
		cout << "destructor " << this << endl;
	}
private:
	string str;

};