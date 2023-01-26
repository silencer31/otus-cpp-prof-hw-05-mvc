#pragma once

#include "Figure.h"
#include "Point.h"

/**
* @brief Класс, описывающий линию от точки до точки.
*/
class Line : public Figure {
public:
	Line(const Point& spt, const Point& fpt, const std::string& id) :
		Figure(id), start_point(spt), finish_point(fpt) {}

	/**
	* Получить точку начала.
	*/
	Point get_start_point() { return start_point; }

	/**
	* Получить точку конца.
	*/
	Point get_finish_point() { return finish_point; }

	/**
	* Узнать тип фигуры.
	*/
	std::string get_type() override { return "Line"; }

private:
	Point start_point;
	Point finish_point;
};