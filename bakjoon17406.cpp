#include <stdio.h>
#include <stdlib.h>

int rotate(int r, int c, int s, int a[][50],int n, int m){
	int result=5000;
	int i,j,k;
	int l_x=r-s-1;
	int l_y=c-s-1;
	int r_x=r+s-1;
	int r_y=c+s-1;
	int temp;
	int copy[50][50];
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			copy[i][j]=a[i][j];
	}
	
	k=0;
	for(i=r_x-l_x;i>0;i=i-2){	
		for(j=0;j<i;j++){
			a[l_x+k][l_y+k+j+1]=copy[l_x+k][l_y+k+j];
		}
		for(j=0;j<i;j++){
			a[l_x+k+j+1][r_y-k]=copy[l_x+k+j][r_y-k];
		}
		for(j=0;j<i;j++){
			a[r_x-k][r_y-k-j-1]=copy[r_x-k][r_y-k-j];
		}
		for(j=0;j<i;j++){
			a[r_x-k-j-1][l_y+k]=copy[r_x-k-j][l_y+k];
		}
		k++;
	}
	
	for(i=0;i<n;i++){
		temp=0;
		for(j=0;j<m;j++){
			temp=a[i][j]+temp;
		}
		if(temp<result)
			result=temp;
	}
	return result;
}

int main(){
	int n,m,k;
	int a[50][50]={0,};
	int r,s,c;
	int i,j;
	int min=5000;
	int temp;
	
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	
	for(i=0;i<k;i++){
		scanf("%d %d %d",&r,&c,&s);
		temp=rotate(r,c,s,a,n,m);
		
		if(min>temp)
			min=temp;
	}
	
	printf("%d\n",min);
}
