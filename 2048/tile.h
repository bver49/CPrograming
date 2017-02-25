#ifndef TILE_H
#define TILE_H

#include <QFrame>
#include <QPainter>
#include <QPaintEvent>


class Tile : public QFrame
{
    Q_OBJECT
public:
    Tile(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    int  getNumber() { return number;}
    void setNumber(int num);
    bool isEmpty();
    void upgrade(){ setNumber(getNumber()*2);}
private:
    int number;
    QPixmap *image;
};

#endif
