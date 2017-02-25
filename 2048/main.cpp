#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget game;
    game.show();
    return app.exec();

}
