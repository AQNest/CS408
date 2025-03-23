#include"Orthogonal_linked_list.h"

int main(){
    OrthLinkGraph G;
    CreateGraph(G);

    // 依次计算 各顶点的度
    for(int i = 0; i < G.Vexnum; i++){
        // 入度，出度，度
        int InCount, OutCount, Count;
        InCount = OutCount = Count = 0;

        // 出度
        for(ArcNode *ptr = G.Vex[i].First_Adjhead; ptr != nullptr; ptr = ptr->AdjPointer)
            OutCount++;
        
        // 出度
        for(ArcNode *ptr = G.Vex[i].First_RAdjhead; ptr != nullptr; ptr = ptr->RAdjPointer)
            InCount++;

        Count = InCount + OutCount;

        std::cout << "vextex: " << G.Vex[i].Info << "   --- Indegree: " << InCount << "\tOutdegree:" << OutCount << "\tdegree:" << Count << std::endl;
    }

    return 0;
}