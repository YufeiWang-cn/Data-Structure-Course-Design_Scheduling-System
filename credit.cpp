#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowTitle("学分");
    //ui->lineEdit->setFocus();
    ui->doubleSpinBox->setRange(0, 17.5);  // 设置数值范围
    ui->doubleSpinBox->setSingleStep(0.5);  // 每次点击箭头时增加的数值
    ui->doubleSpinBox->setDecimals(1);  // 设置小数点位数
    ui->doubleSpinBox->setSpecialValueText(tr("只能0.5的倍数"));  // 特殊文本值，数值为最小时显示
    ui->doubleSpinBox->setSuffix("学分");
    ui->doubleSpinBox->setWrapping(true);  // 开启循环
    ui->horizontalSlider->setRange(0, 17.5);
    ui->horizontalSlider->setSingleStep(0.5);  // 每次拖动时增加的数值
    ui->horizontalSlider->setPageStep(1);  // 每次点击slider时增加的数值
    ui->horizontalSlider->setTickPosition(QSlider::TicksAbove);  // 设置slider刻度的位置
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->horizontalSlider->setValue(arg1);
}


void Credit::on_horizontalSlider_valueChanged(int value)
{
    ui->doubleSpinBox->setValue(value);
}

// 确定
void Credit::on_pushButton_clicked()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

