#include "item.h"


void Item::scaleImage(int direction, QPointF mouseScenePos)
{
    // 1) Разобраться с определением положения курсора в классе Item (этого не нашел, могу определить только на сцене - не очень удобно). Если
    // не найду как - грамотно использовать сцену (проверка координат слева справа сверху снизу + когда не в зоне автоматически выставляем на центр)
    // 2) Сделать item по центру сцены
    qDebug() << "positions:" << mouseScenePos.x() << this->width * this->scale();

    qDebug() << "position in Item:" << this->mapFromItem(this, mouseScenePos);


    this->setTransformOriginPoint(mouseScenePos.x(), mouseScenePos.y());

    // Этот код неправильный! плюс желательно все равно получить координаты именно не сцены, а item-а
    /*
    if (mouseScenePos.x() > 0 & mouseScenePos.x() < this->width * this->scale() &
        mouseScenePos.y() > 0 & mouseScenePos.y() < this->height * this->scale() &
        this->scale() > 0.5)
    {
        qDebug() << "В пределах Item";
        this->setTransformOriginPoint(mouseScenePos.x(), mouseScenePos.y());
    } else
    {
        qDebug() << "Нет! Выход за пределы Item!";
        this->setTransformOriginPoint(0, 0);
    }
    */



    if (direction==true) {
        // Координаты фокуса для масштабирования
        //this->setTransformOriginPoint(mouseScenePos.x(), mouseScenePos.y());
        // Масштабирование
        this->setScale(this->scale() + 0.1);
    } else if (this->scale() > 0.5) {
        //this->setTransformOriginPoint(mouseScenePos.x(), mouseScenePos.y());
        this->setScale(this->scale() - 0.1);
    }
    qDebug() << this->scale();


    // Сигнал для обновления сцены
    updateScene();
}




