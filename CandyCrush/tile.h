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
    bool isempty();
    void mousePressEvent(QMouseEvent *event);
    int click;
    void unclick();
    QPixmap *image;
private:
    int number;
signals:
    void clicked();
};


class Star : public QFrame
{
    Q_OBJECT
public:
    Star(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setPoint(int pt);
    QPixmap *image;
private:
    int point;
};

#endif
