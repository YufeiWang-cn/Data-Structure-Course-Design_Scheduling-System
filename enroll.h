#ifndef ENROLL_H
#define ENROLL_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Enroll;
}

class Enroll : public QDialog
{
    Q_OBJECT

public:
    explicit Enroll(QDialog *parent = nullptr);
    ~Enroll();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Enroll *ui;
};

#endif // ENROLL_H
