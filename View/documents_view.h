#pragma once

#include <memory>

#include "../Observ/observer.h"
#include "../Models/v_documents_model.h"

/**
* @brief Класс, описывающий View для документов.
* Под отображением документа подразумевается не отрисовка всей графики внутри, а некий вывод миниатюры и сводки о содержимом.
*/
class DocumentsView : public Observer {
public:
	DocumentsView(const std::shared_ptr<VDocumentsModel>& docs_mdl);
	
	/**
	* Реакция на изменения в модели с документами.
	*/
	void update() override;

private:
	std::shared_ptr<VDocumentsModel> documents_model;
};