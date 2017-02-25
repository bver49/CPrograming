#include "widget.h"
#include <QApplication>
#include <time.h>


int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication app(argc, argv);
    Widget game;
    game.show();
    return app.exec();

}
