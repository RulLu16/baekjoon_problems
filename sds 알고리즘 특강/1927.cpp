#include <stdio.h>
#include <vector>

using namespace std;

vector<int> heap;
int heap_size = 1;

void heap_pop(){
	int idx = heap_size - 1;
	printf("%d\n", heap[1]);
	
	heap[1] = heap[idx];
	heap[idx] = 0;
	
	idx = 1;
	while(1){
		int change = idx*2;
		if(heap[change] == 0) break;
		
		if(heap[idx*2] > heap[idx*2+1] && heap[idx*2+1] != 0) 
			change = idx*2 + 1;
		
		if(heap[idx] > heap[change]){
			int tmp = heap[idx];
			heap[idx] = heap[change];
			heap[change] = tmp;
			
			idx = change;
		}
		else break;
	}
}

void heap_push(int command){
	int idx = heap_size;
	
	heap[idx] = command;
	
	while(1){
		if(idx == 0) break;
		
		if(heap[idx] < heap[idx/2]){
			int tmp = heap[idx];
			heap[idx] = heap[idx/2];
			heap[idx/2] = tmp;
			
			idx = idx/2;
		}
		else break;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	
	heap.assign(100000, 0);
	
	for(int i=0;i<n;i++){
		int command;
		scanf("%d", &command);
		
		if(command == 0){
			if(heap_size == 1) printf("0\n");
			else {
				heap_pop();
				heap_size--;
			}
		}
		else{
			heap_push(command);
			heap_size++;
		}
	}
}
