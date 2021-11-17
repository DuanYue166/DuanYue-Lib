#include<cstdio>
struct P{
	int a;//4
	char s;//4
	long long t;//8
};
struct PP{
	long double t;//16
	int a;		//4
	char s;		//4
};
int main(){
	printf("%d\n",sizeof(P));
	printf("%d\n",sizeof(PP));
}