#pragma once

#include <memory>

#include "../Models/graphics_model.h"
#include "../View/graphics_view.h"
#include "../Graphics/Point.h"

/**
* @brief �����, ����������� ���������� �� ������ � ������������ ���������.
*/
class GraphicsController {
public:
	GraphicsController() = delete;

	explicit GraphicsController(const std::shared_ptr<VGraphicsModel>& gr_mdl) : graphics_model(gr_mdl) {
		// ������� View � �������� �� ��������� �� ������ � ��������.
		graphics_view = std::make_shared<GraphicsView>(graphics_model);
		
		// � ������ ��������� View ��� ������������.
		graphics_model->attach(graphics_view);
	}
	
	~GraphicsController() {
		graphics_model->detach(graphics_view);
	}

	/**
	* �������� ������������ ������� - �����.
	* @param p1 ����������.
	*/
	void create_dot(const Point& p1);

	/**
	* �������� ������������ ������� - �����.
	* @param p1 ���������� ������ �����.
	* @param p2 ���������� ������ �����.
	*/
	void create_line(const Point& p1, const Point& p2);

	/**
	* �������� ������������ ������� - �����.
	* @param p1 ���������� ������.
	* @param radius ������ �����.
	*/
	void create_circle(const Point& p1, const uint32_t& radius);

	/**
	* �������� ������������ ������� - ��������������.
	* @param p1 ���������� ������ ������� ����.
	* @param p2 ���������� ������� �������� ����.
	*/
	void create_rectangle(const Point& p1, const Point& p2);
	
	/**
	* �������� ������������ �������.
	* @param figure_id ������������� ������.
	*/
	void delete_object(const std::string& figure_id);

	/**
	* @return ��������� �� View.
	*/
	std::shared_ptr<GraphicsView> get_view() { 
		return graphics_view;
	}

private:
	std::shared_ptr<VGraphicsModel> graphics_model;

	std::shared_ptr<GraphicsView> graphics_view;
};