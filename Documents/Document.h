#pragma once

#include <string>

#include "../Graphics/Figure.h"


/**
* @brief �����, ����������� ��������.
*/
class Document {
public:
	Document() : document_id("unknown") {}

	explicit Document(const std::string& doc_id) : document_id(doc_id) {}

	~Document() = default;

	/**
	* @return �������� id ���������.
	*/
	std::string get_document_id() { return document_id; }

	/**
	* ���������� ������������ ������� � ��������.
	* @param figure_ptr ����� ��������� �� ����������� ������.
	*/
	void add_figure(const shared_figure& figure_ptr) {
		graphic_objects.push_back(figure_ptr);
	}

	/**
	* ������� ��� ����������� ������� �� ���������.
	*/
	void clear() {
		graphic_objects.clear();
	}

private:
	std::string document_id; // ������������� ���������.

	vector_figure graphic_objects; // ����������� �������, �������������� � ���������.
};

using shared_document = std::shared_ptr<Document>;
using vector_document = std::vector<std::shared_ptr<Document>>;