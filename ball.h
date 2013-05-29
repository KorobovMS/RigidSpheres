#ifndef BALL_H
#define BALL_H
#include <qobject.h>
#include "vector.h"
class Ball : public QObject
{
	Q_OBJECT
public:
	float x;
	float y;
	float z;

	Vector v;
	float m;

public slots:
	void inc()
	{
		x+=v.i/1000.0;
		y+=v.j/1000.0;
		z+=v.k/1000.0;
	}
};

#endif // BALL_H
