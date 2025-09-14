#pragma once
#include"Total.h"

class myEdge {
    friend class Graph;
	friend class Graphl;
	friend class List;
private:
    int from, to;//起始点，终止点

public:
	//构造函数
    myEdge() {
		from = 0;
        to = 0;
	}
    myEdge(int f, int t) {
		from = f;
        to = t;
	}
};
