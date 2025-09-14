#pragma once
#include"Graph.h"
#include <QMap>
#include <QString>
#include <QDir>
#include <QTextStream>
#include <QDebug>

//邻接表表示图
class Graphl : public Graph {
private:

public:
    List* list;
    QMap<QString, int> name_index;  // 记录图中Node的课程名称与索引的对应关系
    QMap<QString, int> name_weight;  // 记录图中Node的课程名称与学分的对应关系
    // 构造函数
    Graphl(int v) : Graph(v) {
		int i;
		list = new List[numVertex + 1];
		for (i = 1; i <= numVertex; i++) {
            list[i].head = new myNode(i, NULL);
			list[i].tail = list[i].head;
		}
	}

    // 拷贝构造函数
    Graphl(const Graphl &g) {
        numVertex = g.numVertex;
        // 根据结点数创建数组
        int i;
        list = new List[numVertex + 1];
        for (i = 1; i <= numVertex; i++) {
            list[i].head = new myNode(i, NULL);
            list[i].tail = list[i].head;
        }
        Mark = new bool[numVertex + 1];
        added = new bool[numVertex + 1];
        inDegree = new int[numVertex + 1];
        outDegree = new int[numVertex + 1];

        // 赋值
        myNode *temp;
        name_index = g.name_index;
        name_weight = g.name_weight;
        for(int i = 1; i <= numVertex; i++) {
            temp = g.list[i].head->next;
            while(temp != NULL) {
                setEdge(i, temp->index);
                temp = temp->next;
            }
            // 不能在此处赋值，因为更新后续的list[i]时调用seEdge会修改之前复制好的inDegree与outDegree
            // inDegree[i] = g.inDegree[i];
            // outDegree[i] = g.outDegree[i];
        }
        for(int i = 1; i <= numVertex; i++) {
            Mark[i] = g.Mark[i];
            added[i] = g.added[i];
            inDegree[i] = g.inDegree[i];
            outDegree[i] = g.outDegree[i];
        }
    }

    /*
	//析构函数
	~Graphl() {
		int i;
        myNode* temp;
		for (i = 0; i <= numVertex; i++) {
			temp = list[i].head;
			while (temp != NULL) {
				list[i].head = list[i].head->next;
				delete temp;
				temp = list[i].head;
			}
		}
		delete list;
    }*/


	//返回顶点v的第一条边
	myEdge fistEdge(int v) {
        myNode* first = list[v].head->next;
        myEdge edge(v, first->index);
        return edge;
	}
	//返回与边e有同样初始点的下一条边
    myEdge nextEdge(myEdge e) {
        myNode* first = list[e.from].head->next;
		while (first->index != e.to) {
			first = first->next;
		}
		first = first->next;
        myEdge edge(e.from, first->index);
        return edge;
	}
	//判断是否为图中的边
    bool isMyEdge(myEdge e) {
		myNode* first = list[e.from].head->next;
		if (!isEdge(e)) return false; //如果e不为边必定为假
		while (first != NULL) {
            if (first->index == e.to) return true;
			first = first->next;
		}
		return false;
	}
	//为图设置一条边
    bool setEdge(int f, int t) {
        myEdge e(f, t);
        if (isMyEdge(e)) return false; //如果该边已经存在，返回false
		else {
            list[f].insert(e);
			inDegree[t]++;
            outDegree[f]++;
			return true;
		}
	}
	//删除图的一条边
	bool delEdge(int f, int t) {
		myNode* first = list[f].head->next;
		myNode* pre = list[f].head;
		while (first != NULL) {
			//若找到该边
			if (first->index == t) break;
			pre = first;
			first = first->next;
		}
		//找到该边
		if (first != NULL) {
			pre->next = first->next;
			//如果删除的是最后一条边
			if (first->next == NULL) list[t].tail = pre;
			inDegree[t]--;
            outDegree[f]--;
			return true;
		}
		//未找到该边
		else return false;
    }

    // 删除入度为0的zero结点
    void delZero(int zIndex) {
        myNode *tempNode = list[zIndex].head->next;
        int tempIndex;
        while(tempNode != NULL) {
            tempIndex = tempNode->index;
            delEdge(zIndex, tempIndex);
            tempNode = list[zIndex].head->next;  // 指向的第一个结点
        }
    }

    // 拓扑排序并写入文件，若包含回路则返回false
    bool topologySort(QString projectName, int i) {
        bool noLoop = false;  // 如果遍历所有结点找不到入度为0的点，则说明图中包含回路
        QDir dir("../Scheduling-System/Scheduling-System/myProject");  // 初始化dir为当前目录
        dir.cd(projectName);
        QString s = QString::number(i).append(".txt");  // i.txt
        QString filePath = dir.absoluteFilePath(s);
        QFile file(filePath);
        // 以读写的方式打开文件，成功返回true，失败返回false
        // 创建i.txt文件
        file.open(QIODevice::ReadWrite);
        file.close();
        // 清空文件内容
        file.open(QFile::WriteOnly|QFile::Truncate);
        file.close();
        // 写入内容
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        int j;
        for(j = 1; j <= numVertex; j++) {
            if(inDegree[j] == 0) {
                // 如果入度为0且未被访问，说明本轮拓扑暂时未检测到环
                if(Mark[j] == 0) {
                    Mark[j] = 1;
                    noLoop = true;
                }
                // 不能直接删去边，因为会直接导致本该下一次选的课程在本次入度就为0
            }
        }
        for(j = 1; j <= numVertex; j++) {
            if(Mark[j] == 1) {
                // 如果该课程未被添加到课程表中
                if(added[j] == 0) {
                    added[j] = 1;  // 标记为已添加过，防止再次添加课程
                    delZero(j);
                    out << name_index.key(j);
                    out << "\n";
                }
            }
        }
        return noLoop;
    }
};
