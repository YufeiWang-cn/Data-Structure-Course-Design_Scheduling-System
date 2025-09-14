#include "addcourse.h"
#include "ui_addcourse.h"

addCourse::addCourse(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::addCourse)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowTitle("添加");
    ui->lineEdit->setFocus();
}

addCourse::~addCourse()
{
    delete ui;
}

void addCourse::on_pushButton_2_clicked()
{
    int ret = QMessageBox::warning(this, tr("警告"),
                                   tr("确定要清空所有课程信息？\n"
                                      "此操作会导致课程丢失"),
                                   QMessageBox::Ok | QMessageBox::Cancel,
                                   QMessageBox::Ok);
    if(ret == QMessageBox::Ok) {
        emit clear();
    }
}


void addCourse::on_pushButton_clicked()
{
    QString n = ui->lineEdit->text();
    QString p = ui->lineEdit_2->text();
    QString c = ui->lineEdit_3->text();
    bool ok;
    int credit_int = c.toInt(&ok);
    if(!ok) QMessageBox::critical(NULL, "警告", "课程学分格式错误!!!", QMessageBox::Ok, QMessageBox::Ok);
    else {
        emit writeFile(n, p, c);
        QMessageBox::information(NULL, "提示", "添加成功!", QMessageBox::Ok, QMessageBox::Ok);
    }
}

