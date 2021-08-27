#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Node{
	char alpha;
	Node* child[26];
	int end;
	int hit;
}node;

node* root;
vector<vector<char> > board;
vector<node*> endPoint;
long score;
long w_count;
string long_word;
int xmove[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int ymove[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int word_score[8] = {0, 0, 1, 1, 2, 3, 5, 11};
int visit[4][4] = {0,};

node* makeNode(char c){
	node* n = (node*)malloc(sizeof(node)); 
			
	n->alpha = c;
	for(int i=0;i<26;i++)
		n->child[i] = NULL;
	
	return n;
}

void insert(string word){
	node* cur = root;
	
	for(int i=0;i<word.size();i++){
		
		if(cur->child[word[i] - 'A'] == NULL){
			
			cur->child[word[i] - 'A'] = makeNode(word[i]);
			cur = cur->child[word[i] - 'A'];
		}	
		else{
			cur = cur->child[word[i] - 'A'];
		}
	}
	cur->end = 1;
	endPoint.push_back(cur);
}

void dfs(int len, node* cur, string w, int x, int y){
	if(w.length() > 8) return;
	
	if(cur->end == 1 && cur->hit == 0){
		cur->hit = 1;
		score += word_score[len - 1];
		w_count++;
		if(w.length() > long_word.length() || (w.length() == long_word.length() && w.compare(long_word) < 0)){
			long_word = w;			
		}
	}
	
	for(int i=0;i<8;i++){
		int nextx = x + xmove[i];
		int nexty = y + ymove[i];
		
		if(nextx < 0 || nextx >= 4 || nexty < 0 || nexty >= 4)
			continue;
			
		if(visit[nextx][nexty] == 0 && cur->child[board[nextx][nexty] - 'A'] != NULL){
			visit[nextx][nexty] = 1;
			dfs(len+1, cur->child[board[nextx][nexty] - 'A'], w + board[nextx][nexty], nextx, nexty);
			visit[nextx][nexty] = 0;
		}
	}
}

void init(){
	score = 0; w_count = 0; long_word = "Z";
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			visit[i][j] = 0;
		}
	}
	
	for(int i=0;i<endPoint.size();i++){
		endPoint[i]->hit = 0;
	}
}

int main(){
	int n;
	
	scanf("%d", &n);
	getchar();
	board.assign(4, vector<char>(4, 0));
	
	root = (node*)malloc(sizeof(node));
	for(int i=0;i<26;i++)
		root->child[i] = NULL;
	
	for(int i=0;i<n;i++){
		string word;
		
		getline(cin, word);
		insert(word);
	} // make trie
	
	int t;
	scanf("%d", &t);
	
	for(int i=0;i<t;i++){
		
		getchar();
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				char c;
				scanf("%1c", &c);
				board[j][k] = c;	
			}
			getchar();
		}
		// input board
		
		init();
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(root->child[board[j][k] - 'A'] != NULL){
					string tmp;
					tmp.push_back(board[j][k]);
					visit[j][k] = 1;
					dfs(1, root->child[board[j][k] - 'A'], tmp, j, k);
					visit[j][k] = 0;
				}
			}
		}
		
		printf("%ld ", score);
		cout << long_word << " ";
		printf("%ld\n", w_count);
	}
}
