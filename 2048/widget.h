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
    void startGame();
    void randomtile();
    void keyPressEvent(QKeyEvent *event);
    bool isFull();
    void exchange(Tile *Box1,Tile *Box2);
    void emptytileMoveLft();
    void emptytileMoveDown();
    void emptytileMoveRight();
    void emptytileMoveUp();
    void moveUp();
    void moveRight();
    void moveLeft();
    void moveDown();
    bool movepossible();
    void endGame(int ch);
    Tile* tile[4][4];
    int score;
    QPushButton* resetb;
    QPushButton* exit;
    QWidget* endgame;
    QVBoxLayout *layout;
    QLabel* word;

public slots:
     void reset();
     void quits();
signals:
     void changed(int score);
};

#endif
