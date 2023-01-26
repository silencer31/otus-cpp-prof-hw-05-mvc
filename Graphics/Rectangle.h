#pragma once

#include "Figure.h"
#include "Point.h"

/**
* @brief Класс, описывающий прямоугольник.
*/
class Rectangle : public Figure {
public:
	Rectangle(const Point& llp, const Point& hrp, const std::string& id) :
		Figure(id), low_left_point(llp), high_right_point(hrp) {}

	/**
	* Получить левый нижний угол.
	*/
	Point get_low_left_point() { return low_left_point; }

	/**
	* Получить правый верхний угол.
	*/
	Point get_high_right_point() { return high_right_point; }

	/**
	* @return Узнать тип фигуры.
	*/
	std::string get_type() override { return "Rectangle"; }

private:
	Point low_left_point;   // Левый нижний угол.
	Point high_right_point; // Правый верхний угол.
};