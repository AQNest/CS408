// 堆 - 完全二叉树 - 顺序存储（数组）
#include<iostream>

// 结点
typedef struct
{
    int val;    // 结点比较的值
    // 可能还有其他数据成员
}HeapNode;

// 堆
#define MAXNODE 100
typedef struct
{
    /* data */
    HeapNode node[MAXNODE];
    int size;     // 记录结点个数
}Heap_AQ;


// 为了代码更简洁 （更专注于操作本身) ,阿Q默认结点内只有 val 值
typedef struct
{
    int val[MAXNODE];
    int size;
}Heap;

void swap(int &val1, int &val2){
    int tmp = val1;
    val1 = val2;
    val2 = tmp;
}

// 初始化
void InitHeap(Heap &H){
    H.size = 0;
}

// 以下为最小堆为例

// 基本操作 - 上浮 & 下沉
// 上浮  
// 组下标从0开始，结点下标 i 的左孩子下标为 2i + 1，右孩子下标为 2i + 2
void heapifyup(Heap &H, int index){
    // 沿双亲进行比较
    int ptr = index;
    while(ptr != 0){
        int parent = (ptr - 1) >> 1;
        if(H.val[parent] > H.val[ptr]) swap(H.val[parent], H.val[ptr]);
        // 否则上浮结点已处于正确位置，退出循环即可
        else break;
        ptr = parent;
    }
}

// 插入
void insertHeap(Heap &H, int val){
    if(H.size == MAXNODE){
        std::cout << "The Heap is full" << std::endl;
        return;
    }
    // 数组尾插入
    H.val[H.size] = val;
    // 上浮操作
    heapifyup(H, H.size);
    H.size++;
}


// 下沉 
void heapifydown(Heap &H, int index){
    // 沿孩子进行比较
    int ptr = 2 * index + 1;
    while(ptr < H.size){
        int parent = (ptr - 1) >> 1;
        // 与孩子中最小的结点进行比较
        if((ptr + 1) < H.size && H.val[ptr] > H.val[ptr+1]) ptr = ptr + 1;
        if(H.val[parent] > H.val[ptr]) swap(H.val[parent], H.val[ptr]);
        // 否则下称结点已处于正确位置，退出循环即可
        else break;
        ptr = 2 * ptr + 1;
    }
}

// 弹出堆顶元素
void PopHeap(Heap &H){
    if(H.size == 0){
        std::cout << "The Heap is empty" << std::endl;
        return;
    }
    H.val[0] = H.val[H.size - 1];
    H.size--;
    heapifydown(H, 0);
}


// 查堆顶
int heapTop(Heap H){
    return H.val[0];
}

// 堆化
// 自顶向下
Heap TopCreateHeap(int val[], int n){
    Heap H;
    InitHeap(H);
    // 插入堆尾 + 上浮
    for(int i = 0; i < n; i++)
        insertHeap(H, val[i]);
    return H;
}

// 自底向上
Heap DownCreateHeap(int val[], int n){
    Heap H;
    InitHeap(H);
    for(int i = 0; i < n; i++){
        H.val[i] = val[i];
    }
    H.size = n;
    // 对每个父节点下沉
    int parent = (n - 1 - 1) >> 1;
    for(int i = parent; i > -1; i--)
        heapifydown(H, i);
    return H;
}