#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FuckItServer.h"

class FuckItServer : public QMainWindow
{
	Q_OBJECT

public:
	FuckItServer(QWidget *parent = Q_NULLPTR);

private:
	Ui::FuckItServerClass ui;
};
