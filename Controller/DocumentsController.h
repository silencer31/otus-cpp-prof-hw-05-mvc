#pragma once

#include <memory>

#include "../Models/documents_model.h"
#include "../View/documents_view.h"

/**
* @brief �����, ����������� ���������� �� ������ � �����������.
*/
class DocumentsController {
public:
	DocumentsController() = delete;

	explicit DocumentsController(const std::shared_ptr<VDocumentsModel>& doc_mdl) : documents_model(doc_mdl) {
		// ������� View � �������� �� ��������� �� ������ � �����������.
		documents_view = std::make_shared<DocumentsView>(documents_model);

		// � ������ ��������� View ��� ������������.
		documents_model->attach(documents_view);
	}

	~DocumentsController() {
		documents_model->detach(documents_view);
	}

	/**
	* �������� ������ ���������.
	*/
	void create_document();

	/**
	* ������ ��������� �� �����.
	* @param file_path ���� � �����.
	*/
	void import_document_from_file(const std::string& file_path);

	/**
	* ������� ��������� � ��������� ����.
	* @param doc_id ������������� ���������.
	* @param file_path ���� � �����.
	*/
	void export_document_to_file(const std::string& doc_id, const std::string& file_path);

	/**
	* ������� ��������� � ������� ����.
	* @param doc_id ������������� ���������.
	*/
	void export_document(const std::string& doc_id);

	/**
	* �������� ���������.
	* @param doc_id ������������� ���������.
	*/
	void close_document(const std::string& doc_id);

	/**
	* @return ��������� �� View.
	*/
	std::shared_ptr<DocumentsView> get_view() {
		return documents_view;
	}

private:
	std::shared_ptr<VDocumentsModel> documents_model;

	std::shared_ptr<DocumentsView> documents_view;
};