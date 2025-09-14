#include "enroll.h"
#include "ui_enroll.h"

Enroll::Enroll(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Enroll)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowTitle(u8"注册");
    ui->lineEdit->setFocus();
}

Enroll::~Enroll()
{
    delete ui;

}

void Enroll::on_pushButton_2_clicked()
{
    this->close();
}

// 确定
void Enroll::on_pushButton_clicked()
{
    QMessageBox::information(NULL, "sorry", u8"该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

