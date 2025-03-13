// 顺序存储

typedef int WeightType;  // float、double、..

typedef struct
{
    /* data */
    char c;

    WeightType weight;
    
    int parent;
    
    int lchild;

    int rchild;
}HNode;

typedef struct
{
    /* data */
    HNode *Nodes;    // 动态分配

    int n;          // 记录叶子结点树，分配 Htree.Nodes = new HNode[2 * n]

    // int r;         // 记录根结点下标
}Htree;

// 初始化
void InitHuffmanTree(Htree &T, int weight[], char c[] ,int n){
    T.n = n;
    T.Nodes = new HNode[2*n];
    
    for(int i = 1; i < 2*n; i++){
        T.Nodes[i].weight = 0;
        T.Nodes[i].lchild = 0;
        T.Nodes[i].rchild = 0;
        T.Nodes[i].parent = 0;
    }

    for(int i = 1; i <= n; i++){
        T.Nodes[i].weight = weight[i-1];
        T.Nodes[i].c = c[i-1];
        // 或者直接输入权值(不传weight数组)
        // cin >> T.Nodes[i].weight;
    }
}

// 找到最小的两个权值的下标（注意：从 parent == 0中找 - 未组成新树)
// 查找可自行完成 - 阿Q用了最笨的办法
void FindSmall(Htree T, int rlimit, int &fir_small, int &sec_small){
    fir_small = sec_small = -1;
    
    // 先找一遍最小值
    for(int i = 1; i < rlimit; i++){
        // 若已组成新树
        if(T.Nodes[i].parent) continue;

        if(fir_small < 0) fir_small = i;
        else if(T.Nodes[i].weight < T.Nodes[fir_small].weight) fir_small = i;
    }

    // 再找一遍倒数第二大的
    for(int i = 1; i < rlimit; i++){
        if(T.Nodes[i].parent || i == fir_small) continue;

        if(sec_small < 0) sec_small = i;
        else if(T.Nodes[i].weight < T.Nodes[sec_small].weight) sec_small = i;
    }
}

// 构造过程
void CreateHuffmanTree(Htree &T){
    int fir_small, sec_small;
    for(int i = T.n+1; i < 2*T.n; i++){
        // 找到最小的两个权值的下标
        FindSmall(T, i, fir_small, sec_small);
        
        // 组新树
        T.Nodes[fir_small].parent = i;
        T.Nodes[sec_small].parent = i;
        T.Nodes[i].lchild = fir_small;
        T.Nodes[i].rchild = sec_small;
        T.Nodes[i].weight = T.Nodes[fir_small].weight + T.Nodes[sec_small].weight;
    }
}


