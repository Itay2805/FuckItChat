#pragma once

#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>

#include <QtWidgets/QMessageBox>

class Client : public QObject {
	Q_OBJECT
private:
	QTcpSocket* socket;

	QWidget* parent;

public:
	Client(QWidget* parent);
	~Client();

	void Connect(QString ip, QString port, QString password);
	void Disconnect();

private slots:
	void Error(QAbstractSocket::SocketError socketError);
};
