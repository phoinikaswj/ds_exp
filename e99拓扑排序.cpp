/*
# 拓扑排序
题目描述
已知有向图，顶点从0开始编号，求它的求拓扑有序序列。
拓扑排序算法：给出有向图邻接矩阵
1.逐列扫描矩阵，找出入度为0且编号最小的顶点v
2.输出v，并标识v已访问
3.把矩阵第v行全清0
重复上述步骤，直到所有顶点输出为止

输入
第一行输入一个整数t，表示有t个有向图
第二行输入n，表示图有n个顶点
第三行起，输入n行整数，表示图对应的邻接矩阵
以此类推输入下一个图的顶点数和邻接矩阵

输出
每行输出一个图的拓扑有序序列

样例输入
2
5
0 1 0 1 1
0 0 1 0 0
0 0 0 0 1
0 0 1 0 0
0 0 0 0 0
7
0 0 0 0 0 0 0
1 0 1 1 0 0 0
1 0 0 0 0 0 0
1 0 1 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 0 0 1 0 1 0

样例输出
0 1 3 2 4 
4 6 5 1 3 2 0 
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
        for(int i=0; i<n; ++i)
            visited[i] = false;
        AdjMatrix = new int*[n];
        for(int i=0; i<n; ++i)
            AdjMatrix[i] = new int[n];
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin >> AdjMatrix[i][j];
    }
    void topologicalSort() {
        int v;
        int indegree[VexNum];
 
        int count = VexNum;
        while (count) {
            for(int i=0; i<VexNum; ++i)
                indegree[i] = 0;
            for(int i=0; i<VexNum; ++i)
                for(int j=0; j<VexNum; ++j)
                    if(AdjMatrix[i][j])
                        ++indegree[j];
            for(v=0; v<VexNum; ++v)
                if(!indegree[v] && !visited[v]) {
                    cout << v << " ";
                    --count;
                    visited[v] = true;
                    for(int j=0; j<VexNum; ++j)
                        AdjMatrix[v][j] = 0;
                }
        }
        cout << endl;
    }
};
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Graph graph(n);
        graph.topologicalSort();
    }
    return 0;
}