#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bmicalculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    if (!checkInputFields()) {
        ui->bmiLineEdit->clear();
        return;
    }

    double weight = ui->weightLineEdit->text().toDouble();
    double height = ui->heightLineEdit->text().toDouble();

    BmiCalculator calculator(weight, height);

    QString result = QString::number(calculator.getBmi()) + " - " +
        calculator.getBmiCategory();

    ui->bmiLineEdit->setText(result);
}

bool MainWindow::checkInputFields() {
    bool isEmptyWeight = validateEmptyField(ui->weightLineEdit);
    bool isEmptyHeight = validateEmptyField(ui->heightLineEdit);

    if (isEmptyWeight || isEmptyHeight) {
        return false;
    }

    bool isInvalidWeight = validateInvalidField(ui->weightLineEdit);
    bool isInvalidHeight = validateInvalidField(ui->heightLineEdit);

    if (isInvalidWeight || isInvalidHeight) {
        return false;
    }

    return true;
}

bool MainWindow::validateEmptyField(QLineEdit* lineEdit) {
    bool isError = lineEdit->text().isEmpty();

    updateBorderColorOnError(isError, lineEdit);

    return isError;
}

bool MainWindow::validateInvalidField(QLineEdit *lineEdit) {
    bool isError = (lineEdit->text().toDouble() <= 0);

    updateBorderColorOnError(isError, lineEdit);

    return isError;
}

void MainWindow::updateBorderColorOnError(bool isError, QLineEdit* lineEdit) {
    if (isError) {
        lineEdit->setStyleSheet("QLineEdit { border: 2px solid red; }");
    } else {
        lineEdit->setStyleSheet("");
    }
}
