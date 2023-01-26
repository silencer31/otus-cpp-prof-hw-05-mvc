#include "lib.h"

#include "Models/graphics_model.h"
#include "Models/documents_model.h"

#include "View/graphics_view.h"
#include "View/documents_view.h"

#include "Controller/GraphicsController.h"
#include "Controller/DocumentsController.h"

/**
 * @file main.cpp
 *
 * Simple vector graphcs editor.
 */

int main (int, char **) {
    // Создаем модели данных.
    std::shared_ptr<GraphicsModel>  graphics_model  = std::make_shared<GraphicsModel>(100, 100);
    std::shared_ptr<DocumentsModel> documents_model = std::make_shared<DocumentsModel>(graphics_model);

    // Создаем контролеры.
    std::shared_ptr<GraphicsController>  graphics_controller  = std::make_shared<GraphicsController>(graphics_model);
    std::shared_ptr<DocumentsController> documents_controller = std::make_shared<DocumentsController>(documents_model);

    // Получаем указатели на View
    auto graphics_view  = graphics_controller->get_view();
    auto documents_view = documents_controller->get_view();

    documents_controller->create_document();

    graphics_controller->create_dot( Point(2, 3) );
    graphics_controller->create_line( Point(2, 3), Point(9, 23) );
    graphics_controller->create_circle( Point(30, 30), 15 );
    graphics_controller->create_rectangle( Point(2, 3), Point(41, 8) );

    return 0;
}
