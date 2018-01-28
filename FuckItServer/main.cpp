#include "FuckItServer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FuckItServer w;
	w.show();
	return a.exec();
}
