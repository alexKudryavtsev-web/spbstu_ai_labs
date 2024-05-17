#include <iostream>
#include <string.h>
using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	double Getx() {
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

	// перегрузка операторов
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

	Point operator-(const Point& other) {
		return Point(x-other.x, y-other.y);
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

	Point operator -=(const Point& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Point operator -=(double i) {
		x -= i;
		y -= i;
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

private:
	double x;
	double y;
};