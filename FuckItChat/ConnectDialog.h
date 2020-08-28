#pragma once

#include "GeneratedFiles/ui_ConnectDialog.h"
#include <QDialog>

class ConnectDialog : public QDialog
{
	Q_OBJECT

public:
	ConnectDialog(QWidget *parent = Q_NULLPTR);
	~ConnectDialog();


	inline QString GetIp() { return ui.ip->text(); }
	inline QString GetPort() { return ui.port->text(); }
	inline QString GetPassword() { return ui.password->text(); }

private slots:
	void Connect();

private:
	Ui::ConnectDialog ui;
};
