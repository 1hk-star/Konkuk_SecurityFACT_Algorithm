#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> bridge; // truck_idx, fin_time
    int curTime = 0, curWeight = 0; // 현재시간, 현재 다리 위 무게
    for(int i=0; i<truck_weights.size(); i++){
        curTime+=1;
        if(bridge.size()>0 && bridge.front().second==curTime){
            // 맨 앞 트럭이 도착시간이 되면, 트럭 빼주기
            curWeight -= truck_weights[bridge.front().first];
            bridge.pop();
        }
        while(weight < curWeight+truck_weights[i]){
            // 트럭이 오르지 못함
            curWeight -= truck_weights[bridge.front().first];
            curTime = bridge.front().second;
            bridge.pop();            
        }
        //트럭이 다리에 오를 수 있음
        bridge.push(make_pair(i, curTime+bridge_length));
        curWeight+=truck_weights[i];
    }
    answer = bridge.back().second;
    return answer;
}