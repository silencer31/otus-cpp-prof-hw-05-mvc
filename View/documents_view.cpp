#include "documents_view.h"

DocumentsView::DocumentsView(const std::shared_ptr<VDocumentsModel>& docs_mdl) :
	documents_model(docs_mdl) {}

void DocumentsView::update()
{
	documents_model->output_info();
}