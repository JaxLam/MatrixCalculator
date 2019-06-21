#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H

#include <QMainWindow>

namespace Ui {
class MatrixCalculator;
}

class MatrixCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit MatrixCalculator(QWidget *parent = 0);
    ~MatrixCalculator();

private slots:
    void on_buttonExchange_clicked();

    void on_buttonAplusB_clicked();

    void on_buttonAminusB_clicked();

    void on_buttonAtimeB_clicked();

    void on_buttonClear1_clicked();

    void on_buttonClear2_clicked();

    void on_buttonClear3_clicked();

    void on_buttonCopyToA_clicked();

    void on_buttonCopyToB_clicked();

    void on_buttonTran1_clicked();

    void on_buttonTran2_clicked();

    void on_buttonTran3_clicked();

    void on_buttonPower1_clicked();

    void on_buttonPower2_clicked();

    void on_buttonPower3_clicked();

    void on_textEditMatA_textChanged();

    void on_textEditMatB_textChanged();

    void on_textEditMatC_textChanged();

    void on_buttonRREF1_clicked();

    void on_buttonRREF2_clicked();

    void on_buttonRREF3_clicked();

    void on_buttonInverse1_clicked();

    void on_buttonInverse2_clicked();

    void on_buttonInverse3_clicked();

    void on_buttonDet1_clicked();

    void on_buttonDet2_clicked();

    void on_buttonDet3_clicked();

private:
    Ui::MatrixCalculator *ui;
};

#endif // MATRIXCALCULATOR_H
