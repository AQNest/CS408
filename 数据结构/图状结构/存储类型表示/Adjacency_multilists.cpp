#include"Adjacency_multilists.h"


int main(){
    AdjMulGraph G;
    CreateGraph(G);

    // 依次输出各顶点的依附边
    for(int i = 0; i < G.Vexnum; i++){
        EdgeNode *ptr = G.Vex[i].first;
        if(ptr == nullptr) continue;
        else{
            while(ptr != nullptr){
                // 判断其下一步走 Ulink还是Vlink
                if(ptr->Uvex == i){   // 走Ulink
                    std::cout << "(" << G.Vex[i].Info << "," << G.Vex[ptr->Vvex].Info << ")\t";
                    ptr = ptr->Ulink;
                }
                else if(ptr->Vvex == i){  // 走Vlink
                    std::cout << "(" << G.Vex[i].Info << "," << G.Vex[ptr->Uvex].Info << ")\t";
                    ptr = ptr->Vlink;
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}