#pragma once

#include <vector>
#include <memory>
#include <string>

#include "../Observ/observer.h"
#include "../Graphics/Figure.h"

/**
* @brief Класс - интерфейс для модели с графическими объектами.
*/
class VGraphicsModel : public Observable {
public:

	/**
	* Добавление примитива на графическую область редактора.
	* @param figure_ptr умный указатель на фигуру-примитив.
	*/
	virtual void add_figure(const shared_figure& figure_ptr) = 0;

	/**
	* Удаление примитива из графической области.
	* @param figure_id идентификатор фигуры.
	*/
	virtual void delete_figure(const std::string& figure_id) = 0;

	/**
	* Получить все графические объекты.
	*/
	virtual vector_figure get_all_graphic_objects() = 0;

	/**
	* Получить текущий графический объект.
	*/
	virtual shared_figure get_current_figure() = 0;

	/**
	* Удалить все графические объекты из коллекции.
	*/
	virtual void clear() = 0;

	/**
	* @return номер для создания уникального идентификатора графического элемента.
	*/
	virtual uint32_t get_last_number() = 0;

	/**
	* Вывод общей информации для тестирования работы паттерна.
	*/
	virtual void output_info() = 0;
};