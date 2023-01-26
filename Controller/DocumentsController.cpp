#include "DocumentsController.h"

void DocumentsController::create_document()
{
	documents_model->create_document();
}

void DocumentsController::import_document_from_file(const std::string& file_path)
{
	documents_model->import_document_from_file(file_path);
}

void DocumentsController::export_document_to_file(const std::string& doc_id, const std::string& file_path)
{
	documents_model->export_document_to_file(doc_id, file_path);
}

void DocumentsController::export_document(const std::string& doc_id)
{
	documents_model->export_document(doc_id);
}

void DocumentsController::close_document(const std::string& doc_id)
{
	documents_model->close_document(doc_id);
}