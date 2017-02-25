#include "tile.h"

Tile::Tile(QWidget *parent) :QFrame(parent)
{
    number = 0;
    image = new QPixmap(":/tile/image/0.png");
}

void Tile::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,80,80,*image);
}

void Tile::setNumber(int num)
{
    number = num;
    QString name = QString::number(num);
    QString filename  = ":/tile/image/"+name+".png";
    image->load(filename);
    *image = image->scaled(QSize(80,80));
    update();
}

bool Tile::isEmpty() 
{ 
    if(number==0) 
        return true;
    else 
        return false;
}
