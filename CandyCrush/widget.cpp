#include "widget.h"
#include "ui_widget.h"
#include <qpushbutton>
#include <qwidget.h>
#include <qhboxlayout>
#include <QTimer>
#include <QPropertyAnimation>
Widget::Widget(QWidget *parent) :QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer;
    tileclick=0;
    tx=-2;
    ty=-2;
    cx=-2;
    cy=-2;
    life=3;
    mode=0;
    score=0;
    time=60;
    connect(ui->tile01,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile02,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile03,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile04,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile05,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile06,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile07,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile08,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile11,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile12,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile13,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile14,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile15,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile16,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile17,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile18,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile21,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile22,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile23,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile24,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile25,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile26,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile27,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile28,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile31,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile32,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile33,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile34,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile35,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile36,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile37,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile38,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile41,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile42,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile43,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile44,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile45,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile46,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile47,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile48,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile51,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile52,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile53,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile54,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile55,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile56,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile57,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile58,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile61,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile62,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile63,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile64,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile65,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile66,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile67,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile68,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile71,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile72,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile73,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile74,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile75,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile76,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile77,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile78,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile81,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile82,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile83,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile84,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile85,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile86,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile87,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile88,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile91,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile92,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile93,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile94,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile95,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile96,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile97,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile98,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile101,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile102,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile103,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile104,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile105,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile106,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile107,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(ui->tile108,SIGNAL(clicked()),this,SLOT(checkboard()));
    connect(this,SIGNAL(scorechanged(int)),ui->score,SLOT(display(int)));
    connect(this,SIGNAL(lifechanged(int)),ui->life,SLOT(display(int)));
    connect(this,SIGNAL(timechanged(int)),ui->time,SLOT(display(int)));
    connect(timer,SIGNAL(timeout()),this,SLOT(countdown()));
    timer->start(1000);
    createboard();
}

void Widget::countdown()
{
    if(time>0  && mode==0)
        time--;
    star->setPoint(score);

    emit timechanged(time);

    if(time==0 && mode==0)
    {
        if(score>=100 )
        endGame(2);
        else
        endGame(1);
    }
}


