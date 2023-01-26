#pragma once

#include "Figure.h"
#include "Point.h"

/**
* @brief �����, ����������� ���� � �������� ������� � ��������.
*/
class Circle : public Figure {
public:
	Circle(const Point& ctr, const uint32_t& rds, const std::string& id) :
		Figure(id), center(ctr), radius(rds) {}

	/**
	* @return �������� ����� ������.
	*/
	Point get_center() { return center; }

	/**
	* @return ������ ������ �����.
	*/
	uint32_t get_radius() { return radius; }

	/**
	* @return ������ ��� ������.
	*/
	std::string get_type() override { return "Circle"; }

private:
	Point center;
	uint32_t radius;
};