#pragma once

#include "../Observ/observer.h"
#include "../Documents/Document.h"

/**
* @brief ����� - ��������� ��� ������ � �����������.
*/
class VDocumentsModel : public Observable, Observer {
public:

	/**
	* ������� ����� ��������.
	*/
	virtual void create_document() = 0;

	/**
	* ������ ��������� �� �����. ������ - ������� ��������.
	* @param file_path ���� � �����, ������� ��������� �������.
	*/
	virtual void import_document_from_file(const std::string& file_path) = 0;

	/**
	* ������� ��������� � ��������� ����.
	* @param doc_id ������������� ������������ ���������.
	* @param file_path ����, �� �������� ����� �������� ���� � ����������.
	*/
	virtual void export_document_to_file(const std::string& doc_id, const std::string& file_path) = 0;

	/**
	* ������� ��������� � ����, ������� ��� ��� ����� ������. ������ - ��������� ��������.
	* @param doc_id ������������� ������������ ���������.
	*/
	virtual void export_document(const std::string& doc_id) = 0;

	/**
	* ������� ��������.
	* @param doc_id ������������� ������������ ���������.
	*/
	virtual void close_document(const std::string& doc_id) = 0;

	/**
	* �������� ��� ��������.
	*/
	virtual vector_document get_all_documents() = 0;

	/**
	* �������� ������� ��������.
	*/
	virtual shared_document get_current_document() = 0;

	/**
	* ������� ��� ��������� �� ���������.
	*/
	virtual void clear() = 0;

	/**
	* ����� ����� ���������� ��� ������������ ������ ��������.
	*/
	virtual void output_info() = 0;
};