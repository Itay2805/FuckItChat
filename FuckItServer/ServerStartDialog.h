#pragma once

#include <QDialog>
#include "ui_ServerStartDialog.h"

class ServerStartDialog : public QDialog
{
	Q_OBJECT

public:
	ServerStartDialog(QWidget *parent = Q_NULLPTR);
	~ServerStartDialog();

	inline QString GetPort() { return ui.port->text(); }
	inline QString GetSalt() { return ui.salt->text(); }
	inline QString GetPassword() { return ui.password->text(); }

private:
	Ui::ServerStartDialog ui;

	void Start();
};
