#include <iostream>
#include <string.h>
#define _USE_MATH_DEFINES
#include<math.h>

using namespace std;

enum Color {
	Red,
	Green,
	Blue,
	Yellow,
	White,
	Black
};

class Shape
{
public:
	Shape(Color color, double height, double width)
	{
		this->color = color = Black;
		this->height = height = 1;
		this->width = width = 2;
		cout << "����������� Shape CHW " << this << endl;
	}
	Shape(Color color, double radius)
	{
		this->color = color = White;
		this->height = radius = 1;
		cout << "����������� Shape CR " << this << endl;
	}
	Shape() { cout << "������� ����������� Shape " << this << endl; };

	Shape(const Shape& other) {
		this->color = other.color;
		this->height = other.height;
		this->width = other.width;
		cout << "����������� ����������� Shape CHW " << this << endl;
	}
	Shape& operator=(const Shape& other) {
		this->color = other.color;
		this->height = other.height;
		this->width = other.width;
		cout << "�������� ������������ Shape " << this << endl;
		return *this;
	}

	virtual void WhereAmI() {
		cout << "Now I am in class Shape" << endl;
	}

	/*virtual void Inflate(int factor) = 0;*/


	virtual ~Shape()
	{
		cout << "���������� Shape " << this << endl;
	}
protected:
	Color color;
	double height;
	double width;
};

class Rect :public Shape
{
public:
	Rect(Color color, double height, double width) :Shape(color, height, width)
	{
		this->color = color;
		this->height = height;
		this->width = width;
		cout << "����������� Rect " << this << endl;
	}
	Rect() :Shape() { cout << "������� ����������� Rect " << this << endl; }

	Rect(const Rect& other) {
		this->color = other.color;
		this->height = other.height;
		this->width = other.width;
		cout << "����������� ����������� Rect " << this << endl;
	}
	Rect& operator=(const Rect& other) {
		this->color = other.color;
		this->height = other.height;
		this->width = other.width;
		cout << "�������� ������������ Rect " << this << endl;
		return *this;
	}

	void WhereAmI() override
	{
		cout << "Now I am in class Rect" << endl;
	}
	double square() {
		return height * width;
	}

	/*void Inflate(int factor) override {
		this->height += factor;
		this->width += factor;
	}*/

	~Rect() override {
		cout << "���������� Rect " << this << endl;
	}
};

class Circle :public Shape
{
public:
	Circle(Color color, double radius) :Shape(color, radius)
	{
		this->color = color;
		this->height = radius;
		cout << "����������� Circle " << this << endl;
	}
	Circle() :Shape() { cout << "������� ����������� Circle " << this << endl; }
	Circle(Rect r)
	{
		cout << "����������� Circle(Rect) " << this << endl;
	}

	Circle(const Circle& other) {
		this->color = other.color;
		this->height = other.height;
		cout << "����������� ����������� Circle  " << this << endl;
	}
	Circle& operator=(const Circle& other) {
		this->color = other.color;
		this->height = other.height;
		cout << "�������� ������������ Circle " << this << endl;
		return *this;
	}


	void WhereAmI() override
	{
		cout << "Now I am in class Circle" << endl;
	}
	double square()
	{
		return M_PI * radius * radius;
	}
	/*void Inflate(int factor) override {
		this->height += factor;
	}*/

	~Circle() override
	{
		cout << "���������� Circle " << this << endl;
	}
private:
	double radius = height;
};