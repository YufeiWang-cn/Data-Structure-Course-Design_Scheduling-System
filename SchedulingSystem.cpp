#include "SchedulingSystem.h"

SchedulingSystem::SchedulingSystem(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    resize(800, 600);
    setWindowTitle("排课系统");
    setWindowIcon(QIcon(":/Image/bgd.jpg"));
    ui.tabWidget->setTabsClosable(true);
}

SchedulingSystem::~SchedulingSystem()
{}

void SchedulingSystem::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    /*
    QPixmap pix;
    pix.load(":/Image/background.jpg");
    // 背景图片适应窗口大小
    painter.drawPixmap(0, 0, this->frameGeometry().width(), this->frameGeometry().height(), pix);*/
}

// 点击“颜色”菜单后
void SchedulingSystem::on_color_triggered()
{
    color = QColorDialog::getColor();
}

// 点击“字体”菜单后
void SchedulingSystem::on_typeface_triggered()
{
   font = QFontDialog::getFont(0);
}


// 点击“退出”菜单后
void SchedulingSystem::on_exit_triggered()
{
    this->close();
}

// 点击“注册”菜单后
void SchedulingSystem::on_enroll_triggered()
{
    Enroll* enroll = new Enroll;
    enroll->show();
}

// 点击“登录”菜单后
void SchedulingSystem::on_login_triggered()
{
    Login* login = new Login;
    login->show();
}

// 点击“学分”菜单后
void SchedulingSystem::on_credit_triggered()
{
    Credit* credit = new Credit;
    credit->show();
}


