#include <stdio.h>
#include <stack>

using namespace std;

int main(){
	stack <char> bracket;
	int found=0;
	int only=0;
	
	char temp;
	while(scanf("%1c",&temp)!=NULL){
		if(temp=='.'){
			if(only==0){
				break;
			}
			getchar();
			if(bracket.empty() && found==0){
				printf("yes\n");
			}
			else{
				printf("no\n");
			}
			
			while(!bracket.empty()){
				bracket.pop();
			}
			found=0;
			only=0;
			
			continue;
		}
		only=1;
		
		if(temp=='(' || temp=='['){
			bracket.push(temp);
		}
		else if(temp==')'){
			if(bracket.empty() || bracket.top()!='(') {
				found=1;
				continue;	
			}
			bracket.pop();
		}
		else if(temp==']'){
			if(bracket.empty() || bracket.top()!='[') {
				found=1;
				continue;	
			}
			bracket.pop();
		}
	}
}
