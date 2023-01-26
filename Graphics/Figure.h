#pragma once

#include <vector>
#include <string>
#include <memory>

/**
* @brief Базовый класс для всех графических объектов.
*/
class Figure {
public:
	Figure() : figure_id("unknown") {}

	Figure(const std::string& id) : figure_id(id) {}

	/**
	* @return Получить id фигуры.
	*/
	std::string get_id() { return figure_id; }

	/**
	* @return Узнать тип фигуры.
	*/
	virtual std::string get_type() = 0;
		

private:
	std::string figure_id; // Идентификатор фигуры.
};

using shared_figure = std::shared_ptr<Figure>;
using vector_figure = std::vector<std::shared_ptr<Figure>>;