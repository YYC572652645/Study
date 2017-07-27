#include "qsoundrout.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSoundRout w;
    w.show();

    return a.exec();
}
