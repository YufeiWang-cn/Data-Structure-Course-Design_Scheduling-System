#include "coursemap.h"
#include "ui_coursemap.h"

courseMap::courseMap(QWidget *parent, QString name) :
    QGraphicsView(parent),
    ui(new Ui::courseMap)
{
    ui->setupUi(this);
    resize(600, 450);
    setWindowTitle("已有课程");
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setBackgroundBrush(Qt::gray);  // 设置背景色

    int i,j;
    QMap<QString, int> name_index;  // 记录图中Node的课程名称与索引的对应关系
    QDir dir("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
    dir.cd(name);
    QString filePath = dir.absoluteFilePath("course.txt");
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    // 读取文件中的课程信息
    QTextStream txtInput(&file);
    QString lineStr;  // 每次读取文件内容的一行
    QStringList strs;  // 存储分隔后的字符
    i = 1;  // 用于循环记录索引
    bool hasKey;
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        strs = lineStr.split('$');
        // strs[0]为课程名称，strs[1]为先修课程，strs[2]为学分
        // name_index和name_weight对应关系处理（map类型）
        hasKey = name_index.contains(strs[0]);  // 判断是否已经添加过课程，若添加过，则不重复添加
        if(!hasKey) {
            name_index.insert(strs[0],i);
            i++;
        }
    }
    file.close();
    // 再次打开文件，用于建立课程之间的前驱后继关系
    int num = name_index.size();
    Graphl g(num);
    g.name_index = name_index;
    file.open(QIODevice::ReadOnly);
    int index1, index2;  // 用于存储先修课程和课程的索引
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        strs = lineStr.split('$');
        // strs[0]为课程名称，strs[1]为先修课程，strs[2]为学分
        if(strs[1] == "") continue;  // 如果没有先修课程，说明不用添加边，进入下一次循环
        index1 = name_index.value(strs[1]);
        index2 = name_index.value(strs[0]);
        g.setEdge(index1, index2);
    }
    file.close();
    Node **node = new Node*[num + 1];
    for(j = 1; j <= num; j++) {
        node[j] = new Node;
        scene->addItem(node[j]);
    }
    // 根据课程之间的关系确定点的位置以及边的指向
    QDir dir_("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir_为当前目录
    dir_.cd(name);
    QString s;  // 用于拼接文件名
    QString filePath_;
    int index;
    // 读取所有课程节点并确定位置
    for(i = 1; i <= 8; i++) {
        s = QString::number(i + 10).append(".txt");  // i.txt
        filePath_ = dir_.absoluteFilePath(s);
        QFile file_(filePath_);
        file_.open(QIODevice::ReadOnly);
        // 读取文件中的课程信息
        QTextStream txtInput_(&file_);
        j = 1;
        while(!txtInput_.atEnd())
        {
            lineStr = txtInput_.readLine();
            strs = lineStr.split(' ');
            index = name_index.value(strs[0]);
            node[index]->setPos(double(i * 200), double(j * 100));
            QGraphicsTextItem *txtitem = new QGraphicsTextItem(strs[0]);
            txtitem->setPos(QPointF(i * 200, j * 100));
            scene->addItem(txtitem);
            j++;
        }
        file_.close();
    }
    // 设置有向边
    QDir dir__("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir__为当前目录
    dir__.cd(name);
    QString filePath__ = dir__.absoluteFilePath("course.txt");
    QFile file__(filePath__);
    file__.open(QIODevice::ReadOnly);
    QTextStream txtInput__(&file__);
    while(!txtInput__.atEnd())
    {
        lineStr = txtInput__.readLine();
        strs = lineStr.split('$');
        // strs[0]为课程名称，strs[1]为先修课程，strs[2]为学分
        if(strs[1] == "") continue;  // 如果没有先修课程，说明不用添加边，进入下一次循环
        index1 = name_index.value(strs[1]);
        index2 = name_index.value(strs[0]);
        scene->addItem(new Edge(node[index1], node[index2]));
    }
    file__.close();

    QGraphicsView *view = new QGraphicsView(scene);
    QHBoxLayout *layout = new QHBoxLayout;  // 水平布局
    layout->addWidget(view);
    setLayout(layout);
}

courseMap::~courseMap()
{
    delete ui;
}
