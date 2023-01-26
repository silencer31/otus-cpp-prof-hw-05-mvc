#pragma once

#include "v_documents_model.h"
#include "v_graphics_model.h"

/**
* @brief ����� - ������ ��� �������� ���������� � ������ � ����.
*/
class DocumentsModel : public VDocumentsModel {
public:
	DocumentsModel() = delete;

	explicit DocumentsModel(const std::shared_ptr<VGraphicsModel>& gr_mdl) :
		graphics_model(gr_mdl), current_document(nullptr), last_number(1) {}

	~DocumentsModel() = default;

	/**
	* ������� ����� ��������.
	*/
	void create_document() override;

	/**
	* ������ ��������� �� �����. ������ - ������� ��������.
	* @param file_path ���� � �����, ������� ��������� �������.
	*/
	void import_document_from_file(const std::string& file_path) override;

	/**
	* ������� ��������� � ��������� ����.
	* @param doc_id ������������� ������������ ���������.
	* @param file_path ����, �� �������� ����� �������� ���� � ����������.
	*/
	void export_document_to_file(const std::string& doc_id, const std::string& file_path) override;

	/**
	* ������� ��������� � ����, ������� ��� ��� ����� ������. ������ - ��������� ��������.
	* @param doc_id ������������� ������������ ���������.
	*/
	void export_document(const std::string& doc_id) override;

	/**
	* ������� ��������.
	* @param doc_id ������������� ������������ ���������.
	*/
	void close_document(const std::string& doc_id) override;

	/**
	* @return �������� ��� ��������.
	*/
	vector_document get_all_documents() override {
		return documents;
	}

	/**
	* @return �������� ������� ��������.
	*/
	shared_document get_current_document() override {
		return current_document;
	}

	/**
	* ������� ��� ��������� �� ���������.
	*/
	void clear() override {
		documents.clear();
		notify();
	}

	/**
	* ����� ����� ���������� ��� ������������ ������ ��������.
	*/
	void output_info() override;

	/**
	* ������� �� ��������� � ������ � ������������ ���������.
	*/
	void update() override;

private:
	vector_document documents; // ��������� ���������� � ������.

	shared_document current_document; // ������� ��������.

	std::string current_file; // ����, � ������� �������������� ������� ���.

	std::shared_ptr<VGraphicsModel> graphics_model; // ��� ����� � ������� � ������������ ���������.

	uint32_t last_number; // ��� ��������� ����������� �������������� ���������.
};