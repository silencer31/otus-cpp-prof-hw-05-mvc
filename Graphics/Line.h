#pragma once

#include "Figure.h"
#include "Point.h"

/**
* @brief �����, ����������� ����� �� ����� �� �����.
*/
class Line : public Figure {
public:
	Line(const Point& spt, const Point& fpt, const std::string& id) :
		Figure(id), start_point(spt), finish_point(fpt) {}

	/**
	* �������� ����� ������.
	*/
	Point get_start_point() { return start_point; }

	/**
	* �������� ����� �����.
	*/
	Point get_finish_point() { return finish_point; }

	/**
	* ������ ��� ������.
	*/
	std::string get_type() override { return "Line"; }

private:
	Point start_point;
	Point finish_point;
};