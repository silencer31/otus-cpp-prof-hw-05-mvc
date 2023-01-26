#pragma once

#include "Figure.h"
#include "Point.h"

/**
* @brief Класс, описывающий одну точку на графической области.
* Может быть добавлен в коллекцию фигур, т.к. наследует класс Figure.
*/
class Dot : public Figure {
public:
	Dot(int x, int y, const std::string& id) : Figure(id), position( Point( x, y )) {}

	Dot(const Point& psn, const std::string& id) : Figure(id), position(psn) {}

	/**
	* @return Получить координаты точки.
	*/
	Point get_position() { return position; }

	/**
	* @return Узнать тип фигуры.
	*/
	std::string get_type() override { return "Dot"; }

private:
	Point position;
};