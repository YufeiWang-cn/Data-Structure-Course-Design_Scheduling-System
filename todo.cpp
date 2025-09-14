#include "todo.h"
#include "ui_todo.h"

todo::todo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::todo)
{
    ui->setupUi(this);
    resize(600, 450);
    setWindowTitle("todo");
}

todo::~todo()
{
    delete ui;
}
