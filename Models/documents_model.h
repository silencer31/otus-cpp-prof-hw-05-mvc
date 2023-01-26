#pragma once

#include "v_documents_model.h"
#include "v_graphics_model.h"

/**
* @brief Класс - модель для хранения документов и работы с ними.
*/
class DocumentsModel : public VDocumentsModel {
public:
	DocumentsModel() = delete;

	explicit DocumentsModel(const std::shared_ptr<VGraphicsModel>& gr_mdl) :
		graphics_model(gr_mdl), current_document(nullptr), last_number(1) {}

	~DocumentsModel() = default;

	/**
	* Создать новый документ.
	*/
	void create_document() override;

	/**
	* Импорт документа из файла. Аналог - Открыть документ.
	* @param file_path путь к файлу, который требуется открыть.
	*/
	void import_document_from_file(const std::string& file_path) override;

	/**
	* Экспорт документа в указанный файл.
	* @param doc_id идентификатор сохраняемого документа.
	* @param file_path путь, по которому будет сохранен файл с документом.
	*/
	void export_document_to_file(const std::string& doc_id, const std::string& file_path) override;

	/**
	* Экспорт документа в файл, который уже был ранее указан. Аналог - Сохранить документ.
	* @param doc_id идентификатор сохраняемого документа.
	*/
	void export_document(const std::string& doc_id) override;

	/**
	* Закрыть документ.
	* @param doc_id идентификатор закрываемого документа.
	*/
	void close_document(const std::string& doc_id) override;

	/**
	* @return Получить все докумены.
	*/
	vector_document get_all_documents() override {
		return documents;
	}

	/**
	* @return Получить текущий документ.
	*/
	shared_document get_current_document() override {
		return current_document;
	}

	/**
	* Удалить все документы из коллекции.
	*/
	void clear() override {
		documents.clear();
		notify();
	}

	/**
	* Вывод общей информации для тестирования работы паттерна.
	*/
	void output_info() override;

	/**
	* Реакция на изменения в модели с графическими объектами.
	*/
	void update() override;

private:
	vector_document documents; // Коллекция документов в модели.

	shared_document current_document; // Текущий документ.

	std::string current_file; // Файл, в который экспортировали прошлый раз.

	std::shared_ptr<VGraphicsModel> graphics_model; // Для связи с моделью с графическими объектами.

	uint32_t last_number; // Для генерации уникального идентификатора документа.
};