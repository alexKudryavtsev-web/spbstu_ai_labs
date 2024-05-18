// lab2sem4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string.h>
#include "List.cpp"
#include<fstream>

using namespace std;

ostream& operator <<(ostream& out, const List& l) {
	Node* ptr = l.Head.pNext;
	for (int i = 0; i < l.size; i++) {
		out << ptr->data;
		ptr = ptr->pNext;
	}
	return out;
}
istream& operator >>(istream& in, List& l) {
	Circle addData;
	while (in >> addData) {
		l.addToTail(addData);
	}
	return in;
}


int main()
{
	List l;

	Point c1;
	Point c2(0, 0);
	Point c3(1, 1);
	Point c4(10, 12);

	Circle circle1(c1, 1);
	Circle circle2(c2, 2);
	Circle circle3(c3, 3);
	Circle circle4(c4, 4);

	l.addToHead(circle1);
	l.addToTail(circle2);
	l.addToTail(circle3);
	l.addToHead(circle4);
	l.addToTail(circle2);

	l.sort();

	ofstream file;

	file.open("res.txt");
	if (!file)
		cout << "Error";
	else {
		file << l;
	}
	file.close();

	l.clear();

	ifstream ifile("res.txt");
	if (!ifile)
		cout << "Error";
	else {
		ifile >> l;
	}
	ifile.close();

	cout << l;

	return 0;
}
