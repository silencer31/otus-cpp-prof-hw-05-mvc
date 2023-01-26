#pragma once

#include <string>

#include "../Graphics/Figure.h"


/**
* @brief Класс, описывающий документ.
*/
class Document {
public:
	Document() : document_id("unknown") {}

	explicit Document(const std::string& doc_id) : document_id(doc_id) {}

	~Document() = default;

	/**
	* @return Получить id документа.
	*/
	std::string get_document_id() { return document_id; }

	/**
	* Добавление графического объекта в документ.
	* @param figure_ptr умный указатель на графический объект.
	*/
	void add_figure(const shared_figure& figure_ptr) {
		graphic_objects.push_back(figure_ptr);
	}

	/**
	* Удалить все графические объекты из документа.
	*/
	void clear() {
		graphic_objects.clear();
	}

private:
	std::string document_id; // Идентификатор документа.

	vector_figure graphic_objects; // Графические объекты, присутствующие в документе.
};

using shared_document = std::shared_ptr<Document>;
using vector_document = std::vector<std::shared_ptr<Document>>;