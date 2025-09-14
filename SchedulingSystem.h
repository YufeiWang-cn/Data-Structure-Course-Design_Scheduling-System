#pragma once

#include <QtWidgets/QMainWindow>  // 包含头文件，窗口类
#include <QProcess>
#include <QMessageBox>
#include <QPainter>
#include <QDebug>
#include <QColorDialog>
#include <QFontDialog>
#include <QtWidgets/QApplication>  // 包含一个应用程序类的头文件
#include <QIcon>
#include <QPixmap>
#include <QGridLayout>
#include <QDebug>
#include <QDir>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QByteArray>
#include <QMap>
#include <QCheckBox>
#include "ui_SchedulingSystem.h"
#include "enroll.h"
#include "login.h"
#include "credit.h"
#include "init_project.h"
#include "addcourse.h"
#include "node.h"
#include "edge.h"
#include "coursemap.h"
#include "automatically.h"
#include "timetable.h"
#include "help.h"
#include "about.h"
#include "todo.h"
#include "ui_help.h"
#include "ui_about.h"
#include "ui_todo.h"

class SchedulingSystem : public QMainWindow
{
    Q_OBJECT  // 宏，允许类中使用信号和槽的机制

public:
    SchedulingSystem(QWidget *parent = nullptr);  // 构造函数
    ~SchedulingSystem();  // 析构函数

    void paintEvent(QPaintEvent *event);
    QString name;
    QColor color;
    QFont font;
    // 颜色转字符串
    QString ColorToString(QColor v_color);
    // 返回可选课程总数
    int courseSelect(Graphl g, QString projectName, int i, QTableWidget *table, QCheckBox *check[100]) {
        QDir projectPath("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
        projectPath.cd(projectName);
        QDir base;
        QString course;
        Graphl originalGraphl(g);  // 防止破坏上一学期选课后的图状态，使用拷贝构造函数创建新的图
        // 可选课程写入文件
        // 如果包含回路，则弹出警告，说明输入错误，无法进行拓扑排序
        // if(!(originalGraphl.topologySort(projectName, i))) QMessageBox::critical(NULL, "错误", "图中存在环，无法进行拓扑排序!!!", QMessageBox::Ok, QMessageBox::Ok);
        originalGraphl.topologySort(projectName, i);
        base = projectPath;
        QString fileName = QString::number(i) + ".txt";
        QString path = base.absoluteFilePath(fileName);
        QFile project(path);
        project.open(QIODevice::ReadOnly);
        QTextStream txt(&project);
        // 每次读取文件内容的一行
        int num = 0;
        while(!txt.atEnd()) {
            course = txt.readLine();  // 可选的课程名称
            table->setItem(num, 1, new QTableWidgetItem(course));
            table->setItem(num, 2, new QTableWidgetItem(QString::number(originalGraphl.name_weight.value(course))));
            num++;
        }
        for(int j = 0; j < num; j++) {
            check[j] = new QCheckBox;
            table->setCellWidget(j, 0, check[j]);
        }
        return num;
    }

private:
    Ui::SchedulingSystemClass ui;

signals:
    // 自定义信号可以写在signals下
    // 返回值是void，只需要声明，不需要实现
    // 可以有参数，可以重载
    void createGraphl();
    // 学期i确定后发出信号
    void semester1();
    void semester2();
    void semester3();
    void semester4();
    void semester5();
    void semester6();
    void semester7();
    void semester8();
    // 重置学期i发出信号
    void resetting1();
    void resetting2();
    void resetting3();
    void resetting4();
    void resetting5();
    void resetting6();
    void resetting7();
    void resetting8();
    // 学期i课程设置完成
    void workDone1(Graphl g);
    void workDone2(Graphl g);
    void workDone3(Graphl g);
    void workDone4(Graphl g);
    void workDone5(Graphl g);
    void workDone6(Graphl g);
    void workDone7(Graphl g);
    void workDone8(Graphl g);
    // 传递参数（图的初始状态，用于重置）
    //void graphl1(Graphl g);
    void graphl3(Graphl g);
    void graphl4(Graphl g);
    void graphl5(Graphl g);
    void graphl6(Graphl g);
    void graphl7(Graphl g);
    void graphl8(Graphl g);

    void nameReady();

public slots:
    // 早期Qt版本必须写在public slots下，高级版本可以写在public或者全局下
    // 返回值void，需要声明，也需要实现
    // 可以有参数，可以重载

private slots:
    void on_color_triggered();
    void on_typeface_triggered();
    void on_exit_triggered();
    void on_enroll_triggered();
    void on_login_triggered();
    void on_credit_triggered();
    void on_newProject_triggered();
    void on_add_triggered();
    void on_exist_triggered();
    void on_timetable_triggered();
    void on_automatically_triggered();
    void on_newFile_triggered();
    void on_openFile_triggered();
    void on_closeProject_triggered();
    void on_closeAll_triggered();
    void on_saveProject_triggered();
    void on_saveAll_triggered();
    void on_openProject_triggered();
    void on_personalInfo_triggered();
    void on_help_triggered();
    void on_about_triggered();
    void on_todo_triggered();
};
