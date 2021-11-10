#include<cstdio>
#include<cstring>
int main(){
	freopen("words_noNum.dat","r",stdin);
	freopen("words_two_noNum.dat","w",stdout);
	char s[20];
	while(~scanf("%s",s)){
		if(strlen(s)>3)
			printf("%s\n",s);
	}
	return 0;
}