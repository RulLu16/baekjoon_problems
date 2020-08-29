#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	int n;
	vector <pair<int, int> > person;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int first, second;
		
		scanf("%d %d",&first, &second);
		person.push_back(make_pair(first, second));
	}
	
	for(int i=0;i<n;i++){
		int result=0;
		for(int j=0;j<n;j++){
			if(i==j) continue;
			
			if(person[i].first<person[j].first && person[i].second<person[j].second){
				result++;
			}
		}
		printf("%d ",result+1);
	}
	printf("\n");
}
