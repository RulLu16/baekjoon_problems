#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(){
	int n;
	
	scanf("%d", &n);
	getchar();
	
	for(int i=0;i<n;i++){
		string command;
		getline(cin, command);
		
		string sub = command.substr(0, 2);
		
		if(!sub.compare("pu")){
			s.push(stoi(command.substr(5)));
		}
		else if(!sub.compare("po")){
			if(s.empty()){
				printf("-1\n");
			}
			else{
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if(!sub.compare("si")){
			printf("%d\n", s.size());
		}
		else if(!sub.compare("em")){
			if(s.empty()) printf("1\n");
			else printf("0\n");
		}
		else if(!sub.compare("to")){
			if(s.empty()){
				printf("-1\n");
			}
			else{
				printf("%d\n", s.top());
			}
		}
	}
}