void Widget::createboard()
{
    star= ui->star;
    tile[0][0] = ui->tile01;
    tile[0][1] = ui->tile02;
    tile[0][2] = ui->tile03;
    tile[0][3] = ui->tile04;
    tile[0][4] = ui->tile05;
    tile[0][5] = ui->tile06;
    tile[0][6] = ui->tile07;
    tile[0][7] = ui->tile08;
    tile[1][0] = ui->tile11;
    tile[1][1] = ui->tile12;
    tile[1][2] = ui->tile13;
    tile[1][3] = ui->tile14;
    tile[1][4] = ui->tile15;
    tile[1][5] = ui->tile16;
    tile[1][6] = ui->tile17;
    tile[1][7] = ui->tile18;
    tile[2][0] = ui->tile21;
    tile[2][1] = ui->tile22;
    tile[2][2] = ui->tile23;
    tile[2][3] = ui->tile24;
    tile[2][4] = ui->tile25;
    tile[2][5] = ui->tile26;
    tile[2][6] = ui->tile27;
    tile[2][7] = ui->tile28;
    tile[3][0] = ui->tile31;
    tile[3][1] = ui->tile32;
    tile[3][2] = ui->tile33;
    tile[3][3] = ui->tile34;
    tile[3][4] = ui->tile35;
    tile[3][5] = ui->tile36;
    tile[3][6] = ui->tile37;
    tile[3][7] = ui->tile38;
    tile[4][0] = ui->tile41;
    tile[4][1] = ui->tile42;
    tile[4][2] = ui->tile43;
    tile[4][3] = ui->tile44;
    tile[4][4] = ui->tile45;
    tile[4][5] = ui->tile46;
    tile[4][6] = ui->tile47;
    tile[4][7] = ui->tile48;
    tile[5][0] = ui->tile51;
    tile[5][1] = ui->tile52;
    tile[5][2] = ui->tile53;
    tile[5][3] = ui->tile54;
    tile[5][4] = ui->tile55;
    tile[5][5] = ui->tile56;
    tile[5][6] = ui->tile57;
    tile[5][7] = ui->tile58;
    tile[6][0] = ui->tile61;
    tile[6][1] = ui->tile62;
    tile[6][2] = ui->tile63;
    tile[6][3] = ui->tile64;
    tile[6][4] = ui->tile65;
    tile[6][5] = ui->tile66;
    tile[6][6] = ui->tile67;
    tile[6][7] = ui->tile68;
    tile[7][0] = ui->tile71;
    tile[7][1] = ui->tile72;
    tile[7][2] = ui->tile73;
    tile[7][3] = ui->tile74;
    tile[7][4] = ui->tile75;
    tile[7][5] = ui->tile76;
    tile[7][6] = ui->tile77;
    tile[7][7] = ui->tile78;
    tile[8][0] = ui->tile81;
    tile[8][1] = ui->tile82;
    tile[8][2] = ui->tile83;
    tile[8][3] = ui->tile84;
    tile[8][4] = ui->tile85;
    tile[8][5] = ui->tile86;
    tile[8][6] = ui->tile87;
    tile[8][7] = ui->tile88;
    tile[9][0] = ui->tile91;
    tile[9][1] = ui->tile92;
    tile[9][2] = ui->tile93;
    tile[9][3] = ui->tile94;
    tile[9][4] = ui->tile95;
    tile[9][5] = ui->tile96;
    tile[9][6] = ui->tile97;
    tile[9][7] = ui->tile98;
    tile[10][0] = ui->tile101;
    tile[10][1] = ui->tile102;
    tile[10][2] = ui->tile103;
    tile[10][3] = ui->tile104;
    tile[10][4] = ui->tile105;
    tile[10][5] = ui->tile106;
    tile[10][6] = ui->tile107;
    tile[10][7] = ui->tile108;
    startgame();
}

void Widget::startgame()
{
    allclear();
    fillempty();
    score=0;
    time=60;
    mode=0;
    emit scorechanged(score);
    emit lifechanged(life);
    emit timechanged(time);
}

Widget::~Widget()
{
    delete ui;
}

int Widget::checkclick()
{
    for(int y=0;y<11;y++)
       for(int x=0;x<8;x++)
       {
           if(tile[y][x]->click==1)
           {
               tileclick++;
               if(tileclick==1)
               {
                   tx=x;
                   ty=y;
               }
               if(tileclick==2)
               {
                   cx=tx-x;
                   cy=ty-y;
                   if((cx==0 && ( cy==-1 || cy==1)) || (cy==0 && ( cx==-1 || cx==1)))
                   {
                       tileclick=0;
                       return 1;
                   }
                   else
                   {
                       tileclick=0;
                       return 2;
                   }
               }
           }
       }

        tileclick=0;
        return 0;
}

void Widget::checkboard()
{
    int act=0;
    if(checkclick()==1)
    {
        exchange(tile[ty][tx],tile[ty-cy][tx-cx]);
        tile[ty][tx]->unclick();
        tile[ty-cy][tx-cx]->unclick();
        act=allclear();
        if(act==0)
        exchange(tile[ty][tx],tile[ty-cy][tx-cx]);
        else
        fillempty();
        cx=cy=tx=ty=-2;
    }
    if(checkclick()==2)
    {
        tile[ty][tx]->unclick();
        tile[ty-cy][tx-cx]->unclick();
        cx=cy=tx=ty=-2;
    }
}

int Widget::allclear()
{
    int check=0;
    emptyMove();
    if(rowclear()==1 || vclear()==1)
      check=1;

    if(check==1)
       allclear();

    emptyMove();
    return check;
}

int Widget::rowclear()
{
    int rcheck=0;
    for(int y=0;y<11;y++)
    {
        for(int x=0;x<6;x++)
       {
           if(tile[y][x]->getNumber()!=0 && tile[y][x]->getNumber()==tile[y][x+1]->getNumber() && tile[y][x+1]->getNumber()==tile[y][x+2]->getNumber())
           {
               rcheck=1;
               int num=tile[y][x]->getNumber();
               tile[y][x]->setNumber(0);
               tile[y][x+1]->setNumber(0);
               tile[y][x+2]->setNumber(0);
               x=x+3;
               for(int z=x;z<8;z++)
               {
                   if(tile[y][z]->getNumber()==num)
                      tile[y][z]->setNumber(0);
                   else
                   {
                       emptyMove();
                       break;
                   }
               }
               score+=3;
               emit scorechanged(score);
           }
       }
    }
    return rcheck;
}

