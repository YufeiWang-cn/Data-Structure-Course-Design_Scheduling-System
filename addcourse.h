#ifndef ADDCOURSE_H
#define ADDCOURSE_H

#include <QDialog>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QCloseEvent>
#include <QDebug>

namespace Ui {
class addCourse;
}

class addCourse : public QDialog
{
    Q_OBJECT

public:
    explicit addCourse(QDialog*parent = nullptr);
    ~addCourse();
    QString name;  // 课程名称
    QString pre;  // 先修课程
    QString credit;  // 学分
    QString projectName;  // 项目名称

    // 重写关闭事件，否则关闭后无法发出addClose信号
    void closeEvent ( QCloseEvent * e )
    {
        if( QMessageBox::question(this,
                                  tr("Quit"),
                                  tr("Are you sure to quit this application?"),
                                  QMessageBox::Yes, QMessageBox::No )
            == QMessageBox::Yes){
            e->accept();  // 不会将事件传递给组件的父组件
            emit addClose();
        }
        else
            e->ignore();
    }

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void writeFile(QString n, QString p, QString c);
    void addClose();
    void clear();

private:
    Ui::addCourse *ui;
};

#endif // ADDCOURSE_H
