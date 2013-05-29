#ifndef MAINCLASS_H
#define MAINCLASS_H

///////////////////////////////////////////////////////////////////////////
#include <QObject>
#include <qapplication.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <GL/glut.h>
#include <Qt/qgl.h>
#include <qlayout.h>
#include "vector.h"
#include "paintingclass.h"
///////////////////////////////////////////////////////////////////////////


class mainClass : public QWidget
{
	Q_OBJECT
public:
    mainClass();
public slots:
    void buttonClicked();
    void addButtonClicked();
    void okButtonClicked();

signals:

private:
    QPushButton *btn;
    QPushButton *add;
    char painting;
    PaintingClass *paintSpace;
    void setBall(float m, float v, float x0, float y0, float z0, float x, float y, float z);

    QWidget *popupWindow;
    QLineEdit *em;
    QLineEdit *ev;
    QLineEdit *ex0;
    QLineEdit *ey0;
    QLineEdit *ez0;
    QLineEdit *ex;
    QLineEdit *ey;
    QLineEdit *ez;
    QPushButton *ok;


};

#endif // MAINCLASS_H
