#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    int count = 0;
    while(pq.size()!=1 && pq.top() < K){
        // pq 내용물이 1개밖에 남지 않거나, 모든 값이 K보다 크면 종료
        int tmp1 = pq.top(); // 가장 맵지 않은 스코빌 값
        pq.pop();
        int tmp2 = pq.top(); // 두번째로 맵지 않은 스코빌 값
        pq.pop();
        pq.push(tmp1 + tmp2*2);
        count++;
    }
    if(pq.size()==1 && pq.top() < K){
        // 실패 (한 개밖에 안남았는데, K보다 작음)
        answer = -1;
    } else {
        // 성공
        answer = count;
    }
    return answer;
}