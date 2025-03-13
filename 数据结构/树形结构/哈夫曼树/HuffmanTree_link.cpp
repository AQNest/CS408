#include<iostream>
#include"HuffmanTree_link.h"
 
#define n 4

int WPL(Htree T, int height = 0){
    if(!T) return 0;
    if(!T->lchild && !T->rchild)  return T->weight * height;

    // 递归
    return WPL(T->lchild, height + 1) + WPL(T->rchild, height + 1);
}


int main(){
    int weight[n] = {7, 5, 2, 4};
    char c[n] = {'a', 'b', 'c', 'd'};
    Prior_Queue Q;
    InitHuffmanTree(Q, weight, c, n);
    Htree T = CreateHuffmanTree(Q);
 
    // int wpl = 0;
    // WPL(T, wpl);

    int wpl = WPL(T);

    // 打印哈夫曼树的带权路径长度
    std::cout << "WPL = " << wpl;
 
    return 0;
}