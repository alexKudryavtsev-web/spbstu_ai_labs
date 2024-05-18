#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {
		cout << "constructor Point: " << this << endl;
	}

	double GetX() {
		return x;
	}
	void SetX(int x) {
		this->x = x;
	}
	double GetY() {
		return y;
	}
	void SetY(int y) {
		this->y = y;
	}
	void print() {
		cout << "x = " << x << "\ty = " << y << endl;
	}

	~Point() {
		cout << "destuctor Point: " << this << endl;
	}

	bool operator ==(const Point& other) {
		return this->x == other.x and this->y == other.y;

	}
	friend ostream& operator <<(ostream& out, const Point& p) {
		out << "(" << p.x << ";" << p.y << ")";
		return out;
	}

	friend istream& operator >>(istream& in, Point& p) {
		in.ignore(1);
		in >> p.x;
		in.ignore(1);
		in >> p.y;
		in.ignore(1);
		return in;
	}

	bool operator !=(const Point& other) {
		return x != other.x or y != other.y;
	}

	Point operator +(const Point& other) {
		Point tmp;
		tmp.x = x + other.x;
		tmp.y = y + other.y;
		
		return tmp;
	}

	Point operator +(double i) {
		Point tmp;
		tmp.x = i + this->x;
		tmp.y = i + this->y;
		return tmp;
	}
	friend Point operator+(double i, const Point& other) {
		Point tmp;
		tmp.x = i + other.x;
		tmp.y = i + other.y;
		return tmp;
	}
	Point operator-() {
		return Point(-x, -y);
	}

	Point operator+() {
		return Point(x, y);
	}
	Point operator +=(const Point& other) {
		x = x + other.x;
		y = y + other.y;
		return *this;
	}
	Point operator +=(double i) {
		x = x + i;
		y = y + i;
		return *this;
	}
	Point& operator ++() {
		this->x++;
		this->y++;
		return *this;
	}

	Point& operator ++(int value) {
		Point tmp(*this);
		this->x++;
		this->y++;
		return tmp;
	}

public:
	double x;
	double y;
};

class Circle {
	Point center;
	double radius;
public:
	Circle() :radius(0) {}
	Circle(Point p, int r) :center(p), radius(r) {}
	bool operator==(const Circle& other) {
		return ((radius == other.radius) && (center == other.center));
	}
	const double calculateArea()const {
		return  M_PI * radius * radius;
	}
	friend ostream& operator <<(ostream& out, const Circle& c) {
		out << "area: " << c.calculateArea() << "\rradius: " << c.radius << "\tcenter: " << c.center << "\n";
		return out;
	}
	friend istream& operator >>(istream& in, Circle& c) {
		in.ignore(strlen("\tradius: "));
		in >> c.radius;
		in.ignore(strlen("\tcenter: "));
		in >> c.center;
		return in;
	}
};
