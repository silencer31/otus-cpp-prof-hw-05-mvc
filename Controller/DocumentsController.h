#pragma once

#include <memory>

#include "../Models/documents_model.h"
#include "../View/documents_view.h"

/**
* @brief Класс, описывающий контроллер по работе с документами.
*/
class DocumentsController {
public:
	DocumentsController() = delete;

	explicit DocumentsController(const std::shared_ptr<VDocumentsModel>& doc_mdl) : documents_model(doc_mdl) {
		// Создаем View и передаем ей указатель на модель с документами.
		documents_view = std::make_shared<DocumentsView>(documents_model);

		// У модели указываем View как обозреватель.
		documents_model->attach(documents_view);
	}

	~DocumentsController() {
		documents_model->detach(documents_view);
	}

	/**
	* Создание нового документа.
	*/
	void create_document();

	/**
	* Импорт документа из файла.
	* @param file_path путь к файлу.
	*/
	void import_document_from_file(const std::string& file_path);

	/**
	* Экспорт документа в указанный файл.
	* @param doc_id идентификатор документа.
	* @param file_path путь к файлу.
	*/
	void export_document_to_file(const std::string& doc_id, const std::string& file_path);

	/**
	* Экспорт документа в текущий файл.
	* @param doc_id идентификатор документа.
	*/
	void export_document(const std::string& doc_id);

	/**
	* Закрытие документа.
	* @param doc_id идентификатор документа.
	*/
	void close_document(const std::string& doc_id);

	/**
	* @return указатель на View.
	*/
	std::shared_ptr<DocumentsView> get_view() {
		return documents_view;
	}

private:
	std::shared_ptr<VDocumentsModel> documents_model;

	std::shared_ptr<DocumentsView> documents_view;
};