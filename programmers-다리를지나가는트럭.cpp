#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int current_weight = 0;
    queue <pair<int, int> > start;
    int time = 0;
    int index = 0;
    
    while(1){        
        if(time - start.front().first == bridge_length){
            current_weight -= start.front().second;
            start.pop();
        }
        
        if(index < truck_weights.size() && truck_weights[index] + current_weight <= weight){
            current_weight += truck_weights[index];
            start.push(make_pair(time, truck_weights[index]));
            index++;
        }
        time++;
        
        if(start.empty()) {
            break;
        }
    }
    
    return time;
}
