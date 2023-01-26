#pragma once

#include "Figure.h"
#include "Point.h"

/**
* @brief Класс, описывающий круг с заданным центром и радиусом.
*/
class Circle : public Figure {
public:
	Circle(const Point& ctr, const uint32_t& rds, const std::string& id) :
		Figure(id), center(ctr), radius(rds) {}

	/**
	* @return Получить точку центра.
	*/
	Point get_center() { return center; }

	/**
	* @return Узнать радиус круга.
	*/
	uint32_t get_radius() { return radius; }

	/**
	* @return Узнать тип фигуры.
	*/
	std::string get_type() override { return "Circle"; }

private:
	Point center;
	uint32_t radius;
};