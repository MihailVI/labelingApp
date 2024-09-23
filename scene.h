#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QWheelEvent>

#include "./item.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT


public:
    explicit Scene(QObject *parent = 0);
    ~Scene();
    QPointF mousePos;
    // Second scene (using for class with one mask)
    QGraphicsScene *secondScene = new QGraphicsScene();
    // Main item where we keep our image
    Item *item = new Item;
private:
    // Флаг для мышки (зажата ли клавиша или нет)
    bool mousePressed = false;


private:
    void wheelEvent(QGraphicsSceneWheelEvent  *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

public slots:
    void update_scene();
    void save_mask();

signals:
    void changeWheel(int diretion, QPointF mousePos);

};
#endif // SCENE_H
