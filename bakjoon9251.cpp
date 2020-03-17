#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i,j;
	int** dp;
	char str1[1001];
	char str2[1001];
	char temp;
	int len1,len2;
	
	dp=(int**)malloc(sizeof(int*)*1001);
	for(i=0;i<1002;i++)
		dp[i]=(int*)malloc(sizeof(int)*1001);
		
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
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				if(dp[i-1][j]<dp[i][j-1])
					dp[i][j]=dp[i][j-1];
				else
					dp[i][j]=dp[i-1][j];
			}
		}
	}

	
	printf("%d\n",dp[i-1][j-1]);
}