int Widget::vclear()
{
    int vcheck=0;
    for(int x=0;x<8;x++)
    {
       for(int y=0;y<9;y++)
       {
           if(tile[y][x]->getNumber()!=0 && tile[y][x]->getNumber()==tile[y+1][x]->getNumber() && tile[y+1][x]->getNumber()==tile[y+2][x]->getNumber())
           {
               vcheck=1;
               int num=tile[y][x]->getNumber();
               tile[y][x]->setNumber(0);
               tile[y+1][x]->setNumber(0);
               tile[y+2][x]->setNumber(0);
               y=y+3;
               for(int z=y;y<11;y++)
               {
                   if(tile[z][x]->getNumber()==num)
                      tile[z][x]->setNumber(0);
                   else
                   {
                       emptyMove();
                       break;
                   }
               }
               score+=3;
               emit scorechanged(score);
           }
       }
    }
    return vcheck;
}

void Widget::exchange(Tile *Box1, Tile *Box2)
{
     int Num1 = Box1->getNumber();
     int Num2 = Box2->getNumber();
     Box1->setNumber(Num2);
     Box2->setNumber(Num1);
}


void Widget::emptyMove()
{
    for(int j = 0;j < 8;j++)
        for(int i = 10;i >=0;i--)
            if(tile[i][j]->isempty())
                for(int k=i;k>0;k--)
                    exchange(tile[k][j],tile[k-1][j]);

}

void Widget::endGame(int ch)
{
        mode=1;
        endgame= new QWidget;
        layout = new QVBoxLayout;
        resetb = new QPushButton;
        exit = new QPushButton;
        word =new QLabel;
        layout->addWidget(word);
        if(life>0)
        layout->addWidget(resetb);
        layout->addWidget(exit);
        QObject::connect(resetb,SIGNAL(clicked()),this,SLOT(reset()) );
        QObject::connect(exit,SIGNAL(clicked()),this,SLOT(quits()) );
        resetb->setText("Reset");
        exit->setText("Exit");
        if(ch==2)
        word->setText("You win!");
        else if(life==0)
        {
            word->setText("No any life!Gameover!!");
        }
        else
        {
            word->setText("Gameover!Try again");
            life--;
        }
        endgame->setLayout(layout);
        endgame->show();

}

void Widget::reset()
{
    score=40;
    time=5;
    endgame->hide();
    for(int x=0;x<8;x++)
       for(int y=0;y<11;y++)
       {
           int n =rand()%4;
           switch(n)
           {
            case 0:
            tile[y][x]->setNumber(2);
            break;
            case 1:
            tile[y][x]->setNumber(4);
            break;
            case 2:
            tile[y][x]->setNumber(6);
            break;
            case 3:
            tile[y][x]->setNumber(8);
            break;
            case 4:
            tile[y][x]->setNumber(10);
            break;
           }
           tile[y][x]->unclick();
       }
    startgame();
}

void Widget::quits()
{
    qApp->quit();
}

void Widget::fillempty()
{
    for(int x=0;x<8;x++)
       for(int y=0;y<11;y++)
       {
           if(tile[y][x]->getNumber()==0)
           {
               int n =rand()%5;
               switch(n)
              {
                case 0:
                tile[y][x]->setNumber(2);
                break;
                case 1:
                tile[y][x]->setNumber(4);
                break;
                case 2:
                tile[y][x]->setNumber(6);
                break;
                case 3:
                tile[y][x]->setNumber(8);
                break;
                case 4:
                tile[y][x]->setNumber(10);
                break;
               }
           }
       }
        allclear();
    if(checkempty()==1)
        fillempty();
}

int Widget::checkempty()
{
    for(int x=0;x<8;x++)
       for(int y=0;y<11;y++)
           if(tile[y][x]->getNumber()==0)
               return 1;

    return 0;
}
