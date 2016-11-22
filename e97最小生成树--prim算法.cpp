/*
# 最小生成树--prim算法

题目描述
使用prim算法求一个连通图的是最小生树。

输入
第一行为两个整数n，表示图有n（n < 100）个顶点。 接下来是图的邻接矩阵，权值为0表示边不存在

输出
输出只有一行，表示最小生成树所有边的和。

样例输入
3
0 1 2
1 0 3
2 3 0

样例输出
3
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
    void prim(int v) {
        int k, cnt=0;
        int low = 10000;
        struct {
            int adj;
            int lowcost;
        }closedge[VexNum];
        k = v;
        closedge[v].lowcost=0;
        for(int j=0; j<VexNum; ++j)
            if(j!=k) {
                closedge[j].adj = k;
                if(!AdjMatrix[k][j] && k!=j)
                    closedge[j].lowcost=10000;
                else
                    closedge[j].lowcost=AdjMatrix[k][j];
            }
        for(int i=1; i<VexNum; ++i) {
            low = 10000;
            for(int j=0; j<VexNum; ++j)
                if(low > closedge[j].lowcost && closedge[j].lowcost) {
                    low = closedge[j].lowcost;
                    k = j;
                }
            cnt+=closedge[k].lowcost;
            closedge[k].lowcost = 0;
            for(int j=0; j<VexNum; ++j) {
                if(closedge[j].lowcost>AdjMatrix[k][j] && AdjMatrix[k][j] && k!=j) {
                    closedge[j].adj=k;
                    closedge[j].lowcost=AdjMatrix[k][j];
                }
            }
        }
        cout << cnt << endl;
    }
};
 
int main() {
    int n;
    cin >> n;
    Graph graph(n);
    graph.prim(0);
    return 0;
}