// 点击“新建项目”菜单后
void SchedulingSystem::on_newProject_triggered()
{
    QTabWidget *pageWidget = new QTabWidget;
    Init_project* init_project = new Init_project;
    init_project->show();

    // 接收到项目名和学分后才开始创建项目
    connect(init_project, &Init_project::waitText, this, [=]()mutable{
        name = init_project->text;
        ui.tabWidget->addTab(pageWidget, init_project->text);
        ui.tabWidget->setCurrentWidget(pageWidget);
        // 为项目创建文件夹
        QDir dir("../Scheduling-System/Scheduling-System/");  // 初始化dir为当前目录
        dir.cd("./myProject");  // 目录切换到myProject文件夹下
        if(!dir.exists(init_project->text)) {
            dir.mkdir(init_project->text);  // 创建文件夹（名称为刚刚输入的项目名）
            QMessageBox::information(NULL, "提示", "创建成功~", QMessageBox::Ok, QMessageBox::Ok);
        }
        else QMessageBox::warning(NULL, "警告", "已存在该项目!!!", QMessageBox::Ok, QMessageBox::Ok);
        // 初始化时加载文件路径
        dir.cd(init_project->text);
        QString filePath = dir.absoluteFilePath("course.txt");
        QFile file(filePath);
        // 以读写的方式打开文件，成功返回true，失败返回false
        // 创建课程文件
        file.open(QIODevice::ReadWrite);
        file.close();
        // 创建存储课程数量的文件
        filePath = dir.absoluteFilePath("num.txt");
        QFile file1(filePath);
        // 清空文件内容
        file1.open(QFile::WriteOnly|QFile::Truncate);
        file1.close();

        file1.open(QIODevice::ReadWrite | QIODevice::Text);
        file1.write(init_project->num.toUtf8());
        file1.close();
        // tab点击红叉关闭
        connect(ui.tabWidget, &QTabWidget::tabCloseRequested, ui.tabWidget, &QTabWidget::removeTab);
    });

    // 创建表格
    QStringList qlist;
    qlist << "是否选中" << "课程名称" << "学分";

    // table1
    QTableWidget *table1 = new QTableWidget(100, 3);
    //table1->resize(377, 200);
    table1->setFont(font);
    table1->horizontalHeader()->setVisible(true);  // 横向表头可视化
    table1->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置编辑方式：禁止编辑表格
    table1->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置表格选择方式：设置表格为整行选中
    table1->setStyleSheet("selection-background-color:pink");  // 设置选中颜色:粉色
    table1->setHorizontalHeaderLabels(qlist);
    // table2
    QTableWidget *table2 = new QTableWidget(100, 3);
    table2->setFont(font);
    table2->horizontalHeader()->setVisible(true);  // 横向表头可视化
    table2->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置编辑方式：禁止编辑表格
    table2->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置表格选择方式：设置表格为整行选中
    table2->setStyleSheet("selection-background-color:pink");  // 设置选中颜色:粉色
    table2->setColumnCount(4);
    table2->setHorizontalHeaderLabels(qlist);
    // table3
    QTableWidget *table3 = new QTableWidget(100, 3);
    table3->setFont(font);
    table3->horizontalHeader()->setVisible(true);  // 横向表头可视化
    table3->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置编辑方式：禁止编辑表格
    table3->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置表格选择方式：设置表格为整行选中
    table3->setStyleSheet("selection-background-color:pink");  // 设置选中颜色:粉色
    table3->setColumnCount(4);
    table3->setHorizontalHeaderLabels(qlist);
    // table4
    QTableWidget *table4 = new QTableWidget(100, 3);
    table4->setFont(font);
    table4->horizontalHeader()->setVisible(true);  // 横向表头可视化
    table4->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置编辑方式：禁止编辑表格
    table4->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置表格选择方式：设置表格为整行选中
    table4->setStyleSheet("selection-background-color:pink");  // 设置选中颜色:粉色
    table4->setColumnCount(4);
    table4->setHorizontalHeaderLabels(qlist);
    // table5
    QTableWidget *table5 = new QTableWidget(100, 3);
    table5->setFont(font);
    table5->horizontalHeader()->setVisible(true);  // 横向表头可视化
    table5->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置编辑方式：禁止编辑表格
    table5->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置表格选择方式：设置表格为整行选中
    table5->setStyleSheet("selection-background-color:pink");  // 设置选中颜色:粉色
    table5->setColumnCount(4);
    table5->setHorizontalHeaderLabels(qlist);
    // table6
    QTableWidget *table6 = new QTableWidget(100, 3);
    table6->setFont(font);
    table6->horizontalHeader()->setVisible(true);  // 横向表头可视化
    table6->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置编辑方式：禁止编辑表格
    table6->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置表格选择方式：设置表格为整行选中
    table6->setStyleSheet("selection-background-color:pink");  // 设置选中颜色:粉色
    table6->setColumnCount(4);
    table6->setHorizontalHeaderLabels(qlist);
    // table7
    QTableWidget *table7 = new QTableWidget(100, 3);
    table7->setFont(font);
    table7->horizontalHeader()->setVisible(true);  // 横向表头可视化
    table7->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置编辑方式：禁止编辑表格
    table7->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置表格选择方式：设置表格为整行选中
    table7->setStyleSheet("selection-background-color:pink");  // 设置选中颜色:粉色
    table7->setColumnCount(4);
    table7->setHorizontalHeaderLabels(qlist);
    // table8
    QTableWidget *table8 = new QTableWidget(100, 3);
    table8->setFont(font);
    table8->horizontalHeader()->setVisible(true);  // 横向表头可视化
    table8->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置编辑方式：禁止编辑表格
    table8->setSelectionBehavior(QAbstractItemView::SelectRows);  // 设置表格选择方式：设置表格为整行选中
    table8->setStyleSheet("selection-background-color:pink");  // 设置选中颜色:粉色
    table8->setColumnCount(4);
    table8->setHorizontalHeaderLabels(qlist);

    // label1
    QLabel *label1 = new QLabel;
    label1->setText("第一学期");
    label1->setAlignment(Qt::AlignCenter);  // 设置对齐方式为居中对齐
    // label2
    QLabel *label2 = new QLabel;
    label2->setText("第二学期");
    label2->setAlignment(Qt::AlignCenter);
    // label3
    QLabel *label3 = new QLabel;
    label3->setText("第三学期");
    label3->setAlignment(Qt::AlignCenter);
    // label4
    QLabel *label4 = new QLabel;
    label4->setText("第四学期");
    label4->setAlignment(Qt::AlignCenter);
    // label5
    QLabel *label5 = new QLabel;
    label5->setText("第五学期");
    label5->setAlignment(Qt::AlignCenter);
    // label6
    QLabel *label6 = new QLabel;
    label6->setText("第六学期");
    label6->setAlignment(Qt::AlignCenter);
    // label7
    QLabel *label7 = new QLabel;
    label7->setText("第七学期");
    label7->setAlignment(Qt::AlignCenter);
    // label8
    QLabel *label8 = new QLabel;
    label8->setText("第八学期");
    label8->setAlignment(Qt::AlignCenter);

    // button1
    QPushButton *button1_1 = new QPushButton("确认");
    connect(button1_1, &QPushButton::clicked, this, [=](){
        emit semester1();
    });
    QPushButton *button1_2 = new QPushButton("重置");
    connect(button1_2, &QPushButton::clicked, this, [=](){
        emit resetting1();
    });
    // button2
    QPushButton *button2_1 = new QPushButton("确认");
    connect(button2_1, &QPushButton::clicked, this, [=](){
        emit semester2();
    });
    QPushButton *button2_2 = new QPushButton("重置");
    connect(button2_2, &QPushButton::clicked, this, [=](){
        emit resetting2();
    });
    // button3
    QPushButton *button3_1 = new QPushButton("确认");
    connect(button3_1, &QPushButton::clicked, this, [=](){
        emit semester3();
    });
    QPushButton *button3_2 = new QPushButton("重置");
    connect(button3_2, &QPushButton::clicked, this, [=](){
        emit resetting3();
    });
    // button4
    QPushButton *button4_1 = new QPushButton("确认");
    connect(button4_1, &QPushButton::clicked, this, [=](){
        emit semester4();
    });
    QPushButton *button4_2 = new QPushButton("重置");
    connect(button4_2, &QPushButton::clicked, this, [=](){
        emit resetting4();
    });
    // button5
    QPushButton *button5_1 = new QPushButton("确认");
    connect(button5_1, &QPushButton::clicked, this, [=](){
        emit semester5();
    });
    QPushButton *button5_2 = new QPushButton("重置");
    connect(button5_2, &QPushButton::clicked, this, [=](){
        emit resetting5();
    });
    // button6
    QPushButton *button6_1 = new QPushButton("确认");
    connect(button6_1, &QPushButton::clicked, this, [=](){
        emit semester6();
    });
    QPushButton *button6_2 = new QPushButton("重置");
    connect(button6_2, &QPushButton::clicked, this, [=](){
        emit resetting6();
    });
    // button7
    QPushButton *button7_1 = new QPushButton("确认");
    connect(button7_1, &QPushButton::clicked, this, [=](){
        emit semester7();
    });
    QPushButton *button7_2 = new QPushButton("重置");
    connect(button7_2, &QPushButton::clicked, this, [=](){
        emit resetting7();
    });
    // button8
    QPushButton *button8_1 = new QPushButton("确认");
    connect(button8_1, &QPushButton::clicked, this, [=](){
        emit semester8();
    });
    QPushButton *button8_2 = new QPushButton("重置");
    connect(button8_2, &QPushButton::clicked, this, [=](){
        emit resetting8();
    });


    // 新建布局
    QGridLayout *gridlayout = new QGridLayout(this);
    pageWidget->setLayout(gridlayout); // 添加该布局
    // 第一行
    gridlayout->addWidget(label1, 0, 0);
    gridlayout->addWidget(label2, 0, 1);
    gridlayout->addWidget(label3, 0, 2);
    gridlayout->addWidget(label4, 0, 3);
    // 第二行
    gridlayout->addWidget(table1, 1, 0);
    gridlayout->addWidget(table2, 1, 1);
    gridlayout->addWidget(table3, 1, 2);
    gridlayout->addWidget(table4, 1, 3);
    // 第三行
    QHBoxLayout *horizontalLayout1 = new QHBoxLayout;
    horizontalLayout1->addWidget(button1_1);
    horizontalLayout1->addWidget(button1_2);
    gridlayout->addLayout(horizontalLayout1, 2, 0);
    QHBoxLayout *horizontalLayout2 = new QHBoxLayout;
    horizontalLayout2->addWidget(button2_1);
    horizontalLayout2->addWidget(button2_2);
    gridlayout->addLayout(horizontalLayout2, 2, 1);
    QHBoxLayout *horizontalLayout3 = new QHBoxLayout;
    horizontalLayout3->addWidget(button3_1);
    horizontalLayout3->addWidget(button3_2);
    gridlayout->addLayout(horizontalLayout3, 2, 2);
    QHBoxLayout *horizontalLayout4 = new QHBoxLayout;
    horizontalLayout4->addWidget(button4_1);
    horizontalLayout4->addWidget(button4_2);
    gridlayout->addLayout(horizontalLayout4, 2, 3);

    // 第四行
    gridlayout->addWidget(label5, 3, 0);
    gridlayout->addWidget(label6, 3, 1);
    gridlayout->addWidget(label7, 3, 2);
    gridlayout->addWidget(label8, 3, 3);
    // 第五行
    gridlayout->addWidget(table5, 4, 0);
    gridlayout->addWidget(table6, 4, 1);
    gridlayout->addWidget(table7, 4, 2);
    gridlayout->addWidget(table8, 4, 3);
    // 第六行
    QHBoxLayout *horizontalLayout5 = new QHBoxLayout;
    horizontalLayout5->addWidget(button5_1);
    horizontalLayout5->addWidget(button5_2);
    gridlayout->addLayout(horizontalLayout5, 5, 0);
    QHBoxLayout *horizontalLayout6 = new QHBoxLayout;
    horizontalLayout6->addWidget(button6_1);
    horizontalLayout6->addWidget(button6_2);
    gridlayout->addLayout(horizontalLayout6, 5, 1);
    QHBoxLayout *horizontalLayout7 = new QHBoxLayout;
    horizontalLayout7->addWidget(button7_1);
    horizontalLayout7->addWidget(button7_2);
    gridlayout->addLayout(horizontalLayout7, 5, 2);
    QHBoxLayout *horizontalLayout8 = new QHBoxLayout;
    horizontalLayout8->addWidget(button8_1);
    horizontalLayout8->addWidget(button8_2);
    gridlayout->addLayout(horizontalLayout8, 5, 3);

    // 初始化图（关闭添加课程界面后进行）
    connect(this, &SchedulingSystem::createGraphl, this, [=](){
        int numVertex = init_project->num.toInt();
        init_project->g = new Graphl(numVertex);
        QDir dir2("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
        dir2.cd(init_project->text);
        QString filePath2 = dir2.absoluteFilePath("course.txt");
        QFile file2(filePath2);
        bool ok = file2.open(QIODevice::ReadOnly);
        // 读取文件中的课程信息
        QTextStream txtInput(&file2);
        QString lineStr;  // 每次读取文件内容的一行
        QStringList strs;  // 存储分隔后的字符
        int i = 1;  // 用于循环记录索引
        bool hasKey;
        while(!txtInput.atEnd())
        {
            lineStr = txtInput.readLine();
            strs = lineStr.split('$');
            // strs[0]为课程名称，strs[1]为先修课程，strs[2]为学分
            // name_index和name_weight对应关系处理（map类型）
            hasKey = init_project->g->name_index.contains(strs[0]);  // 判断是否已经添加过课程，若添加过，则不重复添加
            if(!hasKey) {
                init_project->g->name_index.insert(strs[0],i);
                init_project->g->name_weight.insert(strs[0],strs[2].toInt());
                i++;
            }
        }
        file2.close();
        // 再次打开文件，用于建立课程之间的前驱后继关系
        ok = file2.open(QIODevice::ReadOnly);
        int index1, index2;  // 用于存储先修课程和课程的索引
        while(!txtInput.atEnd())
        {
            lineStr = txtInput.readLine();
            strs = lineStr.split('$');
            // strs[0]为课程名称，strs[1]为先修课程，strs[2]为学分
            if(strs[1] == "") continue;  // 如果没有先修课程，说明不用添加边，进入下一次循环
            index1 = init_project->g->name_index.value(strs[1]);
            index2 = init_project->g->name_index.value(strs[0]);
            init_project->g->setEdge(index1, index2);
        }
        file2.close();

        int j;
        Graphl g(*init_project->g);  // 拷贝构造，防止对原来的图进行修改

        QString temp;

        // 第一学期选课
        Graphl g1_original(g);  // 保存g1的初始状态，重置时重新拷贝
        Graphl g1_select(g);  // 删除用户选择的课程，生成下一学期选课的初始状态

        // 一键生成课表，将入度为零的课程放入一个文件夹，分成八个学期
        for(i = 1; i <= 8; i++) {
            g.topologySort(name, 10 + i);
        }

        QCheckBox *check1[100];
        // courseSelect找出所有当前阶段可选课程
        int num1 = courseSelect(g1_original, init_project->text, 1, table1, check1);  // courseSelect函数不对原图修改
        // 选课确认后
        connect(this, &SchedulingSystem::semester1, this, [=]()mutable{
            QDir projectPath1("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
            projectPath1.cd(init_project->text);
            QString path1 = projectPath1.absoluteFilePath("第一学期.txt");
            QFile f1(path1);
            // 创建“第一学期”文件
            f1.open(QIODevice::ReadWrite);
            f1.close();
            // 清空文件内容
            f1.open(QFile::WriteOnly | QFile::Truncate);
            f1.close();
            // 将选中课程加入第一学期
            f1.open(QIODevice::Append | QIODevice::Text);
            QTextStream out1(&f1);
            for(j = 0; j < num1; j++) {
                //如果该课程被选中
                // todo：创建第一学期文件，加入文件，第一学期不可修改，删去选中课程，生成新的图状态
                if(check1[j]->isChecked()) {
                    temp = table1->item(j, 1)->text();  // 课程名称
                    out1 << temp;
                    out1 << "\n";
                    g1_select.delZero(g1_select.name_index.value(temp));
                    g1_select.Mark[g1_select.name_index.value(temp)] = 1;
                    g1_select.added[g1_select.name_index.value(temp)] = 1;  // 标记该课程已经添加过
                }
            }
            f1.close();
            for(j = 0; j < num1; j++) {
                check1[j]->setEnabled(false);
            }
            emit workDone1(g1_select);
        });

        // 第二学期选课
        // 只有第一学期选完课才能进行第二学期选课
        connect(this, &SchedulingSystem::workDone1, this, [=](Graphl original)mutable{
            Graphl g2_original(original);  // 保存初始状态，重置时重新拷贝
            Graphl g2_select(original);  // 删除用户选择的课程，生成下一学期选课的初始状态
            QCheckBox *check2[100];
            // courseSelect找出所有当前阶段可选课程
            int num2 = courseSelect(g2_original, init_project->text, 2, table2, check2);  // courseSelect函数不对原图修改
            // 选课确认后
            connect(this, &SchedulingSystem::semester2, this, [=]()mutable{
                QDir projectPath2("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
                projectPath2.cd(init_project->text);
                QString path2 = projectPath2.absoluteFilePath("第二学期.txt");
                QFile f2(path2);
                // 创建文件
                f2.open(QIODevice::ReadWrite);
                f2.close();
                // 清空文件内容
                f2.open(QFile::WriteOnly|QFile::Truncate);
                f2.close();
                // 将选中课程加入学期
                f2.open(QIODevice::Append | QIODevice::Text);
                QTextStream out2(&f2);
                for(j = 0; j < num2; j++) {
                    //如果该课程被选中
                    if(check2[j]->isChecked()) {
                        temp = table2->item(j, 1)->text();  // 课程名称
                        out2 << temp;
                        out2 << "\n";
                        g2_select.delZero(g2_select.name_index.value(temp));
                        g2_select.added[g2_select.name_index.value(temp)] = 1;  // 标记该课程已经添加过
                    }
                }
                f2.close();
                for(j = 0; j < num2; j++) {
                    check2[j]->setEnabled(false);
                }
                emit workDone2(g2_select);
            });
        });

        // 第三学期选课
        // 只有第二学期选完课才能进行第三学期选课
        connect(this, &SchedulingSystem::workDone2, this, [=](Graphl original)mutable{
            Graphl g3_original(original);  // 保存初始状态，重置时重新拷贝
            Graphl g3_select(original);  // 删除用户选择的课程，生成下一学期选课的初始状态
            QCheckBox *check3[100];
            // courseSelect找出所有当前阶段可选课程
            int num3 = courseSelect(g3_original, init_project->text, 3, table3, check3);  // courseSelect函数不对原图修改
            // 选课确认后
            connect(this, &SchedulingSystem::semester3, this, [=]()mutable{
                QDir projectPath3("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
                projectPath3.cd(init_project->text);
                QString path3 = projectPath3.absoluteFilePath("第三学期.txt");
                QFile f3(path3);
                // 创建文件
                f3.open(QIODevice::ReadWrite);
                f3.close();
                // 清空文件内容
                f3.open(QFile::WriteOnly|QFile::Truncate);
                f3.close();
                // 将选中课程加入学期
                f3.open(QIODevice::Append | QIODevice::Text);
                QTextStream out3(&f3);
                for(j = 0; j < num3; j++) {
                    //如果该课程被选中
                    if(check3[j]->isChecked()) {
                        temp = table3->item(j, 1)->text();  // 课程名称
                        out3 << temp;
                        out3 << "\n";
                        g3_select.delZero(g3_select.name_index.value(temp));
                        g3_select.added[g3_select.name_index.value(temp)] = 1;  // 标记该课程已经添加过
                    }
                }
                f3.close();
                for(j = 0; j < num3; j++) {
                    check3[j]->setEnabled(false);
                }
                emit workDone3(g3_select);
            });
        });

        // 第四学期选课
        // 只有第三学期选完课才能进行第四学期选课
        connect(this, &SchedulingSystem::workDone3, this, [=](Graphl original)mutable{
            Graphl g4_original(original);  // 保存初始状态，重置时重新拷贝
            Graphl g4_select(original);  // 删除用户选择的课程，生成下一学期选课的初始状态
            QCheckBox *check4[100];
            // courseSelect找出所有当前阶段可选课程
            int num4 = courseSelect(g4_original, init_project->text, 4, table4, check4);  // courseSelect函数不对原图修改
            // 选课确认后
            connect(this, &SchedulingSystem::semester4, this, [=]()mutable{
                QDir projectPath4("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
                projectPath4.cd(init_project->text);
                QString path4 = projectPath4.absoluteFilePath("第四学期.txt");
                QFile f4(path4);
                // 创建文件
                f4.open(QIODevice::ReadWrite);
                f4.close();
                // 清空文件内容
                f4.open(QFile::WriteOnly|QFile::Truncate);
                f4.close();
                // 将选中课程加入学期
                f4.open(QIODevice::Append | QIODevice::Text);
                QTextStream out4(&f4);
                for(j = 0; j < num4; j++) {
                    //如果该课程被选中
                    if(check4[j]->isChecked()) {
                        temp = table4->item(j, 1)->text();  // 课程名称
                        out4 << temp;
                        out4 << "\n";
                        g4_select.delZero(g4_select.name_index.value(temp));
                        g4_select.added[g4_select.name_index.value(temp)] = 1;  // 标记该课程已经添加过
                    }
                }
                f4.close();
                for(j = 0; j < num4; j++) {
                    check4[j]->setEnabled(false);
                }
                emit workDone4(g4_select);
            });
        });

        // 第五学期选课
        // 只有第四学期选完课才能进行第五学期选课
        connect(this, &SchedulingSystem::workDone4, this, [=](Graphl original)mutable{
            Graphl g5_original(original);  // 保存初始状态，重置时重新拷贝
            Graphl g5_select(original);  // 删除用户选择的课程，生成下一学期选课的初始状态
            QCheckBox *check5[100];
            // courseSelect找出所有当前阶段可选课程
            int num5 = courseSelect(g5_original, init_project->text, 5, table5, check5);  // courseSelect函数不对原图修改
            // 选课确认后
            connect(this, &SchedulingSystem::semester5, this, [=]()mutable{
                QDir projectPath5("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
                projectPath5.cd(init_project->text);
                QString path5 = projectPath5.absoluteFilePath("第五学期.txt");
                QFile f5(path5);
                // 创建文件
                f5.open(QIODevice::ReadWrite);
                f5.close();
                // 清空文件内容
                f5.open(QFile::WriteOnly|QFile::Truncate);
                f5.close();
                // 将选中课程加入学期
                f5.open(QIODevice::Append | QIODevice::Text);
                QTextStream out5(&f5);
                for(j = 0; j < num5; j++) {
                    //如果该课程被选中
                    if(check5[j]->isChecked()) {
                        temp = table5->item(j, 1)->text();  // 课程名称
                        out5 << temp;
                        out5 << "\n";
                        g5_select.delZero(g5_select.name_index.value(temp));
                        g5_select.added[g5_select.name_index.value(temp)] = 1;  // 标记该课程已经添加过
                    }
                }
                f5.close();
                for(j = 0; j < num5; j++) {
                    check5[j]->setEnabled(false);
                }
                emit workDone5(g5_select);
            });
        });

        // 第六学期选课
        // 只有第五学期选完课才能进行第六学期选课
        connect(this, &SchedulingSystem::workDone5, this, [=](Graphl original)mutable{
            Graphl g6_original(original);  // 保存初始状态，重置时重新拷贝
            Graphl g6_select(original);  // 删除用户选择的课程，生成下一学期选课的初始状态
            QCheckBox *check6[100];
            // courseSelect找出所有当前阶段可选课程
            int num6 = courseSelect(g6_original, init_project->text, 6, table6, check6);  // courseSelect函数不对原图修改
            // 选课确认后
            connect(this, &SchedulingSystem::semester6, this, [=]()mutable{
                QDir projectPath6("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
                projectPath6.cd(init_project->text);
                QString path6 = projectPath6.absoluteFilePath("第六学期.txt");
                QFile f6(path6);
                // 创建文件
                f6.open(QIODevice::ReadWrite);
                f6.close();
                // 清空文件内容
                f6.open(QFile::WriteOnly|QFile::Truncate);
                f6.close();
                // 将选中课程加入学期
                f6.open(QIODevice::Append | QIODevice::Text);
                QTextStream out6(&f6);
                for(j = 0; j < num6; j++) {
                    //如果该课程被选中
                    if(check6[j]->isChecked()) {
                        temp = table6->item(j, 1)->text();  // 课程名称
                        out6 << temp;
                        out6 << "\n";
                        g6_select.delZero(g6_select.name_index.value(temp));
                        g6_select.added[g6_select.name_index.value(temp)] = 1;  // 标记该课程已经添加过
                    }
                }
                f6.close();
                for(j = 0; j < num6; j++) {
                    check6[j]->setEnabled(false);
                }
                emit workDone6(g6_select);
            });
        });


        // 第七学期选课
        // 只有第六学期选完课才能进行第七学期选课
        connect(this, &SchedulingSystem::workDone6, this, [=](Graphl original)mutable{
            Graphl g7_original(original);  // 保存初始状态，重置时重新拷贝
            Graphl g7_select(original);  // 删除用户选择的课程，生成下一学期选课的初始状态
            QCheckBox *check7[100];
            // courseSelect找出所有当前阶段可选课程
            int num7 = courseSelect(g7_original, init_project->text, 7, table7, check7);  // courseSelect函数不对原图修改
            // 选课确认后
            connect(this, &SchedulingSystem::semester7, this, [=]()mutable{
                QDir projectPath7("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
                projectPath7.cd(init_project->text);
                QString path7 = projectPath7.absoluteFilePath("第七学期.txt");
                QFile f7(path7);
                // 创建文件
                f7.open(QIODevice::ReadWrite);
                f7.close();
                // 清空文件内容
                f7.open(QFile::WriteOnly|QFile::Truncate);
                f7.close();
                // 将选中课程加入学期
                f7.open(QIODevice::Append | QIODevice::Text);
                QTextStream out7(&f7);
                for(j = 0; j < num7; j++) {
                    //如果该课程被选中
                    if(check7[j]->isChecked()) {
                        temp = table7->item(j, 1)->text();  // 课程名称
                        out7 << temp;
                        out7 << "\n";
                        g7_select.delZero(g7_select.name_index.value(temp));
                        g7_select.added[g7_select.name_index.value(temp)] = 1;  // 标记该课程已经添加过
                    }
                }
                f7.close();
                for(j = 0; j < num7; j++) {
                    check7[j]->setEnabled(false);
                }
                emit workDone7(g7_select);
            });
        });

        // 第八学期选课
        // 只有第七学期选完课才能进行第八学期选课
        connect(this, &SchedulingSystem::workDone7, this, [=](Graphl original)mutable{
            Graphl g8_original(original);  // 保存初始状态，重置时重新拷贝
            Graphl g8_select(original);  // 删除用户选择的课程，生成下一学期选课的初始状态
            QCheckBox *check8[100];
            // courseSelect找出所有当前阶段可选课程
            int num8 = courseSelect(g8_original, init_project->text, 8, table8, check8);  // courseSelect函数不对原图修改
            // 选课确认后
            connect(this, &SchedulingSystem::semester8, this, [=]()mutable{
                QDir projectPath8("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
                projectPath8.cd(init_project->text);
                QString path8 = projectPath8.absoluteFilePath("第八学期.txt");
                QFile f8(path8);
                // 创建文件
                f8.open(QIODevice::ReadWrite);
                f8.close();
                // 清空文件内容
                f8.open(QFile::WriteOnly|QFile::Truncate);
                f8.close();
                // 将选中课程加入学期
                f8.open(QIODevice::Append | QIODevice::Text);
                QTextStream out8(&f8);
                for(j = 0; j < num8; j++) {
                    //如果该课程被选中
                    if(check8[j]->isChecked()) {
                        temp = table8->item(j, 1)->text();  // 课程名称
                        out8 << temp;
                        out8 << "\n";
                        g8_select.delZero(g8_select.name_index.value(temp));
                        g8_select.added[g8_select.name_index.value(temp)] = 1;  // 标记该课程已经添加过
                    }
                }
                f8.close();
                for(j = 0; j < num8; j++) {
                    check8[j]->setEnabled(false);
                }
                emit workDone8(g8_select);
            });
        });

        connect(this, &SchedulingSystem::workDone8, this, [=]()mutable{
            QMessageBox::information(NULL, "提示", "课程表已经生成^-^", QMessageBox::Ok, QMessageBox::Ok);
        });
    });
}

// 点击“添加”菜单后
void SchedulingSystem::on_add_triggered()
{
    addCourse *add = new addCourse;
    add->show();
    add->projectName = name;
    connect(add, &addCourse::writeFile, this, [=](QString n, QString p, QString c){
        QDir dir("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
        dir.cd(add->projectName);
        QString filePath = dir.absoluteFilePath("course.txt");
        QFile file(filePath);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << n;
        out << "$";
        out << p;
        out << "$";
        out << c;
        out << "\n";
    });
    connect(add, &addCourse::clear, this, [=]{
        QDir dir("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
        dir.cd(add->projectName);
        QString filePath = dir.absoluteFilePath("course.txt");
        QFile file(filePath);
        file.open(QFile::WriteOnly|QFile::Truncate);
        file.close();
    });
    connect(add, &addCourse::addClose, this, [=](){
        emit createGraphl();
    });
}

// 颜色转字符串
QString ColorToString(QColor v_color)
{
    QRgb mRgb = qRgb(v_color.red(), v_color.green(), v_color.blue());
    QColor mColor = QColor(mRgb);
    QString mRgbStr = QString::number(mRgb, 16);
    return mRgbStr;
}

// 查看已有课程的有向无环图
void SchedulingSystem::on_exist_triggered()
{
    courseMap *coursemap = new courseMap(nullptr, name);
    coursemap->show();
}


// 一键生成课表
void SchedulingSystem::on_automatically_triggered()
{
    automatically *a = new automatically(nullptr, name);
    a->show();
}

// 生成课程表
void SchedulingSystem::on_timetable_triggered()
{
    timetable *t = new timetable(nullptr, name);
    t->show();
}

// 新建文件
void SchedulingSystem::on_newFile_triggered()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

// 打开项目
void SchedulingSystem::on_openProject_triggered()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

// 打开文件
void SchedulingSystem::on_openFile_triggered()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

// 关闭当前项目
void SchedulingSystem::on_closeProject_triggered()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

// 关闭所有项目
void SchedulingSystem::on_closeAll_triggered()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

// 保存当前项目
void SchedulingSystem::on_saveProject_triggered()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

// 保存所有项目
void SchedulingSystem::on_saveAll_triggered()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

// 个人信息
void SchedulingSystem::on_personalInfo_triggered()
{
    QMessageBox::information(NULL, "sorry", "该功能仍在开发中~", QMessageBox::Ok, QMessageBox::Ok);
}

// 帮助文档
void SchedulingSystem::on_help_triggered()
{
    help *h = new help;
    QDir dir("../Scheduling-System/Scheduling-System/Help");  // 初始化dir为当前目录
    QString filePath = dir.absoluteFilePath("help.txt");
    QFile file(filePath);
    // 只读操作
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QByteArray line=file.readLine();
        QString str(line);
        str.remove("\n");
        h->ui->listWidget->addItem(str);
    }
    file.close();
    h->show();
}

// 关于
void SchedulingSystem::on_about_triggered()
{
    about *a = new about;
    QDir dir("../Scheduling-System/Scheduling-System/Help");  // 初始化dir为当前目录
    QString filePath = dir.absoluteFilePath("about.txt");
    QFile file(filePath);
    // 只读操作
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QByteArray line=file.readLine();
        QString str(line);
        str.remove("\n");
        a->ui->listWidget->addItem(str);
    }
    file.close();
    a->show();
}

// 待优化
void SchedulingSystem::on_todo_triggered()
{
    todo *t = new todo;
    QDir dir("../Scheduling-System/Scheduling-System/Help");  // 初始化dir为当前目录
    QString filePath = dir.absoluteFilePath("todo.txt");
    QFile file(filePath);
    // 只读操作
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QByteArray line=file.readLine();
        QString str(line);
        str.remove("\n");
        t->ui->listWidget->addItem(str);
    }
    file.close();
    t->show();
}

