#include"adjacency_matrix.h"

int main(){
    MGraph G;
    InitGraph(G);
    CreateGraph(G, 5, 6);
    
    // 打印顶点信息
    std::cout << "Vextexs: " << std::endl;
    for(int i = 0; i < G.VexNum; i++)
        std::cout << G.Vetex[i] << "\t";

    // 打印边信息
    std::cout << std::endl << "Edges: " << std::endl;
    for(int i = 0; i < G.VexNum; i++){
        for(int j = 0; j < G.VexNum; j++){
            std::cout << G.Edge[i][j] << "\t\t";
        }
        std::cout << std::endl;
    }
    return 0;
}