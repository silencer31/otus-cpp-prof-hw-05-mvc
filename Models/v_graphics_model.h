#pragma once

#include <vector>
#include <memory>
#include <string>

#include "../Observ/observer.h"
#include "../Graphics/Figure.h"

/**
* @brief ����� - ��������� ��� ������ � ������������ ���������.
*/
class VGraphicsModel : public Observable {
public:

	/**
	* ���������� ��������� �� ����������� ������� ���������.
	* @param figure_ptr ����� ��������� �� ������-��������.
	*/
	virtual void add_figure(const shared_figure& figure_ptr) = 0;

	/**
	* �������� ��������� �� ����������� �������.
	* @param figure_id ������������� ������.
	*/
	virtual void delete_figure(const std::string& figure_id) = 0;

	/**
	* �������� ��� ����������� �������.
	*/
	virtual vector_figure get_all_graphic_objects() = 0;

	/**
	* �������� ������� ����������� ������.
	*/
	virtual shared_figure get_current_figure() = 0;

	/**
	* ������� ��� ����������� ������� �� ���������.
	*/
	virtual void clear() = 0;

	/**
	* @return ����� ��� �������� ����������� �������������� ������������ ��������.
	*/
	virtual uint32_t get_last_number() = 0;

	/**
	* ����� ����� ���������� ��� ������������ ������ ��������.
	*/
	virtual void output_info() = 0;
};