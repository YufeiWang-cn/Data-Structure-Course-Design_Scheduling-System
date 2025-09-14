#include "init_project.h"
#include "ui_init_project.h"

Init_project::Init_project(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Init_project)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowTitle("新建项目");
}

Init_project::~Init_project()
{
    delete ui;
}

QString Init_project::getQString()
{
    return ui->lineEdit_5->text();
}

QString Init_project::getNum()
{
    return ui->lineEdit_6->text();
}

void Init_project::on_pushButton_3_clicked()
{
    bool ok;
    text = getQString();
    num = getNum();
    // 如果项目名不为空
    if(text != "") {
        int numVertex = num.toInt(&ok);
        if(!ok) QMessageBox::critical(NULL, "提示", "课程数量格式错误!!!", QMessageBox::Ok, QMessageBox::Ok);
        else if(numVertex == 0) QMessageBox::critical(NULL, "提示", "课程数量必须为正整数!!!", QMessageBox::Ok, QMessageBox::Ok);
        else {
            emit waitText();
            this->close();
        }
    }
    else QMessageBox::critical(NULL, "提示", "请输入项目名!!!", QMessageBox::Ok, QMessageBox::Ok);
}


void Init_project::on_pushButton_4_clicked()
{
    this->close();
}

