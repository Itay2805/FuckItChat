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
	this->ip = ip;
	if (this->ip == "localhost")
		this->ip = "127.0.0.1";

	this->port = port;
	this->password = password;
	QHostAddress addr;
	addr.setAddress(this->ip);

	socket->connectToHost(addr, port.toInt());
	if (socket->waitForConnected(5000)) {
		QMessageBox::information(parent, "Connected", "connected");
	}
}

void Client::Disconnect() {
	//send disconnect packet
}

void Client::Error(QAbstractSocket::SocketError socketError) {
	QMessageBox::information(parent, "Error", socket->errorString());
}