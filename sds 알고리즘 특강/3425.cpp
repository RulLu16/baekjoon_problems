#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

stack<long long> s;
vector<string> command;

int num(long long x){
	s.push(x);
	return 1;
}

int pop(){
	if(s.empty()) return 0;
	s.pop();
	return 1;
}

int inv(){
	if(s.empty()) return 0;
	long long tmp = s.top();
	s.pop();
	s.push(0 - tmp);
	
	return 1;
}

int dup(){
	if(s.empty()) return 0;
	
	s.push(s.top());
	return 1;
}

int swp(){
	if(s.size() < 2) return 0;
	
	long long first = s.top(); s.pop();
	long long second = s.top(); s.pop();
	
	s.push(first);
	s.push(second);
	
	return 1;
}

int add(){
	if(s.size() < 2) return 0;
	long long first = s.top(); s.pop();
	long long second = s.top(); s.pop();
	
	if(abs(first + second) > 1000000000) return 0;
	
	s.push(first + second);
	
	return 1;
}

int sub(){
	if(s.size() < 2) return 0;
	long long first = s.top(); s.pop();
	long long second = s.top(); s.pop();
	
	if(abs(second - first) > 1000000000) return 0;
	
	s.push(second - first);
	
	return 1;
}

int mul(){
	if(s.size() < 2) return 0;
	long long first = s.top(); s.pop();
	long long second = s.top(); s.pop();
	
	if(abs(first * second) > 1000000000) return 0;
	
	s.push(first * second);
	
	return 1;
}

int div(){
	if(s.size() < 2) return 0;
	long long first = s.top(); s.pop();
	long long second = s.top(); s.pop();
	
	if(first == 0) return 0;
	
	s.push(second / first);
	
	return 1;
}

int mod(){
	if(s.size() < 2) return 0;
	long long first = s.top(); s.pop();
	long long second = s.top(); s.pop();
	
	if(first == 0) return 0;
	
	s.push(second % first);
	
	return 1;
}

void s_clear(){
	while(!s.empty()) s.pop();
}

int process(){
	for(int i=0;i<command.size();i++){
		int success;
		
		string co = command[i].substr(0, 3);
		
		if(co.compare("NUM") == 0){
			success = num(stoi(command[i].substr(4)));	
		}
		else if(co.compare("POP") == 0){
			success = pop();
		}
		else if(co.compare("INV") == 0){
			success = inv();
		}
		else if(co.compare("DUP") == 0){
			success = dup();
		}
		else if(co.compare("SWP") == 0){
			success = swp();
		}
		else if(co.compare("ADD") == 0){
			success = add();
		}
		else if(co.compare("SUB") == 0){
			success = sub();
		}
		else if(co.compare("MUL") == 0){
			success = mul();
		}
		else if(co.compare("DIV") == 0){
			success = div();
		}
		else if(co.compare("MOD") == 0){
			success = mod();
		}
		
		if(success == 0){
			printf("ERROR\n");
			return 0;
		}
	}
	
	return 1;
}

int main(){
	
	while(1){
		command.assign(0, "");
		string tmp;
		getline(cin, tmp);
		
		if(tmp.compare("") == 0) continue;
		
		if(tmp.compare("QUIT") == 0)
			return 0;

		while(1){			
			if(tmp.compare("END") == 0){
				break;
			}
			command.push_back(tmp);
			
			getline(cin, tmp);
		}
		
		int iter;
		scanf("%d", &iter);
		
		for(int i=0;i<iter;i++){
			s_clear();
			long long init;
			
			scanf("%lld", &init);
			s.push(init);
			
			if(process() == 1){
				if(s.empty() || s.size() > 1) printf("ERROR\n");
				else printf("%lld\n", s.top());
			}
		}
		printf("\n");
	}
	
	return 0;
}
