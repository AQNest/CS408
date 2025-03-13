#include"HuffmanTree_link.h"

// 哈夫曼编码
#include<map>
#include<string>
typedef std::map<char, std::string> HuffmanCode;

void GetHuffmanCode(Htree T, HuffmanCode &Hcode, std::string s=""){
    /*
        递归实现：
            1、若为叶子节点，直接 Hcode[T.c] = s
            2、递归左子树（s += '0'）
            3、递归右子树 (s += '1'） 
    */
    // 递归终止条件
    if(!T) return;

    // 若为叶子结点
    if(!T->lchild && !T->rchild) Hcode[T->c] = s;

    // 递归左子树
    GetHuffmanCode(T->lchild, Hcode, s+"0");

    // 递归右子树
    GetHuffmanCode(T->rchild, Hcode, s+"1");
}