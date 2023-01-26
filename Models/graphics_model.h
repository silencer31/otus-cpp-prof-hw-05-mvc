#pragma once

#include "v_graphics_model.h"

/**
* @brief ����� - ������ ��� �������� ����������� �������� � �������������� �� ��� ���������� � ���������.
*/
class GraphicsModel : public VGraphicsModel {
public:
	GraphicsModel() : width(10), height(10), last_number(1) {}

	explicit GraphicsModel(const size_t& w, const size_t& h) : width(w), height(h), last_number(1) {}

	~GraphicsModel() = default;

	/**
	* ���������� ��������� �� ����������� ������� ���������.
	* @param figure_ptr ����� ��������� �� ������-��������.
	*/
	void add_figure(const shared_figure& figure_ptr) override;

	/**
	* �������� ��������� �� ����������� �������.
	* @param figure_id ������������� ������.
	*/
	void delete_figure(const std::string& figure_id) override;

	/**
	* @return �������� ��� ����������� �������.
	*/
	vector_figure get_all_graphic_objects() override {
		return figures;
	}

	/**
	* @return �������� ������� ����������� ������.
	*/
	shared_figure get_current_figure() override {
		return current_figure;
	}

	/**
	* ������� ��� ����������� ������� �� ���������.
	*/
	void clear() override {
		figures.clear();
		notify();
	}

	/**
	* @return ����� ��� �������� ����������� �������������� ������������ ��������.
	*/
	uint32_t get_last_number() override {
		return last_number;
	}

	/**
	* ����� ����� ���������� ��� ������������ ������ ��������.
	*/
	void output_info() override;

	void resize(const size_t& w, const size_t& h) {
		width = w;
		height = h;
	}

private:
	vector_figure figures; // ��������� � ������������ ���������.

	shared_figure current_figure; // ������� ����������� ������.

	size_t width;  // ������ ����������� �������.
	size_t height; // ������ ����������� �������.

	uint32_t last_number; // ��� ��������� ����������� �������������� ������������ �������.
};