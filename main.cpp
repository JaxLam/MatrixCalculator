#include "matrixcalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatrixCalculator w;
    w.show();

    return a.exec();
}
