/*
# 图的最短路径

题目描述
给定一个顶点（始点），求该顶点（始点）到（连通）图中其它顶点的最短路径。

输入
第一行：样本顶点个数，假设为n。
第二行，n个顶点（用空格隔开）
第三行开始到n+2行：每一行是某顶点（按第二行的输入为序）与其它顶点的距离（-1表示无穷大）
第n+3行：开始顶点

输出
共计n行（图中顶点数目）
每行是（与输入顺序相同）某顶点（距离）：路径（顶点序列，用空格隔开，回车前无空格）

样例输入
5
a b c d e
-1 5 -1 7 15
-1 -1 5 -1 -1
-1 -1 -1 -1 1
-1 -1 2 -1 -1
-1 -1 -1 -1 -1
a

样例输出
a(0):
b(5): a b
c(9): a d c
d(7): a d
e(10): a d c e
*/

#include <iostream>
using namespace std;
 
const int INFINITY = 10000;
 
class Graph {
public:
    int VexNum;
    int **AdjMatrix;
    char *vertex;
    Graph(int n) {
        VexNum = n;
        AdjMatrix = new int*[n];
        vertex = new char[n];
        for(int i=0; i<n; ++i)
            AdjMatrix[i] = new int[n];
        for(int i=0; i<n; ++i)
            cin >> vertex[i];
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin >> AdjMatrix[i][j];
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(AdjMatrix[i][j]<0) {
                    if(i==j) AdjMatrix[i][j]=0;
                    else AdjMatrix[i][j] = INFINITY;
                }
    }
    void shortestPath_DIJ (char StartVexChar, int Dest[], char Path[][100]) {
        int i, j, m, startVex, currentVex, minDest;
        int s[VexNum];
        for(i=0; i<VexNum; ++i)
            if (vertex[i] == StartVexChar) {
                startVex = i;
                Path[startVex][0] = '\0';
                break;
            }
        for(i=0; i<VexNum; ++i) {
            if(i != startVex) {
                Dest[i] = INFINITY;
                if(AdjMatrix[startVex][i] < INFINITY) {
                    Dest[i] = AdjMatrix[startVex][i];
                    Path[i][0] = vertex[startVex];
                    Path[i][1] = vertex[i];
                    Path[i][2] = '\0';
                }
                s[i] = 'F';
            }
        }
        Dest[startVex] = 0;
        s[startVex] = 'T';
        for(i=0; i<VexNum; ++i) {
            minDest = INFINITY;
            for(j=0; j<VexNum; ++j) {
                if(s[j] == 'F' && Dest[j]<minDest) {
                    currentVex = j;
                    minDest = Dest[j];
                }
            }
            s[currentVex] = 'T';
            for(j=0; j<VexNum; ++j) {
                if(s[j]=='F' && minDest+AdjMatrix[currentVex][j]<Dest[j]) {
                    Dest[j] = minDest+AdjMatrix[currentVex][j];
                    for(m=0; Path[currentVex][m]!='\0'; ++m)
                        Path[j][m] = Path[currentVex][m];
                    Path[j][m++] = vertex[j];
                    Path[j][m]='\0';
                }
            }
        }
    }
};
 
 
 
int main() {
    int n;
    cin >> n;
    int Dest[n];
    char Path[n][100];
    Graph graph(n);
    char ch;
    cin >> ch;
    graph.shortestPath_DIJ(ch, Dest, Path);
    for(int i=0; i<n; ++i) {
        cout << graph.vertex[i] << "(" << Dest[i] << "):";
        for(int j=0; Path[i][j]; ++j)
            cout << " " << Path[i][j];
        cout << endl;
    }
    return 0;
}