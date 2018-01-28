#include "Client.h"



Client::Client(QWidget* parent)
	: QObject(parent), parent(parent) {
	socket = new QTcpSocket(this);


	connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this,
		[=](QAbstractSocket::SocketError socketError) {
		Error(socketError);
	});


}

Client::~Client() {
	socket->close();
	delete socket;
}

void Client::Connect(QString ip, QString port, QString password) {
	QHostAddress addr;
	addr.setAddress(ip);

	socket->connectToHost(addr, port.toInt());


}

void Client::Disconnect() {
	//send disconnect packet
}

void Client::Error(QAbstractSocket::SocketError socketError) {
	QMessageBox::information(parent, "Error", socket->errorString());
}