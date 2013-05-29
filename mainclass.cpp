#include "mainclass.h"

mainClass::mainClass()
{
	QGridLayout *l=new QGridLayout();
	QGridLayout *lp=new QGridLayout();
	btn=new QPushButton(tr("Start"),this);
	add=new QPushButton(tr("Add"),this);
	painting=-1;
	paintSpace=new PaintingClass(this);

	l->addWidget(paintSpace,0,0,10,1);
	paintSpace->setFixedSize(600,600);
	l->addWidget(btn,0,1);
	l->addWidget(add,1,1);
	l->addWidget(new QLabel(QObject::tr("m - Mass of body\nv - Velocity\nx0, y0, z0 - First coordinates of body\nx, y, z - Direction of velocity")),2,1);
	this->setLayout(l);

	popupWindow=new QWidget();
	em=new QLineEdit();
	ev=new QLineEdit();
	ex0=new QLineEdit();
	ey0=new QLineEdit();
	ez0=new QLineEdit();
	ex=new QLineEdit();
	ey=new QLineEdit();
	ez=new QLineEdit();
	ok=new QPushButton(tr("OK"));
	lp->addWidget(new QLabel(QObject::tr("m")),0,0);
	lp->addWidget(new QLabel(QObject::tr("v")),1,0);
	lp->addWidget(new QLabel(QObject::tr("x0")),2,0);
	lp->addWidget(new QLabel(QObject::tr("y0")),3,0);
	lp->addWidget(new QLabel(QObject::tr("z0")),4,0);
	lp->addWidget(new QLabel(QObject::tr("x")),5,0);
	lp->addWidget(new QLabel(QObject::tr("y")),6,0);
	lp->addWidget(new QLabel(QObject::tr("z")),7,0);
	lp->addWidget(em,0,1);
	lp->addWidget(ev,1,1);
	lp->addWidget(ex0,2,1);
	lp->addWidget(ey0,3,1);
	lp->addWidget(ez0,4,1);
	lp->addWidget(ex,5,1);
	lp->addWidget(ey,6,1);
	lp->addWidget(ez,7,1);
	lp->addWidget(ok,8,1);
	popupWindow->setLayout(lp);

	connect(btn,SIGNAL(clicked()),this,SLOT(buttonClicked()));
	connect(add,SIGNAL(clicked()),this,SLOT(addButtonClicked()));
	connect(ok,SIGNAL(clicked()),this,SLOT(okButtonClicked()));

}

void mainClass::buttonClicked()
{
	if (painting==-1)
	{
		painting=1;
		btn->setText(tr("Stop"));
		paintSpace->start();
	}
	else
	{
		painting=-1;
		btn->setText(tr("Start"));
		paintSpace->stop();

	}
}

void mainClass::addButtonClicked()
{
	popupWindow->show();
}

void mainClass::okButtonClicked()
{
	setBall(em->text().toFloat(), ev->text().toFloat(),
		ex0->text().toFloat(), ey0->text().toFloat(), ez0->text().toFloat(),
		ex->text().toFloat(), ey->text().toFloat(), ez->text().toFloat());
	popupWindow->close();
}

void mainClass::setBall(float m, float v, float x0, float y0, float z0, float x, float y, float z)
{
	paintSpace->setBall(m,v,x0,y0,z0,x,y,z);
}
