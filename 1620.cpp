#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	map<int, string> findByNum;
	map<string, int> findByName;
	
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++){
		char str[21];
		scanf("%s",str);
		
		string temp=str;				
		findByNum.insert(make_pair(i,temp));
		findByName.insert(make_pair(temp, i));
	}
	
	for(int i=0;i<m;i++){
		char temp[21];
		scanf("%s",temp);
		
		if(temp[0]>='0' && temp[0]<='9'){
			int key=atoi(temp);
			std::map<int, string>::iterator it=findByNum.find(key);
			// iterator°¡ Á¤È®È÷ ¹¹Â¡..
			string print=it->second;
			printf("%s\n",print.c_str());
		}
		else{
			string skey=temp;
			std::map<string, int>::iterator it=findByName.find(skey);
			printf("%d\n",it->second);
		}
	}
}
