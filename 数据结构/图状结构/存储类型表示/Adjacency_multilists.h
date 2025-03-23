// 无向图的邻接多重表存储

// 边表结点
typedef struct EdgeNode
{
    // (u,v)  - 依附的 u, v 结点下标
    int Uvex, Vvex;

    // (u,v) -> <u,v> & <v,u>
    EdgeNode *Ulink;

    EdgeNode *Vlink;

    // 若为网，则有权值数据
    // double EdgeVal;
}EdgeNode;

typedef char VextexType;

// 顶点表结点
typedef struct
{
    // 顶点信息 
    VextexType Info;

    // 边表头指针
    EdgeNode *first;
}VexNode;

#define MaxVexNum 100

// 无向图的邻接多重表
typedef struct
{
    /* data */
    VexNode Vex[MaxVexNum];

    // 顶点个数、边个数
    int Vexnum, Edgenum;
}AdjMulGraph;


int FindVex(AdjMulGraph G, VextexType v){
    for(int i = 0; i < G.Vexnum; i++)
        if(G.Vex[i].Info == v) return i;
    return -1;
}

// 判断 u, v 是否存在边
bool Exist(AdjMulGraph G, int u, int v){
    EdgeNode *ptr = G.Vex[u].first;
    if(ptr == nullptr) return false;

    for(; ptr != nullptr; ptr = ptr->Ulink)
        if(ptr->Vvex == v) return true;
    return false;
}

void Sort(int &i, int &j){
    if(i < j) return;
    else{
        int tmp = i;
        i = j;
        j = tmp;
    }
}

// 建图过程，以建立无向图的邻接多重表为例
#include<iostream>
// 手动输入顶点和边信息
void CreateGraph(AdjMulGraph &G){
    std::cout << "Input VexNum: ";
    std::cin >> G.Vexnum;

    std::cout << "Input EdgeNum: ";
    std::cin >> G.Edgenum;

    // 初始化并赋顶点信息
    std::cout << "Input VexInfo(char): ";
    for(int i = 0; i < G.Vexnum; i++){
        std::cin >> G.Vex[i].Info;
        G.Vex[i].first = nullptr;
    }

    // 建边
    int i = 0;
    while(i < G.Edgenum){
        // 输入边依附的顶点信息
        VextexType Vex1, Vex2;
        std::cout << "Input vex1 and vex2(char): ";
        std::cin >> Vex1 >> Vex2;

        int index1 = FindVex(G, Vex1);
        int index2 = FindVex(G, Vex2);
        
        // 人为の将 index1 和 index2 从小到大进行排序(简化实现过程)
        Sort(index1, index2);

        // 有这俩顶点 且 该边没有存值 才能存入该边的值
        if(index1 == index2 || index1 == -1 || index2 == -1 || Exist(G, index1, index2)){
            std::cout << "Input same Vex / No such Vex / This edge already have value" << std::endl;
            continue;
        }else{
            i++;
            // 更新邻接多重表 (重点! )

            // 建新的边结点
            EdgeNode *newEdge = new EdgeNode;
            newEdge->Uvex = index1;
            newEdge->Vvex = index2;
            newEdge->Ulink = nullptr;
            newEdge->Vlink = nullptr;
            
            // 维护边表头指针（头插法）
            // 维护第一个指针 - 正向指向 <vex1,vex2>
            newEdge->Ulink = G.Vex[index1].first;
            G.Vex[index1].first = newEdge;

            // 维护第二个指针 - 反向指向 <vex2,vex1>
            newEdge->Vlink = G.Vex[index2].first;
            G.Vex[index2].first = newEdge;
        }
    }
}
