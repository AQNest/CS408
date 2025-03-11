#include"heap.h"

#define n 6

int main(){
    // int val[n] = {4, 3, 9, 7, 1, 5};
    
    // std::cout << "Top-Down Approach" << std::endl;
    // Heap H1 = TopCreateHeap(val, n);
    // for(int i = 0; i < H1.size; i++){
    //     std::cout << H1.val[i] << "  ";
    // }

    // std::cout << std::endl << "Down-Top Approach" << std::endl;
    // Heap H2 = DownCreateHeap(val, n);
    // for(int i = 0; i < H2.size; i++){
    //     std::cout << H2.val[i] << "  ";
    // }

    // 优先队列原理
    Heap PriorQueue;
    InitHeap(PriorQueue);
    int num;
    std::cout << "input num of values: ";
    std::cin >> num;
    int val;
    for(int i = 0; i < num; i++){
        std::cout << "Input n." << i + 1 << " value: ";
        std::cin >> val;
        insertHeap(PriorQueue, val);
    }

    // 依次弹出队头元素 (从小到大)
    while(PriorQueue.size != 0){
        std::cout << heapTop(PriorQueue) << "  ";
        PopHeap(PriorQueue);
    }

    return 0;
}