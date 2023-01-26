#pragma once

#include "Figure.h"
#include "Point.h"

/**
* @brief �����, ����������� ���� ����� �� ����������� �������.
* ����� ���� �������� � ��������� �����, �.�. ��������� ����� Figure.
*/
class Dot : public Figure {
public:
	Dot(int x, int y, const std::string& id) : Figure(id), position( Point( x, y )) {}

	Dot(const Point& psn, const std::string& id) : Figure(id), position(psn) {}

	/**
	* @return �������� ���������� �����.
	*/
	Point get_position() { return position; }

	/**
	* @return ������ ��� ������.
	*/
	std::string get_type() override { return "Dot"; }

private:
	Point position;
};