#pragma once

#include <vector>
#include <string>
#include <memory>

/**
* @brief ������� ����� ��� ���� ����������� ��������.
*/
class Figure {
public:
	Figure() : figure_id("unknown") {}

	Figure(const std::string& id) : figure_id(id) {}

	/**
	* @return �������� id ������.
	*/
	std::string get_id() { return figure_id; }

	/**
	* @return ������ ��� ������.
	*/
	virtual std::string get_type() = 0;
		

private:
	std::string figure_id; // ������������� ������.
};

using shared_figure = std::shared_ptr<Figure>;
using vector_figure = std::vector<std::shared_ptr<Figure>>;