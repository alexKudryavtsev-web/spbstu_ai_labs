#pragma once
#include <string>
#include <iostream>

class Rect{
	int m_left, m_right, m_top, m_bottom;

public:

	Rect() {
		m_left = 0;
		m_right = 0;
		m_top = 0;
		m_bottom = 0;
	}

	Rect(int left, int right, int top, int bottom) {
		m_left = left;
		m_right = right;
		m_top = top;
		m_bottom = bottom;
	}

	Rect(const Rect &r) : m_left(r.m_left), m_right(r.m_right), m_top(r.m_top), m_bottom(r.m_bottom) {}

	~Rect() {}

	void Show() {
		std::cout << "left: " << m_left << "; right: " << m_right << "; top: " << m_top << "; bottom: " << m_bottom << std::endl;
	}

	void InflateRect(int offset_left, int offset_right, int offset_top, int offset_bottom) {
		m_left += offset_left;
		m_top += offset_top;
		m_right += offset_right;
		m_bottom += offset_bottom;
	}

	void InflateRect(int offset_x = 1, int offset_y = 1) {
		m_left -= offset_x;
		m_top += offset_y;
		m_right += offset_x;
		m_bottom -= offset_y;
	}

	void SetAll(int new_left, int new_right, int new_top, int new_bottom) {
		m_left = new_left;
		m_top = new_top;
		m_right = new_right;
		m_bottom = new_bottom;
	}

	void GetAll() {
		Show();
	}

	int GetMLeft() {
		return m_left;
	}

	int GetMTop() {
		return m_top;
	}

	int GetMRight() {
		return m_right;
	}

	int GetMBottom() {
		return m_bottom;
	}
};

Rect BoundingRect(Rect, Rect);

Rect BoundingRect2(Rect&, Rect&);