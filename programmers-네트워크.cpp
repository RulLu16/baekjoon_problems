#include <string>
#include <vector>

using namespace std;

int visit[201] = {0,};

void dfs(vector<vector<int>> computers, int parent, int n){
    for(int i=0;i<n;i++){
        if(visit[i] == 0 && computers[parent][i] == 1){
            visit[i] = 1;
            dfs(computers, i, n);
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            dfs(computers, i, n);
            answer++;
        }
    }
    
    return answer;
}
