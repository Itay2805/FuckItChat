#pragma once

#include "GeneratedFiles/ui_ConnectDialog.h"
#include <QDialog>

class ConnectDialog : public QDialog
{
	Q_OBJECT

public:
	ConnectDialog(QWidget *parent = Q_NULLPTR);
	~ConnectDialog();


	inline QString GetIp() { return ui.ip->toPlainText(); }
	inline QString GetPort() { return ui.port->toPlainText(); }
	inline QString GetPassword() { return ui.password->toPlainText(); }

private slots:
	void Connect();

private:
	Ui::ConnectDialog ui;
};
