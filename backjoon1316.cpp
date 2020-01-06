#include <stdio.h>
#include <stdlib.h>

int main(){
	int isGroup[26];
	int alpha,i,j;
	int n;
	int check=0;
	char first, second;
	int total=0;
	
	scanf("%d",&n);
	getchar();
	
	for(i=0;i<n;i++){
		check=0;
		for(j=0;j<26;j++)
			isGroup[j]=0;
		scanf("%c",&first);
		isGroup[(int)first-97]++;
		
		while(1){
			scanf("%c",&second);
			if(second=='\n')
				break;
			if(first==second)
				isGroup[(int)second-97]++;
			else{
				if(isGroup[(int)second-97]==0)
					isGroup[(int)second-97]++;
				else
					check=1;
			}
			
			first=second;				
		}
		if(check==0)
			total++;
	}
	
	printf("%d",total);
}
