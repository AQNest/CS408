// 并查集存储类型表示

// 为了 操作 更直观，结点内只存有parent下标
#define MAXNODE 100
int UFSets[MAXNODE];

void InitUFSet(int S[]){
    for(int i = 0; i < MAXNODE; i++)
        S[i] = -1;
}

void Union(int S[], int Root1, int Root2){
    // 原本为一个集合内
    if(Root1 == Root2) return;

    // 将 R1 并到 R2
    else S[Root1] = Root2;
}

int Find(int S[], int x){
    while(S[x] >= 0) x = S[x];
    return x;
}

// 优化版 - 小树并到大树
void Union_optimize(int S[], int Root1, int Root2){
    if(Root1 == Root2) return;
    // Root1 parent绝对值 > Root2 -> Root1是大树，Root2 合并到 Root1
    if(S[Root1] < S[Root2]){
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }else{
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}

// 优化版 - 压缩路径
int Find_optimize(int S[], int x){
    int root = x;
    // 找到子集的根节点
    while(S[root] >= 0) root = S[root];
    // 沿路节点全部挂到根节点下
    while(x != root){
        int tmp = S[x];  // 记录双亲结点
        S[x] = root;     // 沿路结点直接挂到根节点
        x = tmp;
    }
    return root;
}


// 阿Q版
#include<string>
#include<iostream>
typedef std::string UElemType;

// 结点
typedef struct
{
    /* data */
    UElemType data;
    int parent;
}UFSetNode;

// 并查集

typedef struct
{
    UFSetNode Node[MAXNODE];
    // // 或者动态分配
    // UFSetNode *UFSet;    // 初始化: UFSet = new UFSetNode[UFSet.size];
    int size; // 记录结点数
}UFSet;


void InitUFSet(UFSet &Set, std::string str[], int n = MAXNODE){
    Set.size = n;
    for(int i = 0; i < n; i++)
    {
        Set.Node[i].parent = -1;
        Set.Node[i].data = str[i];
    }  
}

// 查找 (压缩路径版)
int Find(UFSet Set, int x){
    if(x >= Set.size)  return -1;
    int root = x;
    while(Set.Node[root].parent >= 0) root = Set.Node[root].parent;
    // 压缩路径
    while(x != root){
        int tmp = Set.Node[x].parent;
        Set.Node[x].parent = root;
        x = tmp;
    }
    return root;
}

// 合并 - 小树合并到大树 - 先查找元素在哪个子集，再进行合并
void Union(UFSet &Set, int x, int y){
    int root1 = Find(Set, x);
    int root2 = Find(Set, y);
    if(root1 == root2) return;
    if(Set.Node[root1].parent < Set.Node[root2].parent){
        Set.Node[root1].parent += Set.Node[root2].parent;
        Set.Node[root2].parent = root1;
    }else{
        Set.Node[root2].parent += Set.Node[root1].parent;
        Set.Node[root1].parent = root2;
    }
}

