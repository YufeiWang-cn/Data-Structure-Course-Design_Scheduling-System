#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QWidget>
#include <QDir>
#include <QTextStream>
#include <QDebug>

namespace Ui {
class timetable;
}

class timetable : public QWidget
{
    Q_OBJECT

public:
    QString name;
    explicit timetable(QWidget *parent = nullptr, QString name = "");
    ~timetable();

private:
    Ui::timetable *ui;
};

#endif // TIMETABLE_H
