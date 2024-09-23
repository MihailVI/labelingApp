#ifndef POLYGON_H
#define POLYGON_H

#include <QPolygon>
#include <QMouseEvent>
#include <QDebug>

class Polygon: public QPolygon
{
public:
    Polygon();

    virtual void mouseMoveEvent(QMouseEvent *event);



};

#endif // POLYGON_H
