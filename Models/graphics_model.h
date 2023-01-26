#pragma once

#include "v_graphics_model.h"

/**
* @brief Класс - модель для хранения графических объектов и предоставления их для сохранения в документе.
*/
class GraphicsModel : public VGraphicsModel {
public:
	GraphicsModel() : width(10), height(10), last_number(1) {}

	explicit GraphicsModel(const size_t& w, const size_t& h) : width(w), height(h), last_number(1) {}

	~GraphicsModel() = default;

	/**
	* Добавление примитива на графическую область редактора.
	* @param figure_ptr умный указатель на фигуру-примитив.
	*/
	void add_figure(const shared_figure& figure_ptr) override;

	/**
	* Удаление примитива из графической области.
	* @param figure_id идентификатор фигуры.
	*/
	void delete_figure(const std::string& figure_id) override;

	/**
	* @return Получить все графические объекты.
	*/
	vector_figure get_all_graphic_objects() override {
		return figures;
	}

	/**
	* @return Получить текущий графический объект.
	*/
	shared_figure get_current_figure() override {
		return current_figure;
	}

	/**
	* Удалить все графические объекты из коллекции.
	*/
	void clear() override {
		figures.clear();
		notify();
	}

	/**
	* @return номер для создания уникального идентификатора графического элемента.
	*/
	uint32_t get_last_number() override {
		return last_number;
	}

	/**
	* Вывод общей информации для тестирования работы паттерна.
	*/
	void output_info() override;

	void resize(const size_t& w, const size_t& h) {
		width = w;
		height = h;
	}

private:
	vector_figure figures; // Коллекция с графическими объектами.

	shared_figure current_figure; // Текущий графический объект.

	size_t width;  // Ширина графической области.
	size_t height; // Высота графической области.

	uint32_t last_number; // Для генерации уникального идентификатора графического объекта.
};