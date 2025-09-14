#ifndef AUTOMATICALLY_H
#define AUTOMATICALLY_H

#include <QWidget>
#include <QDir>
#include <QTextStream>
#include <QDebug>

namespace Ui {
class automatically;
}

class automatically : public QWidget
{
    Q_OBJECT

public:
    QString name;
    explicit automatically(QWidget *parent = nullptr, QString name = "");
    ~automatically();

private:
    Ui::automatically *ui;
};

#endif // AUTOMATICALLY_H
