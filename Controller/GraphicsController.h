#pragma once

#include <memory>

#include "../Models/graphics_model.h"
#include "../View/graphics_view.h"
#include "../Graphics/Point.h"

/**
* @brief Класс, описывающий контроллер по работе с графическими объектами.
*/
class GraphicsController {
public:
	GraphicsController() = delete;

	explicit GraphicsController(const std::shared_ptr<VGraphicsModel>& gr_mdl) : graphics_model(gr_mdl) {
		// Создаем View и передаем ей указатель на модель с графикой.
		graphics_view = std::make_shared<GraphicsView>(graphics_model);
		
		// У модели указываем View как обозреватель.
		graphics_model->attach(graphics_view);
	}
	
	~GraphicsController() {
		graphics_model->detach(graphics_view);
	}

	/**
	* Создание графического объекта - точки.
	* @param p1 координаты.
	*/
	void create_dot(const Point& p1);

	/**
	* Создание графического объекта - линии.
	* @param p1 координаты первой точки.
	* @param p2 координаты второй точки.
	*/
	void create_line(const Point& p1, const Point& p2);

	/**
	* Создание графического объекта - круга.
	* @param p1 координаты центра.
	* @param radius радиус круга.
	*/
	void create_circle(const Point& p1, const uint32_t& radius);

	/**
	* Создание графического объекта - прямоугольника.
	* @param p1 координаты левого нижнего угла.
	* @param p2 координаты правого верхнего угла.
	*/
	void create_rectangle(const Point& p1, const Point& p2);
	
	/**
	* Удаление графического объекта.
	* @param figure_id идентификатор фигуры.
	*/
	void delete_object(const std::string& figure_id);

	/**
	* @return указатель на View.
	*/
	std::shared_ptr<GraphicsView> get_view() { 
		return graphics_view;
	}

private:
	std::shared_ptr<VGraphicsModel> graphics_model;

	std::shared_ptr<GraphicsView> graphics_view;
};