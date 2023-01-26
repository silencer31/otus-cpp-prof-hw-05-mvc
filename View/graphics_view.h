#pragma once

#include <memory>

#include "../Observ/observer.h"
#include "../Models/v_graphics_model.h"

/**
* @brief Класс, описывающий View для графических объектов.
*/
class GraphicsView: public Observer {
public:
	GraphicsView() = delete;

	explicit GraphicsView(const std::shared_ptr<VGraphicsModel>& graph_mdl);
	
	/**
	* Реакция на изменения в модели с графическими объектами.
	*/
	void update() override;

private:
	std::shared_ptr<VGraphicsModel> graphics_model;
};
