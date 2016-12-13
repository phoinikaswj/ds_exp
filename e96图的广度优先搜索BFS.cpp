/*
# 图的广度优先搜索BFS

题目描述

1、问题描述
给定一个结点（始点），从它开始，对（连通）图中其它结点进行广度优先搜索。

2、算法
所有顶点访问标志visited[]设置为FALSE
从某顶点v0开始，访问v0，visited[v0]=TRUE，将v0插入队列Q
⑴、如果队列Q不空，则从队列Q头上取出一个顶点v,否则结束
⑵、依次找到顶点v的所有相邻顶点v’，如果visited[v’]==FALSE，则访问该顶点v’，然后将v’插入队列Q，并使visited[v’]=TRUE，
⑶、重复⑴，⑵

输入
第一行：样本顶点个数，假设为n。
第二行，n个顶点（用空格隔开）
第三行，图中边（或弧）的数目
第四行开始：每一行是边（弧）的两个顶点（用空格隔开）

输出
广度优先搜索的顶点序列（用空格隔开，回车前无空格）
从输入的第一个顶点开始（如例题中的’a’顶点）

样例输入
6
a b c d e f
10
a b
a e
a f
b c
b d
b f
c d
d f
e d
e f

样例输出
a b e f c d
*/

#include <iostream>
#include <queue>
 
using namespace std;
 
class ArcNode{
public:
    int AdjVex;
    ArcNode* nextArc;
};
class VexNode{
public:
    char data;
    ArcNode* firstArc;
};
 
class Graph {
public:
    int VexNum;
    bool *visited;
    VexNode *head;
    Graph(int n) {
        int ArcNum;
        char x, y;
        VexNum=n;
        head = new VexNode[n];
        visited = new bool[n];
        for(int i=0; i<n; ++i) {
            cin >> head[i].data;
            head[i].firstArc=NULL;
        }
        cin >> ArcNum;
        for(int i=0; i<ArcNum; ++i) {
            cin >> x >> y;
            insertLinkList(x, y);
        }
    }
    void insertLinkList(char x, char y) {
        int i, j;
        ArcNode *p, *q;
        i=getVexNodeIndex(x);
        j=getVexNodeIndex(y);
        q = new ArcNode;
        q->nextArc=NULL;
        q->AdjVex=j;
        if(!head[i].firstArc || head[i].firstArc->AdjVex>j) {
            q->nextArc = head[i].firstArc;
            head[i].firstArc = q;
        }
        else {
            p = head[i].firstArc;
            while(p->nextArc && p->nextArc->AdjVex < y) p=p->nextArc;
            q->nextArc = p->nextArc;
            p->nextArc = q;
        }
    }
    int getVexNodeIndex(char c) {
        int i;
        for(i=0; i<VexNum; ++i)
            if(head[i].data==c) break;
        return i;
    }
    void BFSTraverse() {
        for(int i=0; i<VexNum; ++i)
            visited[i] = false;
        for(int i=0; i<VexNum; ++i)
            if(!visited[i]) BFS(i);
        cout << endl;
    }
    void BFS(int i) {
        queue<int> GQ;
        int j;
        ArcNode *p;
        cout << head[i].data;
        visited[i] =true;
        GQ.push(i);
        while (!GQ.empty()) {
            j=GQ.front();
            GQ.pop();
            p =head[j].firstArc;
            while (p) {
                j = p->AdjVex;
                if (!visited[j]) {
                    visited[j] =true;
                    cout <<" " << head[j].data;
                    GQ.push(j);
                }
                p = p->nextArc;
            }
        }
    }
};
 
int main() {
    int n;
    cin >> n;
    Graph graph(n);
    graph.BFSTraverse();
    return 0;
}