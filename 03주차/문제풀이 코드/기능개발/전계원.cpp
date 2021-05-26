#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> progress; // 작업
    for(int i=0; i<progresses.size(); i++){
        int left_time = ceil((100-progresses[i])/(double)speeds[i]); // i번째 작업의 작업완료까지 남은 기간
        if(progress.size()>0 && progress.front() < left_time){
            // 현재 queue의 front보다 현재의 남은 작업기간이 더 길 때
            answer.push_back(progress.size());
            while(!progress.empty())
                progress.pop(); // queue 비워버리기
        }
        progress.push(left_time);
    }
    if(progress.size()>0)
        answer.push_back(progress.size()); // 가장 마지막에 남은 데이터 있으면 추가하기
    return answer;
}