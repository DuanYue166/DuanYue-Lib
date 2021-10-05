#include<cstdio>
int main(){
	int *a,*b;
	a=new int;
	(*a)=1;
	b=new int;
	*b=*a;
	(*b)=2;
	printf("%d\n",*a);
	return 0;
}