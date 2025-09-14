#pragma once
#include"myEdge.h"
#include"List.h"

class Graph {

public:
    int numVertex;  // 顶点个数
    // int numEdge;  // 边个数
    bool* Mark;  // 标记图的顶点是否被访问过
    bool* added;  // 标记课程是否已经被添加到课表
    int* inDegree;  // 存放图中顶点的入度
    int* outDegree;  // 存放图中顶点的出度
	//构造函数
	Graph() {
		numVertex = 0;
        // numEdge = 0;
	}
    Graph(int v) {
		numVertex = v;
        // numEdge = e;
		Mark = new bool[numVertex + 1];
        added = new bool[numVertex + 1];
		inDegree = new int[numVertex + 1];
		outDegree = new int[numVertex + 1];
		for (int i = 1; i <= numVertex; i++) {
			Mark[i] = 0;
            added[i] = 0;
			inDegree[i] = 0;
			outDegree[i] = 0;
		}
	}

	/*
	//析构函数
	~Graph() {
		delete[] Mark;
		delete[] inDegree;
		delete[] outDegree;
	}
	*/

	//返回图中顶点个数
	int getNumV() {
		return numVertex;
	}
	//判断e是否为边
    bool isEdge(myEdge e) {
        if (e.from >= 1 && e.from <= numVertex && e.to >= 1 && e.to <= numVertex) return true;
		else return false;
	}
};
