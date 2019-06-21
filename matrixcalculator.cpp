#include "matrixcalculator.h"
#include "ui_matrixcalculator.h"
#include <sstream>
#include <iomanip>

#include "Matrix.h"

MatrixCalculator::MatrixCalculator(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MatrixCalculator)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/1.ico"));
    QPalette p = ui->textBrowserMatA->palette();
    p.setColor(QPalette::Base, QColor(0,0,0,0)); // r,g,b,A
    ui->textBrowserMatA->setPalette(p);
    ui->textBrowserMatB->setPalette(p);
    ui->textBrowserMatC->setPalette(p);
    ui->spinBox1m->setPalette(p);
    ui->spinBox1n->setPalette(p);
    ui->spinBox2m->setPalette(p);
    ui->spinBox2n->setPalette(p);
    ui->spinBox3m->setPalette(p);
    ui->spinBox3n->setPalette(p);
}

MatrixCalculator::~MatrixCalculator()
{
    delete ui;
}


void MatrixCalculator::on_buttonExchange_clicked()
{
    QString text, text2, temp;
    text = ui->textEditMatA->toPlainText();
    text2 = ui->textEditMatB->toPlainText();
    temp = text;
    ui->textEditMatA->setText(text2);
    ui->textEditMatB->setText(temp);
}

void MatrixCalculator::on_buttonAplusB_clicked()
{
    QString text, text2;
    text = ui->textEditMatA->toPlainText();
    text2 = ui->textEditMatB->toPlainText();

    if(text.isEmpty() || text2.isEmpty()) {}
    else
    {
        std::stringstream ins1, ins2, outs;
        ins1 << text.toStdString();
        ins2 << text2.toStdString();
        Matrix temp, temp2;
        ins1 >> temp;
        ins2 >> temp2;
        outs << temp + temp2;

        text = QString::fromStdString(outs.str());
        ui->textEditMatC->setText(text);
    }
}

void MatrixCalculator::on_buttonAminusB_clicked()
{
    QString text, text2;
    text = ui->textEditMatA->toPlainText();
    text2 = ui->textEditMatB->toPlainText();

    if(text.isEmpty() || text2.isEmpty()) {}
    else
    {
        std::stringstream ins1, ins2, outs;
        ins1 << text.toStdString();
        ins2 << text2.toStdString();
        Matrix temp, temp2;
        ins1 >> temp;
        ins2 >> temp2;
        outs << temp - temp2;


        text = QString::fromStdString(outs.str());
        ui->textEditMatC->setText(text);
    }
}

void MatrixCalculator::on_buttonAtimeB_clicked()
{
    QString text, text2;
    text = ui->textEditMatA->toPlainText();
    text2 = ui->textEditMatB->toPlainText();

    if(text.isEmpty() || text2.isEmpty()) {}
    else
    {
        std::stringstream ins1, ins2, outs;
        ins1 << text.toStdString();
        ins2 << text2.toStdString();
        Matrix temp, temp2;
        ins1 >> temp;
        ins2 >> temp2;
        outs << temp * temp2;


        text = QString::fromStdString(outs.str());
        ui->textEditMatC->setText(text);
    }
}

void MatrixCalculator::on_buttonClear1_clicked()
{
    ui->textEditMatA->clear();
}

void MatrixCalculator::on_buttonClear2_clicked()
{
    ui->textEditMatB->clear();
}

void MatrixCalculator::on_buttonClear3_clicked()
{
    ui->textEditMatC->clear();
}

void MatrixCalculator::on_buttonCopyToA_clicked()
{
    ui->textEditMatA->setText(ui->textEditMatC->toPlainText());
}

void MatrixCalculator::on_buttonCopyToB_clicked()
{
    ui->textEditMatB->setText(ui->textEditMatC->toPlainText());
}

void MatrixCalculator::on_buttonTran1_clicked()
{
    QString text;
    text = ui->textEditMatA->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.transpose();


        text = QString::fromStdString(outs.str());
        ui->textEditMatA->setText(text);
    }
}


void MatrixCalculator::on_buttonTran2_clicked()
{
    QString text;
    text = ui->textEditMatB->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.transpose();


        text = QString::fromStdString(outs.str());
        ui->textEditMatB->setText(text);
    }
}void MatrixCalculator::on_buttonTran3_clicked()
{
    QString text;
    text = ui->textEditMatC->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.transpose();


        text = QString::fromStdString(outs.str());
        ui->textEditMatC->setText(text);
    }
}

void MatrixCalculator::on_buttonPower1_clicked()
{
    QString text;
    int m, n;
    int power = ui->spinBoxP1->value();
    text = ui->textEditMatA->toPlainText();
    m = ui->spinBox1m->value();
    n = ui->spinBox1n->value();
    if(n != m || m == 0) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        Matrix temp2(temp);
        for(int i = 1;i < power;i++)
            temp2 = temp2 * temp;
        outs << temp2;

        text = QString::fromStdString(outs.str());
        ui->textEditMatA->setText(text);
    }
}

