#include<iostream>
#include<string>
#include<map>
using std::string;
using std::map;
map<string,bool> v;
int main(){
	freopen("poems_raw.dat","r",stdin);
	freopen("poems.dat","w",stdout);
	string s;
	while(std::cin>>s){
		if(!v[s])
			std::cout<<s<<"\n";
		v[s]=1;
	}
	return 0;
}