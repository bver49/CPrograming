#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include "tile.h"
#include <QLabel>
#include <qboxlayout.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    Ui::Widget *ui;
    void createboard();
    void startgame();
    void endGame(int ch);
    void exchange(Tile *Box1,Tile *Box2);
    void emptyMove();
    void fillempty();
    int checkclick();
    int allclear();
    int rowclear();
    int vclear();
    int checkempty();
    int tileclick;
    int tx;
    int ty;
    int cx;
    int cy;
    int score;
    int life;
    int time;
    int mode;
    Tile* tile[11][8];
    Star* star;
    QPushButton* resetb;
    QPushButton* exit;
    QWidget* endgame;
    QVBoxLayout *layout;
    QLabel* word;
signals:
     void scorechanged(int score);
     void lifechanged(int life);
     void timechanged(int time);
public slots:
     void checkboard();
     void countdown();
     void reset();
     void quits();
};

#endif
