#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QLabel>
#include <string>

class ImageItem : public QGraphicsItem
{
private:
    std::string mode = "nothing";
    bool rotate = false; bool resize = false;
    int angle = 90; float x_scale = 0.5; float y_scale = 0.5;

public:
    void rotate_paint(int angle);
    void resize_paint(float x_scale, float y_scale);

    QRectF ImageItem::boundingRect() const override
    {
        qreal size_0 = 0;
        qreal size_1 = 500;
        return QRectF(size_0, size_0, size_1, size_1);
    }

    void ImageItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                          QWidget *widget) override
    {
        QImage initial("C:/QT5/Labeling/moto.png");
        QImage image = initial.scaled(500, 500, Qt::KeepAspectRatio); // Qt::KeepAspectRatio, Qt::IgnoreAspectRatio

        QPixmap pixmap = QPixmap::fromImage(image);
        QRect Rect = pixmap.rect();
        if (this->rotate == true) {
            painter->rotate(this->angle);
        } else if (this->resize == true) {
            painter->scale(this->x_scale, this->y_scale);
        }
        painter->drawPixmap(0, 0, Rect.width(), Rect.height(), pixmap);
        // check work
        //painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));
        //painter->drawEllipse(100, 50, 150, 150);
    }
};






#endif // IMAGEITEM_H
