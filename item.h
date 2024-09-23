#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QLabel>
#include <string>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsObject>
#include <QPainter>
#include <QPen>
#include <QGraphicsWidget>


class Item : public QGraphicsObject
{
    Q_OBJECT
private:
    std::string mode = "nothing";
    bool rotate = false;
    int angle = 90;
    QImage initialImage = QImage("C:/Users/user/Desktop/QT5/qpainter/cat.jpg");
    QImage image = this->initialImage.scaled(500, 500, Qt::KeepAspectRatio); // Qt::KeepAspectRatio, Qt::IgnoreAspectRatio
    int height = image.height();
    int width = image.width();
    QPixmap pixmap = QPixmap::fromImage(this->image);
    QRect Rect = pixmap.rect();

    QPointF previousMouseScenePos = QPointF(0, 0);

    QPainter *painter = new QPainter;

public:

    int x_size() {return this->width;}
    int y_size() {return this->height;}

    QRectF boundingRect() const override
    {
        return QRectF(0, 0, this->width * this->scale(), this->height * this->scale());
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override
    {
        //qDebug() << 0 << 0<< this->Rect.width()<< this->Rect.height();
        painter->drawPixmap(0, 0, this->Rect.width(), this->Rect.height(), this->pixmap);

        painter->setBrush(QBrush(Qt::red, Qt::NoBrush));
        QRectF rectangle(0, 0, this->width, this->height);
        painter->drawRect(rectangle);
        this->painter = painter;

        // Установить прозрачность для item
        //this->setOpacity(0.6);


        // check work
        //painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));
        //painter->drawEllipse(100, 50, 150, 150);
    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        qDebug() << "Item called" << event->pos().x() << event->pos().y();
        qDebug() << "Item called" << this->width << this->height;
        //this->painter->drawEllipse(1, 1, 12, 12);
    }

public slots:
    void scaleImage(int direction, QPointF mouseScenePos);

signals:
    void updateScene();
};











/*
if (this->rotate == true) {
    painter->rotate(this->angle);
} else if (this->resize == true) {
    painter->scale(this->x_scale, this->y_scale);
}
*/


#endif // ITEM_H
