#ifndef CUSTOMGRAPHITEM_H
#define CUSTOMGRAPHITEM_H

#include <QGraphicsItem>

class CustomGraphItem : public QGraphicsItem
{
public:
    CustomGraphItem();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


};








#endif // CUSTOMGRAPHITEM_H
