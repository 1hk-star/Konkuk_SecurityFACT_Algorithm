#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i<scoville.size(); i++){
        q.push(scoville[i]);
    }
    while(q.size()>1 && q.top()<K){
        int a, b;
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        q.push(a+b*2);
        answer++;
    }
    if(q.top()<K) 
        answer=-1;
    return answer;
}
