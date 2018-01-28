#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFormLayout>

#include "ui_FuckItChat.h"

#include "ConnectDialog.h"

#include "Client.h"

class FuckItChat : public QMainWindow
{
	Q_OBJECT

public:
	FuckItChat(QWidget *parent = Q_NULLPTR);

public:
	void resizeEvent(QResizeEvent *event) override;

private slots:
	void Connect();

private:
	Ui::FuckItChatClass ui;
	Client* client;
};
