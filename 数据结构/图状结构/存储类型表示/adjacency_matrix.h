// 邻接矩阵存图

// 存储类型表示

// 顶点信息
typedef char VetexType;

typedef struct
{
    /* data */
    VetexType info;

    // 其他数据成员 ...
}Vetex;

// 图的几种类型
// 1、无权图 - 可以使用枚举 (限定作用域的枚举)
// 使用枚举
// Connection edge[10][10]
// edge[0][3] = Connection::Connected
enum class Connection { Connected, Disconnected };
// 或者 直接 typedef int EdgeType;

typedef struct
{
    // 一维数组存顶点
    Vetex *Vex; // 动态分配数组 G.vex = new Vetex[num];

    // 二维数组存边
    Connection **Edge; // G.edge = new Connection[num][num];
    
    // 存顶点数量 和 边的数量
    int Vexnum, Edgenum;
}UnWeighted_Graph;

// 2、有权图
typedef double EdgeType;

// 用静态分配来一次
#define MaxVexNum 100

typedef struct
{
    /* data */
    Vetex Vex[MaxVexNum];

    EdgeType Edge[MaxVexNum][MaxVexNum];

    int Vexnum, Edgenum;
}Weighted_Graph;

// 3、无向图 - 可以用压缩存储
// 用一维数组存边的关系
// n * n 矩阵 ——存入——> A[0 … {(n + 1) * n]/2 -1}] ( 定义 A[n * (n + 1) / 2] )
typedef struct
{
    Vetex vex[MaxVexNum];

    EdgeType Edge[MaxVexNum * (MaxVexNum + 1) / 2];
    // 存下三角（下标从0开始）
    // [i][j] -> [k]: k = i*(i - 1) / 2 + j - 1

    int Vexnum, Edgenum;
}Undigraph;


// 为了建图方便，统一用以下存储类型表示
typedef char VetexElemType;
typedef int EdgeElemType;

#define MaxNum 100

typedef struct
{
    /* data */
    VetexElemType Vetex[MaxNum];
    EdgeElemType Edge[MaxNum][MaxNum];

    int VexNum, EdgeNum;

}MGraph;

// 下面以建立无向网为例（会建立无向网，自然就会建立其他类型的图）
// 建无向网(含初始化，手动输入顶点信息 和 边的信息)
#include<iostream>
#include<limits>  // 也可以自定义int类型的最大值为 MAX_INT

void InitGraph(MGraph &G){
    G.EdgeNum = G.VexNum = 0;
}

int FindVex(MGraph G, VetexElemType vex1){
    for(int i = 0; i < G.VexNum; i++){
        if(G.Vetex[i] == vex1) return i;
    }
    return -1;
}

void CreateGraph(MGraph &G, int vexNum, int EdgeNum){
    G.VexNum = vexNum;
    G.EdgeNum = EdgeNum;

    // 初始化边的信息
    for(int i = 0; i < G.VexNum; i++){
        for(int j = 0; j < G.VexNum; j++){
            if(i == j) G.Edge[i][j] = 0;
            else G.Edge[i][j] = INT_MAX; // 在 <limits> 头文件中
        }
    }

    // 输入顶点信息
    std::cout << "Input VexInfo(char): ";
    for(int i = 0; i < G.VexNum; i++){
        std::cin >> G.Vetex[i];
    }

    int i = 0;
    // 依次输入边信息
    while(i < G.EdgeNum){
        VetexElemType vex1, vex2;
        std::cout << "Input vex1 and vex2 (char): ";
        std::cin >> vex1 >> vex2;
        // 查顶点表，返回坐标
        int index1 = FindVex(G, vex1);
        int index2 = FindVex(G, vex2);

        // 有这俩顶点 且 该边没有存值 才能存入该边的值
        if(index1 == index2 || index1 == -1 || index2 == -1 || G.Edge[index1][index2] != INT_MAX){
            std::cout << "Input same Vex / No such Vex / This edge already have value";
            continue;
        }
        else{
            std::cout << "Input EdgeValue: ";
            EdgeElemType value;
            std::cin >> value;
            G.Edge[index2][index1] = G.Edge[index1][index2] = value;
            i++;
        }
    }
}