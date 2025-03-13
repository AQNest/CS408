/*
题目描述
    一位老木匠需要将一根长的木棒切成N段。每段的长度分别为L1,L2,......,LN（1 <= L1,L2,…,LN <=1000，且均为整数）个长度单位。
    我们认为切割时仅在整数点处切且没有木材损失。
    木匠发现，每一次切割花费的体力与该木棒的长度成正比，不妨设切割长度为1的木棒花费1单位体力。
    例如：若N = 3，L1 = 3,L2 = 4,L3 = 5，则木棒原长为12。
    木匠可以有多种切法，如：
    第一种切法先将12切成3+9.，花费12体力，再将9切成4+5，花费9体力，一共花费21体力；
    第二种切法还可以先将12切成4+8，花费12体力，再将8切成3+5，花费8体力，一共花费20体力。
    显然，后者比前者更省体力。
    那么，木匠至少要花费多少体力才能完成切割任务呢？
 
输入描述
    第1行：1个整数N(2<=N<=50000)
    第2 - N + 1行：每行1个整数Li(1<=Li<=1000)。
 
输出描述
    输出最小的体力消耗。
 
样例输入
    3
    3
    4
    5
 
样例输出
　　19
*/


#include<iostream>
#include<queue>
#include<vector>
 
 
int main(){
    int strength, first_small, second_small;
    strength = 0;
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
 
    // n个叶子结点
    int n;
    std::cin >> n;
 
    int val;
    // 构造森林全是树
    for(int i = 0; i < n; i++){
        std::cin >> val;
        q.push(val);
    }
 
    // 循环结束 - 只剩根
    while(q.size() > 1){
        // 先用两小造新树, 删除两小添新树
        first_small = q.top();
        q.pop();
        second_small = q.top();
        q.pop();
 
        strength += first_small + second_small;
 
        q.push(first_small + second_small);
    }
    // 哈夫曼树带权路径长度 - 最小消耗精力
    std::cout << strength;
 
    return 0;
}