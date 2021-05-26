#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //트럭의 무게, 남은 다리의 수
    map<int, int> waiting;
    int time=0;
    //도로 위에 있는 트럭의 무게의 합
    int total = 0;
    while(truck_weights.size() !=0) {
        time+=1;
        //waiting이 bridge_length보다 작은 경우에만 추가 가능
        if(waiting.size() <= bridge_length) {
            //도로 위에 있는 트럭의 무게의 합과 새로 들어올 트럭의 무게의 합이 weight 보다 작은 경우만 추가 가능
            if(total+truck_weights<=weight) {

            }

        }
    }
    return answer;
}

int main(void) {

} 
