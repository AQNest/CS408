#include"HuffmanTree.h"
// 获取哈夫曼编码
#include<map>
#include<string>

typedef std::map<char, std::string> HuffmanCode;

void GetHuffmanCode(Htree T, HuffmanCode &Hcode){
    std::string s;

    // 辅助数组 （倒着存）- 王卓老师版
    char assist[T.n];
    assist[T.n - 1] = '\0';

    int k = T.n;

    // 1 ~ T.n 均为叶子结点
    for(int i = 1; i <= T.n; i++){
        // 每次都从 T.n - 1 开始
        k--;

        s = "";

        // 叶子结点走到根
        int j = i;
        while(T.Nodes[j].parent){
            if(T.Nodes[T.Nodes[j].parent].lchild == j)
                assist[--k] = '0';
            else assist[--k] = '1';
            j = T.Nodes[j].parent;
        }

        // 将 assist 数组下标 k ~ n-1合并即可
        for(; k < T.n; k++) // k走到了 T.n
            s += assist[k];
        
        Hcode[T.Nodes[i].c] = s;
    }
}

