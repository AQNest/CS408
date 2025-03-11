#include "ufset.h"

int main(){
    UFSet Set;
    std::string UID[7] = {"uid:0", "uid:1","uid:2","uid:3","uid:4","uid:5","uid:6"};
    InitUFSet(Set, UID, 7);
    Union(Set, 0, 1);
    Union(Set, 1, 2);
    Union(Set, 2, 3);
    Union(Set, 3, 6);
    Union(Set, 4, 5);
    
    int Uid_A, Uid_B;
    std::cout << "UID: ";
    std::cin >> Uid_A;
    std::cout << "UID: ";
    std::cin >> Uid_B;

    if(Find(Set,Uid_A) == Find(Set, Uid_B))
        std::cout << UID[Uid_A] << " and " << UID[Uid_B] << " are friends" << std::endl;
    else
        std::cout <<  UID[Uid_A] << " and " << UID[Uid_B] << " aren't friends" << std::endl;

    return 0;
}