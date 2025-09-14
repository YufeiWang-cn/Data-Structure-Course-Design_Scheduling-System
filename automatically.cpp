#include "automatically.h"
#include "ui_automatically.h"

automatically::automatically(QWidget *parent, QString name) :
    QWidget(parent),
    ui(new Ui::automatically)
{
    ui->setupUi(this);
    resize(600, 450);
    setWindowTitle("auto");

    QStringList qlist;
    qlist << "第一学期" << "第二学期" << "第三学期" << "第四学期" << "第五学期" << "第六学期" << "第七学期" << "第八学期";
    int i, j;

    ui->tableWidget->setRowCount(100);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->horizontalHeader()->setVisible(true);  // 横向表头可视化
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 设置编辑方式：禁止编辑表格
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);  // 设置表格选择方式：设置表格为整行选中
    ui->tableWidget->setStyleSheet("selection-background-color:pink");  // 设置选中颜色:粉色
    ui->tableWidget->setHorizontalHeaderLabels(qlist);
    // 设置行高与列宽
    for(i = 0; i < 8; i++) ui->tableWidget->setRowHeight(i, 50);
    for(i = 0; i < 100; i++) ui->tableWidget->setColumnWidth(i, 200);

    QDir dir_("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir_为当前目录
    dir_.cd(name);
    QString s;  // 用于拼接文件名
    QString filePath_;
    QString lineStr;  // 每次读取文件内容的一行
    QStringList strs;  // 存储分隔后的字符
    for(i = 1; i <= 8; i++) {
        s = QString::number(i + 10).append(".txt");  // i.txt
        filePath_ = dir_.absoluteFilePath(s);
        QFile file_(filePath_);
        file_.open(QIODevice::ReadOnly);
        // 读取文件中的课程信息
        QTextStream txtInput_(&file_);
        j = 0;
        while(!txtInput_.atEnd())
        {
            lineStr = txtInput_.readLine();
            strs = lineStr.split(' ');
            QTableWidgetItem *temp = new QTableWidgetItem(strs[0]);
            ui->tableWidget->setItem(j, i - 1, temp);
            // 居中显示，只能对添加的单元格进行居中显示，否则程序崩溃（不能对空单元格操作）
            temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            j++;
        }
        file_.close();
    }
}

automatically::~automatically()
{
    delete ui;
}
