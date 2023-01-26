#include "graphics_view.h"

GraphicsView::GraphicsView(const std::shared_ptr<VGraphicsModel>& graph_mdl) :
	graphics_model(graph_mdl) {}


void GraphicsView::update()
{
	graphics_model->output_info();
}
