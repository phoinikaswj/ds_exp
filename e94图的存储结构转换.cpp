/*
# 图的存储结构转换

题目描述

已知图的顶点信息和邻接矩阵存储结构，将其转为邻近表存储结构。(不可直接输出，要有单链表定义和结点构建。）

输入

测试次数

每组测试数据格式如下：

顶点数n

n个顶点

图的邻接矩阵

输出

对每组测试数据，按样例格式输出转换后的邻接表存储结构

样例输入

2
5 
a b c d e
0 1 0 1 1
0 0 1 0 0
0 0 0 0 1
0 0 1 0 0
0 0 0 0 0
4 
0 1 2 3
0 1 1 1
1 0 1 0
1 1 0 0
1 0 0 0

样例输出

a:->1->3->4
b:->2
c:->4
d:->2
e:
0:->1->2->3
1:->0->2
2:->0->1
3:->0
*/

#include <iostream>
 
using namespace std;
 
class VexNode {
public:
    char info;
    int info_num;
    VexNode* next;
    VexNode(){next=NULL; info=' '; info_num=-1;}
};
 
void createAdjList(VexNode *vexNode, int **matrix, int n, char* info) {
    for(int i=0; i<n; ++i) {
        VexNode *node = &vexNode[i];
        VexNode *q;
        for(int j=0; j<n; ++j) {
            if(matrix[i][j]) {
                q = new VexNode;
                q->info = info[j];
                q->info_num = j;
                node->next = q;
                node = node->next;
                q = NULL;
            }
        }
    }
}
void print(VexNode *vexNode, int n) {
    for(int i=0; i<n; ++i) {
        VexNode *node = &vexNode[i];
        cout << node->info << ":";
        for(node = node->next; node; node = node->next)
            cout << "->" << node->info_num;
        cout << endl;
    }
}
 
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char info[n];
        for (int i=0; i<n; ++i) cin >> info[i];
        int **matrix;
        matrix = new int*[n];
        for(int i=0; i<n; ++i) matrix[i] = new int[n];
        VexNode *vexNode = new VexNode[n];
        for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> matrix[i][j];
        for(int i=0; i<n; ++i) {
            vexNode[i].info=info[i];
            vexNode[i].info_num=i;
        }
        createAdjList(vexNode, matrix, n, info);
        print(vexNode, n);
        delete[] vexNode;
    }
    return 0;
}