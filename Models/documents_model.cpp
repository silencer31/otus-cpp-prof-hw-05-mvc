#include "documents_model.h"

#include <iostream>

void DocumentsModel::create_document()
{
	std::string doc_id = "doc_" + std::to_string(last_number);
	last_number++;

	shared_document new_doc = std::make_shared<Document>(doc_id);
		
	documents.push_back(new_doc);
	current_document = documents.back();

	std::cout << "\nNew document with id " << doc_id << " has been created" << std::endl;
	
	notify();
}

void DocumentsModel::import_document_from_file(const std::string& file_path)
{
	/*
	* Некий код с открытием файла и добавлением документа в коллекцию.
	*/

	std::cout << "Document has been imported from file: " << file_path << std::endl;

	notify();
}

void DocumentsModel::export_document_to_file(const std::string& doc_id, const std::string& file_path)
{
	/*
	* Берём содержимое графической модели и записываем в указанный файл.
	*/

	// Указанный файл устанавливаем как текущий.
	current_file = file_path;

	std::cout << "Document with id: " << doc_id << " has been exported to file : " << file_path << std::endl;
}

void DocumentsModel::export_document(const std::string& doc_id)
{
	if (current_file.empty()) {
		return;
	}

	std::cout << "Document with id: " << doc_id << " has been exported to file : " << current_file << std::endl;
}

void DocumentsModel::close_document(const std::string& doc_id)
{
	std::cout << "Document with id: " << doc_id << " has been closed" << std::endl;

	notify();
}

void DocumentsModel::output_info()
{
	std::cout << "\nDocuments Model info. Number of items: " << documents.size() << std::endl;
	for (vector_document::iterator it = documents.begin(); it != documents.end(); ++it)
	{
		std::cout << "Document id: " << (*it)->get_document_id() << std::endl;
	}
}

void DocumentsModel::update()
{
	if (current_document == nullptr) {
		return;
	}
	
	/*
	* При желании, здесь можно релизовать синхронизацию между содержимым графической модели и содержимым документа.
	*/

	std::cout << "Current document with id " << current_document->get_document_id() << " has been updated" << std::endl;
} 