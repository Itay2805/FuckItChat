#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFormLayout>

#include "ui_FuckItChat.h"

class FuckItChat : public QMainWindow
{
	Q_OBJECT

public:
	FuckItChat(QWidget *parent = Q_NULLPTR);

public:
	void resizeEvent(QResizeEvent *event) override;

private:
	Ui::FuckItChatClass ui;
};
