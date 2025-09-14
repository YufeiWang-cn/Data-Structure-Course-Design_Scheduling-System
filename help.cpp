#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
    resize(600, 450);
    setWindowTitle("帮助文档");
}

help::~help()
{
    delete ui;
}
