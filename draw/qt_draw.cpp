#include "qt_draw.h"

void QTDraw::drawObj(SceneObject &so, BaseCamera &cam)
{
    BaseModel *mdl = (BaseModel *)so.getModel();
    for (int i=0; i < mdl->linesNum(); i++)
    {
        Edge t = mdl->getLine(i);
        Matrix<double> c = cam.getView();
        Point beg = t.Beg()*so.getTransfMatr()+so.getCenter();
        Point end = t.End()*so.getTransfMatr()+so.getCenter();
        beg = beg*c;
        end = end*c;

        if (beg.Z() >= 0 && end.Z() >= 0)
            this->drawLine(beg, end);
    }
}

void QTDraw::clearScene()
{
    scene->clear();
}

void QTDraw::drawLine(Point beg, Point end)
{
    QPen pen = getPen();
    scene->addLine(beg.X(), beg.Y(), end.X(), end.Y(), pen);
}

QPen QTDraw::getPen()
{
    return QPen(Qt::blue);
}
