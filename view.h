#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QTimeLine>
#include <QGraphicsScene>



class View : public QGraphicsView
{
public:
    View();

    void scrollContentsBy(int, int);

    /*
    //Для зуммирования
    void wheelEvent(QWheelEvent *event){

        this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        // Scale the view / do the zoom
        double scaleFactor = 1.15;

        qDebug() << event->angleDelta();

        if(event->angleDelta().ry() > 0) {
            // Zoom in
            this-> scale(scaleFactor, scaleFactor);

        } else {
            // Zooming out
            this->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
    }
    */


//public signals:
//void addItemToScene();


};

#endif // VIEW_H
