#include "ConnectDialog.h"

ConnectDialog::ConnectDialog(QWidget *parent)
	: QDialog(parent) {


	ui.setupUi(this);

	connect(ui.connect, SIGNAL(released()), this, SLOT(Connect()));

}

ConnectDialog::~ConnectDialog()
{
}

void ConnectDialog::Connect() {
	this->accept();

}

