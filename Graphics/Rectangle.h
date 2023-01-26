#pragma once

#include "Figure.h"
#include "Point.h"

/**
* @brief �����, ����������� �������������.
*/
class Rectangle : public Figure {
public:
	Rectangle(const Point& llp, const Point& hrp, const std::string& id) :
		Figure(id), low_left_point(llp), high_right_point(hrp) {}

	/**
	* �������� ����� ������ ����.
	*/
	Point get_low_left_point() { return low_left_point; }

	/**
	* �������� ������ ������� ����.
	*/
	Point get_high_right_point() { return high_right_point; }

	/**
	* @return ������ ��� ������.
	*/
	std::string get_type() override { return "Rectangle"; }

private:
	Point low_left_point;   // ����� ������ ����.
	Point high_right_point; // ������ ������� ����.
};