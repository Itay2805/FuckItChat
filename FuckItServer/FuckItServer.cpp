#include "FuckItServer.h"

FuckItServer::FuckItServer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.actionStart_Server, &QAction::triggered, this, &FuckItServer::StartServer);


}

void FuckItServer::StartServer() {
	ServerStartDialog dialog(this);
	if (dialog.exec() == QDialog::Accepted) {
		server = new Server(this);
		server->Start(dialog.GetPort(), dialog.GetSalt(), dialog.GetPassword());
	}
}
