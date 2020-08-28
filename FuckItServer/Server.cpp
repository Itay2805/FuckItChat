#include "Server.h"


Server::Server(QWidget* parent)
	: QObject(parent), parent(parent) {

	server = new QTcpServer();

	connect(server, &QTcpServer::newConnection, this, &Server::NewConnection);

}

void Server::Start(QString port, QString salt, QString password) {
	QHostAddress addr;
	
	if (!server->listen(QHostAddress::Any, port.toShort())) {
		QMessageBox::information(parent, "Error", "Server could not start!");
	}
}

void Server::NewConnection() {
	QTcpSocket* socket = server->nextPendingConnection();

	QMessageBox::information(parent, "Recieved Something!", "asd");

	// store the socket for the client or whatever
	// and only close it when the client disconnects
	socket->close();
}

