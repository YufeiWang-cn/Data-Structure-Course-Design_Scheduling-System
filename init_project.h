#ifndef INIT_PROJECT_H
#define INIT_PROJECT_H

#include <QDialog>
#include <qstring.h>
#include <QTabWidget>
#include <QMessageBox>
#include "Graphl.h"

namespace Ui {
class Init_project;
}

class Init_project : public QDialog
{
    Q_OBJECT

public:
    explicit Init_project(QDialog *parent = nullptr);
    ~Init_project();
    QString getQString();
    QString getNum();
    QString text;  // 项目名
    QString num;  // 课程数量
    Graphl *g;  // 图

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void waitText();

private:
    Ui::Init_project *ui;
};

#endif // INIT_PROJECT_H
