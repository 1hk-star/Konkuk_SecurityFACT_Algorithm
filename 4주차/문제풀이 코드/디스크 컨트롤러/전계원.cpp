#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    // jobs가 오름차순이란 보장이 없어서 직접 오름차순 시켰음
    int answer = 0;
    vector<pair<int, int>> job_list;
    for(int i=0; i<jobs.size(); i++){
        job_list.push_back(make_pair(jobs[i][0], jobs[i][1]));
    }
    sort(job_list.begin(), job_list.end());
    
    // 작업 시작
    int cur_time, cur_idx=1;
    int total_work_time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(job_list[0].second, job_list[0].first));
    cur_time = job_list[0].first; // 현재시간은 첫 작업 요청의 시점으로 변경
    while(!pq.empty()){
        total_work_time += (cur_time + pq.top().first) - pq.top().second; // 요청부터 종료까지 시간 누적
        cur_time += pq.top().first; // 요청 종료시간 업데이트
        pq.pop();
        while(cur_idx<job_list.size() && job_list[cur_idx].first <= cur_time){
            // 현재 요청 종료시간 값 보다 작은 시점에 요청된 작업들 모두 넣어주기 
            pq.push(make_pair(job_list[cur_idx].second, job_list[cur_idx].first));
            cur_idx++;
        }
        if(pq.empty() && cur_idx < job_list.size()){
            // pq는 비어있지만, 아직 job_list가 남았음
            pq.push(make_pair(job_list[cur_idx].second, job_list[cur_idx].first));
            cur_time = job_list[cur_idx].first; // 현재시간은 다음 작업 요청의 시점으로 변경
            cur_idx++;
        }
    }
    answer = int(total_work_time / jobs.size());
    return answer;
}