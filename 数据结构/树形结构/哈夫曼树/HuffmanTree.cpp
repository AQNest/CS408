#include<iostream>
#include"HuffmanTree.h"
 
#define n 4
 
int main(){
    int weight[n] = {7, 5, 2, 4};
    char c[n] = {'a', 'b', 'c', 'd'};
    Htree T;
    InitHuffmanTree(T, weight, c, n);
    CreateHuffmanTree(T);
 
    int wpl = 0;
 
    // 打印数组
    std::cout << "index\tWeight\tParent\tlchild\trchild\t" << std::endl;
    for(int i = 1; i < 2*n; i++){
        std::cout << i << "\t" << T.Nodes[i].weight << "\t" << T.Nodes[i].parent << "\t" << T.Nodes[i].lchild << "\t" << T.Nodes[i].rchild << std::endl;
        wpl += T.Nodes[i].weight;
    }
 
    wpl -= T.Nodes[2*n-1].weight;
    // 打印哈夫曼树的带权路径长度
    std::cout << "\tWPL = " << wpl;
 
    return 0;
}