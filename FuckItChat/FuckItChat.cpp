#include "FuckItChat.h"

FuckItChat::FuckItChat(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);


	connect(ui.actionConnect, &QAction::triggered, this, &FuckItChat::Connect);
}

void FuckItChat::resizeEvent(QResizeEvent *event) {
	QSize size = event->size();
	float width = (float)size.width();
	float height = (float)size.height() - menuBar()->size().height();

	float wSpacing = width / 300.f;
	float hSpacing = height / 300.f;

	float tbw = width - wSpacing * 2.f;
	float tbh = height / 15.f * 14.f - hSpacing * 2.f;
	float tbx = wSpacing;
	float tby = hSpacing;

	float ptw = width / 9.f * 8.f - wSpacing * 2.f;
	float pth = height / 15.f * 1.f - hSpacing * 2.f;
	float ptx = wSpacing;
	float pty = tbh + tby + hSpacing;

	float bow = width / 9.f * 1.f - wSpacing;
	float boh = height / 15.f * 1.f - hSpacing * 2.f;
	float box = ptw + ptx + wSpacing;
	float boy = tbh + tby + hSpacing;


	ui.textBrowser->resize(tbw, tbh);
	ui.textBrowser->move(tbx, tby);
	
	ui.plainTextEdit->resize(ptw, pth);
	ui.plainTextEdit->move(ptx, pty);

	ui.btnOkie->resize(bow, boh);
	ui.btnOkie->move(box, boy);
}

void FuckItChat::Connect() {
	ConnectDialog dialog(this);
	if (dialog.exec() == QDialog::Accepted) {
		client = new Client(this);
		client->Connect(dialog.GetIp(), dialog.GetPort(), dialog.GetPassword());
	}

}