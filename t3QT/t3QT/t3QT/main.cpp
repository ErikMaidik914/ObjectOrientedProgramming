#include "t3QT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller controller{ "vegetables.txt" };


    t3QT gui{ controller };
    gui.show();
    return a.exec();
}
