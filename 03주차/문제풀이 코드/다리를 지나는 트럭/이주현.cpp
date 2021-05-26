#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    int sum = 0;
    int cnt = 0;
    /*
    0 7출발
    1 7가는중
    2 7거의도착? 3에 완전 도착
    3 4출발
    4 4가는중 5출발
    5 4도착 5가는중
    6 5도착
    7 6가는중
    8 6도착
    */
    for(int i=0; i<truck_weights.size(); i++) {
        int w = truck_weights[i];
 
        while (true) {
 
            if (q.empty()) { ////무조건 보내기
                q.push(w); //1) 7넣기
                cnt++; //2) cnt 1됨
                sum += w; //3) sum 7됨
                break;
            }
            
            ////무조건 지남
            else if (q.size() == bridge_length) { //7) 2=2
                sum -= q.front(); //8) sum(7) - 7 =0
                q.pop(); //9) 7 pop (4 남아있음)
            }
            
            ////그 외 상황(보내야하는가?)
            else {
 
                if (sum + w > weight) { //4) 7+4 > 10 
                    ////0 push는 시간때우기임
                    q.push(0); //5) 0 push
                    cnt++; //6) cnt 2됨
                }
                else { //10 4+5 <= 10
                    q.push(w); //11) push 5
                    cnt++; //12) cnt 3됨
                    sum += w; //13) sum 9됨
                    break;
                }
            }
        }
    }
    
    return cnt + bridge_length; //cnt는 마지막 차량이 갈때
}