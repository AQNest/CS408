// 图的邻接表法

// 存储类型表示

// 顶点信息
typedef char vetextype;

// 边表结点
typedef struct ArcNode
{
    /* data */
    // 该顶点在顶点表的下标
    int alvex;
    
    // 指向下一个边表结点的指针
    struct ArcNode *next;

    // 若为网，则需要加上权值
    double Edgeval;
}ArcNode;

// 顶点表结点
#define MaxVexNode 100

typedef struct
{
    /*data*/
    // 顶点信息
    vetextype info;

    // 指向下一个边表结点的指针
    ArcNode *next;
}ALvexNode, AdjList[MaxVexNode]; 

// 邻接表存图
typedef struct
{
    /* data */
    // 顶点表数组
    AdjList Vex;  // 静态分配

    // 顶点个数、边的个数
    int Vexnum, EdgeNum;
}ALGraph;

// 建图过程，以建立有向网为例（手动输入顶点信息、边的信息）
#include<iostream>

int FindVex(ALGraph G, vetextype v){
    for(int i = 0; i < G.Vexnum; i++)
        if(G.Vex[i].info == v) return i;
    return -1;
}

// 判断<u, v> 存在弧 
bool Exist(ALGraph G, int u, int v){
    ArcNode *ptr = G.Vex[u].next;

    for(; ptr != nullptr; ptr = ptr->next)
        if(ptr->alvex == v) return true;
    
    return false;
}

// 头插法建边表
void CreateGraph(ALGraph &G, int vexnum, int egdenum){
    G.Vexnum = vexnum;
    G.EdgeNum = egdenum;

    // 输入顶点信息
    std::cout << "Input vex info(char): ";
    for(int i = 0; i < G.Vexnum; i++){
        std::cin >> G.Vex[i].info;
        G.Vex[i].next = nullptr;
    }

    int i = 0;
    // 边信息
    while(i < G.EdgeNum){
        // <index1, index2>
        vetextype vex1, vex2;

        // 输入待连接的顶点
        std::cout << "Input vex1 and vex2 info(char): ";
        std::cin >> vex1 >> vex2;

        // 查顶点表，返回坐标
        int index1 = FindVex(G, vex1);
        int index2 = FindVex(G, vex2);

        // 有这俩顶点 且 该边没有存值 才能存入该边的值
        if(index1 == index2 || index1 == -1 || index2 == -1 || Exist(G, index1, index2)){
            std::cout << "Input same Vex / No such Vex / This edge already have value" << std::endl;
            continue;
        }else{
            i++;

            // 新建边表结点
            ArcNode *newArc = new ArcNode;

            std::cout << "Input edgeval: ";
            std::cin >> newArc->Edgeval;

            newArc->alvex = index2;

            // 头插法
            newArc->next = G.Vex[index1].next;
            G.Vex[index1].next = newArc;
        }
    }
}
