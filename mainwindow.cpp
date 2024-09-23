#include "mainwindow.h"
#include "./item.h"
#include "./ui_mainwindow.h"


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPixmap>
#include <QDebug>
#include <QLabel>
#include <string>
#include <QTimer>






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);


    //view->setEnabled (true); //delete it!


    //QPoint pos(0, 0);
    //QRectF rect(0, 0, 100, 100);
    //QImage image("C:/QT5/Labeling/moto.png");
    //QPixmap pixmap = QPixmap::fromImage(imageMy);
    //QPainter *painter = new QPainter();
    //painter->drawImage(pos, image, rect);
    //QPainterPath painter();


    // сначала сделать так чтобы вот это заработало:
    // Добавить сначала не изображение, а просто круг!
    //QImage image("C:/QT5/Labeling/moto.png");
    //QPixmap pixmap = QPixmap::fromImage(image);
    // Так не работает:
    //QGraphicsPixmapItem item(pixmap);
    //scene->setSceneRect(0,0,1000,1000);
    //scene->addItem(&item);
    // а так работает (хз почему - разобраться):
    //QGraphicsPixmapItem *item = new QGraphicsPixmapItem;
    //item->setPixmap(QPixmap::fromImage(image));
    //scene->addItem(item);

    // just draw a line
    //QPen penRed(Qt::red);
    //scene->addLine(100, 100, 200, 200, penRed);

    //scene->addItem(this->item);
    //setOpacity




    //scaleButton - эту кнопку связать с функцией, которая будет рескейлить изображение (эту функцию реализовать в SimpleItem)
    //scale_image - функция
    //connect(ui->scaleButton, SIGNAL(clicked()), item, SLOT(scale_image));

    //connect(ui->zoomOutButton, &QPushButton::clicked, this, &MainWindow::zoomOut);
    //connect(ui->zoomInButton, &QPushButton::clicked, this, &MainWindow::zoomIn);

    //connect(scene, &Scene::changeWheel, this->item, &Item::scaleImage);
    //connect(scene, SIGNAL(changeWheel(int, QPointF)), this->item, SLOT(scaleImage(int, QPointF)));
    //connect(ui->scaleButton, SIGNAL(clicked()), this, SLOT(on_scaleButton_clicked(item)));

    // Delete it (тут как посмотреть сколько виджетов в окне создано)
    //int numberOfItems = ui->vertical_1->count();
    //qDebug() << numberOfItems;
    //ui->scaleButton; //scaleButton



    // Убрать таймер и сделать обновление сцены сразу после зуммирования (создать и отправить сигнал от this->item после зуммирования на
    // сцену и получить его в слоте this->scene (который надо предварительно создать)
    //connect(this->item, SIGNAL(updateScene()), this->scene, SLOT(update_scene()));
    //connect(this->item, &Item::updateScene, this->scene, &Scene::update_scene);

    //QTimer *timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this->scene, SLOT(update_scene()));
    //connect(timer, &QTimer::timeout, this->scene, &Scene::update_scene);
    //timer->start(10);

    connect(scene->item, &Item::updateScene, this->scene, &Scene::update_scene);
    connect(scene, SIGNAL(changeWheel(int, QPointF)), scene->item, SLOT(scaleImage(int, QPointF)));

    connect(ui->saveMaskButton, &QPushButton::clicked, scene, &Scene::save_mask);

    // Установить начальный фокус на этом qgraphicitem
    this->scene->setFocusItem(scene->item);
    // Чтобы можно было перемещать объект по сцене (но есть проблемы с отрисовкой - надо обновлять сцену при любом передвижении виджета updateScene в Item)
    //this->item->setFlag(QGraphicsItem::ItemIsMovable);

    this->view->setScene(this->scene);
    ui->vertical_1->addWidget(this->view);
    this->setMinimumHeight(400);
    this->setMinimumWidth(400);
    //Временно отключаю горизонтальные и вертикальные ползунки
    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

MainWindow::~MainWindow()
{
    delete ui;
}



/*
 * Заметки
 * 1) https://habr.com/ru/articles/791136/ - зуммирование хороший пример
 * 2) https://wiki.qt.io/Smooth_Zoom_In_QGraphicsView - плавное зуммирование (но хз че как)
 * 3) https://qtcentre.org/threads/52603-Zoom-effect-by-mouse-Wheel-in-QGraphicsview
 * 4) Мб сделать учетпредыдущей точки для зумирования
 * */





/*
class SimpleItem : public QGraphicsItem
{
private:
    std::string mode = "nothing";
    bool rotate = false; bool resize = false;
    int angle = 90; float x_scale = 0.5; float y_scale = 0.5;

public:


    void rotate_paint(int angle)
    {
        this->rotate = true;
        this->angle = angle;
    }

    void resize_paint(float x_scale, float y_scale)
    {
        this->resize = true;
        this->x_scale = x_scale;
        this->y_scale = y_scale;
    }

    QRectF boundingRect() const override
    {
        qreal size_0 = 0;
        qreal size_1 = 500;
        return QRectF(size_0, size_0, size_1, size_1);
    }


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
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
*/






