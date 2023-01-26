#pragma once

#include "../Observ/observer.h"
#include "../Documents/Document.h"

/**
* @brief Класс - интерфейс для модели с документами.
*/
class VDocumentsModel : public Observable, Observer {
public:

	/**
	* Создать новый документ.
	*/
	virtual void create_document() = 0;

	/**
	* Импорт документа из файла. Аналог - Открыть документ.
	* @param file_path путь к файлу, который требуется открыть.
	*/
	virtual void import_document_from_file(const std::string& file_path) = 0;

	/**
	* Экспорт документа в указанный файл.
	* @param doc_id идентификатор сохраняемого документа.
	* @param file_path путь, по которому будет сохранен файл с документом.
	*/
	virtual void export_document_to_file(const std::string& doc_id, const std::string& file_path) = 0;

	/**
	* Экспорт документа в файл, который уже был ранее указан. Аналог - Сохранить документ.
	* @param doc_id идентификатор сохраняемого документа.
	*/
	virtual void export_document(const std::string& doc_id) = 0;

	/**
	* Закрыть документ.
	* @param doc_id идентификатор закрываемого документа.
	*/
	virtual void close_document(const std::string& doc_id) = 0;

	/**
	* Получить все докумены.
	*/
	virtual vector_document get_all_documents() = 0;

	/**
	* Получить текущий документ.
	*/
	virtual shared_document get_current_document() = 0;

	/**
	* Удалить все документы из коллекции.
	*/
	virtual void clear() = 0;

	/**
	* Вывод общей информации для тестирования работы паттерна.
	*/
	virtual void output_info() = 0;
};