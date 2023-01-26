#pragma once

#include <memory>

#include "../Observ/observer.h"
#include "../Models/v_documents_model.h"

/**
* @brief �����, ����������� View ��� ����������.
* ��� ������������ ��������� ��������������� �� ��������� ���� ������� ������, � ����� ����� ��������� � ������ � ����������.
*/
class DocumentsView : public Observer {
public:
	DocumentsView(const std::shared_ptr<VDocumentsModel>& docs_mdl);
	
	/**
	* ������� �� ��������� � ������ � �����������.
	*/
	void update() override;

private:
	std::shared_ptr<VDocumentsModel> documents_model;
};