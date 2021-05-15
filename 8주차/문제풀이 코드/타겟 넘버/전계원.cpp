#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    // BFS로 모든 더하고 빼는 경우의 수를 시도 했을 때의 결과를 queue에 넣기
    queue<int> q;
    q.push(numbers[0]);
    q.push(-numbers[0]);
    for(int i=1; i<numbers.size(); i++){
        int q_size = q.size();
        for(int j=0; j<q_size; j++){
            int tmp = q.front(); // 하나 빼서
            q.pop();
            q.push(tmp+numbers[i]); // i번째 값 더한 값 넣기 
            q.push(tmp-numbers[i]); // i번째 값 뺀 값 넣기
        }
    }
    
    // 하나씩 빼면서 target 넘버와 일치 하는 수의 개수 세기
    while(!q.empty()){
        if(q.front()==target)
            answer++;
        q.pop();
    }
    return answer;
}