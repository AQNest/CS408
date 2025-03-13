// 哈夫曼的链式存储
#include<queue>
#include<vector>

typedef struct HNode
{
    /* data */
    char c;

    int weight;

    struct HNode *lchild, *rchild;
}HNode, *Htree;

// 定义自定义比较器
struct CompareHNode {
    bool operator()(const HNode* a, const HNode* b) const {
        return a->weight > b->weight; // 小顶堆（升序排列，队首最小）； 比较器的返回值直接控制元素的排列顺序，但它的语义是“谁应该排在后面”
        // 若需要大顶堆，改为 a->weight < b->weight
    }
};

typedef std::priority_queue<HNode*, std::vector<HNode*>, CompareHNode> Prior_Queue;

// 初始化
void InitHuffmanTree(Prior_Queue &q, int weight[], char c[], int n){
    // 构造森林全是树
    for(int i = 0; i < n; i++){
        HNode *node = new HNode;
        node->weight = weight[i];
        node->c = c[i];
        node->lchild = nullptr;
        node->rchild = nullptr;

        q.push(node);
    }
}

// 构造过程
Htree CreateHuffmanTree(Prior_Queue &q){
    HNode *fir_small, *sec_small;

    while(q.size() > 1){
        // 选用两小造新树，删除两小添新树
        fir_small = q.top();
        q.pop();
        sec_small = q.top();
        q.pop();

        HNode *newNode = new HNode;
        newNode->weight = fir_small->weight + sec_small->weight;
        newNode->lchild = fir_small;
        newNode->rchild = sec_small;

        q.push(newNode);
    }

    // 返回根结点
    Htree Root = q.top();

    return Root;
}