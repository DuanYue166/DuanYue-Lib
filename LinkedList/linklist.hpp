#include<cstdio>

#define voidLL template<typename type>	\
			void LinkList<type>

template<typename type>
class LinkList{
private:
	struct Node{
		type dat;
		Node *pre,*suc;
		Node():pre(NULL),suc(NULL){}
	};
	Node *st,*ed;
	*Node find();
public:
	void push_back(type dat_);
	void push_front(type dat_);
	void erase(type dat_);
};
voidLL::push_back(type dat_){

}
voidLL::push_front(type dat_){

}
voidLL::erase(type dat_){

}