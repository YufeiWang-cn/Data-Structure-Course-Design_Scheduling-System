#include "SchedulingSystem.h"

// 快捷键
/*
 * 整行移动，ctrl + shift + ↑ 或者 ↓
 * 帮助文档 F1
 * 自动对齐 ctrl + i
 * 同名之间的.h 和 .cpp的切换 F4
 * */

//main程序入口，argc：命令行变量的数量，argv：命令行变量的数组
int main(int argc, char *argv[])
{
    // a，应用程序对象，在Qt中应用程序对象有且只有一个，并且必须要有一个存在
    QApplication a(argc, argv);
    // 窗口对象
    SchedulingSystem w;
    // 窗口对象，默认不会显示，必须要调用show方法显示窗口
    w.show();
    // 让应用程序对象进入消息循环机制
    // 让代码阻塞到这行
    return a.exec();
}
