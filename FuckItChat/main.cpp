#include "FuckItChat.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FuckItChat w;
	w.show();
	return a.exec();
}
