#include "ServerStartDialog.h"

ServerStartDialog::ServerStartDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, this, &ServerStartDialog::Start);
}

ServerStartDialog::~ServerStartDialog()
{
}

void ServerStartDialog::Start() {
	this->accept();
}

