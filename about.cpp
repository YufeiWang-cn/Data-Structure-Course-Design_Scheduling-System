#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    resize(600, 450);
    setWindowTitle("关于");
}

about::~about()
{
    delete ui;
}
