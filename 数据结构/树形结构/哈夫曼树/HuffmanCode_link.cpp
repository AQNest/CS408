#include"HuffmanCode_link.h"
#include<iostream>

#define n 4

int main(){
    int weight[n] = {7, 5, 2, 4};
    char c[n] = {'a', 'b', 'c', 'd'};

    Prior_Queue Q;
    InitHuffmanTree(Q, weight, c, n);

    Htree T = CreateHuffmanTree(Q);

    HuffmanCode code;
    GetHuffmanCode(T, code);

    for(auto iter = code.begin(); iter != code.end(); iter++)
        std::cout << "char = " << iter->first <<"\t" << "Huffmancode = " << iter->second << std::endl;

    return 0;
}