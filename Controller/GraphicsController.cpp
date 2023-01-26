#include "GraphicsController.h"

#include "../Graphics/Dot.h"
#include "../Graphics/Line.h"
#include "../Graphics/Circle.h"
#include "../Graphics/Rectangle.h"

void GraphicsController::create_dot(const Point& p1)
{
	std::string figure_id = "figure_" + std::to_string(graphics_model->get_last_number());

	shared_figure new_figure = std::make_shared<Dot>(p1, figure_id);

	graphics_model->add_figure(new_figure);
}

void GraphicsController::create_line(const Point& p1, const Point& p2)
{
	std::string figure_id = "figure_" + std::to_string(graphics_model->get_last_number());

	shared_figure new_figure = std::make_shared<Line>(p1, p2, figure_id);

	graphics_model->add_figure(new_figure);
}

void GraphicsController::create_circle(const Point& p1, const uint32_t& radius)
{
	std::string figure_id = "figure_" + std::to_string(graphics_model->get_last_number());

	shared_figure new_figure = std::make_shared<Circle>(p1, radius, figure_id);

	graphics_model->add_figure(new_figure);
}

void GraphicsController::create_rectangle(const Point& p1, const Point& p2)
{
	std::string figure_id = "figure_" + std::to_string(graphics_model->get_last_number());

	shared_figure new_figure = std::make_shared<Rectangle>(p1, p2, figure_id);

	graphics_model->add_figure(new_figure);
}


void GraphicsController::delete_object(const std::string& figure_id)
{
	graphics_model->delete_figure(figure_id);
}