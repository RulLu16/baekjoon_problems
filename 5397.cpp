#include <stdio.h>
#include <list>

using namespace std;

int main(){
	int n;
	
	scanf("%d",&n);	
	getchar();
	
	for(int i=0;i<n;i++){
		list <char> password;
		list <char>::iterator cursor = password.begin();
		
		while(1){
			char temp;
			scanf("%1c",&temp);
			
			if(temp=='>'){
				if(cursor !=password.end()){
					cursor++;
				}
			}
			else if(temp=='<'){
				if(cursor !=password.begin()){
					cursor--;
				}
			}
			else if(temp=='-'){
				if(cursor !=password.begin()){
					cursor=password.erase(--cursor);
				}
			}
			else if(temp=='\n') break;
			else{
				password.insert(cursor, temp);
			}
		}
		for(cursor=password.begin(); cursor!=password.end(); cursor++){
			printf("%c",*cursor);
		}
		printf("\n");
	}
}
