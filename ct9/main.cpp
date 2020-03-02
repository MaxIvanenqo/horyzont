#include <iostream>
#include "list.cpp"

int main()
{
	List q;
	q.push_back(1);
	q.push_back(4);
    q.push_back(5);
    std::cout<<"q: "<<q;
    List l;
    l.push_back(8);
    l.push_back(10);
    l.push_back(12);
    l.push_back(11);
    l.push_back(15);
    std::cout<<"q size before concat: "<<q.length()<<std::endl;
    std::cout<<"l: "<<l;
    std::cout<<"l size before concat: "<<l.length()<<std::endl;
    std::cout<<"q.concatenate(l):"<<std::endl;
    q.concatenate(l);
    std::cout<<"l size after concat: "<<l.length()<<std::endl;
    std::cout<<q;
    std::cout<<"q size after concat: "<<q.length()<<std::endl;
    q.reverse();
    std::cout<<"q.reverse(): "<<std::endl;
    std::cout<<q;
    std::cout<<"q.remove(1): " << std::endl;
    q.remove(1);
    std::cout<<q;
    std::cout<<"size after remove(): "<<q.length()<<std::endl;
    q.insert(5, 12);
    q.insert(6, 12);
    std::cout<<"size after 2xinsert():"<<q.length()<<std::endl;
    std::cout<<q;
    std::cout<<"q.removeall(12): "<<std::endl;
    q.removeall(12);
    std::cout<<q;
    std::cout<<"size after removeall(12): "<<q.length()<<std::endl;
	return 0;
}