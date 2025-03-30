#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_calculateButton_clicked();

private:
    bool checkInputFields();

    bool validateEmptyField(QLineEdit* lineEdit);

    bool validateInvalidField(QLineEdit* lineEdit);

    void updateBorderColorOnError(bool isError, QLineEdit* lineEdit);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
