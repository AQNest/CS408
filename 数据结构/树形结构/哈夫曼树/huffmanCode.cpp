#include<iostream>
#include"HuffmanCode.h"

#define n 4

int main(){
    int weight[n] = {7, 5, 2, 4};
    char c[n] = {'a', 'b', 'c', 'd'};
    
    Htree T;

    InitHuffmanTree(T, weight, c, n);
    
    CreateHuffmanTree(T);

    HuffmanCode code;

    GetHuffmanCode(T, code);
    
    for(auto iter = code.begin(); iter != code.end(); iter++)
        std::cout << "char = " << iter->first <<"\t" << "Huffmancode = " << iter->second << std::endl;

    return 0;
}