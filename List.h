#pragma once
#include"myNode.h"
#include"myEdge.h"

class List {
public:
    myNode* head = NULL; //头指针
    myNode* tail = NULL; //尾指针
	//构造函数
    List() {}
	//插入操作
    void insert(myEdge e) {
        myNode* temp = head;
        myNode* node;
		while (temp->next != NULL) {
			if (e.to < temp->next->index) break;
			temp = temp->next;
		}
		if (temp == NULL || temp->next == NULL) {
            node = new myNode(e.to, NULL);
            tail = node;
		}
        else node = new myNode(e.to, temp->next);
        temp->next = node;
    }

	//析构函数
	~List() {
        myNode* temp = head;
		while (temp != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
    }
};
