#include "mainclass.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	glutInit(&argc, argv);
	mainClass mc;
	mc.show();
	return app.exec();
}
