#pragma once
#include <qobject.h>
#include <qtcpserver.h>
#include <qwidget.h>
#include <qmessagebox.h>
#include <qtcpsocket.h>


class Server : public QObject {
	Q_OBJECT
private:
	QTcpServer* server;

	QWidget* parent;

	QString port;
	QString salt;
	QString password;

public:
	Server(QWidget* parent);

	void Start(QString port, QString salt, QString password);

private:
	void NewConnection();
};