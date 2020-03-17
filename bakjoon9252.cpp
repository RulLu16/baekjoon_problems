#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i,j;
	int** dp;
	int** path;
	char str1[1001];
	char str2[1001];
	char temp;
	char result[1001];
	int len1,len2;
	int rl=0;
	
	dp=(int**)malloc(sizeof(int*)*1001);
	for(i=0;i<1002;i++)
		dp[i]=(int*)malloc(sizeof(int)*1001);
	path=(int**)malloc(sizeof(int*)*1001);
	for(i=0;i<1002;i++){
		path[i]=(int*)malloc(sizeof(int)*1001); //left-1 leftup-2 up-3
		for(j=0;j<1002;j++)
			path[i][j]=0;
	}
		
	scanf("%s",str1);
	scanf("%s",str2);
	
	len1=strlen(str1);
	len2=strlen(str2);
	for(i=0;i<=len2;i++){
		dp[0][i]=0;
	}
	
	for(i=1;i<=len1;i++){
		dp[i][0]=0;
		for(j=1;j<=len2;j++){
			if(str1[i-1]==str2[j-1]){
				//printf("dd");
				path[i][j]=2;
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				if(dp[i-1][j]<dp[i][j-1]){
					path[i][j]=1;
					dp[i][j]=dp[i][j-1];
				}
				else{
					dp[i][j]=dp[i-1][j];
					path[i][j]=3;
				}
			}
		}
	}
	/*for(i=0;i<=len1;i++){
		for(j=0;j<=len2;j++)
			printf("%d ",path[i][j]);
		printf("\n");
	}*/
	printf("%d\n",dp[i-1][j-1]);
	i=len1;
	j=len2;
	while(i>=1 && j>=1){
		switch(path[i][j]){
			case 1:
				j--;
				break;
			case 2:
				result[rl]=str1[i-1];
				i--;
				j--;
				rl++;
				break;
			case 3:
				i--;
				break;
		}
	}
	for(i=rl-1;i>=0;i--)
		printf("%c",result[i]);
	printf("\n");
	
}
