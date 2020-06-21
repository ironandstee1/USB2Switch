#include "mainwindow.h"
#include "gamepadform.h"
#include "windows.h"
#include "ftd2xx.h"
#include "ftdifunctions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow widget;
    Ui::MainWindow ui;
    ui.setupUi(&widget);

    widget.show();
    return app.exec();
}
