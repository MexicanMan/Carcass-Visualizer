#ifndef QT_DRAW_H
#define QT_DRAW_H
#include "draw_strategy.h"
#include <QGraphicsScene>

class QTDraw : public DrawStrategy
{
private:
    QGraphicsScene *scene;

    void drawLine(Point beg, Point end);
    QPen getPen();
public:
    QTDraw(QGraphicsScene *sc) : scene(sc) { }
    ~QTDraw() { }

    void drawObj(SceneObject &so, BaseCamera &cam);
    void clearScene();
};

#endif // QT_DRAW_H
