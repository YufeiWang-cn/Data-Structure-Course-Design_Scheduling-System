#pragma once
#include"Total.h"

class myNode {
public:
    int index = 0; // 点的索引值
    QString name = ""; // 课程名称
    int weight = 0; // 学分
    myNode* next = NULL; //指向下一条边
	//构造函数
    myNode(int d, myNode* next) {
        index = d;
        this->next = next;
    }

    myNode(int d, int w, QString n, myNode* next) {
		index = d;
		weight = w;
        name = n;
		this->next = next;
	}
};

