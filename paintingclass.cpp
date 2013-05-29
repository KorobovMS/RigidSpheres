#include "paintingclass.h"
#include <qlabel.h>
#define PI 3.14159265358979323846

PaintingClass::PaintingClass(QWidget *parent):QGLWidget(parent)
{
	ballCount=0;
}

PaintingClass::~PaintingClass()
{

}

void PaintingClass::start()
{
	for (int i=0; i<ballCount; i++)
		timer[i]->start();
}

void PaintingClass::stop()
{
	for (int i=0; i<ballCount; i++)
		timer[i]->stop();
}

void PaintingClass::setBall(float m, float v, float x0, float y0, float z0, float x, float y, float z)
{
	ball.resize(ball.size()+1);
	ball[ballCount]=new Ball();
	timer.resize(timer.size()+1);
	timer[ballCount]=new QTimer();
	connect(timer[ballCount],SIGNAL(timeout()),ball[ballCount],SLOT(inc()));
	connect(timer[ballCount],SIGNAL(timeout()),this,SLOT(updateGL()));
	ball[ballCount]->m=m;
	ball[ballCount]->x=x0;
	ball[ballCount]->y=y0;
	ball[ballCount]->z=z0;
	ball[ballCount]->v.i=v*(x-x0)/sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));
	ball[ballCount]->v.j=v*(y-y0)/sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));
	ball[ballCount]->v.k=0; //v*(z-z0)/sqrt((x-x0)*(x-x0)+(z-z0)*(z-z0));
	timer[ballCount]->setInterval(static_cast<int>(1000.0/ball[ballCount]->v.length()));
	ballCount++;
}

void PaintingClass::initializeGL()
{
	glViewport(0,0,600,600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 600.0, 0.0, 600., -600.0, 600.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void PaintingClass::resizeGL(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, w, 0.0, h, -600.0, 600.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void PaintingClass::paintGL()
{
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT );

	for (int i=0; i<ballCount; i++)
	{
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(ball[i]->x, ball[i]->y, ball[i]->z);
		glutWireSphere(25.0, 25, 25);
		glPopMatrix();
	}
	glFinish();

	for (int i=0; i<ballCount-1; i++)
		for (int j=i+1; j<ballCount; j++)
	if (sqrt( (ball[i]->x-ball[j]->x)*(ball[i]->x-ball[j]->x) + (ball[i]->y-ball[j]->y)*(ball[i]->y-ball[j]->y) + (ball[i]->z-ball[j]->z)*(ball[i]->z-ball[j]->z) )<=51.)
	{
		QLabel *info=new QLabel();
		Vector E,
				Vc1, Vo1,
				Vc2, Vo2,
				Vc1n, Vc2n,
				V1(ball[i]->v),V2(ball[j]->v);

		E.i=ball[j]->x-ball[i]->x;
		E.j=ball[j]->y-ball[i]->y;
		E.k=ball[j]->z-ball[i]->z;
		E=E*(1./E.length());

		Vc1=E*(V1*E);
		Vo1=V1-Vc1;
		Vc2=E*(V2*E);
		Vo2=V2-Vc2;

		Vc1n=(Vc1*(ball[i]->m-ball[j]->m)+Vc2*ball[j]->m*2)*(1./(ball[i]->m+ball[j]->m));
		Vc2n=(Vc2*(ball[j]->m-ball[i]->m)+Vc1*ball[i]->m*2)*(1./(ball[i]->m+ball[j]->m));

		ball[i]->v=Vc1n+Vo1;
		ball[j]->v=Vc2n+Vo2;

		timer[i]->stop();
		timer[j]->stop();
		timer[i]->setInterval(static_cast<int>(1000.0/ball[i]->v.length()));
		timer[j]->setInterval(static_cast<int>(1000.0/ball[j]->v.length()));
		timer[i]->start();
		timer[j]->start();

		info->setText(QString::number(i+1)+tr("<->")+QString::number(j+1)+tr("\n")+
			      tr("v")+QString::number(i+1)+tr("={")+QString::number(ball[i]->v.i)+tr(", ")+QString::number(ball[i]->v.j)+tr(", ")+QString::number(ball[i]->v.k)+tr("}")+tr(" ")+QString::number(ball[i]->v.length())+tr("\n")+
			      tr("v")+QString::number(j+1)+tr("={")+QString::number(ball[j]->v.i)+tr(", ")+QString::number(ball[j]->v.j)+tr(", ")+QString::number(ball[j]->v.k)+tr("}")+tr(" ")+QString::number(ball[j]->v.length()));
		info->show();
	}

}
