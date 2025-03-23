// 有向图的十字链表法


// 边表结点
typedef struct ArcNode
{
    /*data*/
    // 弧尾顶点下标
    int tailvex;

    // 弧头顶点下标
    int headvex;

    // 逆邻接表指针
    struct ArcNode *RAdjPointer;

    // 邻接表指针
    struct ArcNode *AdjPointer;

    // 若为网，则添加权值
    // double ArcVal;
}ArcNode;


typedef char VextexType;

// 顶点表结点
typedef struct
{
    /*data*/
    // 顶点信息
    VextexType Info;

    // 逆邻接表表头指针
    ArcNode *First_RAdjhead;

    // 邻接表表头指针
    ArcNode *First_Adjhead;

}VexNode;


#define MaxVexNode 100

// 图的十字链表存储
typedef struct
{
    /* data */
    //顶点表数组
    VexNode Vex[MaxVexNode];

    // 顶点和弧的个数
    int Vexnum, ArcNum;

}OrthLinkGraph;

int FindVex(OrthLinkGraph G, VextexType v){
    for(int i = 0; i < G.Vexnum; i++)
        if(G.Vex[i].Info == v) return i;
    return -1;
}

// 判断<u, v> 存在弧 
bool Exist(OrthLinkGraph G, int u, int v){
    // 找邻接表（出度）
    ArcNode *ptr = G.Vex[u].First_Adjhead;

    for(; ptr != nullptr; ptr = ptr->AdjPointer)
        if(ptr->headvex == v) return true; // <tailvex, headvex>
    
    return false;
}

// 建图过程
#include<iostream>
// 十字链表是有向图（网）的存储结构，此处以建立有向图为例
// 手动输入顶点信息和边信息
void CreateGraph(OrthLinkGraph &G){
    std::cout << "Input VexNum: ";
    std::cin >> G.Vexnum;

    std::cout << "Input ArcNum: ";
    std::cin >> G.ArcNum;

    // 初始化十字链表 并 输入顶点信息
    std::cout << "Input VexInfo(char): ";
    for(int i = 0; i < G.Vexnum; i++){
        std::cin >> G.Vex[i].Info;
        G.Vex[i].First_Adjhead = nullptr;
        G.Vex[i].First_RAdjhead = nullptr;
    }

    // 输入边信息，建立所需图的十字链表
    int i = 0;
    while(i < G.ArcNum){
        // <vex1,vex2> 弧边
        VextexType vex1, vex2;
        std::cout << "Input <vex1,vex2>(char): ";
        std::cin >> vex1 >> vex2;

        int index1 = FindVex(G, vex1);
        int index2 = FindVex(G, vex2);

        // 有这俩顶点 且 该边没有存值 才能存入该边的值
        if(index1 == index2 || index1 == -1 || index2 == -1 || Exist(G, index1, index2)){
            std::cout << "Input same Vex / No such Vex / This edge already have value" << std::endl;
            continue;
        }else{
            i++;
            // 维护邻接表和逆邻接表（重点！）
            
            // 新建边表结点
            ArcNode *newArc = new ArcNode;

            // <index1, index2>
            newArc->tailvex = index1;
            newArc->headvex = index2;

            newArc->AdjPointer = nullptr;
            newArc->RAdjPointer = nullptr;

            // 维护vex1的邻接表
            // 头插法（后半部分指针 - 邻接表）
            newArc->AdjPointer = G.Vex[index1].First_Adjhead;
            G.Vex[index1].First_Adjhead = newArc;

            // 维护vex2的逆邻接表
            // 头插法（前半部分指针 - 逆邻接表）
            newArc->RAdjPointer = G.Vex[index2].First_RAdjhead;
            G.Vex[index2].First_RAdjhead = newArc;
        }
    }

}