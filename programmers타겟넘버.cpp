#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> ope;

int calculate(vector<int> numbers){
    int sum = 0;
    
    for(int i=0;i<ope.size();i++){
        if(ope[i] == 0){
            sum += numbers[i];
        }
        else{
            sum -= numbers[i];
        }
    }
    
    return sum;
}

void dfs(int depth, vector<int> numbers, int target){
    if(depth == numbers.size()){
        if(calculate(numbers) == target){
            answer++;
        }
        
        return;
    }
    
    for(int i=0;i<2;i++){
        ope[depth] = i;
        dfs(depth + 1, numbers, target);
    }
    
    return;
}

int solution(vector<int> numbers, int target) {
    ope.assign(numbers.size(), 0);
    dfs(0, numbers, target);
    
    return answer;
}