void MatrixCalculator::on_buttonPower2_clicked()
{
    QString text;
    int m, n;
    int power = ui->spinBoxP2->value();
    text = ui->textEditMatB->toPlainText();
    m = ui->spinBox2m->value();
    n = ui->spinBox2n->value();
    if(n != m || m == 0) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        Matrix temp2(temp);
        for(int i = 1;i < power;i++)
            temp2 = temp2 * temp;
        outs << temp2;

        text = QString::fromStdString(outs.str());
        ui->textEditMatB->setText(text);
    }
}

void MatrixCalculator::on_buttonPower3_clicked()
{
    QString text;
    int m, n;
    int power = ui->spinBoxP3->value();
    text = ui->textEditMatC->toPlainText();
    m = ui->spinBox3m->value();
    n = ui->spinBox3n->value();
    if(n != m || m == 0) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        Matrix temp2(temp);
        for(int i = 1;i < power;i++)
            temp2 = temp2 * temp;
        outs << temp2;

        text = QString::fromStdString(outs.str());
        ui->textEditMatC->setText(text);
    }
}

void MatrixCalculator::on_textEditMatA_textChanged()
{
    QString text;
    text = ui->textEditMatA->toPlainText();
    std::stringstream ins;
    ins << text.toStdString();
    Matrix temp;
    ins >> temp;
    ui->spinBox1m->setValue(temp.getRow());
    ui->spinBox1n->setValue(temp.getColumn());
    on_buttonDet1_clicked();
}
void MatrixCalculator::on_textEditMatB_textChanged()
{
    QString text;
    text = ui->textEditMatB->toPlainText();
    std::stringstream ins;
    ins << text.toStdString();
    Matrix temp;
    ins >> temp;
    ui->spinBox2m->setValue(temp.getRow());
    ui->spinBox2n->setValue(temp.getColumn());
    on_buttonDet2_clicked();

}
void MatrixCalculator::on_textEditMatC_textChanged()
{
    QString text;
    text = ui->textEditMatC->toPlainText();
    std::stringstream ins;
    ins << text.toStdString();
    Matrix temp;
    ins >> temp;
    ui->spinBox3m->setValue(temp.getRow());
    ui->spinBox3n->setValue(temp.getColumn());
    on_buttonDet3_clicked();

}

void MatrixCalculator::on_buttonRREF1_clicked()
{
    QString text;
    text = ui->textEditMatA->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.rref();


        text = QString::fromStdString(outs.str());
        ui->textEditMatA->setText(text);
    }
}

void MatrixCalculator::on_buttonRREF2_clicked()
{
    QString text;
    text = ui->textEditMatB->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.rref();


        text = QString::fromStdString(outs.str());
        ui->textEditMatB->setText(text);
    }
}

void MatrixCalculator::on_buttonRREF3_clicked()
{
    QString text;
    text = ui->textEditMatC->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.rref();


        text = QString::fromStdString(outs.str());
        ui->textEditMatC->setText(text);
    }
}

void MatrixCalculator::on_buttonInverse1_clicked()
{
    QString text;
    text = ui->textEditMatA->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.inverse();


        text = QString::fromStdString(outs.str());
        ui->textEditMatA->setText(text);
    }
}

void MatrixCalculator::on_buttonInverse2_clicked()
{
    QString text;
    text = ui->textEditMatB->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.inverse();


        text = QString::fromStdString(outs.str());
        ui->textEditMatB->setText(text);
    }
}

void MatrixCalculator::on_buttonInverse3_clicked()
{
    QString text;
    text = ui->textEditMatC->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.inverse();


        text = QString::fromStdString(outs.str());
        ui->textEditMatC->setText(text);
    }
}

void MatrixCalculator::on_buttonDet1_clicked()
{
    QString text;
    text = ui->textEditMatA->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.det();
        text = "det = ( " + QString::fromStdString(outs.str()) + " )";
        ui->buttonDet1->setText(text);
    }
}
void MatrixCalculator::on_buttonDet2_clicked()
{
    QString text;
    text = ui->textEditMatB->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.det();
        text = "det = ( " + QString::fromStdString(outs.str()) + " )";
        ui->buttonDet2->setText(text);
    }
}
void MatrixCalculator::on_buttonDet3_clicked()
{
    QString text;
    text = ui->textEditMatC->toPlainText();
    if(text.isEmpty()) {}
    else
    {
        std::stringstream ins, outs;
        ins << text.toStdString();
        Matrix temp;
        ins >> temp;
        outs << temp.det();
        text = "det = ( " + QString::fromStdString(outs.str()) + " )";
        ui->buttonDet3->setText(text);
    }
}
