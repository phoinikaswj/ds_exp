/*
# 图遍历之深度优先搜索DFS

题目描述

给出一个图的邻接矩阵，对图进行深度优先搜索，图的结点编号从0到n-1

输入

第一行输入t，表示有t个测试实例

第二行输入n，表示第1个图有n个结点

第三行起，每行输入邻接矩阵的一行，以此类推输入n行

第i个结点与其他结点如果相连则为1，无连接则为0，数据之间用空格隔开

以此类推输入下一个示例

输出

每行输出一个图的深度优先搜索结果，结点编号之间用空格隔开

样例输入

2
4
0 0 1 1
0 0 1 1
1 1 0 1
1 1 1 0
5
0 0 0 1 1
0 0 1 0 0
0 1 0 1 1
1 0 1 0 0
1 0 1 0 0
样例输出

0 2 1 3 
0 3 2 1 4
*/

#include <iostream>
 
using namespace std;
 
class Graph {
public:
    int VexNum;
    int **AdjMatrix;
    bool *visited;
    Graph(int n) {
        VexNum = n;
        visited = new bool[n];
        AdjMatrix = new int*[n];
        for(int i=0; i<n; ++i)
            AdjMatrix[i] = new int[n];
        for(int i=0; i<n; ++i)
            visited[i] = false;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin >> AdjMatrix[i][j];
    }
    int firstAdjVex(int i) {
        int j;
        for(j=0; j<VexNum; ++j)
            if(AdjMatrix[i][j]) break;
        if(j<VexNum) return j;
        else return -1;
    }
    int nextAdjVex(int i, int j) {
        for(j=j+1; j<VexNum; ++j)
            if(AdjMatrix[i][j]) break;
        if(j<VexNum) return j;
        else return -1;
    }
    void DFSTraverse() {
        for(int i=0; i<VexNum; ++i)
            if (!visited[i]) DFS(i);
        cout << endl;
    }
    void DFS(int i) {
        int j;
        cout << i << ' ';
        visited[i]=true;
        for(j=firstAdjVex(i); j>=0; j=nextAdjVex(i, j))
            if(!visited[j]) DFS(j);
    }
};
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Graph graph(n);
        graph.DFSTraverse();
    }
    return 0;
}