#include<cstring>
#include<iostream>
#include<algorithm>
enum Color{
	red,green,blue
};
struct S{
	int a,b,c;
}s;
int *q=new int;
S fun(){
	return s;
}
class Mod{
public:
	int a;
	Mod(int a):a(a){}
	int operator () (int b){
		return a%b;
	}
};
int main(){
	printf("%d\n",Mod(5)(3));
	return 0;
	int a[10];
	printf("%d\n",fun().a);
	return 0;
	int *p;
	p=new int[10];
	p[0]=1;
	printf("%d\n",*q);
	return 0;
}