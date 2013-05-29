#ifndef PAINTINGCLASS_H
#define PAINTINGCLASS_H

#include <QGLWidget>
#include <qvector.h>
#include <qtimer.h>
#include <qlabel.h>
#include "ball.h"
#include <math.h>
#include <GL/glut.h>

class PaintingClass : public QGLWidget
{
	Q_OBJECT
public:
    PaintingClass(QWidget *parent=0);
    ~PaintingClass();
    void setBall(float m, float v, float x0, float y0, float z0, float x, float y, float z);
    void start();
    void stop();

signals:

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    QVector<Ball*> ball;
    int ballCount;
    QVector<QTimer*> timer;

};

#endif // PAINTINGCLASS_H
