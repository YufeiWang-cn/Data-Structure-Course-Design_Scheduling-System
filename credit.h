#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Credit;
}

class Credit : public QDialog
{
    Q_OBJECT

public:
    explicit Credit(QDialog *parent = nullptr);
    ~Credit();

private slots:
    void on_doubleSpinBox_valueChanged(double arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::Credit *ui;
};

#endif // CREDIT_H
