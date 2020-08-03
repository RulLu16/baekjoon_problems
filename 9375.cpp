#include <stdio.h>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
	int t, n;
	char name[21];
	char kind[21];
	
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		map<string, int> cloth;
		std::map<string, int>::iterator it;
		int result=1;
		
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%s %s",name,kind);
		
			string key=kind;
		
			if(cloth.find(key)==cloth.end()){
				cloth.insert(make_pair(key,2));
			}
			else{
				cloth[key]++;
			}
		}
		
		for(it=cloth.begin(); it!=cloth.end(); it++){
			result*=it->second;
		}
		
		printf("%d\n",result-1);
	}
}
