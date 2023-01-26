#include "graphics_model.h"

#include <iostream>

#include <vector>


void GraphicsModel::add_figure(const shared_figure& figure_ptr)
{
	std::cout << "\nNew figure " << figure_ptr->get_type() << " with id " << figure_ptr->get_id() << " has been added" << std::endl;
	
    figures.push_back(figure_ptr);
    last_number++;

    notify();
}

void GraphicsModel::delete_figure(const std::string& figure_id)
{
    for (vector_figure::iterator it = figures.begin(); it != figures.end(); it++)
    {
        if ((*it)->get_id() == figure_id) {
            it = figures.erase(it);
            
            std::cout << "Figure with id " << figure_id << " has been deleted" << std::endl;
            
            break;
        }
    }
	
    notify();
}


void GraphicsModel::output_info()
{
    std::cout << "\nGraphics Model info. Number of items: " << figures.size() << std::endl;
    
    for (vector_figure::iterator it = figures.begin(); it != figures.end(); it++)
    {
        std::cout << "Figure type: " << (*it)->get_type() << " id: " << (*it)->get_id() << std::endl;
    }
}