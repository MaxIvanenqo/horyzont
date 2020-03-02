#include <cstdlib>
#include <ctime>
#include "bst.cpp"

int main(){
    Bst bst;
    srand(time(nullptr));
    for (int i = 0; i < 30; ++i)
        bst.insert(rand() % 100);
    bst.print();
    std::cout<<std::endl;
    std::cout<<"height "<<bst.height()<<std::endl;
    std::cout<<"width  "<<bst.width()<<std::endl;
    return 0;
}