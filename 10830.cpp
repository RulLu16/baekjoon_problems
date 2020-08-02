#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
	
void printMat(vector<vector<int> > mat){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",mat[i][j]%1000);
		}
		printf("\n");
	}
	return;
}

vector<vector<int> > calculateMat(vector<vector<int> > &first, vector<vector<int> > &second){
	vector<vector<int> > cal(n,vector<int>(n,0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				cal[i][j]+=(first[i][k]*second[k][j]);
				cal[i][j]%=1000;
			}
		}
	}
	
	return cal;
}

vector<vector<int> > pow(vector<vector<int> > &a, long long b){
	vector<vector<int> > temp(n,vector<int>(n,0));
	
	if(b==1){
		return a;
	}
	
	if(b%2==0){
		temp=pow(a,b/2);
		return calculateMat(temp, temp);
		//return calculateMat(pow(a,b/2), pow(a,b/2));
	}
	else{
		temp=pow(a,b-1);
		return calculateMat(temp, a);
	}
}

int main(){
	long long b;
	
	scanf("%lld %lld",&n,&b);
	vector<vector<int> > ans(n,vector<int>(n,0));
	vector<vector<int> > matrix(n,vector<int>(n,0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp;
			scanf("%d",&temp);
			matrix[i][j]=temp;
		}
	}
	
	ans=pow(matrix, b);
	
	printMat(ans);
}
