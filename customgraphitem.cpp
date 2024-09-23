#include "customgraphitem.h"

CustomGraphItem::CustomGraphItem() {}


CustomGraphItem::boundingRect() const override
{
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

CustomGraphItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override
{
    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
}






