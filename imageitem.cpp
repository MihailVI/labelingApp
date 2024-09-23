#include "imageitem.h"

void ImageItem::rotate_paint(int angle)
{
    this->rotate = true;
    this->angle = angle;
}

void ImageItem::resize_paint(float x_scale, float y_scale)
{
    this->resize = true;
    this->x_scale = x_scale;
    this->y_scale = y_scale;
}






