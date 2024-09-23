#include "view.h"


View::View()
{
    // Чтобы отслеживать положение мыши по умолчанию
    setMouseTracking(true);
    //setTransformationAnchor(AnchorUnderMouse);
    //setResizeAnchor(AnchorViewCenter);
}

void View::scrollContentsBy(int, int)
{
    //don't do anything hah!

}



