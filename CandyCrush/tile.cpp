#include "tile.h"

Tile::Tile(QWidget *parent) :QFrame(parent)
{
    click=0;
    int n =rand()%5;
    switch(n)
    {
        case 0:
        number = 2;
        image = new QPixmap(":/tile/image/2.png");
        break;
        case 1:
        number = 4;
        image = new QPixmap(":/tile/image/4.png");
        break;
        case 2:
        number = 6;
        image = new QPixmap(":/tile/image/6.png");
        break;
        case 3:
        number = 8;
        image = new QPixmap(":/tile/image/8.png");
        break;
        case 4:
        number = 10;
        image = new QPixmap(":/tile/image/10.png");
        break;
    }
}

void Tile::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,40,40,*image);
}

void Tile::setNumber(int num)
{
    number = num;
    QString name = QString::number(num);
    if(number ==0)
    {
        QString filename  = ":/tile/image/0.png";
        image->load(filename);
    }
    else
    {
        if(click==0)
        {
            QString filename  = ":/tile/image/"+name+".png";
            image->load(filename);
        }
        else if(click==1)
        {
            QString filename  = ":/tile/image/"+name+"c.png";
            image->load(filename);
        }
    }
    *image = image->scaled(QSize(40,40));
    update();
}

bool Tile::isempty()
{ 
    if(number==0) 
        return true;
    else 
        return false;
}

void Tile::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton && click==0 && number!=0)
    {
        click=1;
        setNumber(number);
        emit clicked();
    }
    else if(event->button() == Qt::LeftButton && click==1 )
    {
        unclick();
    }
}

void Tile::unclick(){
        click=0;
        setNumber(number);
}

Star::Star(QWidget *parent) :QFrame(parent)
{
    point=0;
    image = new QPixmap(":/tile/image/0star.png");
}

void Star::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,60,30,*image);
}

void Star::setPoint(int pt)
{
    point = pt;
    if(point<25)
    {
        QString filename  = ":/tile/image/0star.png";
        image->load(filename);
    }
    else if(point>=25&&point<50)
    {
        QString filename  = ":/tile/image/1star.png";
        image->load(filename);
    }
    else if(point>=50 && point <75)
    {
        QString filename  = ":/tile/image/2star.png";
        image->load(filename);
    }
    else
    {
        QString filename  = ":/tile/image/3star.png";
        image->load(filename);
    }

    *image = image->scaled(QSize(60,30));
    update();
}
