#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FuckItServer.h"
#include "ServerStartDialog.h"
#include "Server.h"

class FuckItServer : public QMainWindow
{
	Q_OBJECT
	
private:
	Server* server;
public:
	FuckItServer(QWidget *parent = Q_NULLPTR);

private:
	Ui::FuckItServerClass ui;

	void StartServer();
};
