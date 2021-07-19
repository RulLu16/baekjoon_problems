#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	int t;
	char temp;
	int flag=0;
	vector <char> v;
	
	scanf("%d",&t);
	getchar();
	
	for(int i=0;i<t;i++){
		while(1){
			scanf("%1c",&temp);
			
			if(temp=='('){
				v.push_back(temp);
			}
			else if(temp==')'){
				if(!v.empty()){
					v.pop_back();
				}
				else{
					flag=1;
				}
			}
			else{
				//getchar();
				if(v.empty() && flag==0){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
				break;
			}
		}
		v.clear();
		flag=0;
	}
}
