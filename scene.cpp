#include "scene.h"

#include <QImage>
#include <QPainter>


Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    this->addItem(this->item);
    // Добавляем элементы на другую сцену
    this->secondScene->setSceneRect(0, 0, this->item->x_size(), this->item->y_size());
    this->secondScene->addRect(0, 0, this->item->x_size() - 1, this->item->y_size() - 1);
}

Scene::~Scene()
{

}

void Scene::wheelEvent(QGraphicsSceneWheelEvent *event)
{


    if(event->delta() > 0)
    {
        emit changeWheel(1, this->mousePos);
    }
    else
    {
        emit changeWheel(-1, this->mousePos);
    }

}

void Scene::update_scene()
{
    // Чтобы не происходило образование множества изображений на сцене нужно ее обновлять после отрисовки
    update();
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // Для обработки движения мыши флаг
    this->mousePressed = true;
    //
    auto pos = mouseEvent->scenePos();
    qDebug() << pos.rx();
    this->addEllipse(pos.rx()-7, pos.ry()-7, 14, 14, QPen(Qt::red), QBrush(Qt::red));
    this->secondScene->addEllipse(pos.rx()-7, pos.ry()-7, 14, 14, QPen(Qt::red), QBrush(Qt::red));
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // Для обработки движения мыши флаг
    this->mousePressed = false;
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (this->mousePressed)
    {
        auto pos = event->scenePos();
        this->addEllipse(pos.rx()-7, pos.ry()-7, 14, 14, QPen(Qt::red), QBrush(Qt::red));
        this->secondScene->addEllipse(pos.rx()-7, pos.ry()-7, 14, 14, QPen(Qt::red), QBrush(Qt::red));
    }
}

void Scene::save_mask()
{
    QImage image(this->sceneRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);                                              // Start all pixels transparent
    QPainter painter(&image);
    this->render(&painter);
    image.save("C:/Users/user/Desktop/QT5/qpainter/meeeeeeeeeeeeeeeeeeeu.png");

    QImage image2(this->secondScene->sceneRect().size().toSize(), QImage::Format_ARGB32);
    // Choose background
    image2.fill(Qt::black); // Qt::transparent
    QPainter painter2(&image2);
    this->secondScene->render(&painter2);
    image2.save("C:/Users/user/Desktop/QT5/qpainter/meeeeeeeeeeeeeeeeeeeu_2.png");
}



















