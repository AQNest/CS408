// 堆排序
#include"heap.h"

// 在头文件里阿Q实现了最小堆
// 因此此处实现从大到小的堆排序

void Sort_largest_to_smallest(Heap &H){
    int n = H.size;
    // 维护与堆顶待交换的位置 (注意：此处应将H的 size更改，否则固定的数组区域会被更改)
    H.size--;
    while(H.size > 0){
        swap(H.val[0], H.val[H.size]);
        // 堆顶结点下沉
        heapifydown(H, 0);
        H.size--;
    }
    H.size = n;
}

Heap HeapSort(int val[], int n){
    // 要堆化为最小堆
    Heap H = DownCreateHeap(val, n);

    // 进行堆排序
    Sort_largest_to_smallest(H);

    return H;
}

#define n 6

int main(){
    int val[n] = {4, 3, 9, 7, 1, 5};
    Heap H = HeapSort(val, n);
    // 打印
    for(int i = 0; i < H.size; i++){
        std::cout << H.val[i] << "  ";
    }
    return 0;
}