cmake_minimum_required(VERSION 3.3)
project(ds_exp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    e93构建邻接表.cpp
    e94图的存储结构转换.cpp
    e95图遍历之深度优先搜索DFS.cpp
    e96图的广度优先搜索BFS.cpp
    e97最小生成树--prim算法.cpp
    e98图的最短路径.cpp
    e99拓扑排序.cpp)

add_executable(ds_exp ${SOURCE_FILES})