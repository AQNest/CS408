#include "adjacency_list.h"

int main(){
    ALGraph G;
    CreateGraph(G, 5, 6);

    // 遍历输出存在边信息
    for(int i = 0; i < G.Vexnum; i++){
        for(ArcNode *ptr = G.Vex[i].next; ptr != nullptr; ptr = ptr->next){
            std::cout << "<" << G.Vex[i].info << "," << G.Vex[ptr->alvex].info << ">" << ": " << ptr->Edgeval << std::endl;
        }
    }
    return 0;
}