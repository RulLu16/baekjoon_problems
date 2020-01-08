#include <stdio.h>
#include <stdlib.h>

int main(){
	int con[4][2];
	int i;
	int tempx,tempy;
	
	for(i=0;i<3;i++){
		scanf("%d %d",&con[i][0],&con[i][1]);
	}
	
	tempx=con[0][0];
	if(tempx==con[1][0]){
		con[3][0]=con[2][0];
	}
	else{
		if(tempx==con[2][0]){
			con[3][0]=con[1][0];
		}
		else
			con[3][0]=tempx;
	}
	
	tempy=con[0][1];
	if(tempy==con[1][1]){
		con[3][1]=con[2][1];
	}
	else{
		if(tempy==con[2][1]){
			con[3][1]=con[1][1];
		}
		else
			con[3][1]=tempy;
	}
	
	printf("%d %d\n",con[3][0],con[3][1]);
}
