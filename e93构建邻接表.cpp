/*
# 构建邻接表

已知一个图的结构，构建该图对应的邻接表

邻接表包含数组和单链表两种数据结构，其中每个数组元素也是单链表的头结点，数组元素包含两个属性，属性一是顶点编号info，属性二是指针域next指向与它相连的顶点信息。顶点编号从大写字母A开始连续编号，例如一个图有5个顶点，则顶点编号是A\B\C\D\E

单链表的每个结点也包含两个属性，属性一是顶点在数组的位置下标，属性二是指针域next指向下一个结点。

 

输入

第1行输入整数t，表示有t个图
第2行输入n和k，表示该图有n个顶点和k条弧，注意n个顶点在数组中的位置下标是0到n-1，顶点编号从大写字母A开始，连续编号n个字母。
第3行起输入k条弧的起点和终点，连续输入k行
以此类推输入下一个图
输出

输出每个图的邻接表，每行输出格式：数组下标 顶点编号-连接顶点下标-......-^
具体请参考示范数据，每行最后加入“^”表示NULL
样例输入

1
5 7
A B
A D
A E
B D
C B
C E
E D
样例输出

0 A-1-3-4-^
1 B-3-^
2 C-1-4-^
3 D-^
4 E-3-^
*/

#include <iostream>
 
using namespace std;
 
class VexNode {
public:
    char info;
    VexNode* next;
    VexNode(){next=NULL; info=' ';}
};
 
void createAdjList(VexNode* vexNode, int k) {
    for(int i=0; i<k; ++i) {
        char start, end;
        cin >> start >> end;
        int s = start-'A';
        VexNode* node = &vexNode[s];
        VexNode* q = new VexNode;
        q->info = end;
        for(; node->next && node->next->info<q->info; node = node->next);
        if(!node->next) node->next=q;
        else {
            q->next = node->next;
            node->next = q;
        }
        q = NULL;
    }
}
void print(VexNode* vexNode, int n) {
    for(int i=0; i<n; ++i) {
        VexNode* node = &vexNode[i];
        cout << i << " " << node->info << "-";
        for(node=node->next; node ; node=node->next) {
            cout << node->info-'A' << "-";
        }
        cout << "^" << endl;
    }
}
 
int main()
{
    int t;
    cin >> t;
    VexNode* vexNode;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vexNode = new VexNode[n];
        for(int i=0; i<n; ++i) {
            vexNode[i].info = i+'A';
        }
        createAdjList(vexNode, k);
        print(vexNode, n);
        delete[] vexNode;
    }
    return 0;
}