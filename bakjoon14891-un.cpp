#include <stdio.h>
#include <stdlib.h>

int tire[4][8]={0,};
int copy[4][8]={0,};
void clock(int);
void reverse(int);
void rotate(int, int);
void copy_t(){
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++)
			copy[i][j]=tire[i][j];
	}
}
//int isrotate(int, int);
int point(){
	int result=0;
	
	if(tire[0][0]==1)
		result+=1;
	if(tire[1][0]==1)
		result+=2;
	if(tire[2][0]==1)
		result+=4;
	if(tire[3][0]==1)
		result+=8;
	
	return result;
}

int main(){
	int i,j;
	int k;
	int num, dir;
	
	for(i=0;i<4;i++){
		for(j=0;j<8;j++)
			scanf("%1d",&tire[i][j]);
	}
	
	scanf("%d",&k);
	
	for(i=0;i<k;i++){
		scanf("%d %d",&num,&dir);
		copy_t();  
		rotate(num-1,dir);
	}
	printf("%d\n",point());
}

void rotate(int num, int dir){
	int i;
	int j=0;
	
	if(dir==1){
		clock(num);
		for(i=num-1;i>=0;i--){
			if(j==0){
				if(copy[i+1][6]!=copy[i][2]){
					reverse(i);
				}
				else
					break;				
				j=1;
			}
			else{
				if(copy[i+1][6]!=copy[i][2]){
					clock(i);
				}
				else
					break;
				j=0;
			}
		}
		j=0;
		for(i=num+1;i<4;i++){
			if(j==0){
				if(copy[i-1][2]!=copy[i][6]){
					reverse(i);
				}
				else
					break;				
				j=1;
			}
			else{
				if(copy[i-1][2]!=copy[i][6]){
					clock(i);
				}
				else
					break;
				j=0;
			}
		}
		
	}
	else{
		reverse(num);
		for(i=num-1;i>=0;i--){
			if(j==0){
				if(copy[i+1][6]!=copy[i][2]){
					clock(i);
				}
				else
					break;				
				j=1;
			}
			else{
				if(copy[i+1][6]!=copy[i][2]){
					reverse(i);
				}
				else
					break;
				j=0;
			}
		}
		j=0;
		for(i=num+1;i<4;i++){
			if(j==0){
				if(copy[i-1][2]!=copy[i][6]){
					clock(i);
				}
				else
					break;				
				j=1;
			}
			else{
				if(copy[i-1][2]!=copy[i][6]){
					reverse(i);
				}
				else
					break;
				j=0;
			}
		}
	}
}

void clock(int num){
	int temp[8]={0,};
	int i;
	
	for(i=0;i<8;i++){
		temp[i]=tire[num][i];
	}
	
	for(i=1;i<8;i++){
		tire[num][i]=temp[i-1];
	}
	tire[num][0]=temp[7];
}

void reverse(int num){
	int temp[8]={0,};
	int i;
	
	for(i=0;i<8;i++){
		temp[i]=tire[num][i];
	}
	
	for(i=0;i<7;i++){
		tire[num][i]=temp[i+1];
	}
	tire[num][7]=temp[0];
}
