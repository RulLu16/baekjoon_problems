#include <stdio.h>

int findNum(int n){
	int posi[3];
	int num=0;
	
	for(int i=111;i<=n;i++){
		if(i==1000) break;
		
		posi[0]=i%10;
		posi[1]=(i%100)/10;
		posi[2]=i/100;
		
		if(posi[1]-posi[0] == posi[2]-posi[1]) num++;
	}
	
	return num+99;
}

int main(){
	int n, num;
	
	scanf("%d",&n);
	
	if(n<100) num=n;
	else if(n<111) num = 99;
	else num=findNum(n);
	
	printf("%d\n",num);
}
