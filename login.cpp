#include "login.h"
#include "ui_login.h"

Login::Login(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowTitle("登录");
    ui->lineEdit_5->setFocus();
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_4_clicked()
{
    this->close();
}

// 确定
void Login::on_pushButton_3_clicked()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

