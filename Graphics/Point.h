#pragma once

/**
* @brief  ласс, описывающий одну точку с заданными координатами. Ётот класс не наследует Figure и
* его нельз€ добавить в коллекцию фигур на графической области.
*/
class Point {
public:
	Point() : _x(0), _y(0) {}
	
	explicit Point(int x, int y) : _x(x), _y(y) {}
	
	Point(const Point& point) : _x(point._x), _y(point._y) {}
	
	Point(Point&& point) noexcept : _x(point._x), _y(point._y) {}

	void set_x(int x) { _x = x; }
	void set_y(int y) { _y = y; }

	int get_x() { return _x; }
	int get_y() { return _y; }

private:
	int _x;
	int _y;
};